#ifndef PROGRAM_H
#define PROGRAM_H

#include <string>
#include <vector>
#include <string_view>

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


    void set_weight(int w)      { weight = w; }
    void set_parent(Program* p) { parent = p; }

    auto get_name()   const -> std::string_view
                                            { return std::string_view{name}; }
    auto get_weight() const -> int          { return weight; }
    auto get_parent() const -> Program*     { return parent; }
    auto get_num_children() const -> size_t { return children.size(); }

private:
    std::string name;
    int weight = 0;
    Program* parent = nullptr;
    std::vector<Program*> children;
};

#endif // PROGRAM_H
