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
#include "MinerConcerned.h"
#include "MinerFair.h"
#include "MinerSelfish.h"
#include "MinerTimedSelfish.h"

using namespace std;

int main(int, char **)
{
	auto random = make_shared<default_random_engine>(random_device{}());
	const list<shared_ptr<const Miner>> miners = {
		make_shared<MinerFair>("Alice", random),
		make_shared<MinerFair>("Bob", random),
		make_shared<MinerSelfish>(
			make_shared<MinerConcerned>(
				make_shared<MinerFair>("Pavel", random)
			)
		)
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
