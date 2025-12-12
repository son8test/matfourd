#include <testing/mat_alias.hxx>
#include <son8/matfourd/mat/multiply.hxx>
#include <son8/matfourd/mat/equality.hxx>
#include <son8/matfourd/print.hxx>

void son8::main( Args ) {
    auto test = []( Msg msg, auto vecL, auto vecR, auto expect ) {
        auto result = vecL ^ ~vecR;
        if ( result == expect ) return;
        err << msg
            << PRINT( vecL )
            << PRINT( vecR )
            << PRINT( result )
            << PRINTEND ( expect );
    };

    test( "Vec2 outer multiply", Vec2{ 1, 2 }, Vec2{ 1, 10 }, Mat2x2{ { 1, 2 }, { 10, 20 } } );
    test( "Vec3 outer multiply", Vec3{ 1, 2, 4 }, Vec3{ 1, 10, 100 }, Mat3x3{ { 1, 2, 4 }, { 10, 20, 40 }, { 100, 200, 400 } } );
    test( "Vec4 outer multiply", Vec4{ 1, 2, 4, 8 }, Vec4{ 1, 10, 100, 1'000 }
        , Mat4x4{ { 1, 2, 4, 8 }, { 10, 20, 40, 80 }, { 100, 200, 400, 800 }, { 1'000, 2'000, 4'000, 8'000 } } );
}
