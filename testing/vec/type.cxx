#include <testing/vec_alias.hxx>
#include <son8/matfourd/vec/type.hxx>
#include <son8/matfourd/vec/equality.hxx>
#include <son8/matfourd/print.hxx>

void son8::main( Args const & ) {
    auto test = []( Msg msg, auto result, auto expect ) {
        if ( result == expect ) return;
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
}
