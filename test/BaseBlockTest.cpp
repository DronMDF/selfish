// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BaseBlockTest.h"
#include <2out/Representation.h>
#include <2out/Result.h>
#include <2out/TestStartsWith.h>
#include "../BaseBlock.h"

using namespace std;
using namespace oout;

class BlockHashRepr final : public Representation {
public:
	explicit BlockHashRepr(const shared_ptr<const Block> &block)
		: block(block)
	{
	}

	string asString() const override
	{
		return block->hash();
	}
private:
	const shared_ptr<const Block> block;
};

BaseBlockTest::BaseBlockTest()
	: tests(
		make_unique<TestStartsWith>(
			make_unique<BlockHashRepr>(
				make_unique<BaseBlock>()
			),
			"00000000"
		)
	)
{
}

unique_ptr<const Result> BaseBlockTest::result() const
{
	return tests->result();
}
