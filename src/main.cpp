#include <iostream>
#include <tower.h>
#include <find_diff.h>

const Program* find_unbalanced_program(const Program* p_prog)
{
    for (const auto p_child : p_prog->get_children())
        if (!p_child->is_balanced())
            return find_unbalanced_program(p_child);

    return p_prog;
}

class Prog_cmp {
    public:
        Prog_cmp() = default;

        bool operator()(const Program* a, const Program* b)
        {
            return a->total_weight() == b->total_weight();
        }
};

void report_imbalance(const Program* base)
{
    const auto p_unbal = find_unbalanced_program(base);

    auto p_first = p_unbal->get_children().front();

    const auto p_prob = *find_diff(std::begin(p_unbal->get_children()),
                                   std::end(p_unbal->get_children()),
                                   Prog_cmp());

    const auto p_targ = p_prob == p_first ? ++p_first : p_first;

    // Report
    std::cout << p_prob->get_name() << " needs to be "
              << p_prob->get_weight() + p_targ->total_weight() -
                                        p_prob->total_weight();
}

int main()
{
    std::cout << "\nAdvent of Code 2017 REDUX\n";

    auto tf = Tower_factory{std::cin};
    auto tower = tf.create_tower();

    std::cout << "\nPart 1: " << tower.get_base()->get_name() << '\n';

    std::cout << "\nPart 2: ";

    report_imbalance(tower.get_base());
    std::cout << "\n\n";
}
