cmake_minimum_required(VERSION 3.5)

add_library(volt_event INTERFACE)
target_include_directories(volt_event INTERFACE "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>")
target_link_libraries (volt_event ${CMAKE_THREAD_LIBS_INIT})

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(config_install_dir "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}")

set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")

set(version_config "${generated_dir}/${PROJECT_NAME}ConfigVersion.cmake")
set(project_config "${generated_dir}/${PROJECT_NAME}Config.cmake")
set(TARGETS_EXPORT_NAME "${PROJECT_NAME}Targets")

write_basic_package_version_file(
    "${version_config}" COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake.in"
    "${project_config}"
    INSTALL_DESTINATION "${config_install_dir}"
)

# Don't know how much we need this given this is a header-only library
install(
    TARGETS              volt_event
    EXPORT               "${TARGETS_EXPORT_NAME}"
    LIBRARY DESTINATION  "${CMAKE_INSTALL_LIBDIR}" # Probably not needed
    ARCHIVE DESTINATION  "${CMAKE_INSTALL_LIBDIR}" # Probably not needed
    RUNTIME DESTINATION  "${CMAKE_INSTALL_BINDIR}" # Probably not needed
    INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

# Headers
install(
    DIRECTORY "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
    # FILES_MATCHING PATTERN "*.hpp"
)

# Configs
install(
    FILES "${project_config}" "${version_config}"
    DESTINATION "${config_install_dir}"
)

# Config
#   * <prefix>/lib/cmake/Foo/FooTargets.cmake
install(
    EXPORT "${TARGETS_EXPORT_NAME}"
    # NAMESPACE "${namespace}"
    DESTINATION "${config_install_dir}"
)