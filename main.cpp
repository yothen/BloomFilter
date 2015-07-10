//
//  main.cpp
//  BloomFilter
//
//  Created by 郑元庆 on 15/7/9.
//  Copyright (c) 2015 郑元庆. All rights reserved.
//

#include <iostream>
#include "BloomFilter.h"

int main(int argc, const char * argv[])
{
	BloomFilter fit(10, 8);

	fit.add("aaaaaaaaaaaaaaaaaa");
	fit.add("grhuifdhgfhduighruid");
	fit.add("re98y5uygr7wtyn985igh");
	fit.add("FHUIEWTN4Y8NRHUGFHKD");
	fit.add("^&TT*GJGTY%*&*%^FJVHJ");
	fit.add("5479692065892067586754092");
	fit.add("1");

	printf("%d, %d, %d, %d, %d, %d, %d\n",
	fit.find("aaaaaaaaaaaaaaaaaa"),
	fit.find("grhuifdhgfhduighruid"),
	fit.find("re98y5uygr7wtyn985igh"),
	fit.find("FHUIEWTN4Y8NRHUGFHKD"),
	fit.find("^&TT*GJGTY%*&*%^FJVHJ"),
	fit.find("5479692065892067586754092"),
	fit.find("1"));


	char str[10];
	while(std::cin >> str)
	{
		std::string s(str);
		if (s == "1")
		{
			return 0;
		}
	}

    return 0;
}