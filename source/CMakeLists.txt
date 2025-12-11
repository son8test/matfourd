set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )

FetchContent_Declare(
    son8__${TESTREPO}
    GIT_REPOSITORY https://github.com/${TESTUSER}/${TESTREPO}.git
    GIT_TAG        ${TESTHASH}
)
FetchContent_MakeAvailable( son8__${TESTREPO} )

FetchContent_Declare(
    son8__mainland
    GIT_REPOSITORY https://github.com/soneight/mainland.git
    GIT_TAG        main
)
FetchContent_MakeAvailable( son8__mainland )
