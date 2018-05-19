// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <iostream>
#include <list>
#include <memory>
#include <random>
#include "Block.h"
#include "ChainEmpty.h"
#include "ChainFull.h"
#include "MinerFair.h"

using namespace std;

int main(int, char **)
{
	auto random = make_shared<default_random_engine>(random_device{}());
	// @todo #22 Add MinerConcerned whoes prefers self block
	//  is all block from othre - behaves like a fair
	// @todo #22 Add MinerSelfish whoes mine inside
	//  until someone else finds the next block.
	const list<shared_ptr<const Miner>> miners = {
		make_shared<MinerFair>("Alice", random),
		make_shared<MinerFair>("Bob", random),
		make_shared<MinerFair>("Pavel", random)
	};
	shared_ptr<const Chain> chain = make_shared<ChainEmpty>();
	while (true) {
		chain = chain->mine(miners);
		for (const auto &miner : miners) {
			cout << miner->name() << ": " << chain->amount(miner) << ", ";
		}
		cout << endl;
	}
	return 0;
}
