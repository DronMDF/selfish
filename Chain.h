// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <list>

class Block;
class Miner;

class Chain {
public:
	virtual ~Chain() = default;

	// Current chain difficulty
	virtual int difficulty() const = 0;

	// Produce new chain with next block[s]
	virtual std::shared_ptr<const Chain> mine(
		const std::list<std::shared_ptr<const Miner>> &miners
	) const = 0;

	// User amount
	virtual int amount(const std::shared_ptr<const Miner> &miner) const = 0;
};
