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

    Program(std::string& n, Program* p)
        : name{std::move(n)}, parent{p} { }

    const std::string& get_name() const { return name; }

    int get_weight() const { return weight; }
    void set_weight(int w) { weight = w; }

    int get_above_weight() const { return above_weight; }
    void set_above_weight(int w) { above_weight = w; }

    int total_weight() const { return weight + above_weight; }

    Program* get_parent() const { return parent; }
    void set_parent(Program* p) { parent = p; }

    void is_balanced(bool bal) { balanced = bal; }
    bool is_balanced() const   { return balanced; }

    size_t get_num_children() const { return children.size(); }

private:
    std::string name;
    int weight = 0;
    int above_weight = 0;
    bool balanced = false;
    Program* parent = nullptr;
    std::vector<Program*> children;
};

std::ostream& operator<<(std::ostream& os, const Program& prog);

#endif // PROGRAM_H
