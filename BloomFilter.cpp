//
// Created by 郑元庆 on 15/7/10.
// Copyright (c) 2015 郑元庆. All rights reserved.
//

#include "BloomFilter.h"


BloomFilter::BloomFilter(unsigned long long size, size_t hashcount)
:_data(size*hashcount), _hash_count(hashcount)
{

}

BloomFilter::~BloomFilter()
{

}

void BloomFilter::add(const char *str)
{
    unsigned long long num;
    
    switch(_hash_count)
    {
        case 8:
            num = hash(str) % _data.size();
            _data.set_value(num, true);
        case 7:
            num = SDBMHash(str) % _data.size();
            _data.set_value(num, true);
        case 6:
            num = RSHash(str) % _data.size();
            _data.set_value(num, true);
        case 5:
            num = JSHash(str) % _data.size();
            _data.set_value(num, true);
        case 4:
            num = PJWHash(str) % _data.size();
            _data.set_value(num, true);
        case 3:
            num = BKDRHash(str) % _data.size();
            _data.set_value(num, true);
        case 2:
            num = DJBHash(str) % _data.size();
            _data.set_value(num, true);
        case 1:
            num = APHash(str) % _data.size();
            _data.set_value(num, true);
    }
}

bool BloomFilter::find(const char *str)
{
    unsigned long long num;
    
    switch(_hash_count)
    {
        case 8:
            num = hash(str) % _data.size();
            if(!_data[num])
                return false;
        case 7:
            num = SDBMHash(str) % _data.size();
            if(!_data[num])
                return false;
        case 6:
            num = RSHash(str) % _data.size();
            if(!_data[num])
                return false;
        case 5:
            num = JSHash(str) % _data.size();
            if(!_data[num])
                return false;
        case 4:
            num = PJWHash(str) % _data.size();
            if(!_data[num])
                return false;
        case 3:
            num = BKDRHash(str) % _data.size();
            if(!_data[num])
                return false;
        case 2:
            num = DJBHash(str) % _data.size();
            if(!_data[num])
                return false;
        case 1:
            num = APHash(str) % _data.size();
            if(!_data[num])
                return false;
    }
    
    
	return true;
}

unsigned long long BloomFilter::SDBMHash(const char *str)
{
    unsigned long long hash = 0;
    
    while (*str)
    {
        hash = (*str++) + (hash << 6) + (hash << 16) - hash;
    }
    
    return (hash & 0x7FFFFFFF);
}

unsigned long long BloomFilter::RSHash(const char *str)
{
    unsigned long long b = 378551;
    unsigned long long a = 63689;
    unsigned long long hash = 0;
    
    while (*str)
    {
        hash = hash * a + (*str++);
        a *= b;
    }
    
    return (hash & 0x7FFFFFFF);
}

unsigned long long BloomFilter::JSHash(const char *str)
{
    unsigned long long hash = 1315423911;
    
    while (*str)
    {
        hash ^= ((hash << 5) + (*str++) + (hash >> 2));
    }
    
    return (hash & 0x7FFFFFFF);
}

unsigned long long BloomFilter::PJWHash(const char *str)
{
    unsigned long long b = (unsigned long long)(sizeof(unsigned long long) * 8);
    unsigned long long t = (unsigned long long)((b  * 3) / 4);
    unsigned long long o = (unsigned long long)(b / 8);
    unsigned long long h = (unsigned long long)(0xFFFFFFFF) << (b - o);
    unsigned long long hash = 0;
    unsigned long long test = 0;
    
    while (*str)
    {
        hash = (hash << o) + (*str++);
        if ((test = hash & h) != 0)
        {
            hash = ((hash ^ (test >> t)) & (~h));
        }
    }
    
    return (hash & 0x7FFFFFFF);
}

unsigned long long BloomFilter::BKDRHash(const char *str)
{
    unsigned long long seed = 13131313131;
    unsigned long long hash = 0;
    
    while (*str)
    {
        hash = hash * seed + (*str++);
    }
    
    return (hash & 0x7FFFFFFF);
}

unsigned long long BloomFilter::DJBHash(const char *str)
{
    unsigned long long hash = 5381;
    
    while (*str)
    {
        hash += (hash << 5) + (*str++);
    }
    
    return (hash & 0x7FFFFFFF);
}

unsigned long long BloomFilter::APHash(const char *str)
{
    unsigned long long hash = 0;
    int i;
    
    for (i=0; *str; i++)
    {
        if ((i & 1) == 0)
        {
            hash ^= ((hash << 7) ^ (*str++) ^ (hash >> 3));
        }
        else
        {
            hash ^= (~((hash << 11) ^ (*str++) ^ (hash >> 5)));
        }
    }
    
    return (hash & 0x7FFFFFFF);
}

unsigned long long BloomFilter::hash(const char *str)
{
    unsigned long long h = 0;
    
    while (*str)
    {
        h = 31* h + (*str++);
    }
    
    return h % 29989;
}













