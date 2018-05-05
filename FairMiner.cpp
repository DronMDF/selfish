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
	const auto heads = chain->heads();
	auto parent = heads.begin();

	random_device rd;
	mt19937 g(rd());
	normal_distribution<> distribution(0, heads.size() - 1);
	// @todo #23 Two heads cause segmentation fault, Test needed
	advance(parent, distribution(g));

	const auto block = make_shared<NextBlock>(*parent, name, g());
	// @todo #14 Add difficulty
	if (block->hash().find("0") == 0) {
		return block;
	}
	return {};
}
