// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <string>

class Block {
public:
	~Block() = default;

	virtual size_t number() const = 0;
	virtual std::string hash() const = 0;
	virtual std::string identity() const = 0;
	// @todo #28 Block should have getNthParentTime method
	//  This method goes back to history, give nth parent and return his time.
	//  This method should work recursyvely. With BlockNull case.
};
