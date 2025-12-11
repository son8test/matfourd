#include <testing/mat_alias.hxx>

int main( ) {
    auto test = []( Msg msg, auto result, auto expect ) {
        if ( result == expect ) return;
        err << msg
            << ", result: " << result
            << ", expect: " << expect
            << std::endl;
    };

    test( "Mat2x2 cols", Mat2x2::cols( ), 3 );
}
