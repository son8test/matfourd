#include <testing/mat_alias.hxx>
#include <son8/matfourd/mat/type.hxx>
#include <son8/matfourd/mat/equality.hxx>
#include <son8/matfourd/print.hxx>

#define VEC2_0 { 0, 0 }
#define VEC3_0 { 0, 0, 0 }
#define VEC4_0 { 0, 0, 0, 0 }

#define VEC2_I( i ) { i, i + 1 }
#define VEC3_I( i ) { i, i + 1, i + 2 }
#define VEC4_I( i ) { i, i + 1, i + 2, i + 3 }

void son8::main( Args ) {
    auto test = []( Msg msg, auto result, auto expect ) {
        if ( result == expect ) return;
        err << msg
            << PRINT( result )
            << PRINTEND( expect );
    };

    Mat2x2 mat2x2{ };
    Mat2x3 mat2x3{ };
    Mat2x4 mat2x4{ };
    Mat3x2 mat3x2{ };
    Mat3x3 mat3x3{ };
    Mat3x4 mat3x4{ };
    Mat4x2 mat4x2{ };
    Mat4x3 mat4x3{ };
    Mat4x4 mat4x4{ };

    test( "Mat2x2{ }\n", mat2x2, Mat2x2{ VEC2_0, VEC2_0 } );
    test( "Mat2x3{ }\n", mat2x3, Mat2x3{ VEC3_0, VEC3_0 } );
    test( "Mat2x4{ }\n", mat2x4, Mat2x4{ VEC4_0, VEC4_0 } );
    test( "Mat3x2{ }\n", mat3x2, Mat3x2{ VEC2_0, VEC2_0, VEC2_0 } );
    test( "Mat3x3{ }\n", mat3x3, Mat3x3{ VEC3_0, VEC3_0, VEC3_0 } );
    test( "Mat3x4{ }\n", mat3x4, Mat3x4{ VEC4_0, VEC4_0, VEC4_0 } );
    test( "Mat4x2{ }\n", mat4x2, Mat4x2{ VEC2_0, VEC2_0, VEC2_0, VEC2_0 } );
    test( "Mat4x3{ }\n", mat4x3, Mat4x3{ VEC3_0, VEC3_0, VEC3_0, VEC3_0 } );
    test( "Mat4x4{ }\n", mat4x4, Mat4x4{ VEC4_0, VEC4_0, VEC4_0, VEC4_0 } );

    test( "Mat2x2 size", mat2x2.size( ), 4u );
    test( "Mat2x3 size", mat2x3.size( ), 6u );
    test( "Mat2x4 size", mat2x4.size( ), 8u );
    test( "Mat3x2 size", mat3x2.size( ), 6u );
    test( "Mat3x3 size", mat3x3.size( ), 9u );
    test( "Mat3x4 size", mat3x4.size( ), 12u );
    test( "Mat4x2 size", mat4x2.size( ), 8u );
    test( "Mat4x3 size", mat4x3.size( ), 12u );
    test( "Mat4x4 size", mat4x4.size( ), 16u );
    // test that memory is ordered accoring to C++ rules no matter is it (Col|Row)-major matrix
    //      when performing value construction
    auto test_data = []( auto mat ) {
        auto expect = 0;
        for ( auto i = 0u; i < mat.size( ); ++i ) {
            auto result = *( mat.data( ) + i );
            if ( result != expect ) {
                err << "test data failed: "
                    << PRINT( mat )
                    << PRINT( i )
                    << PRINT( result )
                    << PRINTEND( expect );
            }
            ++expect;
        }
    };

    Col2x2 col2x2i{ VEC2_I( 0 ), VEC2_I( 2 ) };
    Row2x2 row2x2i{ VEC2_I( 0 ), VEC2_I( 2 ) };
    Col2x3 col2x3i{ VEC3_I( 0 ), VEC3_I( 3 ) };
    Row2x3 row2x3i{ VEC2_I( 0 ), VEC2_I( 2 ), VEC2_I( 4 ) };
    Col2x4 col2x4i{ VEC4_I( 0 ), VEC4_I( 4 ) };
    Row2x4 row2x4i{ VEC2_I( 0 ), VEC2_I( 2 ), VEC2_I( 4 ), VEC2_I( 6 ) };
    Col3x2 col3x2i{ VEC2_I( 0 ), VEC2_I( 2 ), VEC2_I( 4 ) };
    Row3x2 row3x2i{ VEC3_I( 0 ), VEC3_I( 3 ) };
    Col3x3 col3x3i{ VEC3_I( 0 ), VEC3_I( 3 ), VEC3_I( 6 ) };
    Row3x3 row3x3i{ VEC3_I( 0 ), VEC3_I( 3 ), VEC3_I( 6 ) };
    Col3x4 col3x4i{ VEC4_I( 0 ), VEC4_I( 4 ), VEC4_I( 8 ) };
    Row3x4 row3x4i{ VEC3_I( 0 ), VEC3_I( 3 ), VEC3_I( 6 ), VEC3_I( 9 ) };
    Col4x2 col4x2i{ VEC2_I( 0 ), VEC2_I( 2 ), VEC2_I( 4 ), VEC2_I( 6 ) };
    Row4x2 row4x2i{ VEC4_I( 0 ), VEC4_I( 4 ) };
    Col4x3 col4x3i{ VEC3_I( 0 ), VEC3_I( 3 ), VEC3_I( 6 ), VEC3_I( 9 ) };
    Row4x3 row4x3i{ VEC4_I( 0 ), VEC4_I( 4 ), VEC4_I( 8 ) };
    Col4x4 col4x4i{ VEC4_I( 0 ), VEC4_I( 4 ), VEC4_I( 8 ), VEC4_I( 12 ) };
    Row4x4 row4x4i{ VEC4_I( 0 ), VEC4_I( 4 ), VEC4_I( 8 ), VEC4_I( 12 ) };

    test_data( col2x2i );
    test_data( row2x2i );
    test_data( col2x3i );
    test_data( row2x3i );
    test_data( col2x4i );
    test_data( row2x4i );
    test_data( col3x2i );
    test_data( row3x2i );
    test_data( col3x3i );
    test_data( row3x3i );
    test_data( col3x4i );
    test_data( row3x4i );
    test_data( col4x2i );
    test_data( row4x2i );
    test_data( col4x3i );
    test_data( row4x3i );
    test_data( col4x4i );
    test_data( row4x4i );
}
