// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <iostream>
#include <list>
#include <memory>
#include "Block.h"
#include "ChainEmpty.h"
#include "ChainFull.h"
// @todo #9 rename FairMiner to MinerFair
#include "FairMiner.h"
#include "MinedBlocks.h"

using namespace std;

int main(int, char **)
{
	const list<shared_ptr<const Miner>> miners = {
		make_shared<FairMiner>("Alice"),
		make_shared<FairMiner>("Bob"),
		make_shared<FairMiner>("Pavel")
	};
	shared_ptr<const Chain> chain = make_shared<ChainEmpty>();
	while (true) {
		const auto mined = MinedBlocks(miners, chain).asList();
		if (!mined.empty()) {
			for (const auto &m : mined) {
				// @todo #16 Show timestamp for each entry.
				cout << m->identity() << endl;
			}
			chain = make_shared<ChainFull>(chain, mined);
			cout << "Amount: ";
			for (const auto &miner : miners) {
				cout << miner->name() << ": " << miner->amount(chain) << ", ";
			}
			cout << endl;
		}
	}
	return 0;
}
