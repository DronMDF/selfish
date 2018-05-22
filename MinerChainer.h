// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Miner.h"

// @todo #52 add chance to append block to train.
//  If chain is growth - Selfish miner want to apperd he head to chain.
//  And he do it block by block.

// This is selfish miner whoes try produce longest chain.
class MinerChainer final : public Miner {
public:
	explicit MinerChainer(const std::shared_ptr<const Miner> &miner);
	std::string name() const override;
	std::shared_ptr<Block> mine(
		const std::list<std::shared_ptr<const Block>> &heads,
		int difficulty
	) const override;
private:
	const std::shared_ptr<const Miner> miner;

	struct BlockHolder final {
		std::shared_ptr<const Block> block;
	};
	const std::shared_ptr<BlockHolder> mined;
};
