// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "MinerConcerned.h"
#include <algorithm>
#include "Block.h"

using namespace std;

MinerConcerned::MinerConcerned(const shared_ptr<const Miner> &miner)
	: miner(miner)
{
}

string MinerConcerned::name() const
{
	return miner->name();
}

shared_ptr<Block> MinerConcerned::mine(const list<shared_ptr<const Block>> &heads, int difficulty) const
{
	list<shared_ptr<const Block>> my_heads;
	copy_if(
		heads.begin(),
		heads.end(),
		back_inserter(my_heads),
		[this](const auto &b){
			// @todo #51 Block do not provide method for check author
			return b->identity().find(this->name()) != string::npos;
		}
	);
	return miner->mine(my_heads.empty() ? heads : my_heads, difficulty);
}

