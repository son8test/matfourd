#include <testing/mat_alias.hxx>
#include <son8/matfourd/mat/equality.hxx>

void son8::main( Args const & ) {
    auto test = []( Msg msg, auto ...args ) {
        bool all = ( true && ... && args );
        if ( all ) return;
        failed( );
        err << msg << std::endl;
    };

    Vec2 vec2_1{ 11, 21 }        , vec2_2{ 12, 22 }        , vec2_3{ 13, 23 }        , vec2_4{ 14, 24 };
    Vec3 vec3_1{ 11, 21, 31 }    , vec3_2{ 12, 22, 32 }    , vec3_3{ 13, 23, 33 }    , vec3_4{ 14, 24, 34 };
    Vec4 vec4_1{ 11, 21, 31, 41 }, vec4_2{ 12, 22, 32, 42 }, vec4_3{ 13, 23, 33, 43 }, vec4_4{ 14, 24, 34, 44 };

    Mat2x2 mat2x2  { vec2_1, vec2_2 };
    Mat3x2 mat3x2{ vec2_1, vec2_2, vec2_3 };
    Mat4x2 mat4x2{ vec2_1, vec2_2, vec2_3, vec2_4 };
    Mat2x3 mat2x3{ vec3_1, vec3_2 };
    Mat3x3 mat3x3{ vec3_1, vec3_2, vec3_3 };
    Mat4x3 mat4x3{ vec3_1, vec3_2, vec3_3, vec3_4 };
    Mat2x4 mat2x4{ vec4_1, vec4_2 };
    Mat3x4 mat3x4{ vec4_1, vec4_2, vec4_3 };
    Mat4x4 mat4x4{ vec4_1, vec4_2, vec4_3, vec4_4 };

    auto mat2x2_copy = mat2x2;
    auto mat3x2_copy = mat3x2;
    auto mat4x2_copy = mat4x2;
    auto mat2x3_copy = mat2x3;
    auto mat3x3_copy = mat3x3;
    auto mat4x3_copy = mat4x3;
    auto mat2x4_copy = mat2x4;
    auto mat3x4_copy = mat3x4;
    auto mat4x4_copy = mat4x4;

    test( "Mat2   equality", mat2x2.v1( ) == vec2_1, mat2x2.v2( ) == vec2_2,                                                 mat2x2 == mat2x2_copy );
    test( "Mat3x2 equality", mat3x2.v1( ) == vec2_1, mat3x2.v2( ) == vec2_2, mat3x2.v3( ) == vec2_3,                         mat3x2 == mat3x2_copy );
    test( "Mat4x2 equality", mat4x2.v1( ) == vec2_1, mat4x2.v2( ) == vec2_2, mat4x2.v3( ) == vec2_3, mat4x2.v4( ) == vec2_4, mat4x2 == mat4x2_copy );
    test( "Mat2x3 equality", mat2x3.v1( ) == vec3_1, mat2x3.v2( ) == vec3_2,                                                 mat2x3 == mat2x3_copy );
    test( "Mat3   equality", mat3x3.v1( ) == vec3_1, mat3x3.v2( ) == vec3_2, mat3x3.v3( ) == vec3_3,                         mat3x3 == mat3x3_copy );
    test( "Mat4x3 equality", mat4x3.v1( ) == vec3_1, mat4x3.v2( ) == vec3_2, mat4x3.v3( ) == vec3_3, mat4x3.v4( ) == vec3_4, mat4x3 == mat4x3_copy );
    test( "Mat2x4 equality", mat2x4.v1( ) == vec4_1, mat2x4.v2( ) == vec4_2,                                                 mat2x4 == mat2x4_copy );
    test( "Mat3x4 equality", mat3x4.v1( ) == vec4_1, mat3x4.v2( ) == vec4_2, mat3x4.v3( ) == vec4_3,                         mat3x4 == mat3x4_copy );
    test( "Mat4   equality", mat4x4.v1( ) == vec4_1, mat4x4.v2( ) == vec4_2, mat4x4.v3( ) == vec4_3, mat4x4.v4( ) == vec4_4, mat4x4 == mat4x4_copy );

    mat2x2_copy.v2( ).y( ) = 8;
    mat3x2_copy.v3( ).y( ) = 8;
    mat4x2_copy.v4( ).y( ) = 8;
    mat2x3_copy.v2( ).z( ) = 8;
    mat3x3_copy.v3( ).z( ) = 8;
    mat4x3_copy.v4( ).z( ) = 8;
    mat2x4_copy.v2( ).w( ) = 8;
    mat3x4_copy.v3( ).w( ) = 8;
    mat4x4_copy.v4( ).w( ) = 8;

    test( "Mat2   inequality", mat2x2 != mat2x2_copy );
    test( "Mat3x2 inequality", mat3x2 != mat3x2_copy );
    test( "Mat4x2 inequality", mat4x2 != mat4x2_copy );
    test( "Mat2x3 inequality", mat2x3 != mat2x3_copy );
    test( "Mat3x3 inequality", mat3x3 != mat3x3_copy );
    test( "Mat4x3 inequality", mat4x3 != mat4x3_copy );
    test( "Mat2x4 inequality", mat2x4 != mat2x4_copy );
    test( "Mat3x4 inequality", mat3x4 != mat3x4_copy );
    test( "Mat4x4 inequality", mat4x4 != mat4x4_copy );
}
