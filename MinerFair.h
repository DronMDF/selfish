// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Miner.h"
#include <random>
#include <vector>

class MinerFair final : public Miner {
public:
	MinerFair(
		const std::string &name,
		const std::shared_ptr<std::default_random_engine> &random
	);
	std::string name() const override;
	std::shared_ptr<const Block> mine(
		const std::list<std::shared_ptr<const Block>> &heads,
		const std::list<std::shared_ptr<const Block>> &current,
		int difficulty
	) const override;
private:
	const std::string user;
	const std::shared_ptr<std::default_random_engine> random;
	const std::shared_ptr<int> level;
};
