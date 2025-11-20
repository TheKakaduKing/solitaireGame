cmake_minimum_required(VERSION 3.20)  # bumped a bit for nicer features
project(solitaireGame LANGUAGES CXX)

# ----------------- Settings -----------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Make all the cmake/ helpers visible
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# ----------------- Dependencies -----------------
include(FetchFTXUI)   # ← pulls in FTXUI exactly like you had

# ----------------- Your executable -----------------
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/render.cpp
    src/board.cpp
    # add more files here later, e.g. src/card.cpp src/board.cpp
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE ftxui::component   # you can also use ftxui::screen + ftxui::dom if you want
)

# ----------------- Magic: symlink compile_commands.json to root -----------------
# This makes clangd / nvim LSP happy instantly after git clone
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink
        ${CMAKE_BINARY_DIR}/compile_commands.json
        ${CMAKE_SOURCE_DIR}/compile_commands.json
    COMMENT "Symlinking compile_commands.json to project root for clangd"
)
