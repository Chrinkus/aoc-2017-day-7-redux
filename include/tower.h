#ifndef TOWER_H
#define TOWER_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

#include <program.h>

class Tower {
public:
    Tower() = delete;
    explicit Tower(size_t size) { tower.reserve(size); }

    Program* add_program(Program_data& data);
    Program* add_program(std::string& n);
    void set_base();

    void establish_weights();
    void establish_balance();

    Program* get_base() const { return base; }
    size_t tower_size() const { return tower.size(); }

    void print_tower() const;
private:

    std::vector<Program> tower;
    Program* base = nullptr;
};

class Tower_factory {
public:
    explicit Tower_factory(std::istream& is);

    Tower create_tower();
    size_t data_size() const { return data_tbl.size(); }
private:
    Program* fetch_program(const std::string& name);

    std::vector<Program_data> data_tbl;
    std::unordered_map<std::string,Program*> location_tbl;
};

#endif // TOWER_H
