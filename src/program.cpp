#include <program.h>

#include <regex>
#include <algorithm>

using Reg_it = std::regex_iterator<std::string::iterator>;

Program_data::Program_data(const std::string& line)
{
    static const std::regex name_age_pat {R"(^(\w+)\s\((\d+)\))"};
    static const std::regex child_pat    {R"((\w+))"};

    std::smatch matches;
    std::regex_search(line, matches, name_age_pat);

    auto it = ++matches.begin();        // skip full match
    name = *it++;
    weight = std::stoi(*it++);
    std::string rest = matches.suffix();

    if (rest.size()) {
        auto rit = Reg_it{std::begin(rest), std::end(rest), child_pat};
        auto sentry = Reg_it{};
        std::for_each(rit, sentry, [this](const auto& m_res) {
                    this->child_names.push_back(m_res.str());
                });
    }
}

std::ostream& operator<<(std::ostream& os, const Program& prog)
{
    os << prog.get_name() << " (" << prog.get_weight() << ") [";
    for (const auto p_child : prog.get_children())
        os << p_child->get_name() << ' ';
    os << "] Above: (" << prog.get_above_weight() << ')';
    return os;
}
