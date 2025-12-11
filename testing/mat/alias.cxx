#include <testing/mat_alias.hxx>
#include <son8/main.hxx>

#define TEST( c, r )\
test("Mat" #c "x" #r " col-major", Mat##c##x##r{ }, (unsigned)c, (unsigned)r );\
test("Mat" #c "x" #r " row-major",~Mat##c##x##r{ }, (unsigned)c, (unsigned)r );\
Mat##c##x##r mat##c##x##r{ };\
test("mat" #c "x" #r " col-major", mat##c##x##r, (unsigned)c, (unsigned)r );\
test("mat" #c "x" #r " row-major",~mat##c##x##r, (unsigned)c, (unsigned)r )

void son8::main( Args const & ) {
    auto test = []( Msg msg, auto mat, auto ecols, auto erows ) {
        auto cols = mat.cols( ), rows = mat.rows( );
        if ( cols == ecols && rows == erows ) return;
        err << msg
            << ", result cols: " << cols
            << ", result rows: " << rows
            << ", expect cols: " << ecols
            << ", expect rows: " << erows
            << std::endl;
    };

    TEST( 2, 2 );
    TEST( 2, 3 );
    TEST( 2, 4 );
    TEST( 3, 2 );
    TEST( 3, 3 );
    TEST( 3, 4 );
    TEST( 4, 2 );
    TEST( 4, 3 );
    TEST( 4, 4 );
}
