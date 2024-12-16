set(CMAKE_CXX_FLAGS_INIT "-Wall -Wextra -std=c++23 -stdlib=libc++ -I~/.local/include --rtlib=compiler-rt")
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-g")
set(CMAKE_CXX_FLAGS_MINSIZEREL_INIT "-Werror -Wextra -Os -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Werror -Wextra -O3 -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO_INIT "-Og")
set(CMAKE_EXE_LINKER_FLAGS "-lc++ -latomic")
