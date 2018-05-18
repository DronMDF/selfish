// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Chain.h"
#include <list>

class ChainFull final : public Chain {
public:
	explicit ChainFull(const std::list<std::shared_ptr<const Block>> &blocks);

	int difficulty() const override;
	std::shared_ptr<const Chain> mine(
		const std::list<std::shared_ptr<const Miner>> &miners
	) const override;
	int amount(const std::shared_ptr<const Miner> &miner) const override;
private:
	const std::list<std::shared_ptr<const Block>> blocks;
};
