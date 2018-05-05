// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ChainFull.h"

using namespace std;

ChainFull::ChainFull(
	const shared_ptr<const Chain> &chain,
	const list<shared_ptr<const Block>> &blocks
) : chain(chain), blocks(blocks)
{
}

list<shared_ptr<const Block>> ChainFull::heads() const
{
	return blocks;
}
