cmake_minimum_required(VERSION 3.21)

project(mysym)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(fmt)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(ExternalAntlr4Cpp)
include_directories(${ANTLR4_INCLUDE_DIRS})
link_directories(${ANTLR4_LIBS})
message(STATUS "antlr4 include=${ANTLR4_INCLUDE_DIRS} ; libs=${ANTLR4_LIBS}")

add_library(mysym OBJECT
    LangBaseListener.cpp
    LangLexer.cpp
    LangListener.cpp
    LangParser.cpp
    AST.cpp
    ASTBuilder.cpp
)
target_link_libraries(mysym antlr4_static fmt::fmt)

add_executable(mysym-tool Main.cpp)
target_link_libraries(mysym-tool mysym)

include_directories(${CMAKE_SOURCE_DIR})
add_subdirectory(tests)