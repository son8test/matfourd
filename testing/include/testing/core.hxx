#ifndef SON8TEST_TESTING_CORE_HXX
#define SON8TEST_TESTING_CORE_HXX

#include <son8/main.hxx>

#include <iostream>

#define PRINT( v ) ", " #v ": " << v
#define PRINTEND( v ) ", " #v ": " << v << std::endl

namespace son8::matfourd { }
namespace m4d = son8::matfourd;

using Msg = char const *;

struct Failed final {
    Failed( ) { son8::exit = son8::Exit::Success; }
    void operator()( ) { son8::exit = son8::Exit::Failure; }
};

struct RemoveThisFailed {
    void operator()( ) { }
};

class Error final {
    Failed failed{ };
public:
    template< typename Type >
    Error &operator<<( Type const &type ) {
        failed( );
        std::cerr << type;
        return *this;
    }

    Error &operator<<( std::ostream &(*manip)(std::ostream&) ) {
        failed( );
        manip( std::cerr );
        return *this;
    }
};

inline Error err;

#endif
