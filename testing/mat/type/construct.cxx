#include <testing/mat_alias.hxx>
#include <son8/matfourd/mat/type.hxx>
#include <son8/matfourd/mat/equality.hxx>
#include <son8/matfourd/print.hxx>
// std
#include <array>

void son8::main( Args ) {
    auto test = []( Msg msg, auto result, auto expect ) {
        if ( result == expect && result == ~expect ) return;
        err << msg
            << PRINT( result )
            << PRINTEND(~expect );
    };

    using Type = Vec2 const;
    Type v12{ 1, 2 }, v13{ 1, 3 }, v24{ 2, 4 }, v34{ 3, 4 };

    Col2x2 matColCB{ v12, v34 }, matColRB( v12, v34 );
    Row2x2 matRowCB{~v13,~v24 }, matRowRB(~v13,~v24 );
    Col2x2 matColCI{ { 1, 2 }, { 3, 4 } }, matColRI( { 1, 2 }, { 3, 4 } );
    Row2x2 matRowCI{ { 1, 3 }, { 2, 4 } }, matRowRI( { 1, 3 }, { 2, 4 } );

    test( "Mat col, vec and val curly braces\n", matColCI, matColCB );
    test( "Mat row, vec and val round braces\n", matRowCI, matRowCB );

    using Arr2x2 = std::array< Vec2, 2 >;
    Arr2x2 matArrCB{ v12, v34 }, matArrRB({v12, v34});

    Col2x2 matUnused [[maybe_unused]]
        , mat1{{v12, v34}}, mat2({{v12, v34}})
        , mat3{ matColCB }, mat4(  matColRB  )
        , mat5{ matRowCB }, mat6(  matColRB  )
        , mat7{ matArrCB }, mat8( {matArrRB} )
    ;

    Row2x2 expect{~v13,~v24 };

    test( "Mat vec curly braces", mat1, expect );
    test( "Mat vec round braces", mat2, expect );
    test( "Mat col curly braces", mat3, expect );
    test( "Mat col round braces", mat4, expect );
    test( "Mat row curly braces", mat5, expect );
    test( "Mat row round braces", mat6, expect );
    test( "Mat arr curly braces", mat7, expect );
    test( "Mat arr round braces", mat8, expect );
}
