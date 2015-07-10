//
// Created by 郑元庆 on 15/7/9.
// Copyright (c) 2015 郑元庆. All rights reserved.
//


#ifndef __BitList_H_
#define __BitList_H_

#include <iostream>
#include <vector>

/**
 *  位链表
 */
class BitList
{
public:
    /**
     *  bit size
     */
	BitList(const unsigned long long size);
	~BitList();

public:
    /**
     *  重置元素
     *
     *  @param val 0(false) or 1(true)
     */
	void reset(const bool val);
    /**
     *  bit大小
     *
     *  @return bits
     */
	long long size();
    /**
     *  []重载
     *
     *  @param index 位下标
     *
     *  @return 0(false) or 1(true)
     */
	bool operator[](const unsigned long long index);
    /**
     *  设置元素
     *
     *  @param size 位下标
     *  @param val  0(false) or 1(true)
     */
	void set_value(const unsigned long long index, const bool val);
    /**
     *  清空内存
     */
	void clear();

private:
	std::vector<unsigned char*> _data;
	unsigned long long _size;//bit大小
	size_t _block_size;//链表块大小
};


#endif //__BitList_H_
