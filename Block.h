// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <chrono>
#include <string>

/// @todo #33 Block interface is huge
class Block {
public:
	~Block() = default;

	virtual size_t number() const = 0;
	virtual std::string hash() const = 0;
	virtual std::string identity() const = 0;
	/// Time of generation nth parent (0 - self time)
	virtual std::chrono::high_resolution_clock::time_point getNthParentTime(size_t n) const = 0;
	/// Block difficulty
	virtual int difficulty() const = 0;
	/// Counts of block with same difficult
	virtual int difficultySeries() const = 0;
	/// Get user amount
	virtual int amount(const std::string &user) const = 0;
};
