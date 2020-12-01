#pragma once
#include <iostream>
#include <string>



template <typename T>

void verification(T& x, std::string name)
{
    do {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << name;
        std::cin >> x;
    } while (x < 0 || std::cin.fail());
}