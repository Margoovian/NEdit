#pragma once
#include <iostream>

class NTest {
public:

	inline static void PrintTest(const char* message)
	{
		std::cout << message << '\n';
	}

};