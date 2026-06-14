#pragma once

#include <codecvt>
#include <fstream>
#include <locale>
#include <stdexcept>
#include <string>
#include <vector>

namespace SpellCheck { class Dictionary_RU; }

class SpellCheck::Dictionary_RU
{
private:
    std::vector<std::wstring> words;

public:
    Dictionary_RU(const std::string &path);
    size_t WordsCount() const;
    const std::wstring& operator[](std::size_t index) const;
    ~Dictionary_RU() = default;
};