#ifndef SON8TEST_TESTING_CORE_HXX
#define SON8TEST_TESTING_CORE_HXX

#include <iostream>
#include <cstdlib>

namespace son8::matfourd { }
namespace m4d = son8::matfourd;

using Msg = char const *;

class Failed final {
    bool failed{ };
public:
   ~Failed( ) { if ( failed ) std::exit( EXIT_FAILURE ); }
    void operator()( ) { failed = true; }
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
        manip( std::cout );
        return *this;
    }
};

inline Error err;
// inline auto &err = std::cout;
inline Failed failed;

#endif
