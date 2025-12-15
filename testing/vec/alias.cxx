#include <testing/vec_alias.hxx>

void son8::main( Args ) {
    auto test = []( Msg msg, auto result, auto expect ) {
        if ( result == expect ) return;
        err << msg
            << ", result: " << result
            << ", expect: " << expect
            << std::endl;
    };

    test( "Vec2 type col-major size", Vec2::size( ), 2u );
    test( "Vec3 type col-major size", Vec3::size( ), 3u );
    test( "Vec4 type col-major size", Vec4::size( ), 4u );

    test( "Col2 type col-major size", Col2::size( ), 2u );
    test( "Col3 type col-major size", Col3::size( ), 3u );
    test( "Col4 type col-major size", Col4::size( ), 4u );

    test( "Row2 type col-major size", Row2::size( ), 2u );
    test( "Row3 type col-major size", Row3::size( ), 3u );
    test( "Row4 type col-major size", Row4::size( ), 4u );

    Vec2 vec2; Vec3 vec3; Vec4 vec4;
    Col2 col2; Col3 col3; Col4 col4;
    Row2 row2; Row3 row3; Row4 row4;

    test( "Vec2 var col-major size", vec2.size( ), 2u );
    test( "Vec3 var col-major size", vec3.size( ), 3u );
    test( "Vec4 var col-major size", vec4.size( ), 4u );

    test( "Col2 var col-major size", col2.size( ), 2u );
    test( "Col3 var col-major size", col3.size( ), 3u );
    test( "Col4 var col-major size", col4.size( ), 4u );

    test( "Row2 var col-major size", row2.size( ), 2u );
    test( "Row3 var col-major size", row3.size( ), 3u );
    test( "Row4 var col-major size", row4.size( ), 4u );
}
