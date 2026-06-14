#pragma once

#include <cmath>
#include <string>
#include <vector>
#include "ISpellCheck.hpp"
#include "hash_function.hpp"

namespace SpellCheck { class SC_Bloom_filter; }

using HashFunc = SpellCheck::IHashFunction<std::wstring>;

class SpellCheck::SC_Bloom_filter : public SpellCheck::ISpellCheck
{
private:
    std::vector<bool> storage;
    HashFunc *h1;
    HashFunc *h2;
    UINT h_count;
    UINT storage_size;

public:
    SC_Bloom_filter(UINT data_count, float p_false_positive);

    bool Check(const std::wstring &word) const override;
    void Register(const std::wstring *word) override;

    ~SC_Bloom_filter();
};