#include "hash_function.hpp"

SpellCheck::MMH3::MMH3(uint32_t seed_)
    : IHashFunction(), seed(seed_) {}


uint32_t SpellCheck::MMH3::Hash(const std::wstring &value) const
{
    uint32_t result;
    MurmurHash3_x86_32(value.c_str(), value.size() * sizeof(wchar_t), seed, &result);

    return result;
}