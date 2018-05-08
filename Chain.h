// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <list>

class Block;

class Chain {
public:
	virtual ~Chain() = default;
	virtual std::list<std::shared_ptr<const Block>> heads() const = 0;
	// Current chain difficulty
	virtual int difficulty() const = 0;
};
