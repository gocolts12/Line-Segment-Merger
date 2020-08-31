#pragma once
#include <iostream>
#include <utility>

#ifndef hash_H
#define hash_H

struct Key
{
    std::pair<double, double> slopeInterceptPair;

    bool operator==(const Key& other) const;
};

template <>
struct std::hash<Key>
{
    std::size_t operator()(const Key& k) const;
};

#endif