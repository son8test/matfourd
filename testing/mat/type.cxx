#include <son8/matfourd/mat/type.hxx>
#include <son8/matfourd/mat/alias.hxx>
#include <son8/matfourd/mat/equality.hxx>
#include <son8/matfourd/print.hxx>
// std
#include <iostream>

#define VEC2_0 { 0, 0 }
#define VEC3_0 { 0, 0, 0 }
#define VEC4_0 { 0, 0, 0, 0 }

namespace m4d = son8::matfourd;

int main( ) {
    using Msg = char const *;
    using Type = int;
    using Mat2x2 = m4d::Mat2< Type >;
    using Mat2x3 = m4d::Mat2x3< Type >;
    using Mat2x4 = m4d::Mat2x4< Type >;
    using Mat3x2 = m4d::Mat3x2< Type >;
    using Mat3x3 = m4d::Mat3< Type >;
    using Mat3x4 = m4d::Mat3x4< Type >;
    using Mat4x2 = m4d::Mat4x2< Type >;
    using Mat4x3 = m4d::Mat4x3< Type >;
    using Mat4x4 = m4d::Mat4< Type >;

    int failed{ };
    auto test = [&failed]( Msg msg, auto result, auto expect ) {
        auto &err = std::cerr;
        if ( result == expect ) return;
        ++failed;
        err << msg
            << ", result: " << result
            << ", expect: " << expect
            << std::endl;
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

    if ( failed ) return 1;
}
