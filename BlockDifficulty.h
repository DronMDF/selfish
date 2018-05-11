// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <memory>

class Block;

class BlockDifficulty final {
public:
	explicit BlockDifficulty(const std::shared_ptr<const Block> &block);
	int value() const;
private:
	const std::shared_ptr<const Block> block;
};
