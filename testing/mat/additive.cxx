#include <testing/mat_alias.hxx>
#include <son8/matfourd/mat/additive.hxx>
#include <son8/matfourd/mat/equality.hxx>
#include <son8/matfourd/print.hxx>

#define PRINT( v )\
<< ", " #v ": " << v

#define ENDL( ) << std::endl

#define V8_2 { 8, 8 }
#define V8_3 { 8, 8, 8 }
#define V8_4 { 8, 8, 8, 8 }

void son8::main( Args ) {

    auto test = []( Msg msg, auto matL, auto matR, auto expect ) {
        auto plusLR = matL + matR;
        auto plusRL = ( +matR ) + ( +matL );
        auto minusLR =-( ( -matL ) - matR );
        auto minusRL =-( ( -matR ) + ( -matL ) );
        if ( plusLR == plusRL && minusLR == minusRL && expect == plusLR && expect == ~plusLR ) return;
        err << msg
            PRINT( plusLR )
            PRINT(~plusLR )
            PRINT( plusRL )
            PRINT( minusLR )
            PRINT( minusRL )
            PRINT( expect )
            ENDL( );
    };

    Vec2 vec2L{ 0, 1 }, vec2R{ 8, 7 };
    Vec3 vec3L{ 2, 3, 4 }, vec3R{ 6, 5, 4 };
    Vec4 vec4L{ 5, 6, 7, 8 }, vec4R{ 3, 2, 1, 0 };

    test( "Mat2x2 additive\n", Mat2x2{ vec2L, vec2R }, Mat2x2{ vec2R, vec2L }, Mat2x2{ V8_2, V8_2 } );
    test( "Mat2x3 additive\n", Mat2x3{ vec3L, vec3R }, Mat2x3{ vec3R, vec3L }, Mat2x3{ V8_3, V8_3 } );
    test( "Mat2x4 additive\n", Mat2x4{ vec4L, vec4R }, Mat2x4{ vec4R, vec4L }, Mat2x4{ V8_4, V8_4 } );
    test( "Mat3x2 additive\n", Mat3x2{ vec2L, vec2R, vec2L }, Mat3x2{ vec2R, vec2L, vec2R }, Mat3x2{ V8_2, V8_2, V8_2 } );
    test( "Mat3x3 additive\n", Mat3x3{ vec3L, vec3R, vec3L }, Mat3x3{ vec3R, vec3L, vec3R }, Mat3x3{ V8_3, V8_3, V8_3 } );
    test( "Mat3x4 additive\n", Mat3x4{ vec4L, vec4R, vec4L }, Mat3x4{ vec4R, vec4L, vec4R }, Mat3x4{ V8_4, V8_4, V8_4 } );
    test( "Mat4x2 additive\n", Mat4x2{ vec2L, vec2R, vec2L, vec2R }, Mat4x2{ vec2R, vec2L, vec2R, vec2L }, Mat4x2{ V8_2, V8_2, V8_2, V8_2 } );
    test( "Mat4x3 additive\n", Mat4x3{ vec3L, vec3R, vec3L, vec3R }, Mat4x3{ vec3R, vec3L, vec3R, vec3L }, Mat4x3{ V8_3, V8_3, V8_3, V8_3 } );
    test( "Mat4x4 additive\n", Mat4x4{ vec4L, vec4R, vec4L, vec4R }, Mat4x4{ vec4R, vec4L, vec4R, vec4L }, Mat4x4{ V8_4, V8_4, V8_4, V8_4 } );
}
