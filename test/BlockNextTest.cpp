// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlockNextTest.h"
#include <2out/Representation.h>
#include <2out/Result.h>
#include <2out/TestEqual.h>
#include <2out/TestSuite.h>
#include "../BlockNext.h"

using namespace std;
using namespace oout;

class BlockDifficultyRepr final : public Representation {
public:
	explicit BlockDifficultyRepr(const shared_ptr<const Block> &block)
		: block(block)
	{
	}

	string asString() const override
	{
		return to_string(block->difficulty());
	}
private:
	const shared_ptr<const Block> block;
};

BlockNextTest::BlockNextTest()
	: tests(
		make_unique<TestEqual>(
			make_shared<BlockDifficultyRepr>(
				make_shared<BlockNext>(shared_ptr<Block>{}, "", 0x7fffffff, 7)
			),
			"7"
		)
	)
{
}

unique_ptr<const Result> BlockNextTest::result() const
{
	return tests->result();
}

