#include <son8/matfourd/vec/multiply.hxx>
#include <son8/matfourd/vec/equality.hxx>
#include <son8/matfourd/vec/alias.hxx>
#include <son8/matfourd/print.hxx>

#include <iostream>

namespace m4d = son8::matfourd;

int main( ) {
    using Msg = char const *;
    using Vec2 = m4d::Vec2< int >;
    using Vec3 = m4d::Vec3< int >;
    using Vec4 = m4d::Vec4< int >;

    auto failed = 0u;
    auto test = [&failed]( Msg msg, auto l, auto r, auto expect ) {
        auto lr = l * r;
        auto rl = r * l;
        if ( lr == rl && lr == expect && rl == expect ) return;
        ++failed;
        std::cerr << msg
            << ", l: " << l
            << ", r: " << r
            << ", expect: " << expect
            << ", result lr: " << lr
            << ", result rl: " << rl
            << std::endl;
    };

    test( "Vec2 * scalar", Vec2{ 4,-4 }, 2, Vec2{ 8,-8 } );
    test( "Vec3 * scalar", Vec3{ 1, 2, 3 }, 4, Vec3{ 4, 8, 12 } );
    test( "Vec4 * scalar", Vec4{ 1, 2, 4, 8 },-8, Vec4{-8,-16,-32,-64 } );
    if ( failed ) return 1;
}
