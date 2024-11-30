# CMakeList.txt : CMake project for Cyclon, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Cyclon "Cyclon.cpp" "Lexer/Token.h" "Lexer/TokenType.h" "Lexer/Lexer.h" "Lexer/IsNumber.h" "Lexer/IsAlphabetical.h" "Lexer/IsSkippable.h" "Parser/Parser.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Cyclon PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
