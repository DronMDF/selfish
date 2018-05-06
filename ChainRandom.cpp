// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ChainRandom.h"
#include <random>

using namespace std;

ChainRandom::ChainRandom(const shared_ptr<const Chain> &chain, const function<int()> &generator)
	: chain(chain), generator(generator)
{
}

ChainRandom::ChainRandom(const shared_ptr<const Chain> &chain)
	: ChainRandom(chain, mt19937(random_device()()))
{
}

list<shared_ptr<const Block>> ChainRandom::heads() const
{
	const auto heads = chain->heads();
	auto parent = heads.begin();
	advance(parent, generator() % heads.size());
	return {*parent};
}
