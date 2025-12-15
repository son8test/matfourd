#include <testing/vec_alias.hxx>

#define TEST( s )\
test( "Vec" #s " type col-major", Vec##s::size( ), Vec##s::order( ), (unsigned)s, false );\
test( "Col" #s " type col-major", Col##s::size( ), Col##s::order( ), (unsigned)s, false );\
test( "Row" #s " type row-major", Row##s::size( ), Row##s::order( ), (unsigned)s, true );\
Vec##s vec##s;\
Col##s col##s;\
Row##s row##s;\
test( "vec" #s " var col-major", vec##s.size( ), vec##s.order( ), (unsigned)s, false );\
test( "col" #s " var col-major", col##s.size( ), col##s.order( ), (unsigned)s, false );\
test( "row" #s " var row-major", row##s.size( ), row##s.order( ), (unsigned)s, true )

void son8::main( Args ) {
    auto test = []( Msg msg, auto resultSize, auto resultOrder, auto expectSize, auto expectOrder ) {
        if ( resultSize == expectSize && resultOrder == expectOrder ) return;
        err << msg
            << PRINT( resultSize )
            << PRINT( resultOrder )
            << PRINT( expectSize )
            << PRINT( expectOrder )
            << std::endl;
    };

    TEST( 2 );
    TEST( 3 );
    TEST( 4 );

}
