#pragma once

#include <string>

#ifndef UINT
#define UINT unsigned int
#endif

namespace SpellCheck {class ISpellCheck; }

class SpellCheck::ISpellCheck
{
public:
    ISpellCheck() = default;
    virtual bool Check(const std::wstring &word) const = 0;
    virtual void Register(const std::wstring *word) = 0;
    virtual ~ISpellCheck() = default;
};