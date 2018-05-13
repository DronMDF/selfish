// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Miner.h"

class MinerFair final : public Miner {
public:
	explicit MinerFair(const std::string &name);
	std::string name() const override;
	std::shared_ptr<Block> mine(const std::shared_ptr<const Chain> &chain) const override;
	int amount(const std::shared_ptr<const Chain> &chain) const override;
private:
	const std::string user;
};