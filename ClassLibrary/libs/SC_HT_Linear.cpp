#include "SC_HT_Linear.hpp"

SpellCheck::SC_HT_Linear::SC_HT_Linear(UINT size_)
    : ISpellCheck(), storage_size(size_)
{
    storage.resize(storage_size, nullptr);
    h_func = new MMH3(0);
}

bool SpellCheck::SC_HT_Linear::Check(const std::wstring &value) const
{
    UINT hash = h_func->Hash(value) % storage_size;

    for (UINT i = 0; i < storage_size; ++i)
    {
        UINT index = (hash + i) % storage_size;
        if (storage[index] == nullptr)
            return false;
        
        else if (*(storage[index]) == value)
            return true;
    }
    return false;
}

void SpellCheck::SC_HT_Linear::Register(const std::wstring *value)
{
    UINT hash = h_func->Hash(*value) % storage_size;

    for (UINT i = 0; i < storage_size; ++i)
    {
        UINT index = (hash + i) % storage_size;
        if (storage[index] != nullptr && *(storage[index]) == *value)
            return;
        
        if (storage[index] == nullptr)
        {
            storage[index] = value;
            return;
        }
    }
}

SpellCheck::SC_HT_Linear::~SC_HT_Linear()
{
    delete h_func;
}
