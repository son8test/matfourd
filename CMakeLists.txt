cmake_minimum_required( VERSION 3.14...3.27 )
project( son8test VERSION 0.0.0 LANGUAGES CXX )

set( SON8PROJ son8__${PROJECT_NAME} )

set( TESTUSER soneight CACHE STRING "FetchContent user andor organization" )
set( TESTREPO matfourd CACHE STRING "FetchContent GIT_REPOSITORY project!" )
set( TESTHASH ff5f91c1d451e5e3d1304b6d0246245417210149 CACHE STRING "FetchContent GIT_TAG hash andor tag!" )

include( FetchContent )

if ( NOT ${TESTREPO} STREQUAL "testrepo" AND NOT ${TESTHASH} STREQUAL "testhash" )
    add_subdirectory( source )
else( )
    message( WARNING " set variables `TESTREPO` andor `TESTHASH` are not overridden! " )
endif( )

enable_testing()
add_subdirectory( testing )
