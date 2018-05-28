// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Miner.h"
#include <queue>

// This is selfish miner wait for other block or time
class MinerTimedSelfish final : public Miner {
public:
	explicit MinerTimedSelfish(const std::shared_ptr<const Miner> &miner);
	std::string name() const override;
	std::shared_ptr<const Block> mine(
		const std::list<std::shared_ptr<const Block>> &heads,
		int difficulty
	) const override;
	std::shared_ptr<const Block> postmine(
		const std::list<std::shared_ptr<const Block>> &heads,
		int difficulty
	) const override;
private:
	const std::shared_ptr<const Miner> miner;

	struct BlockHolder final {
		std::queue<std::shared_ptr<const Block>> blocks;
		bool timed = false;
	};
	const std::shared_ptr<BlockHolder> mined;
};
