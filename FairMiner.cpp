// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "FairMiner.h"
#include <random>
#include "ChainRandom.h"
#include "BlockNext.h"

using namespace std;

FairMiner::FairMiner(const string &name)
	: name(name)
{
}

shared_ptr<Block> FairMiner::mine(const shared_ptr<const Chain> &chain) const
{
	const auto parent = ChainRandom(chain).heads().front();

	default_random_engine rand(random_device{}());
	const auto block = make_shared<BlockNext>(parent, name, rand());
	// @todo #14 Add difficulty
	if (block->hash().find("0") == 0) {
		return block;
	}
	return {};
}
