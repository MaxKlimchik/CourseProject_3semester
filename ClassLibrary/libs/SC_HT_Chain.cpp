#include "SC_HT_Chain.hpp"

SpellCheck::SC_HT_Chain::Field::Field() :
    value(nullptr), is_free(true), next(nullptr) {}

SpellCheck::SC_HT_Chain::Field::Field(const std::wstring *value_) :
    value(value_), is_free(false), next(nullptr) {}

SpellCheck::SC_HT_Chain::SC_HT_Chain(UINT size_)
    : ISpellCheck(), storage_size(size_)
{
    storage.resize(storage_size, Field());
    h_func = new MMH3(0);
}

bool SpellCheck::SC_HT_Chain::Check(const std::wstring &value) const
{
    UINT hash = h_func->Hash(value) % storage_size;
    
    if (!storage[hash].is_free && *(storage[hash].value) == value) return true;
    
    else if (storage[hash].next != nullptr)
    {
        Field *tmp = storage[hash].next;
        while (tmp != nullptr)
        {
            if (*(tmp->value) == value) return true;
            else tmp = tmp->next;
        }
    }
    
    return false;
}

void SpellCheck::SC_HT_Chain::Register(const std::wstring *value)
{
    UINT hash = h_func->Hash(*value) % storage_size;

    if (!storage[hash].is_free && *(storage[hash].value) == *value) return;
    else if (storage[hash].is_free)
    {
        storage[hash].value = value;
        storage[hash].is_free = false;
    }
    else if (storage[hash].next == nullptr && *(storage[hash].value) != *value)
        storage[hash].next = new Field(value);
    
    else
    {
        Field *tmp = storage[hash].next;
        if (!tmp->is_free && *(tmp->value) == *(value))
            return;
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
            if (!tmp->is_free && *(tmp->value) == *value) return;
        }
        
        tmp->next = new Field(value);
    }
}

SpellCheck::SC_HT_Chain::~SC_HT_Chain()
{
    for (UINT cell_index = 0; cell_index < storage_size; ++cell_index)
    {
        Field* current = storage[cell_index].next;
        while (current != nullptr)
        {
            Field* to_delete = current;
            current = current->next;
            delete to_delete;
        }
    }

    delete h_func;
}