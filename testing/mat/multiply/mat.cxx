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
    test( mat2x4, mat2x2 * 9, Mat2x4{ { 99, 126, 153, 180 }, { 207, 270, 333, 396 } } );
    test( mat2x4, mat3x2 * 9, Mat3x4{ { 99, 126, 153, 180 }, { 207, 270, 333, 396 }, { 315, 414, 513, 612 } } );
    test( mat2x4, mat4x2 * 9, Mat4x4{ { 99, 126, 153, 180 }, { 207, 270, 333, 396 }, { 315, 414, 513, 612 }, { 423, 558, 693, 828 } } );
    test( mat3x2, mat2x3 * 7, Mat2x2{ { 154, 196 }, { 343, 448 } } );
    test( mat3x2, mat3x3 * 7, Mat3x2{ { 154, 196 }, { 343, 448 }, { 532, 700 } } );
    test( mat3x2, mat4x3 * 7, Mat4x2{ { 154, 196 }, { 343, 448 }, { 532, 700 }, { 721, 952 } } );

    test( mat3x3, mat2x3 *10, Mat2x3{ { 300, 360, 420 }, { 660, 810, 960 } } );
    test( mat3x3, mat3x3 *10, Mat3x3{ { 300, 360, 420 }, { 660, 810, 960 }, { 1'020, 1'260, 1'500 } } );
    test( mat3x3, mat4x3 *10, Mat4x3{ { 300, 360, 420 }, { 660, 810, 960 }, { 1'020, 1'260, 1'500 }, { 1'380, 1'710, 2'040 } } );
    test( mat4x2, mat2x4 * 9, Mat2x2{ { 450, 540 }, { 1'026, 1'260 } } );
    test( mat4x2, mat3x4 * 9, Mat3x2{ { 450, 540 }, { 1'026, 1'260 }, { 1'602, 1'980 } } );
    test( mat4x2, mat4x4 * 9, Mat4x2{ { 450, 540 }, { 1'026, 1'260 }, { 1'602, 1'980 }, { 2'178, 2'700 } } );
    test( mat4x3, mat2x4 *13, Mat2x3{ { 910, 1'040, 1'170 }, { 2'054, 2'392, 2'730 } } );
    test( mat4x3, mat3x4 *13, Mat3x3{ { 910, 1'040, 1'170 }, { 2'054, 2'392, 2'730 }, { 3'198, 3'744, 4'290 } } );
    test( mat4x3, mat4x4 *13, Mat4x3{ { 910, 1'040, 1'170 }, { 2'054, 2'392, 2'730 }, { 3'198, 3'744, 4'290 }, { 4'342, 5'096, 5'850 } } );
    test( mat4x4, mat2x4 *17, Mat2x4{ { 1'530, 1'700, 1'870, 2'040 }, { 3'434, 3'876, 4'318, 4'760 } } );
    test( mat4x4, mat3x4 *17, Mat3x4{ { 1'530, 1'700, 1'870, 2'040 }, { 3'434, 3'876, 4'318, 4'760 }, { 5'338, 6'052, 6'766, 7'480 } } );
    test( mat4x4, mat4x4 *17, Mat4x4{ { 1'530, 1'700, 1'870, 2'040 }, { 3'434, 3'876, 4'318, 4'760 }, { 5'338, 6'052, 6'766, 7'480 }, { 7'242, 8'228, 9'214, 10'200 } } );
}

