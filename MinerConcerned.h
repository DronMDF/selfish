// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Miner.h"

class MinerConcerned final : public Miner {
public:
	explicit MinerConcerned(const std::shared_ptr<const Miner> &miner);
	std::string name() const override;
	std::shared_ptr<Block> mine(
		const std::list<std::shared_ptr<const Block>> &heads,
		int difficulty
	) const override;
private:
	const std::shared_ptr<const Miner> miner;
};
