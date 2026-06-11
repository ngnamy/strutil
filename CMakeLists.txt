cmake_minimum_required(VERSION 3.15)
project(strutil C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Compiler warnings
add_compile_options(-Wall -Wextra -Werror)

# Static library
add_library(strutil STATIC src/strutil.c)
target_include_directories(strutil PUBLIC include)

# Test executable
add_executable(strutil_test
    src/main.c
    src/test_strutil.c)
target_link_libraries(strutil_test PRIVATE strutil)

# Debug sanitizer option
option(ENABLE_SANITIZERS "Enable AddressSanitizer and UBSan" OFF)
if(ENABLE_SANITIZERS)
    target_compile_options(strutil PUBLIC -fsanitize=address,undefined)
    target_link_options(strutil PUBLIC -fsanitize=address,undefined)
    target_compile_options(strutil_test PRIVATE -fsanitize=address,undefined)
    target_link_options(strutil_test PRIVATE -fsanitize=address,undefined)
endif()
