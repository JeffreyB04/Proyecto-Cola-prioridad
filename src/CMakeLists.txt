set(BINARY ${CMAKE_PROJECT_NAME})

# add_executable(ExampleProject main.cpp file1.cpp file1.h)
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp) #simplification

set(SOURCES ${SOURCES} Menu.cpp)

add_executable(${BINARY}_run ${SOURCES} Menu.cpp)

add_library(${BINARY}_lib STATIC ${SOURCES} Menu.cpp)