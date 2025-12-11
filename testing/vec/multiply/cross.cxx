#include <testing/vec_alias.hxx>
#include <son8/matfourd/vec/multiply.hxx>
#include <son8/matfourd/vec/equality.hxx>

void son8::main( Args const & ) {
    using Vec = Vec3;

    auto result = Vec{ 1,-1, 0 } ^ Vec{ 8, 0,-8 };
    auto expect = Vec{ 8, 8, 8 };

    exit = not ( result == expect );
}
