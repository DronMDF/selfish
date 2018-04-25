// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "NextBlock.h"
#include <sstream>
#include <iomanip>

using namespace std;

NextBlock::NextBlock(
	const shared_ptr<const Block> &parent,
	const string &miner,
	const int nonce
) : parent(parent), miner(miner), nonce(nonce)
{
}

size_t NextBlock::number() const
{
	return parent->number() + 1;
}

string NextBlock::hash() const
{
	// @todo #10 Implement hash alg here
	ostringstream out;
	out << hex << setfill('0') << setw(8) << nonce;
	return out.str();
}

string NextBlock::identity() const
{
	return to_string(number()) + ":" + hash() + "@" + parent->hash() + " by " + miner;
}
