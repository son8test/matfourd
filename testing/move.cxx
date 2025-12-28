#include <testing/move.hxx>
#include <son8/matfourd/vec.hxx>
#include <son8/matfourd/print.hxx>
#include <utility>

void son8::main( Args ) {
    auto test = []( Msg msg, auto result, auto expect ) {
        if ( result == expect ) return;
        err << msg
            << PRINT( result )
            << PRINTEND( expect );
    };

    using Vec = m4d::Vec< Move, 2 >;
    Vec *volatile ptr;
    {
        Vec vec;
        ptr = &vec;
        test( "vec after creating", Vec2{ vec.x( ), vec.y( ) }, Vec2{ TESTING_CREATING, TESTING_CREATING } );
        Vec vec2{ std::move( vec ) };
        test( "vec after it was moved", Vec2{ vec.x( ), vec.y( ) }, Vec2{ TESTING_MOVEABLE, TESTING_MOVEABLE } );
        Vec vec3{ vec };
        test( "vec after it was copied", Vec2{ vec.x( ), vec.y( ) }, Vec2{ TESTING_COPYABLE, TESTING_COPYABLE } );
    }

    test( "vec after it was destructed", Vec2{ ptr->x( ), ptr->y( ) }, Vec2{ TESTING_DESTRUCT, TESTING_DESTRUCT } );
}
