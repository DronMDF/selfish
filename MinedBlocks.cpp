// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "MinedBlocks.h"
#include "Miner.h"

using namespace std;

MinedBlocks::MinedBlocks(
	const list<shared_ptr<const Miner>> &miners,
	const shared_ptr<const Chain> &chain
) : miners(miners), chain(chain)
{
}

list<shared_ptr<const Block>> MinedBlocks::asList() const
{
	list<shared_ptr<const Block>> result;
	for (const auto &m : miners) {
		const auto block = m->mine(chain);
		if (block) {
			result.push_back(block);
		}
	}

	return result;
}
