#include <testing/mat_alias.hxx>
#include <son8/main.hxx>

#define TEST( c, r )\
test("Mat" #c "x" #r " col-major", Mat##c##x##r{ }, (unsigned)c, (unsigned)r, false );\
test("Mat" #c "x" #r " row-major",~Mat##c##x##r{ }, (unsigned)c, (unsigned)r, true );\
test("Col" #c "x" #r " col-major", Col##c##x##r{ }, (unsigned)c, (unsigned)r, false );\
test("Row" #c "x" #r " row-major", Row##c##x##r{ }, (unsigned)c, (unsigned)r, true );\
Mat##c##x##r mat##c##x##r{ };\
Col##c##x##r col##c##x##r{ };\
Row##c##x##r row##c##x##r{ };\
test("mat" #c "x" #r " col-major", mat##c##x##r, (unsigned)c, (unsigned)r, false );\
test("mat" #c "x" #r " row-major",~mat##c##x##r, (unsigned)c, (unsigned)r, true );\
test("col" #c "x" #r " col-major", col##c##x##r, (unsigned)c, (unsigned)r, false );\
test("row" #c "x" #r " row-major", row##c##x##r, (unsigned)c, (unsigned)r, true )

void son8::main( Args ) {
    auto test = []( Msg msg, auto mat, auto ecols, auto erows, bool eorder ) {
        auto cols = mat.cols( ), rows = mat.rows( );
        bool order = mat.order( );
        if ( cols == ecols && rows == erows && order == eorder ) return;
        err << msg
            << ", result cols: " << cols
            << ", result rows: " << rows
            << ", result order: " << order
            << ", expect cols: " << ecols
            << ", expect rows: " << erows
            << ", expect order: " << eorder
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
