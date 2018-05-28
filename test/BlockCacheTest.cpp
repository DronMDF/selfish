// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlockCacheTest.h"
#include <sstream>
#include <2out/Representation.h>
#include <2out/Result.h>
#include <2out/TestEqual.h>
#include <2out/TestSuite.h>
#include "../BlockCache.h"

using namespace std;
using namespace oout;

namespace {

class BlockCounted final : public Block {
public:
	BlockCounted() = default;

	size_t number() const override
	{
		return 1;
	}

	string hash() const override
	{
		invocations++;
		return __func__;
	}

	string identity() const override
	{
		return {};
	}

	chrono::high_resolution_clock::time_point getNthParentTime(size_t n) const override
	{
		return chrono::high_resolution_clock::now();
	}

	int difficulty() const override
	{
		return 0;
	}

	int difficultySeries() const override
	{
		return 0;
	}

	int amount(const string &, int counts) const override
	{
		return counts;
	}

	int getInvocations() {
		return invocations;
	}

private:
	mutable int invocations = 0;
};

class BlockCacheCallRepr final : public Representation {
public:
	explicit BlockCacheCallRepr(const shared_ptr<BlockCounted> &block)
		: block(block), cache(make_shared<BlockCache>(block))
	{
	}

	string asString() const override
	{
		ostringstream out;
		out << cache->hash() << " " << cache->hash() << " " << block->getInvocations();
		return out.str();
	}
private:
	const shared_ptr<BlockCounted> block;
	const shared_ptr<const Block> cache;
};

}  // anonymous namespace

BlockCacheTest::BlockCacheTest()
	: tests(
		make_unique<TestEqual>(
			make_shared<BlockCacheCallRepr>(
				make_shared<BlockCounted>()
			),
			"hash hash 1"
		)
	)
{
}

unique_ptr<const Result> BlockCacheTest::result() const
{
	return tests->result();
}
