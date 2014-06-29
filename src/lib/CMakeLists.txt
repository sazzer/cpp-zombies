PROJECT (ZOMBIES_LIB)

FILE(GLOB_RECURSE Sources "main/*.cpp")
FILE(GLOB_RECURSE Tests "test/*.cpp")

ADD_LIBRARY(zombies_lib STATIC ${Sources})
add_cppcheck(zombies_lib)

INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}")
INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}")

STRING(REPLACE ";" " " TestsAsString "${Tests}")
IF (NOT "${TestsAsString}" STREQUAL "")
    ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)

    ADD_EXECUTABLE(lib_test ${Tests})
    TARGET_LINK_LIBRARIES(lib_test ${Boost_LIBRARIES})
    TARGET_LINK_LIBRARIES(lib_test zombies_lib)

    ENABLE_TESTING()
    ADD_TEST(ZOMBIES_LIB lib_test)
ENDIF()
