// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "BlockCache.h"

using namespace std;

BlockCache::BlockCache(const shared_ptr<const Block> &parent)
	: parent(parent),
	  number_cache(make_shared<CachedValue<size_t>>()),
	  hash_cache(make_shared<CachedValue<string>>()),
	  identity_cache(make_shared<CachedValue<string>>())
{
}

size_t BlockCache::number() const
{
	return number_cache->value(bind(&Block::number, parent));
}

string BlockCache::hash() const
{
	return hash_cache->value(bind(&Block::hash, parent));
}

string BlockCache::identity() const
{
	return identity_cache->value(bind(&Block::identity, parent));
}

chrono::high_resolution_clock::time_point BlockCache::getNthParentTime(size_t n) const
{
	return parent->getNthParentTime(n);
}

int BlockCache::difficulty() const
{
	return parent->difficulty();
}

// @todo #43 cache dificulty series
int BlockCache::difficultySeries() const
{
	return parent->difficultySeries();
}

int BlockCache::amount(const string &user) const
{
	return parent->amount(user);
}

