#pragma once 

#include <iostream>
#include <utility>
#include "merge.h"

std::size_t std::hash<Key>::operator()(const Key& k) const
{
    using std::size_t;
    using std::hash;

    // Compute individual hash values for the pair
    // and combine them using XOR and bit shifting:

    return ((hash<double>()(k.slopeInterceptPair.first)
        ^ (hash<double>()(k.slopeInterceptPair.second) << 1)) >> 1);
}

std::pair<double, double> slopeInterceptPair;

bool Key::operator==(const Key& other) const
{
    return (slopeInterceptPair.first == other.slopeInterceptPair.first
        && slopeInterceptPair.second == other.slopeInterceptPair.second);
}
