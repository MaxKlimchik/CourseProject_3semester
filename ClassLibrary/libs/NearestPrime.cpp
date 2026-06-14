#include "NearestPrime.hpp"

unsigned int SpellCheck::NearestPrime::Find(unsigned int start)
{
    for (int curr = start; ; ++curr)
    {
        bool is_prime = true;
        for (int divider = 2; divider <= sqrt(curr) && is_prime; ++divider)
        {
            if (curr % divider == 0)
                is_prime = false;
        }
        
        if (is_prime)
            return curr;
    }
}