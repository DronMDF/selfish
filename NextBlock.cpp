// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "NextBlock.h"
#include <sstream>
#include <iomanip>

using namespace std;

NextBlock::NextBlock(const shared_ptr<const Block> &parent, const void *id, int nonce)
	: parent(parent), id(id), nonce(nonce)
{
}

string NextBlock::hash() const
{
	// @todo #10 Implement hash alg here
	ostringstream out;
	out << hex << setfill('0') << setw(8) << nonce;
	return out.str();
}
