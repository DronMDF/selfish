// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "EmptyChain.h"
#include "BaseBlock.h"

using namespace std;

vector<shared_ptr<const Block>> EmptyChain::heads() const
{
	return { make_shared<BaseBlock>() };
}
