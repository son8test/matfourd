#include <testing/vec_alias.hxx>
#include <son8/matfourd/vec/multiply.hxx>
#include <son8/matfourd/vec/equality.hxx>
#include <son8/matfourd/print.hxx>

int main( ) {
    auto test = []( Msg msg, auto l, auto r, auto expect ) {
        auto lr = l * r;
        auto rl = r * l;
        if ( lr == rl && lr == expect && rl == expect ) return;
        failed( );
        err << msg
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
}
