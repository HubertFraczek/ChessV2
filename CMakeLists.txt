cmake_minimum_required(VERSION 3.13)
project(Chess)

set(CMAKE_CXX_STANDARD 14)

add_executable(ChessV2 src/main.cpp)

set(SOURCE_FILES src/main.cpp src/game/source/Game.cpp src/game/headers/Game.h src/pieces/source/Piece.cpp src/pieces/headers/Piece.h src/pieces/source/Pawn.cpp src/pieces/headers/Pawn.h src/pieces/source/Rook.cpp src/pieces/headers/Rook.h src/pieces/source/Knight.cpp src/pieces/headers/Knight.h src/pieces/source/Bishop.cpp src/pieces/headers/Bishop.h src/pieces/source/Queen.cpp src/pieces/headers/Queen.h src/pieces/source/King.cpp src/pieces/headers/King.h src/pieces/source/FreeSpace.cpp src/pieces/headers/FreeSpace.h src/game/source/Board.cpp src/game/headers/Board.h)
add_executable(Chess ${SOURCE_FILES})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML COMPONENTS system graphics window network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()