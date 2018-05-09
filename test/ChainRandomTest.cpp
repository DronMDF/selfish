// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ChainRandomTest.h"
#include <2out/Representation.h>
#include <2out/Result.h>
#include <2out/TestEqual.h>
#include "../Block.h"
#include "../ChainEmpty.h"
#include "../ChainFull.h"
#include "../ChainRandom.h"

using namespace std;
using namespace oout;

class BlockTest final : public Block {
public:
	explicit BlockTest(const string &id)
		: id(id)
	{
	}

	size_t number() const override
	{
		return 1;
	}

	string hash() const override
	{
		return "hash";
	}

	string identity() const override
	{
		return id;
	}

	chrono::high_resolution_clock::time_point getNthParentTime(size_t n) const override
	{
		return chrono::high_resolution_clock::now();
	}

	int difficulty() const override
	{
		return 0;
	}

	int amount(const string &) const override
	{
		return 0;
	}

private:
	const string id;
};

class ReprChainHead final : public Representation {
public:
	explicit ReprChainHead(const shared_ptr<const Chain> &chain)
		: chain(chain)
	{
	}

	string asString() const override
	{
		return chain->heads().front()->identity();
	}
private:
	const shared_ptr<const Chain> chain;
};

ChainRandomTest::ChainRandomTest()
	: tests(
		make_unique<TestEqual>(
			make_unique<ReprChainHead>(
				make_unique<ChainRandom>(
					make_shared<ChainFull>(
						make_shared<ChainEmpty>(),
						list<shared_ptr<const Block>>{
							make_shared<BlockTest>("first"),
							make_shared<BlockTest>("second")
						}
					),
					[](){ return 0; }
				)
			),
			"first"
		)
	)
{
}

unique_ptr<const Result> ChainRandomTest::result() const
{
	return tests->result();
}

