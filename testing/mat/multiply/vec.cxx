#include <testing/mat_alias.hxx>
#include <son8/matfourd/mat/multiply.hxx>
#include <son8/matfourd/mat/equality.hxx>
#include <son8/matfourd/mat/alter.hxx>
#include <son8/matfourd/print.hxx>

void son8::main( Args ) {
    auto test = []( auto mat, auto vec, auto expect ) {
        auto matXvec = mat * vec;
        auto vecXmat_ransposed = vec * m4d::transpose( mat );
        if ( matXvec == expect && vecXmat_ransposed == expect ) return;
        err << PRINT( matXvec )
            << PRINT( vecXmat_ransposed )
            << PRINTEND( expect );
    };

    test( Mat2x2{ { 1, 3 }, { 2, 4 } }, Vec2{ 2, 3 }, Vec2{ 8, 18 } );
    test( Mat2x3{ { 1, 3, 5 }, { 2, 4, 6 } }, Vec2{ 2, 3 }, Vec3{ 8, 18, 28 } );
    test( Mat2x4{ { 1, 3, 5, 7 }, { 2, 4, 6, 8 } }, Vec2{ 2, 3 }, Vec4{ 8, 18, 28, 38 } );
    test( Mat3x2{ { 1, 4 }, { 2, 5 }, { 3, 6 } }, Vec3{ 2, 3, 4 }, Vec2{ 20, 47 } );
    test( Mat3x3{ { 1, 4, 7 }, { 2, 5, 8 }, { 3, 6, 9 } }, Vec3{ 2, 3, 4 }, Vec3{ 20, 47, 74 } );
    test( Mat3x4{ { 1, 4, 7, 10 }, { 2, 5, 8, 11 }, { 3, 6, 9, 12 } }, Vec3{ 2, 3, 4 }, Vec4{ 20, 47, 74, 101 } );
    test( Mat4x2{ { 1, 5 }, { 2, 6 }, { 3, 7 }, { 4, 8 } }, Vec4{ 2, 3, 4, 5 }, Vec2{ 40, 96 } );
    test( Mat4x3{ { 1, 5, 9 }, { 2, 6, 10 }, { 3, 7, 11 }, { 4, 8, 12 } }, Vec4{ 2, 3, 4, 5 }, Vec3{ 40, 96, 152 } );
    test( Mat4x4{ { 1, 5, 9, 13 }, { 2, 6, 10, 14 }, { 3, 7, 11, 15 }, { 4, 8, 12, 16 } }, Vec4{ 2, 3, 4, 5 }, Vec4{ 40, 96, 152, 208 } );
}
