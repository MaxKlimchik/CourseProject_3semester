#pragma once

#include <vector>
#include "ISpellCheck.hpp"
#include "hash_function.hpp"

namespace SpellCheck { class SC_HT_DHash; }

using HashFunc = SpellCheck::IHashFunction<std::wstring>;

class SpellCheck::SC_HT_DHash : public SpellCheck::ISpellCheck
{
private:
    std::vector<const std::wstring*> storage;
    HashFunc *h1;
    HashFunc *h2;
    UINT storage_size;

public:
    SC_HT_DHash(UINT size_);

    bool Check(const std::wstring &value) const override;
    void Register(const std::wstring *value) override;

    ~SC_HT_DHash();
};