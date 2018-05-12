// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlockDifficultyTest.h"
#include <2out/Representation.h>
#include <2out/Result.h>
#include <2out/TestEqual.h>
#include <2out/TestSuite.h>
#include "../BlockDifficulty.h"
#include "../BlockNext.h"
#include "../BlockNull.h"

using namespace std;
using namespace oout;

class BlockDifficultyRepr final : public Representation {
public:
	explicit BlockDifficultyRepr(const shared_ptr<const BlockDifficulty> &dif)
		: dif(dif)
	{
	}

	string asString() const override
	{
		return to_string(dif->value());
	}
private:
	const shared_ptr<const BlockDifficulty> dif;
};

BlockDifficultyTest::BlockDifficultyTest()
	: tests(
		make_unique<TestSuite>(
			make_shared<TestEqual>(
				make_shared<BlockDifficultyRepr>(
					make_shared<BlockDifficulty>(
						make_shared<BlockNull>()
					)
				),
				"128"
			),
			// @todo #38 This test depend on hash alg,
			//  need to break this dependency
			make_shared<TestEqual>(
				make_shared<BlockDifficultyRepr>(
					make_shared<BlockDifficulty>(
						make_shared<BlockNext>(
							make_shared<BlockNull>(),
							"miner",
							5,
							0
						)
					)
				),
				"5"
			)
		)
	)
{
}

unique_ptr<const Result> BlockDifficultyTest::result() const
{
	return tests->result();
}


