set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )

link_libraries( son8::matfourd )

# Add tests ⮟ HERE ⮟ that should NOT use extra warning flags

if ( MSVC )
    add_compile_options( /W4 )
else( )
    add_compile_options( -Wall -Wextra -Wpedantic )
endif( )

# Add tests ⮟ HERE ⮟ that SHOULD use extra warning flags

add_executable( test-vec-equality vec/equality.cxx )
add_test( NAME test-vec-equality COMMAND test-vec-equality )
add_executable( test-vec-additive vec/additive.cxx )
add_test( NAME test-vec-additive COMMAND test-vec-additive )
