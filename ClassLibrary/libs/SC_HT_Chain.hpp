#pragma once

#include <vector>
#include "ISpellCheck.hpp"
#include "hash_function.hpp"

namespace SpellCheck { class SC_HT_Chain; }

using HashFunc = SpellCheck::IHashFunction<std::wstring>;

class SpellCheck::SC_HT_Chain : public SpellCheck::ISpellCheck
{
private:
    struct Field
    {
    public:
        const std::wstring *value;
        bool is_free;
        Field *next;

        Field();
        Field(const std::wstring *value_);
        
        ~Field() = default;
    };

    std::vector<Field> storage;
    HashFunc *h_func;
    UINT storage_size;

public:
    SC_HT_Chain(UINT size_);

    bool Check(const std::wstring &value) const override;
    void Register(const std::wstring *value) override;

    ~SC_HT_Chain();
};