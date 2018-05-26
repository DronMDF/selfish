// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlockNext.h"
#include <sstream>
#include <iomanip>
#include "BlockCache.h"

using namespace std;

BlockNext::BlockNext(
	const shared_ptr<const Block> &parent,
	const string &miner,
	const int nonce,
	const int dvalue
) :
	timestamp(chrono::high_resolution_clock::now()),
	parent(make_shared<BlockCache>(parent)),
	miner(miner),
	nonce(nonce),
	dvalue(dvalue)
{
}

size_t BlockNext::number() const
{
	return parent->number() + 1;
}

string BlockNext::hash() const
{
	// @todo #12 Using GOST hash alg here
	const auto hash = std::hash<string>()(parent->hash() + to_string(nonce) + miner);
	ostringstream out;
	out << hex << setfill('0') << setw(16) << hash;
	return out.str();
}

string BlockNext::identity() const
{
	return to_string(number()) + ":" + hash() + "@" + parent->hash() + " by " + miner;
}

chrono::high_resolution_clock::time_point BlockNext::getNthParentTime(size_t n) const
{
	return n > 0 ? parent->getNthParentTime(n - 1) : timestamp;
}

int BlockNext::difficulty() const
{
	return dvalue;
}

int BlockNext::difficultySeries() const
{
	return 1 + (difficulty() == parent->difficulty() ? parent->difficultySeries() : 0);
}

int BlockNext::amount(const string &user, int counts) const
{
	return parent->amount(user, counts + (user == miner ? 1 : 0));
}
