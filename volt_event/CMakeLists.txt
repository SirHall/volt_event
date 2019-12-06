cmake_minimum_required(VERSION 3.5)

# Set some default values
set(VOLT_EVENT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/)
set(VOLT_EVENT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
# set(CMAKE_CXX_STANDARD 17)

# Find all source files
file(GLOB_RECURSE VOLT_EVENT_SRCS
    "src/*.cpp"
    RELATIVE_PATH
)

add_library(volt_event INTERFACE)
target_include_directories(volt_event INTERFACE ${VOLT_EVENT_INCLUDE_DIR})
target_link_libraries (volt_event ${CMAKE_THREAD_LIBS_INIT})
# SET(GXX_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
# Flags
# if(MSVC)
#     target_compile_options(volt_net PRIVATE /W4 /WX)
# else()

# set(WARNING_FLAGS "-Wall -Wextra -pedantic -Werror -Wno-unknown-pragmas -Wno-unused-parameter")
# set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${WARNING_FLAGS} -g -fprofile-arcs -ftest-coverage")
# set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${WARNING_FLAGS} -flto -O3")

# endif()