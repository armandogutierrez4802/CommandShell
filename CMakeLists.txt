CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(rshell
    src/main.cpp
    src/connectors.cpp
    src/or.cpp
    src/and.cpp
    src/semicolon.cpp
    src/executable.cpp
    src/input.cpp
    
)

ADD_EXECUTABLE(test
    unit_tests/test.cpp
    src/connectors.cpp
    src/or.cpp
    src/and.cpp
    src/semicolon.cpp
    src/executable.cpp
    src/input.cpp
)

ADD_Executable(integration
    src/integration.cpp
    src/or.cpp
    src/and.cpp
    src/semicolon.cpp
    src/executable.cpp
    src/input.cpp
    src/connectors.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
