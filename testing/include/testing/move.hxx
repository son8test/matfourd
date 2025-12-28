#include <testing/mat_alias.hxx>

#define TESTING_DESTRUCT 0xFA1105
#define TESTING_COPYABLE 0x64
#define TESTING_MOVEABLE 0x8
#define TESTING_CREATING 0x1

class Move final {
    int testing_{ TESTING_CREATING };
public:
    using CopyType = Move &;
    using MoveType = Move &&;
    Move( ) = default;
   ~Move( ) { testing_ = TESTING_DESTRUCT; };
    operator int( ) noexcept { return testing_; }
    Move( CopyType copy ) noexcept : testing_{ copy.testing_ } { copy.testing_ = TESTING_COPYABLE; }
    Move( MoveType move ) noexcept : testing_{ move.testing_ } { move.testing_ = TESTING_MOVEABLE; }

    void operator=( MoveType ) = delete;
    void operator=( CopyType ) = delete;
};

