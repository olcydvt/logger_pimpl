#include <logger.hpp>

int main() {
    std::string str{"Hi"};;
    auto& str2= str;
    auto&& str3= "abcd";
    logger _logger(logger::trace);
    _logger.LOG(logger::debug, "test1", "test2", 1, 2, 3.1, 'X', str, str2, std::move(str3));
    return 0;
}
