#include <iostream>
#include <vector>

#include "find_diff.h"

int main()
{
    std::cout << "Advent of Code 2017 REDUX\n";

    auto vi = std::vector<int>{ 3, 3, 3, 7, 3 };
    auto it = find_diff(std::begin(vi), std::end(vi));

    if (it != std::end(vi))
        std::cout << "Found diff value: " << *it << '\n';
    else
        std::cout << "Find_diff found nothing!\n";
}
