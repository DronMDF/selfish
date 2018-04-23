// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <list>
#include <memory>

class Block;
class Chain;
class Miner;

class MinedBlocks final {
public:
	MinedBlocks(
		const std::list<std::shared_ptr<const Miner>> &miners,
		const std::shared_ptr<const Chain> &chain
	);

	std::list<std::shared_ptr<const Block>> asList() const;
private:
	const std::list<std::shared_ptr<const Miner>> miners;
	const std::shared_ptr<const Chain> chain;
};
