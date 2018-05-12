// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlockDifficulty.h"
#include <map>
#include "Block.h"

using namespace std;

BlockDifficulty::BlockDifficulty(const shared_ptr<const Block> &block)
	: block(block)
{
}

int BlockDifficulty::value() const
{
	const auto hash = block->hash();
	const map<char, int> zeros = {
		{'0', 4},
		{'1', 3},
		{'2', 2}, {'3', 2},
		{'4', 1}, {'5', 1}, {'6', 1}, {'7', 1}
	};
	int difficulty = 0;
	for (const auto &c : hash) {
		if (zeros.count(c) == 0) {
			break;
		}
		difficulty += zeros.at(c);
		if (c != '0') {
			break;
		}
	}
	return difficulty;
}
