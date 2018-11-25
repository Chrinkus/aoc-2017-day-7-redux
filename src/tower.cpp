#include <tower.h>
#include <algorithm>
#include <iostream>

Program* Tower::add_program(Program_data& data)
{
    tower.emplace_back(Program{data});
    return &tower.back();
}

Program* Tower::add_program(std::string& n, Program* p)
{
    tower.emplace_back(Program{n, p});
    return &tower.back();
}

void Tower::set_base()
{
    auto p = tower.data();
    while (p->get_parent())
        p = p->get_parent();
    base = p;
}

void Tower::calc_above_weights(Program* p)
{
    std::for_each(std::begin(p->get_children()), std::end(p->get_children()),
            [this, p](Program* p_child) {
                this->calc_above_weights(p_child);
                p->inc_above_weight(p_child->total_weight());
            });
    /*
    for (const auto p_child : p->get_children()) {
        calc_above_weights(p_child);
        p->inc_above_weight(p_child->total_weight());
    }
    */
}

void Tower::print_tower() const
{
    for (const auto& p : tower)
        std::cout << p << '\n';
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

Tower_factory::Tower_factory(std::istream& is)
{
    std::string line;
    while (std::getline(is, line))
        data_tbl.emplace_back(Program_data{line});
}

Tower Tower_factory::create_tower()
{
    Tower tower{data_size()};

    for (auto& data : data_tbl) {
        auto p_prog = fetch_program(data.name);

        if (p_prog)
            p_prog->set_weight(data.weight);
        else {
            p_prog = tower.add_program(data);
            location_tbl[p_prog->get_name()] = p_prog;
        }

        for (auto& name : data.child_names) {   
            auto p_child = fetch_program(name);
            if (p_child)
                p_child->set_parent(p_prog);
            else {
                p_child = tower.add_program(name, p_prog);
                location_tbl[p_child->get_name()] = p_child;
            }
            p_prog->add_child(p_child);
        }
    }
    tower.set_base();
    tower.calc_above_weights(tower.get_base());
    return tower;
}

Program* Tower_factory::fetch_program(const std::string& name)
{
    auto& p = location_tbl[name];
    return p ? p : nullptr;
}
