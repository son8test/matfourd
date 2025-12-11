#include <testing/vec_alias.hxx>
#include <son8/matfourd/vec/swizzles.hxx>
#include <son8/matfourd/vec/equality.hxx>
#include <son8/matfourd/print.hxx>

void son8::main( Args const & ) {
    auto test = []( Msg msg, auto vec, auto swiz, auto expect ) {
        auto result = vec/swiz;
        if ( result == expect ) return;
        failed( );
        err << msg
            << ", vec: " << vec
            << ", vec/swiz: " << result
            << ", expect: " << expect
            << std::endl;
    };

    Vec2 vec2{ 0, 3 };
    Vec3 vec3{ 4, 5, 6 };
    Vec4 vec4{ 1, 2, 4, 8 };

    using namespace m4d::swizzles;
    // same
    test( "vec2/xy"  , vec2, xy, vec2 );
    test( "vec3/xyz" , vec3, xyz, vec3 );
    test( "vec4/xyzw", vec4, xyzw, vec4 );
    // 1,2,3,4 sum 8
    test( "vec2/yyyy", vec2, yyyy, Vec4{ 3, 3, 3, 3 } );
    test( "vec3/yyz" , vec3, yyz , Vec3{ 5, 5, 6 } );
    test( "vec4/ww"  , vec4, ww  , Vec2{ 8, 8 } );
    test( "vec4/xzw" , vec4, xzw , Vec3{ 1, 4, 8 } );
    test( "vec4/yyw" , vec4, yyw , Vec3{ 2, 2, 8 } );
}
