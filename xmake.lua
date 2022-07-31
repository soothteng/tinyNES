add_rules("mode.debug", "mode.release")

add_requires("sfml")

target("tinyNES")
    set_kind("binary")
    add_files("src/*.cpp")
    set_toolchains("clang")
    add_packages("sfml")
