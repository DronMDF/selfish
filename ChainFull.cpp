// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ChainFull.h"
#include "Block.h"

using namespace std;

ChainFull::ChainFull(
	const shared_ptr<const Chain> &chain,
	const list<shared_ptr<const Block>> &blocks
) : chain(chain), blocks(blocks)
{
}

list<shared_ptr<const Block>> ChainFull::heads() const
{
	return blocks;
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
