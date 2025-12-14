#include <son8/matfourd.hxx>

auto test( ) {
    auto failed = 0ull;

#   ifndef SON8_MATFOURD_CORE_HXX
    failed += 1 << 0;
#   endif

#   ifndef SON8_MATFOURD_LAYOUT_HXX
    failed += 1 << 1;
#   endif

#   ifndef SON8_MATFOURD_MAT_HXX
    failed += 1 << 2;
#   endif

#   ifndef SON8_MATFOURD_MAT_ADDITIVE_HXX
    failed += 1 << 3;
#   endif

#   ifndef SON8_MATFOURD_MAT_ALIAS_HXX
    failed += 1 << 4;
#   endif

#   ifndef SON8_MATFOURD_MAT_ALTER_HXX
    failed += 1 << 5;
#   endif

#   ifndef SON8_MATFOURD_MAT_EQUALITY_HXX
    failed += 1 << 6;
#   endif

#   ifndef SON8_MATFOURD_MAT_MULTIPLY_HXX
    failed += 1 << 7;
#   endif

#   ifndef SON8_MATFOURD_MAT_TYPE_HXX
    failed += 1 << 8;
#   endif

#   ifndef SON8_MATFOURD_PRINT_HXX
    failed += 1 << 9;
#   endif

#   ifndef SON8_MATFOURD_STATIC_HXX
    failed += 1 << 10;
#   endif

#   ifndef SON8_MATFOURD_VEC_HXX
    failed += 1 << 11;
#   endif

#   ifndef SON8_MATFOURD_VEC_ADDITIVE_HXX
    failed += 1 << 12;
#   endif

#   ifndef SON8_MATFOURD_VEC_ALIAS_HXX
    failed += 1 << 13;
#   endif

#   ifndef SON8_MATFOURD_VEC_EQUALITY_HXX
    failed += 1 << 14;
#   endif

#   ifndef SON8_MATFOURD_VEC_MULTIPLY_HXX
    failed += 1 << 15;
#   endif

#   ifndef SON8_MATFOURD_VEC_SWIZZLES_HXX
    failed += 1 << 16;
#   endif

#   ifndef SON8_MATFOURD_VEC_TYPE_HXX
    failed += 1 << 17;
#   endif

    return failed;
}

#include <testing/core.hxx>
#include <array>

std::array< Msg, 18 > errors{{
    "core", "layout", "mat",
    "mat/additive", "mat/alias", "mat/alter", "mat/equality", "mat/multiply", "mat/type",
    "print", "static", "vec",
    "vec/additive", "vec/alias", "vec/equality", "vec/multiply", "vec/swizzles", "vec/type"
}};

void son8::main( Args ) {
    auto testFailed = test( );
    if ( not testFailed ) return;
    err << "Headers guads for: [";
    auto f = testFailed;
    for ( auto msg : errors ) {
        if ( f & 1 ) err << " " << msg;
        f >>= 1;
    }
    err << " ] are not included or properly named" << PRINTEND( testFailed );
}







