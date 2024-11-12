cmake_minimum_required(VERSION 3.20)

project(pimple_log)
set(CMAKE_CXX_STANDARD 20)
find_package(spdlog REQUIRED)

# library
add_executable(pimple_log
        src/main.cpp
        src/spd_logger.cpp
)
		
target_include_directories(pimple_log PUBLIC
        include
)

target_link_libraries(pimple_log PUBLIC
        fmt::fmt
)

target_link_libraries(pimple_log PRIVATE
        spdlog::spdlog)


