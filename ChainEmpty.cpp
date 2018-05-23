// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ChainEmpty.h"
#include <iostream>
#include "BlockNull.h"
#include "ChainFull.h"
#include "Miner.h"

using namespace std;

int ChainEmpty::difficulty() const
{
	return 0;
}

shared_ptr<const Chain> ChainEmpty::mine(const list<shared_ptr<const Miner>> &miners) const
{
	const list<shared_ptr<const Block>> blocks = {make_shared<BlockNull>()};
	list<shared_ptr<const Block>> mined;
	for (const auto &m : miners) {
		const auto block = m->mine(blocks, 0);
		if (block) {
			mined.push_back(block);
			cout << block->identity() << endl;
		}
	}
	if (!mined.empty()) {
		for (const auto &m : miners) {
			const auto block = m->postmine(blocks, 0);
			if (block) {
				mined.push_back(block);
				cout << block->identity() << endl;
			}
		}
	}
	return make_shared<ChainFull>(mined);
}

int ChainEmpty::amount(const std::shared_ptr<const Miner> &) const
{
	return 0;
}
