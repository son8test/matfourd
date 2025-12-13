#include <testing/core.hxx>
#include <son8/matfourd/layout.hxx>

void son8::main( Args ) {
    std::cerr << std::boolalpha;
    if ( m4d::Layout::ColMajor != false ) err << "Layout Col-Major should be equal false" << PRINTEND( m4d::Layout::ColMajor );
    if ( m4d::Layout::RowMajor != true  ) err << "Layout Row-Major should be equal true"  << PRINTEND( m4d::Layout::RowMajor );
}
