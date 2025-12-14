#include <testing/core.hxx>
#include <son8/matfourd/core.hxx>

#if !defined( SON8_MATFOURD_FUNC ) || !defined( SON8_MATFOURD_DISC )
#define TESTING_TEST_CORE_FAILED
#endif

void son8::main( Args ) {
#ifdef TESTING_TEST_CORE_FAILED
    err << "SON8_MATFOURD_FUNC or SON8_MATFOURD_DISC is not defined";
#endif
}
