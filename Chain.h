// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <vector>

class Block;

class Chain {
public:
	virtual ~Chain() = default;

	// @todo #9 heads() should return list of blocks
	virtual std::vector<std::shared_ptr<const Block>> heads() const = 0;
};
