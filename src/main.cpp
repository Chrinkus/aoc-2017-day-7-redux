#include <iostream>
#include <tower.h>

int main()
{
    std::cout << "\nAdvent of Code 2017 REDUX\n";

    auto tf = Tower_factory{std::cin};
    auto tower = tf.create_tower();

    std::cout << "\nPart 1: " << *tower.get_base() << '\n';
}
