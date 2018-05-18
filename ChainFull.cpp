// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ChainFull.h"
#include <iostream>
#include "Block.h"
#include "BlockDifficulty.h"
#include "Miner.h"

using namespace std;

ChainFull::ChainFull(const list<shared_ptr<const Block>> &blocks)
	: blocks(blocks)
{
}

int ChainFull::difficulty() const
{
	// @todo #16 Disable negative difficulty
	auto difficult = blocks.front()->difficulty();
	if (blocks.front()->difficultySeries() > 60) {
		const auto first = blocks.front()->getNthParentTime(60);
		const auto last = blocks.front()->getNthParentTime(0);
		const auto interval = last - first;
		if (interval < chrono::seconds(30)) {
			difficult++;
		} else if (interval > chrono::seconds(90)) {
			difficult--;
		}
	}
	return difficult;
}

shared_ptr<const Chain> ChainFull::mine(const list<shared_ptr<const Miner>> &miners) const
{
	while (true) {
		const auto dif = difficulty();
		list<shared_ptr<const Block>> mined;
		for (const auto &m : miners) {
			const auto block = m->mine(blocks, dif);
			if (BlockDifficulty(block).value() >= dif) {
				mined.push_back(block);
				// @todo #16 Show timestamp for each entry.
				cout << block->identity() << endl;
			}
		}
		if (!mined.empty()) {
			return make_shared<ChainFull>(mined);
		}
	}
	return {};
}

int ChainFull::amount(const std::shared_ptr<const Miner> &miner) const
{
	return blocks.front()->amount(miner->name());
}
