#include <testing/mat_alias.hxx>
#include <son8/matfourd/mat/alter.hxx>
#include <son8/matfourd/mat/equality.hxx>
#include <son8/matfourd/print.hxx>

#define T( m ) m4d::transpose( m )

void son8::main( Args ) {
    auto test = []( Msg msg, auto result, auto expect ) {
        if ( result == expect && ~result == expect ) return;
        err << msg
            << ", result: " << result
            << ",~result: " <<~result
            << ", expect: " << expect
            << std::endl;
    };

    Mat2x2 mat2x2{ { 1, 2 }, { 4, 8 } };
    Mat2x3 mat2x3{ { 1, 2, 4 }, { 8, 16, 32 } };
    Mat2x4 mat2x4{ { 1, 2, 4, 8 }, { 16, 32, 64, 128 } };
    Mat3x2 mat3x2{ { 1, 2 }, { 4, 8 }, { 16, 32 } };
    Mat3x3 mat3x3{ { 1, 2, 4 }, { 8, 16, 32 }, { 64, 128, 256 } };
    Mat3x4 mat3x4{ { 1, 2, 4, 8 }, { 16, 32, 64, 128 }, { 256, 512, 1'024, 2'048 } };
    Mat4x2 mat4x2{ { 1, 2 }, { 4, 8 }, { 16, 32 }, { 64, 128 } };
    Mat4x3 mat4x3{ { 1, 2, 4 }, { 8, 16, 32 }, { 64, 128, 256 }, { 512, 1'024, 2'048 } };
    Mat4x4 mat4x4{ { 1, 2, 4, 8 }, { 16, 32, 64, 128 }, { 256, 512, 1'024, 2'048 }, { 4'096, 8'192, 16'384, 32'768 } };

    test( "transpose mat2x2", T( mat2x2 ), Mat2x2{ { 1, 4 }, { 2, 8 }, } );
    test( "transpose mat2x3", T( mat2x3 ), Mat3x2{ { 1, 8 }, { 2, 16 }, { 4, 32 }, } );
    test( "transpose mat2x4", T( mat2x4 ), Mat4x2{ { 1, 16 }, { 2, 32 }, { 4, 64 }, { 8, 128 } } );
    test( "transpose mat3x2", T( mat3x2 ), Mat2x3{ { 1, 4, 16 }, { 2, 8, 32 } } );
    test( "transpose mat3x3", T( mat3x3 ), Mat3x3{ { 1, 8, 64 }, { 2, 16, 128 }, { 4, 32, 256 } } );
    test( "transpose mat3x4", T( mat3x4 ), Mat4x3{ { 1, 16, 256 }, { 2, 32, 512 }, { 4, 64, 1'024 }, { 8, 128, 2'048 } } );

    test( "transpose mat4x2", T( mat4x2 ), Mat2x4{ { 1, 4, 16, 64 }, { 2, 8, 32, 128 } } );
    test( "transpose mat4x3", T( mat4x3 ), Mat3x4{ { 1, 8, 64, 512 }, { 2, 16, 128, 1'024 }, { 4, 32, 256, 2'048 } } );
    test( "transpose mat4x4", T( mat4x4 ), Mat4x4{ { 1, 16, 256, 4'096 }, { 2, 32, 512, 8'192 }, { 4, 64, 1'024, 16'384 }, { 8, 128, 2'048, 32'768 } } );

}
