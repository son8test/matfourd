#include <son8/matfourd/vec/alias.hxx>

#include <iostream>

namespace m4d = son8::matfourd;

int main( ) {
    using Vec2 = m4d::Vec2< int >;
    using Vec3 = m4d::Vec3< int >;
    using Vec4 = m4d::Vec4< int >;

    auto failed = 0u;

    auto test = [&failed]( char const *msg, bool check ) {
        if ( check ) return;
        ++failed;
        std::cerr << msg << std::endl;
    };

    test( "Vec2 type col-major size", Vec2::size( ) == 2 );
    test( "Vec3 type col-major size", Vec3::size( ) == 3 );
    test( "Vec4 type col-major size", Vec4::size( ) == 4 );

    Vec2 vec2; Vec3 vec3; Vec4 vec4;

    test( "Vec2 var col-major size", vec2.size( ) == 2 );
    test( "Vec3 var col-major size", vec3.size( ) == 3 );
    test( "Vec4 var col-major size", vec4.size( ) == 4 );

    static_assert( Vec2::size( ) == vec2.size( ) );
    static_assert( Vec3::size( ) == vec3.size( ) );
    static_assert( Vec4::size( ) == vec4.size( ) );

    if ( failed ) return 1;
}
