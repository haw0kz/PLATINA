#pragma once
#include <iostream>
#include <string>



template <typename T>
bool correct(T var, T left, T right)
{
	return var >= left && var <= right;
}

template <typename T>
T verification(T left, T right, std::string message)
{
	T x;
	while ((std::cin >> x).fail() || !correct(x, left, right))
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << message;
	}
	return x;
}