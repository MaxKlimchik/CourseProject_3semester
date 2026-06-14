#include "SC_SimpleFactory.hpp"

SpellCheck::ISpellCheck* SpellCheck::SC_Factory::CreateSC(Service_type SC_type, UINT data_count)
{
    float ht_load_factor = 0.75;
    switch (SC_type)
    {
        case Service_type::BloomFilter:
            return new SC_Bloom_filter(data_count, 0.01);
        
        case Service_type::HashTable_Chain:
            return new SC_HT_Chain(NearestPrime::Find(static_cast<UINT>(std::ceil(data_count / ht_load_factor))));

        case Service_type::HashTable_DHash:
            return new SC_HT_DHash(NearestPrime::Find(static_cast<UINT>(std::ceil(data_count / ht_load_factor))));

        case Service_type::HashTable_Linear:
            return new SC_HT_Linear(NearestPrime::Find(static_cast<UINT>(std::ceil(data_count / ht_load_factor))));

        default:
            return nullptr;
    }
}
