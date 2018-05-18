// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <iostream>
#include <2out/CountError.h>
#include <2out/CountFailure.h>
#include <2out/Result.h>
#include <2out/TestSuite.h>
#include <2out/TextReport.h>
#include "BlockCacheTest.h"
#include "BlockDifficultyTest.h"
#include "BlockNextTest.h"
#include "BlockNullTest.h"

using namespace std;
using namespace oout;

int main(int, char **)
{
	const TestSuite tests(
		make_shared<BlockCacheTest>(),
		make_shared<BlockDifficultyTest>(),
		make_shared<BlockNextTest>(),
		make_shared<BlockNullTest>()
	);
	const shared_ptr<const Result> result = tests.result();

	cout << TextReport(result).asString() << endl;

	return (
		CountFailure(result).count() == 0 &&
		CountError(result).count() == 0
	) ? 0 : -1;
}
