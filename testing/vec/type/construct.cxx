#include <testing/vec_alias.hxx>
#include <son8/matfourd/vec/type.hxx>
#include <son8/matfourd/vec/equality.hxx>
#include <son8/matfourd/print.hxx>
// std
#include <array>

void son8::main( Args ) {
    auto test = []( Msg msg, auto result, auto expect ) {
        if ( result == expect && result == ~expect ) return;
        err << msg
            << PRINT( result )
            << PRINTEND( ~expect );
    };

    using Type = int const;
    Type x = 1, y = 2;

    using Arr2 = std::array< int, 2 >;

    Col2 vecColCB{ x, y }, vecColRB( x, y );
    Row2 vecRowCB{ x, y }, vecRowRB( x, y );
    Arr2 vecArrCB{ x, y }, vecArrRB({x, y});
    // TODO commented out construct tests that does not work on old compilers
    //      uncomment when workaround savior appear
    // HONORABLE mention, construct ({x,y}) shouldn't work at all for reasons
    Col2 vecUnused [[maybe_unused]]
        // , vec1{ { x, y } }//,vec2({{ x, y }})
        , vec3{ vecColCB }, vec4( vecColRB )
        , vec5{ vecRowCB }, vec6( vecRowRB )
        , vec7{ vecArrCB }, vec8( vecArrRB )
    ;

    Row2 expect{ x, y };

    //test( "Vec val curly braces", vec1, expect );
    //test( "Vec val round braces", vec2, expect );
    test( "Vec col curly braces", vec3, expect );
    test( "Vec col round braces", vec4, expect );
    test( "Vec row curly braces", vec5, expect );
    test( "Vec row round braces", vec6, expect );
    test( "Vec arr curly braces", vec7, expect );
    test( "Vec arr round braces", vec8, expect );
}
