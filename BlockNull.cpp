// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlockNull.h"

using namespace std;

BlockNull::BlockNull()
	: timestamp(chrono::high_resolution_clock::now())
{
}

size_t BlockNull::number() const
{
	return 0;
}

string BlockNull::hash() const
{
	return string(32, '0');
}

string BlockNull::identity() const
{
	return "0:" + hash();
}

chrono::high_resolution_clock::time_point BlockNull::getNthParentTime(size_t n) const
{
	return timestamp;
}

int BlockNull::difficulty() const
{
	return 0;
}

int BlockNull::amount(const string &) const
{
	return 0;
}
