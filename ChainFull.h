// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Chain.h"
#include <list>

class ChainFull final : public Chain {
public:
	ChainFull(
		const std::shared_ptr<const Chain> &chain,
		const std::list<std::shared_ptr<const Block>> &blocks
	);
	std::vector<std::shared_ptr<const Block>> heads() const override;
private:
	const std::shared_ptr<const Chain> chain;
	const std::list<std::shared_ptr<const Block>> blocks;
};
