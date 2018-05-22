// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "MinerChainer.h"
#include <algorithm>
#include "Block.h"
#include "BlockDifficulty.h"
#include "BlockNext.h"

using namespace std;

MinerChainer::MinerChainer(const shared_ptr<const Miner> &miner)
	: miner(miner), mined(make_shared<BlockHolder>())
{
}

string MinerChainer::name() const
{
	return miner->name();
}

shared_ptr<Block> MinerChainer::mine(const list<shared_ptr<const Block>> &heads, int difficulty) const
{
	if (mined->block) {
		for (const auto &b : heads) {
			if (b->hash() == mined->block->hash()) {
				// approved
				mined->block.reset();
			}
		}
		if (mined->block && mined->block->number() < heads.front()->number()) {
			mined->block.reset();
		}
	}
	if (mined->block) {
		const auto block = miner->mine({mined->block}, difficulty);
		if (BlockDifficulty(block).value() >= difficulty) {
			// move forward
			mined->block = block;
		}
		if (block->number() > heads.front()->number()) {
			return block;
		}
	} else {
		const auto block = miner->mine(heads, difficulty);
		if (BlockDifficulty(block).value() < difficulty) {
			return block;
		}
		// Block found - remember
		mined->block = block;
	}
	// return fake
	return make_shared<BlockNext>(heads.front(), name(), 0, difficulty);
}
