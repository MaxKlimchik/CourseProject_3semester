#pragma once

#include <vector>
#include "ISpellCheck.hpp"
#include "hash_function.hpp"

namespace SpellCheck { class SC_HT_Linear; }

using HashFunc = SpellCheck::IHashFunction<std::wstring>;

class SpellCheck::SC_HT_Linear : public SpellCheck::ISpellCheck
{
private:
    std::vector<const std::wstring*> storage;
    HashFunc *h_func;
    UINT storage_size;

public:
    SC_HT_Linear(UINT size_);

    bool Check(const std::wstring &value) const override;
    void Register(const std::wstring *value) override;

    ~SC_HT_Linear();
};