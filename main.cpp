// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <iostream>
#include <list>
#include <memory>
#include "Block.h"
#include "EmptyChain.h"
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
	shared_ptr<const Chain> chain = make_shared<const EmptyChain>();
	while (true) {
		const auto mined = MinedBlocks(miners, chain).asList();
		if (!mined.empty()) {
			for (const auto &m : mined) {
				cout << m->identity() << endl;
			}
			// @todo #7 Implement chain with blocks
			//  chain = make_shared<FullChain>(chain, mined);
		}
	}
	return 0;
}
