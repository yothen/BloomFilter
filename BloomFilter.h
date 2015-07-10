//
// Created by 郑元庆 on 15/7/10.
// Copyright (c) 2015 郑元庆. All rights reserved.
//


#ifndef __BloomFilter_H_
#define __BloomFilter_H_

#include "BitList.h"
/**
 *  布隆过滤器
 */
class BloomFilter
{
public:
    /**
     *  size: 承载多少条记录
     *  count:使用多少次hash计算 1-8
     */
	BloomFilter(unsigned long long size, size_t count);

	~BloomFilter();

public:
    /**
     *  添加一条记录
     *
     *  @param str 记录内容
     */
	void add(const char* str);
    /**
     *  查询记录是否存在
     *
     *  @param str 记录内容
     *
     *  @return true(存在) or false(不存在)
     */
	bool find(const char* str);

protected:
	unsigned long long SDBMHash(const char *str);
	unsigned long long RSHash(const char *str);
	unsigned long long JSHash(const char *str);
	unsigned long long PJWHash(const char *str);
	unsigned long long BKDRHash(const char *str);
	unsigned long long DJBHash(const char *str);
	unsigned long long APHash(const char *str);
	unsigned long long hash(const char *str);

private:
	size_t _hash_count;
	BitList _data;
};


#endif //__BloomFilter_H_
