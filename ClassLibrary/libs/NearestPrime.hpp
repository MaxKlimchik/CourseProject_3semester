#pragma once

#include <cmath>

namespace SpellCheck { class NearestPrime; }

class SpellCheck::NearestPrime
{
public:
    static unsigned int Find(unsigned int start);
};