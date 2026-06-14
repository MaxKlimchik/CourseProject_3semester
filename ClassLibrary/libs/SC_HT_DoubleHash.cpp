#include "SC_HT_DoubleHash.hpp"

SpellCheck::SC_HT_DHash::SC_HT_DHash(UINT size_)
    : ISpellCheck(), storage_size(size_)
{
    storage.resize(storage_size, nullptr);
    h1 = new MMH3(0);
    h2 = new MMH3(42);
}

bool SpellCheck::SC_HT_DHash::Check(const std::wstring &value) const
{
    UINT hash1 = h1->Hash(value) % storage_size;
    UINT hash2 = h2->Hash(value);
    UINT step = 1 + hash2 % (storage_size - 1);

    for (UINT i = 0; i < storage_size; ++i)
    {
        UINT index = (hash1 + i * step) % storage_size;
        if (storage[index] == nullptr)
            return false;

        else if (*(storage[index]) == value)
            return true;
    }
    return false;
}

void SpellCheck::SC_HT_DHash::Register(const std::wstring *value)
{
    UINT hash1 = h1->Hash(*value) % storage_size;
    UINT hash2 = h2->Hash(*value);
    UINT step = 1 + hash2 % (storage_size - 1);

    for (UINT i = 0; i < storage_size; ++i)
    {
        UINT index = (hash1 + i * step) % storage_size;
        if (storage[index] != nullptr && *(storage[index]) == *value)
            return;
        
        if (storage[index] == nullptr)
        {
            storage[index] = value;
            return;
        }
    }
}

SpellCheck::SC_HT_DHash::~SC_HT_DHash()
{
    delete h1;
    delete h2;
}
