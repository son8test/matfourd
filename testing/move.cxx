#include <testing/move.hxx>
#include <son8/matfourd/vec.hxx>
#include <son8/matfourd/mat.hxx>
#include <son8/matfourd/print.hxx>
#include <utility>

#define VEC2( x ) Vec2{ x, x }
#define MAT2( x ) Mat2x2{ { x, x }, { x, x } }

void son8::main( Args ) {
    auto test = []( Msg msg, auto result, auto expect ) {
        if ( result == expect ) return;
        err << msg
            << PRINT( result )
            << PRINTEND( expect );
    };
    // vec
    using Vec = m4d::Vec< Move, 2 >;
    Vec *volatile vp;
    {
        Vec vec;
        vp = &vec;
        test( "vec after creating", Vec2{ vec.x( ), vec.y( ) }, VEC2( TESTING_CREATING ) );
        Vec vec2{ std::move( vec ) };
        test( "vec after it moved", Vec2{ vec.x( ), vec.y( ) }, VEC2( TESTING_MOVEABLE ) );
        Vec vec3{ vec };
        test( "vec after its copy", Vec2{ vec.x( ), vec.y( ) }, VEC2( TESTING_COPYABLE ) );
    }
    test( "vec after it destructs", Vec2{ vp->x( ), vp->y( ) }, VEC2( TESTING_DESTRUCT ) );
    // mat
    using Mat = m4d::Mat2< Move >;
    Mat *volatile mp;
    {
        Mat mat;
        mp = &mat;
        test( "mat after creating", Mat2x2{ Vec2{ mat.v1( ).x( ), mat.v1( ).y( ) }, Vec2{ mat.v2( ).x( ), mat.v2( ).y( ) } }, MAT2( TESTING_CREATING ) );
        Mat mat2{ std::move( mat ) };
        test( "mat after it moved", Mat2x2{ Vec2{ mat.v1( ).x( ), mat.v1( ).y( ) }, Vec2{ mat.v2( ).x( ), mat.v2( ).y( ) } }, MAT2( TESTING_MOVEABLE ) );
        Mat mat3{ mat };
        test( "mat after its copy", Mat2x2{ Vec2{ mat.v1( ).x( ), mat.v1( ).y( ) }, Vec2{ mat.v2( ).x( ), mat.v2( ).y( ) } }, MAT2( TESTING_COPYABLE ) );
    }
    test( "mat after it destructs", Mat2x2{ Vec2{ mp->v1( ).x( ), mp->v1( ).y( ) }, Vec2{ mp->v2( ).x( ), mp->v2( ).y( ) } }, MAT2( TESTING_DESTRUCT ) );
}
