#pragma once

#include "NearestPrime.hpp"
#include "Dictionary_RU.hpp"
#include "SC_Bloom_filter.hpp"
#include "SC_HT_Chain.hpp"
#include "SC_HT_DoubleHash.hpp"
#include "SC_HT_Linear.hpp"

namespace SpellCheck { enum class Service_type; class SC_Factory; }

enum class SpellCheck::Service_type { HashTable_Chain, HashTable_DHash, HashTable_Linear, BloomFilter };

class SpellCheck::SC_Factory
{
public:
    static SpellCheck::ISpellCheck* CreateSC(Service_type SC_type, UINT data_count);
};