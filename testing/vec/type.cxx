#include <testing/vec_alias.hxx>
#include <son8/matfourd/vec/type.hxx>
#include <son8/matfourd/vec/equality.hxx>
#include <son8/matfourd/print.hxx>

void son8::main( Args ) {
    auto test = []( Msg msg, auto result, auto expect ) {
        if ( result == expect ) return;
        err << msg
            << PRINT( result )
            << PRINTEND( expect );
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

    vec2 = { 1, 2 };
    test( "vec2 x", vec2.x( ), 1 );
    test( "vec2 y", vec2.y( ), 2 );
    vec3 = { 1, 2, 4 };
    test( "vec3 x", vec3.x( ), 1 );
    test( "vec3 y", vec3.y( ), 2 );
    test( "vec3 z", vec3.z( ), 4 );
    vec4 = { 1, 2, 4, 8 };
    test( "vec4 x", vec4.x( ), 1 );
    test( "vec4 y", vec4.y( ), 2 );
    test( "vec4 z", vec4.z( ), 4 );
    test( "vec4 w", vec4.w( ), 8 );
}
