// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Block.h"
#include <functional>
#include <memory>

template<typename T>
class CachedValue final {
public:
	CachedValue()
		: is_initialized(false)
	{
	}

	T value(const std::function<T()> &get)
	{
		if (!is_initialized) {
			cache = get();
			is_initialized = true;
		}
		return cache;
	}

private:
	bool is_initialized;
	T cache;
};

class BlockCache final : public Block {
public:
	explicit BlockCache(const std::shared_ptr<const Block> &parent);
	size_t number() const override;
	std::string hash() const override;
	std::string identity() const override;
	std::chrono::high_resolution_clock::time_point getNthParentTime(size_t n) const override;
	int difficulty() const override;
	int difficultySeries() const override;
	int amount(const std::string &user) const override;
private:
	const std::shared_ptr<const Block> parent;
	const std::shared_ptr<CachedValue<size_t>> number_cache;
	const std::shared_ptr<CachedValue<std::string>> hash_cache;
	const std::shared_ptr<CachedValue<std::string>> identity_cache;
};
