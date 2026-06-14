#include "SC_Bloom_filter.hpp"

SpellCheck::SC_Bloom_filter::SC_Bloom_filter(UINT data_count, float p_false_positive)
    : ISpellCheck()
{
    storage_size = -((data_count * log(p_false_positive)) / pow(log(2), 2));
    h_count = ceil((storage_size / data_count) * log(2));
    storage.resize(storage_size, false);
    h1 = new MMH3(0);
    h2 = new MMH3(42);
}

bool SpellCheck::SC_Bloom_filter::Check(const std::wstring &word) const
{
    UINT hash1 = h1->Hash(word) % storage_size;
    UINT hash2 = h2->Hash(word) % storage_size;
    for (UINT i = 0; i < h_count; ++i)
    {
        UINT index = (hash1 + i * hash2) % storage_size;
        if (!storage[index])
            return false;
    }
    return true;
}

void SpellCheck::SC_Bloom_filter::Register(const std::wstring *word)
{
    UINT hash1 = h1->Hash(*word) % storage_size;
    UINT hash2 = h2->Hash(*word) % storage_size;
    for (UINT i = 0; i < h_count; ++i)
    {
        UINT index = (hash1 + i * hash2) % storage_size;
        storage[index] = true;
    }
}

SpellCheck::SC_Bloom_filter::~SC_Bloom_filter()
{
    delete h1;
    delete h2;
}
