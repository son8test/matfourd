#ifndef SON8TEST_TESTING_CORE_HXX
#define SON8TEST_TESTING_CORE_HXX

#include <son8/main.hxx>

#include <iostream>
#include <cstdlib>

namespace son8::matfourd { }
namespace m4d = son8::matfourd;

using Msg = char const *;

class Failed final {
    static inline bool status_{ EXIT_SUCCESS };
public:
    // TODO do better?
    //Failed( ) { std::atexit( []{ std::exit( status_ ); } ); }
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
inline RemoveThisFailed failed;

#endif
