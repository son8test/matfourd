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

inline auto &err = std::cout;
inline Failed failed;

#endif
