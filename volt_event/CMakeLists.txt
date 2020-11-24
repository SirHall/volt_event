cmake_minimum_required(VERSION 3.5)

add_library(volt_event INTERFACE)
target_include_directories(volt_event INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include/)
target_link_libraries (volt_event ${CMAKE_THREAD_LIBS_INIT})

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

install(
    TARGETS              volt_event
    EXPORT               "${TARGETS_EXPORT_NAME}"
    LIBRARY DESTINATION  "${CMAKE_INSTALL_LIBDIR}"
    ARCHIVE DESTINATION  "${CMAKE_INSTALL_LIBDIR}"
    RUNTIME DESTINATION  "${CMAKE_INSTALL_BINDIR}"
    INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

# Find all header files
# file(GLOB_RECURSE VOLT_EVENT_HEADERS
#     "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp"
#     "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
#     RELATIVE_PATH
# )

# set(SOURCES ${VOLT_EVENT_SRCS})
# set(HEADERS_PUBLIC ${VOLT_EVENT_HEADERS})

# include(${PROJECT_SOURCE_DIR}/cmake/LibraryConfig.cmake)
# target_link_libraries(${LIBRARY_NAME} ${CMAKE_THREAD_LIBS_INIT})