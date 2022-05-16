cmake_minimum_required(VERSION 3.15)

if ($ENV{GITHUB_RUN_NUMBER})
    project (Vector_Editor VERSION 0.0.$ENV{GITHUB_RUN_NUMBER})
else()
    project (Vector_Editor VERSION 0.0.1)
endif()

configure_file(version.h.in version.h)
 
add_executable(vector_editor_cli 
source/main.cpp
)

set_target_properties(vector_editor_cli 
PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(vector_editor_cli
    PRIVATE 
    include
    "${CMAKE_BINARY_DIR}"
)

if (MSVC)
    target_compile_options(vector_editor_cli 
    PRIVATE
    /EHsc /W4 /WX
        )    
 else ()
    target_compile_options(vector_editor_cli 
    PRIVATE
    -Wall -Wextra -pedantic -Werror
        )
endif()



