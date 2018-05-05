// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ChainEmpty.h"
#include "BlockNull.h"

using namespace std;

list<shared_ptr<const Block>> ChainEmpty::heads() const
{
	return {make_shared<BlockNull>()};
}
