cmake_minimum_required(VERSION 3.5)

# Set some default values
set(VOLT_EVENT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/)

# Find all source files
file(GLOB_RECURSE VOLT_EVENT_SRCS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
    RELATIVE_PATH
)

# Find all header files
file(GLOB_RECURSE VOLT_EVENT_HEADERS
    "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
    RELATIVE_PATH
)

set(SOURCES ${VOLT_EVENT_SRCS})
set(HEADERS_PUBLIC ${VOLT_EVENT_HEADERS})

# add_library(volt_event INTERFACE)
# target_include_directories(volt_event INTERFACE ${VOLT_EVENT_INCLUDE_DIR})
# target_link_libraries (volt_event ${CMAKE_THREAD_LIBS_INIT})

include(${PROJECT_SOURCE_DIR}/cmake/LibraryConfig.cmake)
target_link_libraries(${LIBRARY_NAME} ${CMAKE_THREAD_LIBS_INIT})