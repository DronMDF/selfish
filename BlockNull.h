// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Block.h"

class BlockNull final : public Block {
public:
	BlockNull();

	size_t number() const override;
	std::string hash() const override;
	std::string identity() const override;
	std::chrono::high_resolution_clock::time_point getNthParentTime(size_t n) const override;
	int difficulty() const override;
	int amount(const std::string &user) const override;
private:
	const std::chrono::high_resolution_clock::time_point timestamp;
};
