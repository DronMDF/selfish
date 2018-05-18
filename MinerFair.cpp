// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "MinerFair.h"
#include <random>
#include "BlockDifficulty.h"
#include "BlockNext.h"
#include "Chain.h"

using namespace std;

MinerFair::MinerFair(const string &name)
	: user(name)
{
}

string MinerFair::name() const
{
	return user;
}

shared_ptr<Block> MinerFair::mine(const list<shared_ptr<const Block>> &heads, int difficulty) const
{
	default_random_engine rand(random_device{}());
	auto head = heads.begin();
	advance(head, rand() % heads.size());
	return make_shared<BlockNext>(*head, user, rand(), difficulty);
}
