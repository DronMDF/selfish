// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BaseBlock.h"

using namespace std;

size_t BaseBlock::number() const
{
	return 0;
}

string BaseBlock::hash() const
{
	return string(32, '0');
}

string BaseBlock::identity() const
{
	return "0:" + hash();
}
