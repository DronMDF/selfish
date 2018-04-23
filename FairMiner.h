// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Miner.h"

class FairMiner final : public Miner {
public:
	std::shared_ptr<Block> mine(const std::shared_ptr<const Chain> &chain) const override;
};