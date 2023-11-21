cmake_minimum_required(VERSION 3.5)

project(Scorp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(.)

execute_process(COMMAND bash -c "cp ${CMAKE_CURRENT_SOURCE_DIR}/db.sqlite3 ${CMAKE_CURRENT_BINARY_DIR}")
find_package(Crow CONFIG REQUIRED)
find_package(SQLite3 REQUIRED)

add_executable(Scorp main.cpp
    models/user.h models/user.cpp
    models/post.h models/post.cpp
    models/follow.h models/follow.cpp
    models/like.h models/like.cpp
    controllers/controller.h controllers/controller.cpp)
target_link_libraries(Scorp PUBLIC Crow::Crow SQLite::SQLite3)
include(GNUInstallDirs)
install(TARGETS Scorp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
