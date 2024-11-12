#pragma once

#include <memory>
#include <sstream>

class logger {
public:
    enum level_enum : int {
        trace = 0,
        debug = 1,
        info = 2,
        warn = 3,
        err = 4,
        critical = 5,
        off = 6,
        n_levels
    };

    explicit logger(logger::level_enum level);
    ~logger();

    template <typename... T>
    void LOG(const level_enum level, T... msg) {
        std::ostringstream stream;
        ((stream << msg << ' '), ...);
        print(level, stream);
    }

    void print(level_enum level, std::ostringstream& stream) const;

private:
    class Impl;
    std::unique_ptr<Impl> const  pImpl;
};
