#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"
#include <logger.hpp>

#include <memory>

class logger::Impl {
    spdlog::logger logger;

public:
    explicit Impl(const spdlog::level::level_enum level)
        : logger("LOG") {
        logger.sinks().push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
        logger.sinks().push_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/basic_sink.txt"));
        logger.set_level(level);
    }

    void log(logger::level_enum level, std::ostringstream& msg) {
        logger.log(static_cast<spdlog::level::level_enum>(level), msg.str());
    }
};

logger::logger(logger::level_enum level)
        : pImpl(std::make_unique<Impl>(static_cast<spdlog::level::level_enum>(level))) {}

logger::~logger() = default;

void logger::print(const level_enum level, std::ostringstream& stream) const {
    this->pImpl->log(level, stream);
}
