#include <tower.h>

#include <string>

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
        }
    }
    tower.set_base();
    return tower;
}

Program* Tower_factory::fetch_program(std::string_view name)
{
    auto& p = location_tbl[name];
    return p ? p : nullptr;
}
