#include <son8/matfourd/vec/multiply.hxx>
#include <son8/matfourd/print.hxx>

namespace m4d = son8::matfourd;

int main( ) {
    using Vec2 = m4d::Vec< int, 2 >;
    using Vec3 = m4d::Vec< int, 3 >;
    using Vec4 = m4d::Vec< int, 4 >;
    using Msg = char const *;

    Vec2 l2{ 1, 2 }, r2{ 2, 3 };
    Vec3 l3{ -1, 0, 4 }, r3{ 4, 8, 3 };
    Vec4 l4{ 4, 4, 4, 4 }, r4{ 4, 4, 4, 4 };

    auto failed = 0u;
    auto test = [&failed]( Msg msg, auto l, auto r, auto expect ) {
        auto lr = l * r;
        auto rl = r * l;
        auto lr_L = ~l ^ r;
        auto rl_L = ~r ^ l;
        if ( lr == rl && lr == expect && rl == expect && lr_L == expect && rl_L == expect ) return;
        ++failed;
        std::cout << msg
            << ", l: " << l
            << ", r: " << r
            << ", expect: " << expect
            << ", result lr: " << lr
            << ", result rl: " << rl
            << ", result lr layout-aware: " << lr_L
            << ", result rl layout-aware: " << rl_L
            << std::endl;
    };

    test( "Vec2 * Vec2", l2, r2, 8 );
    test( "Vec3 * Vec3", l3, r3, 8 );
    test( "Vec4 * Vec4", l4, r4, 64 );

    if ( failed ) return 1;
}
