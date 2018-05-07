// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlockNext.h"
#include <sstream>
#include <iomanip>

using namespace std;

BlockNext::BlockNext(
	const shared_ptr<const Block> &parent,
	const string &miner,
	const int nonce
) : parent(parent), miner(miner), nonce(nonce)
{
}

size_t BlockNext::number() const
{
	return parent->number() + 1;
}

string BlockNext::hash() const
{
	// @todo #10 Implement hash alg here
	ostringstream out;
	out << hex << setfill('0') << setw(8) << nonce;
	return out.str();
}

string BlockNext::identity() const
{
	return to_string(number()) + ":" + hash() + "@" + parent->hash() + " by " + miner;
}
