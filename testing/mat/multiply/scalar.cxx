#include <testing/mat_alias.hxx>
#include <son8/matfourd/mat/multiply.hxx>
#include <son8/matfourd/mat/equality.hxx>
#include <son8/matfourd/print.hxx>

void son8::main( Args ) {
    auto test = []( Msg msg, auto mat ) {
        m4d::Mat< int, mat.cols( ), mat.rows( ) > expect;
        for ( auto i = 0u; i < mat.size( ); ++i ) *(expect.data( ) + i) = 8;
        auto matXscalar = mat * 8;
        auto scalarXmat = 8 * mat;
        if ( matXscalar == expect && scalarXmat == expect ) return;
        err << msg
            << PRINT( matXscalar )
            << PRINT( scalarXmat )
            << PRINTEND( expect );
    };

    Vec2 vec2{ 1, 1 };
    Vec3 vec3{ 1, 1, 1 };
    Vec4 vec4{ 1, 1, 1, 1 };

    test( "Mat2x2", Mat2x2{ vec2, vec2 } );
    test( "Mat2x3", Mat2x3{ vec3, vec3 } );
    test( "Mat2x4", Mat2x4{ vec4, vec4 } );
    test( "Mat3x2", Mat3x2{ vec2, vec2, vec2 } );
    test( "Mat3x3", Mat3x3{ vec3, vec3, vec3 } );
    test( "Mat3x4", Mat3x4{ vec4, vec4, vec4 } );
    test( "Mat4x2", Mat4x2{ vec2, vec2, vec2, vec2 } );
    test( "Mat4x3", Mat4x3{ vec3, vec3, vec3, vec3 } );
    test( "Mat4x4", Mat4x4{ vec4, vec4, vec4, vec4 } );
}
