// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "FairMiner.h"
#include <algorithm>
#include <random>
#include "Chain.h"
#include "NextBlock.h"

using namespace std;

FairMiner::FairMiner(const string &name)
	: name(name)
{
}

shared_ptr<Block> FairMiner::mine(const shared_ptr<const Chain> &chain) const
{
	auto heads = chain->heads();

	random_device rd;
	mt19937 g(rd());
	shuffle(heads.begin(), heads.end(), g);

	const auto parent = heads.front();
	const auto block = make_shared<NextBlock>(parent, name, g());
	// @todo #14 Add difficulty
	if (block->hash().find("0") == 0) {
		return block;
	}
	return {};
}
