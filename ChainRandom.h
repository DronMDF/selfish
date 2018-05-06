// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Chain.h"
#include <functional>

/// This class select one random head of given chain.
/// if chain has one head - return it. If many - return selected.
class ChainRandom final : public Chain {
public:
	ChainRandom(const std::shared_ptr<const Chain> &chain, const std::function<int()> &generator);
	explicit ChainRandom(const std::shared_ptr<const Chain> &chain);

	std::list<std::shared_ptr<const Block>> heads() const override;
private:
	const std::shared_ptr<const Chain> chain;
	const std::function<int()> generator;
};
