// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "MinerTimedSelfish.h"
#include <algorithm>
#include <functional>
#include <iostream>
#include "Block.h"
#include "BlockDifficulty.h"
#include "BlockNext.h"

using namespace std;

MinerTimedSelfish::MinerTimedSelfish(const shared_ptr<const Miner> &miner)
	: miner(miner), mined(make_shared<BlockHolder>())
{
}

string MinerTimedSelfish::name() const
{
	return miner->name();
}

shared_ptr<const Block> MinerTimedSelfish::mine(
	const list<shared_ptr<const Block>> &heads,
	const list<shared_ptr<const Block>> &current,
	int difficulty
) const
{
	shared_ptr<const Block> block;
	if (mined->blocks.empty()) {
		block = miner->mine(heads, {}, difficulty);
	} else {
		block = miner->mine({mined->blocks.back()}, {}, difficulty);
	}
	if (BlockDifficulty(block).value() >= difficulty) {
		mined->blocks.push(block);
	}

	if (!mined->blocks.empty()) {
		const auto block = mined->blocks.front();
		if (!current.empty()
			&& count_if(
				current.begin(),
				current.end(),
				bind(&Block::verify, placeholders::_1, miner->name())
			) == 0
		) {
			mined->blocks.pop();
			return block;
		}

		const auto delta =
			chrono::high_resolution_clock::now() - block->getNthParentTime(1);
		if (delta > chrono::seconds(1)) {
			mined->blocks.pop();
			return block;
		}
	}
	return {};
}
