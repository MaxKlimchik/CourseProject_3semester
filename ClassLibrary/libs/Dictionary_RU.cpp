#include "Dictionary_RU.hpp"

SpellCheck::Dictionary_RU::Dictionary_RU(const std::string &path)
{
    std::wifstream file(path);
    if (file.is_open())
    {
        file.imbue(std::locale(file.getloc(), new std::codecvt_utf8<wchar_t>));

        std::size_t words_count;
        file >> words_count;
        words.reserve(words_count);

        std::wstring word;
        while (file >> word)
            words.push_back(word);
        
        file.close();
    }
}

size_t SpellCheck::Dictionary_RU::WordsCount() const
{
    return words.size();
}

const std::wstring& SpellCheck::Dictionary_RU::operator[](std::size_t index) const
{
    if (index >= 0 && index < words.size())
        return words[index];
    else
        throw std::out_of_range("index out of range");
}
