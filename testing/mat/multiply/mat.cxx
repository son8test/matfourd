#include <testing/mat_alias.hxx>
#include <son8/matfourd/mat/multiply.hxx>
#include <son8/matfourd/mat/equality.hxx>
#include <son8/matfourd/mat/alter.hxx>
#include <son8/matfourd/print.hxx>

void son8::main( Args ) {
    auto test = []( auto matWest, auto matEast, auto matExpect ) {
        auto matWestXmatEast = matWest * matEast;
        auto transposed_matEastXmatWest = m4d::transpose( matEast ) * m4d::transpose( matWest );
        auto transposed_matExpect = m4d::transpose( matExpect );
        if ( matWestXmatEast == matExpect && transposed_matEastXmatWest == transposed_matExpect ) return;
        err << PRINT( matWest )
            << PRINT( matEast )
            << PRINT( matWestXmatEast )
            << PRINT( matExpect )
            << PRINT( transposed_matEastXmatWest )
            << PRINTEND( transposed_matExpect );
    };


    Mat2x2 mat2x2{ { 1, 2 }, { 3, 4 } };
    Mat2x3 mat2x3{ { 1, 2, 3 }, { 4, 5, 6 } };
    Mat2x4 mat2x4{ { 1, 2, 3, 4 }, { 5, 6, 7, 8 } };
    Mat3x2 mat3x2{ { 1, 2 }, { 3, 4 }, { 5, 6 } };
    Mat3x3 mat3x3{ { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    Mat3x4 mat3x4{ { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
    Mat4x2 mat4x2{ { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } };
    Mat4x3 mat4x3{ { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }, { 10, 11, 12 } };
    Mat4x4 mat4x4{ { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };

    test( mat2x2, mat2x2 * 5, Mat2x2{ { 35, 50 }, { 75, 110 } } );
    test( mat2x2, mat3x2 * 5, Mat3x2{ { 35, 50 }, { 75, 110 }, { 115, 170 } } );
    test( mat2x2, mat4x2 * 5, Mat4x2{ { 35, 50 }, { 75, 110 }, { 115, 170 }, { 155, 230 } } );
    test( mat2x3, mat2x2 * 7, Mat2x3{ { 63, 84, 105 }, { 133, 182, 231 } } );
    test( mat2x3, mat3x2 * 7, Mat3x3{ { 63, 84, 105 }, { 133, 182, 231 }, { 203, 280, 357 } } );
    test( mat2x3, mat4x2 * 7, Mat4x3{ { 63, 84, 105 }, { 133, 182, 231 }, { 203, 280, 357 }, { 273, 378, 483 } } );

}

