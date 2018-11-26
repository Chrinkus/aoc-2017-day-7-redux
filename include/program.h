#ifndef PROGRAM_H
#define PROGRAM_H

#include <iostream>
#include <string>
#include <vector>

struct Program_data {
public:
    explicit Program_data(const std::string& line);

    std::string name;
    int weight = 0;
    std::vector<std::string> child_names;
};

class Program {
public:
    explicit Program(Program_data& data)
        : name{std::move(data.name)}, weight{data.weight} { }

    explicit Program(std::string& n)
        : name{std::move(n)} { }

    // special access
    int total_weight()      const { return weight + above_weight; }
    bool is_balanced()      const { return balanced; }
    size_t num_children()   const { return children.size(); }

    // member access
    auto get_name()         const -> const std::string& { return name; }
    auto get_weight()       const -> int { return weight; }
    auto get_above_weight() const -> int { return above_weight; }
    auto get_parent()       const -> Program* { return parent; }
    auto get_children()     const -> const std::vector<Program*>&
                                     { return children; }

    // member modifying
    void set_weight(int w) { weight = w; }
    void set_parent(Program* p) { parent = p; }
    void add_child(Program* p);
    void calc_above_weight();
    void check_balance();

private:
    std::string name;
    int weight       = 0;
    int above_weight = 0;
    bool balanced    = false;
    Program* parent  = nullptr;

    std::vector<Program*> children;
};

std::ostream& operator<<(std::ostream& os, const Program& prog);

#endif // PROGRAM_H
