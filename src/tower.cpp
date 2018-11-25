#include <tower.h>
#include <iostream>

Program* Tower::add_program(Program_data& data)
{
    tower.emplace_back(data);
    return &tower.back();
}

Program* Tower::add_program(std::string& n)
{
    tower.emplace_back(n);
    return &tower.back();
}

void Tower::set_base()
{
    auto p = tower.data();
    while (p->get_parent())
        p = p->get_parent();
    base = p;
}

void Tower::establish_weights()
{
    base->calc_above_weight();
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
        data_tbl.emplace_back(line);
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
            if (!p_child) {
                p_child = tower.add_program(name);
                location_tbl[p_child->get_name()] = p_child;
            }
            p_prog->add_child(p_child);
        }
    }
    tower.set_base();
    tower.establish_weights();
    return tower;
}

Program* Tower_factory::fetch_program(const std::string& name)
{
    auto& p = location_tbl[name];
    return p ? p : nullptr;
}
