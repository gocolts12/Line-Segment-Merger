cmake_minimum_required(VERSION 3.14)
project(take_home_test)

set(CMAKE_CXX_STANDARD 14)

# needed by RapidJSON
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -DGTEST_HAS_POSIX_RE=0")

if (WIN32)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif()

include_directories(include)
include_directories(include/rapidjson)
include_directories(include/rapidjson/error)
include_directories(include/rapidjson/internal)
include_directories(include/take_home_test)

# Your library sources go here
set(LIBRARY_SOURCES source/deserialize.cpp source/linesegment.cpp source/merge.cpp )
set(LIBRARY_HEADERS include/take_home_test/deserialize.h include/take_home_test/merge.h include/take_home_test/linesegment.h )

add_library(take_home_test_library ${LIBRARY_SOURCES} ${LIBRARY_HEADERS}) 

# exec sources go here
set(EXEC_SOURCES source/main.cpp)

add_executable(take_home_test ${EXEC_SOURCES} ${take_home_test_library}) 
target_link_libraries(take_home_test take_home_test_library)

# Tests
enable_testing()

# Your tests
set(TEST_SOURCES test/tests.cpp)

add_executable(unit_tests ${TEST_SOURCES} ${LIBRARY_SOURCES} ${LIBRARY_HEADER})

target_link_libraries(unit_tests take_home_test_library)

add_test(unit_tests unit_tests)