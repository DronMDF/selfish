// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "FairMiner.h"
#include <iomanip>
#include <random>
#include "ChainRandom.h"
#include "BlockNext.h"

using namespace std;

FairMiner::FairMiner(const string &name)
	: name(name)
{
}

// @todo #16 This code should not be here, This is another class Difficulty
int FairMiner::difficulty(const shared_ptr<const Block> &block) const
{
	uint64_t value;
	istringstream in(block->hash());
	// @todo #16 Avoid 31bit lock
	in >> hex >> setw(8) >> setfill('0') >> value;
	int difficulty = 0;
	if (value > 0) {
		while ((value & (1LLU << 31)) == 0) {
			difficulty++;
			value <<= 1;
		}
	}
	return difficulty;
}

shared_ptr<Block> FairMiner::mine(const shared_ptr<const Chain> &chain) const
{
	const auto parent = ChainRandom(chain).heads().front();

	default_random_engine rand(random_device{}());
	const auto block = make_shared<BlockNext>(parent, name, rand(), chain->difficulty());
	if (difficulty(block) >= chain->difficulty()) {
		return block;
	}
	return {};
}
