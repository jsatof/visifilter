from os import environ

optimization_flag = "-g" if int(ARGUMENTS.get("debug", 1)) else "-O2"
env_options = {
    "CC": "clang",
    "CXX": "clang++",
    "LD": "clang++",
    "CXXFLAGS": ["-std=c++23", "-Wall", "-Wextra", "-fdiagnostics-color=always", optimization_flag],
    "CPPPATH": [GetLaunchDir() + "/src", GetLaunchDir() + "/src/thirdparty"],
    "LIBPATH": [],
    "LIBS": ["fmt"],

    # for msys
    "platform": "posix",
    "ENV": environ,
}
env = Environment(**env_options)

SConscript("src/SConscript", variant_dir="build", exports="env", duplicate=False)
