cmake_minimum_required(VERSION 3.24.0 FATAL_ERROR)

project($PROJECT_NAME CXX C)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Global configuration types
set(CMAKE_CONFIGURATION_TYPES "Debug" "Release" "Distribution" CACHE STRING "" FORCE)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# ASAN
if (ENABLE_ASAN)
    add_compile_options(-fsanitize=address)
    add_link_options(-fsanitize=address)
endif()


# fix for dxc
if (UNIX)
    add_compile_options(-fms-extensions)
endif(UNIX)

# Sub-projects
add_subdirectory($PROJECT_NAME)
add_subdirectory($PROJECT_NAMEModule)

