// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Block.h"
#include <memory>

class NextBlock final : public Block {
public:
	NextBlock(const std::shared_ptr<const Block> &parent, const std::string &miner, int nonce);
	size_t number() const override;
	std::string hash() const override;
	std::string identity() const override;
private:
	const std::shared_ptr<const Block> parent;
	const std::string miner;
	const int nonce;
};
