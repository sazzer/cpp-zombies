PROJECT (ZOMBIES_ZOMBIES)

FILE(GLOB_RECURSE Sources "main/*.cpp")
FILE(GLOB_RECURSE Tests "test/*.cpp")

ADD_EXECUTABLE(zombies ${Sources})
TARGET_LINK_LIBRARIES(zombies zombies_lib)

STRING(REPLACE ";" " " TestsAsString "${Tests}")
IF (NOT "${TestsAsString}" STREQUAL "")
    ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)

    ADD_EXECUTABLE(zombies_test ${Tests})
    TARGET_LINK_LIBRARIES(zombies_test ${Boost_LIBRARIES})

    ENABLE_TESTING()
    ADD_TEST(ZOMBIES_ZOMBIES zombies_test)
ENDIF()
