#include <testing/mat_alias.hxx>
#include <son8/matfourd/print.hxx>
// std
#include <sstream>
#include <string_view>

void son8::main( Args ) {
    auto test = []( Msg msg, auto data, std::string_view expect ) {
        std::stringstream ss;
        ss << data;
        auto result = ss.str( );
        if ( result == expect ) return;
        err << msg
            << PRINT( result )
            << PRINTEND( expect );
    };

    test( "print Vec2 Col-Major", Vec2{ },  "Vec2[0, 0]" );
    test( "print Vec2 Row-Major",~Vec2{ }, "~Vec2[0, 0]" );
    test( "print Mat2 Col-Major", Mat2x2{ }, "\nMat2x2{\n\tVec2[0, 0],\n\tVec2[0, 0]\n}" );
    test( "print Mat2 Row-Major",~Mat2x2{ }, "\n~Mat2x2{\n\t~Vec2[0, 0],\n\t~Vec2[0, 0]\n}" );
}
