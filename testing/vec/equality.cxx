#include <testing/vec_alias.hxx>
#include <son8/matfourd/vec/equality.hxx>

void son8::main( Args const & ) {
    auto test = []( char const *msg, auto ...args ) {
        bool all = ( true && ... && args );
        if ( all ) return;
        err << msg << std::endl;
    };

    Vec2 vec2{ 0, 1 };
    Vec3 vec3{ 2, 3, 4 };
    Vec4 vec4{ 5, 6, 7, 8 };

    auto vec2_copy = vec2;
    auto vec3_copy = vec3;
    auto vec4_copy = vec4;

    test( "vec2 equality", vec2.x( ) == 0, vec2.y( ) == 1, vec2 == vec2_copy );
    test( "vec3 equality", vec3.x( ) == 2, vec3.y( ) == 3, vec3.z( ) == 4, vec3 == vec3_copy );
    test( "vec4 equality", vec4.x( ) == 5, vec4.y( ) == 6, vec4.z( ) == 7, vec4.w( ) == 8, vec4 == vec4_copy );

    vec2_copy.x( ) = 8;
    vec3_copy.y( ) = 8;
    vec4_copy.z( ) = 8;

    test( "vec2 x inequality", vec2 != vec2_copy );
    test( "vec3 y inequality", vec3 != vec3_copy );
    test( "vec4 z inequality", vec4 != vec4_copy );
}
