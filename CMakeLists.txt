cmake_minimum_required( VERSION 3.14...3.27 )
project( son8test VERSION 0.0.0 LANGUAGES CXX )

set( SON8PROJ son8__${PROJECT_NAME} )

set( TESTUSER soneight CACHE STRING "FetchContent user andor organization" )
set( TESTREPO matfourd CACHE STRING "FetchContent GIT_REPOSITORY project!" )
set( TESTHASH 7ed6d13aff1416cd171cc832ac8deec6f65abcd6 CACHE STRING "FetchContent GIT_TAG hash andor tag!" )

include( FetchContent )

if ( NOT ${TESTREPO} STREQUAL "testrepo" AND NOT ${TESTHASH} STREQUAL "testhash" )
    add_subdirectory( source )
else( )
    message( WARNING " set variables `TESTREPO` andor `TESTHASH` are not overridden! " )
endif( )

enable_testing()
add_subdirectory( testing )
