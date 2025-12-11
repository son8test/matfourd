#include <testing/vec_alias.hxx>
#include <son8/matfourd/vec/additive.hxx>
#include <son8/matfourd/vec/equality.hxx>
#include <son8/matfourd/print.hxx>

void son8::main( Args const & ) {
    Vec2 l2{ 0, 1 }, r2{ 8, 7 }, plus2{ 8, 8 }, minus2{ -8, -6 };
    Vec3 l3{ 2, 3, 4 }, r3{ 6, 5, 4 }, plus3{ 8, 8, 8 }, minus3{ -4, -2, 0 };
    Vec4 l4{ 5, 6, 7, 8 }, r4{ 3, 2, 1, 0 }, plus4{ 8, 8, 8, 8 }, minus4{ 2, 4, 6, 8 };

    auto test = []( Msg msg, auto l, auto r, auto expect, bool minus ) {
        auto lr = ( minus ) ? l - r : l + r;
        auto rl = ( minus ) ? (-r) - (-l) : (+r) + (+l);
        if ( lr == rl && lr == expect && rl == expect ) return;
        err << msg
            << ", l: " << l
            << ", r: " << r
            << ", expect: " << expect
            << ", result lr: " << lr
            << ", result rl: " << rl
            << std::endl;
    };

    constexpr bool plus = false;
    constexpr bool minus = true;

    test( "vec2 + vec2", l2, r2, plus2, plus );
    test( "vec3 + vec3", l3, r3, plus3, plus );
    test( "vec4 + vec4", l4, r4, plus4, plus );

    test( "vec2 - vec2", l2, r2, minus2, minus );
    test( "vec3 - vec3", l3, r3, minus3, minus );
    test( "vec4 - vec4", l4, r4, minus4, minus );
}
