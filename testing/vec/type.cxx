#include <son8/matfourd/vec/type.hxx>
#include <son8/matfourd/vec/alias.hxx>
#include <son8/matfourd/vec/equality.hxx>
#include <son8/matfourd/print.hxx>
// std
#include <iostream>

namespace m4d = son8::matfourd;


int main( ) {
    using Msg = char const *;
    using Vec2 = m4d::Vec2< int >;
    using Vec3 = m4d::Vec3< int >;
    using Vec4 = m4d::Vec4< int >;

    auto failed = 0u;
    auto test = [&failed]( Msg msg, auto result, auto expect ) {
        auto &err = std::cerr;
        if ( result == expect ) return;
        ++failed;
        err << msg
            << ", result: " << result
            << ", expect: " << expect
            << std::endl;
    };

    Vec2 vec2{ };
    Vec3 vec3{ };
    Vec4 vec4{ };

    test( "Vec2{ }", vec2, Vec2{ 0, 0 } );
    test( "Vec3{ }", vec3, Vec3{ 0, 0, 0 } );
    test( "Vec4{ }", vec4, Vec4{ 0, 0, 0, 0 } );

    test( "Vec2 size", vec2.size( ), 2u );
    test( "Vec3 size", vec3.size( ), 3u );
    test( "Vec4 size", vec4.size( ), 4u );

    if ( failed ) return 1;
}
