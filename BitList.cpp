//
// Created by 郑元庆 on 15/7/9.
// Copyright (c) 2015 郑元庆. All rights reserved.
//

#include "BitList.h"

const unsigned char bits[8] =
{
		0x01,
		0x02,
		0x04,
		0x08,
		0x10,
		0x20,
		0x40,
		0x80
};

BitList::BitList(const unsigned long long size)
:_size(size), _block_size(64)
{
	unsigned long long tmp = (unsigned long long)(_size/8/_block_size);

	while (tmp > 0)
	{
		unsigned char* data = (unsigned char*)malloc(_block_size);
		memset(data, 0, _block_size);
		_data.push_back(data);

		--tmp;
	}

	unsigned char* data = nullptr;
	data = (unsigned char*)malloc(_size % (_block_size*8));
	memset(data, 0, _size % (_block_size*8));
	if(data)
		_data.push_back(data);
}

BitList::~BitList()
{
	for (int i = 0; i < _data.size() / 8; ++i)
	{
		free(_data[i]);
	}
}

long long BitList::size()
{
	return _size;
}

void BitList::reset(const bool val)
{
	for (int i = 0; i < _data.size(); ++i)
	{
		if (val)
		{
			memset(_data[i], 0xFF, _block_size);
		}
		else
		{
			memset(_data[i], 0x00, _block_size);
		}
	}
}

void BitList::clear()
{
	for (int i = 0; i < _data.size(); ++i)
	{
		free(_data[i]);
	}
	_data.clear();
}

bool BitList::operator[](const unsigned long long index)
{
	return _data[index / (_block_size*8)][(index - ((index / (_block_size*8))*64)) / 8] & bits[index % 8];
}

void BitList::set_value(const unsigned long long index, const bool val)
{
	if(val)
		_data[index / (_block_size*8)][(index - ((index / (_block_size*8))*64)) / 8] |= bits[index % 8];
	else
		_data[index / (_block_size*8)][(index - ((index / (_block_size*8))*64)) / 8] &= (~(bits[index % 8]));
}