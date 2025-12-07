#include <son8/matfourd/vec/multiply.hxx>
#include <son8/matfourd/vec/alias.hxx>
#include <son8/matfourd/vec/equality.hxx>

namespace m4d = son8::matfourd;

int main( ) {
    using Vec = m4d::Vec< int, 3 >;

    auto result = Vec{ 1,-1, 0 } ^ Vec{ 8, 0,-8 };
    auto expect = Vec{ 8, 8, 8 };

    return not ( result == expect );
}
