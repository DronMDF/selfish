// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "MinerFair.h"
#include <random>
#include "ChainRandom.h"
#include "BlockDifficulty.h"
#include "BlockNext.h"

using namespace std;

MinerFair::MinerFair(const string &name)
	: user(name)
{
}

string MinerFair::name() const
{
	return user;
}

shared_ptr<Block> MinerFair::mine(const shared_ptr<const Chain> &chain) const
{
	const auto parent = ChainRandom(chain).heads().front();

	default_random_engine rand(random_device{}());
	const auto block = make_shared<BlockNext>(parent, user, rand(), chain->difficulty());
	if (BlockDifficulty(block).value() >= chain->difficulty()) {
		return block;
	}
	return {};
}

int MinerFair::amount(const shared_ptr<const Chain> &chain) const
{
	return chain->heads().front()->amount(user);
}
