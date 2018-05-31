// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "MinerFair.h"
#include <random>
#include "BlockDifficulty.h"
#include "BlockNext.h"
#include "Chain.h"

using namespace std;

// @todo #60 Need to wrap default_random_engine for testing
MinerFair::MinerFair(const string &name, const shared_ptr<default_random_engine> &random)
	: user(name), random(random), level(make_shared<int>(0))
{
}

string MinerFair::name() const
{
	return user;
}

shared_ptr<const Block> MinerFair::mine(
	const list<shared_ptr<const Block>> &heads,
	const list<shared_ptr<const Block>> &current,
	int difficulty
) const
{
	auto head = heads.begin();
	advance(head, (*random)() % heads.size());
	if (*level <= (*head)->number()) {
		const auto block = make_shared<BlockNext>(*head, user, (*random)(), difficulty);
		if (BlockDifficulty(block).value() >= difficulty) {
			*level = block->number();
			return block;
		}
	}

	return {};
}
