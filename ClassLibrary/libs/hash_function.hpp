#pragma once

#include <string>
#include "MurmurHash3.h"

namespace SpellCheck { 
    template <class T>
    class IHashFunction;
    
    class MMH3; 
}

template <class T>
class SpellCheck::IHashFunction
{
public:
    IHashFunction() = default;
    virtual ~IHashFunction() = default;
    virtual uint32_t Hash(const T& value) const = 0;
};

class SpellCheck::MMH3 : public IHashFunction<std::wstring>
{
private:
    uint32_t seed;

public:
    MMH3(uint32_t seed_);
    ~MMH3() = default;
    uint32_t Hash(const std::wstring& value) const override;
};