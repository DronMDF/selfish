// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlockDifficulty.h"
#include <iomanip>
#include <sstream>
#include "Block.h"

using namespace std;

BlockDifficulty::BlockDifficulty(const shared_ptr<const Block> &block)
	: block(block)
{
}

int BlockDifficulty::value() const
{
	uint64_t value;
	istringstream in(block->hash());
	// @todo #16 Avoid 31bit lock
	in >> hex >> setw(8) >> setfill('0') >> value;
	int difficulty = 0;
	if (value > 0) {
		while ((value & (1LLU << 31)) == 0) {
			difficulty++;
			value <<= 1;
		}
	}
	return difficulty;
}
