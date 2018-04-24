// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Chain.h"

class EmptyChain final : public Chain {
public:
	std::vector<std::shared_ptr<const Block>> heads() const override;
};
