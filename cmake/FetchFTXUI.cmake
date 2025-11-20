include(FetchContent)

FetchContent_Declare(
    ftxui
    GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI.git
    GIT_TAG main          # or GIT_TAG v5.0.0 for a stable release
)

FetchContent_MakeAvailable(ftxui)
