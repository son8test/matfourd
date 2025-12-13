set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )

include_directories( include )
link_libraries( son8::matfourd son8::mainland )

# Add tests ⮟ HERE ⮟ that should NOT use extra warning flags

if ( MSVC )
    add_compile_options( /W4 )
else( )
    add_compile_options( -Wall -Wextra -Wpedantic )
endif( )

# Add tests ⮟ HERE ⮟ that SHOULD use extra warning flags

# Layout
add_executable( test-layout layout.cxx )
add_test( NAME test-layout COMMAND test-layout )
# Vec
add_executable( test-vec-alias vec/alias.cxx )
add_test( NAME test-vec-alias COMMAND test-vec-alias )
add_executable( test-vec-equality vec/equality.cxx )
add_test( NAME test-vec-equality COMMAND test-vec-equality )
add_executable( test-vec-additive vec/additive.cxx )
add_test( NAME test-vec-additive COMMAND test-vec-additive )
add_executable( test-vec-multiply-dot vec/multiply/dot.cxx )
add_test( NAME test-vec-multiply-dot COMMAND test-vec-multiply-dot )
add_executable( test-vec-multiply-scalar vec/multiply/scalar.cxx )
add_test( NAME test-vec-multiply-scalar COMMAND test-vec-multiply-scalar )
add_executable( test-vec-multiply-cross vec/multiply/cross.cxx )
add_test( NAME test-vec-multiply-cross COMMAND test-vec-multiply-cross )
add_executable( test-vec-type vec/type.cxx )
add_test( NAME test-vec-type COMMAND test-vec-type )
add_executable( test-vec-swizzles vec/swizzles.cxx )
add_test( NAME test-vec-swizzles COMMAND test-vec-swizzles )
# Mat
add_executable( test-mat-alias mat/alias.cxx )
add_test( NAME test-mat-alias COMMAND test-mat-alias )
add_executable( test-mat-equality mat/equality.cxx )
add_test( NAME test-mat-equality COMMAND test-mat-equality )
add_executable( test-mat-type mat/type.cxx )
add_test( NAME test-mat-type COMMAND test-mat-type )
add_executable( test-mat-alter mat/alter.cxx )
add_test( NAME test-mat-alter COMMAND test-mat-alter )
add_executable( test-mat-additive mat/additive.cxx )
add_test( NAME test-mat-additive COMMAND test-mat-additive )
add_executable( test-mat-multiply-outer mat/multiply/outer.cxx )
add_test( NAME test-mat-multiply-outer COMMAND test-mat-multiply-outer )
add_executable( test-mat-multiply-scalar mat/multiply/scalar.cxx )
add_test( NAME test-mat-multiply-scalar COMMAND test-mat-multiply-scalar )
add_executable( test-mat-multiply-vec mat/multiply/vec.cxx )
add_test( NAME test-mat-multiply-vec COMMAND test-mat-multiply-vec )
add_executable( test-mat-multiply-mat mat/multiply/mat.cxx )
add_test( NAME test-mat-multiply-mat COMMAND test-mat-multiply-mat )

