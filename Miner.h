// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>

class Block;
class Chain;

class Miner {
public:
	virtual ~Miner() = default;
	virtual std::string name() const = 0;
	virtual std::shared_ptr<Block> mine(const std::shared_ptr<const Chain> &chain) const = 0;
	virtual int amount(const std::shared_ptr<const Chain> &chain) const = 0;
};
