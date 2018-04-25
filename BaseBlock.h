// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Block.h"

// @todo #10 This is not a BaseBlock. This is NullBlock.
class BaseBlock final : public Block {
public:
	size_t number() const override;
	std::string hash() const override;
	std::string identity() const override;
};