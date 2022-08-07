add_rules("mode.debug", "mode.release")

add_requires("sfml")
add_requires("gtest")

target("tinyNES")
    set_kind("binary")
    add_files("src/cpu/*.cpp")
    add_files("src/main.cpp")
    add_packages("sfml")

target("test")
    set_kind("binary")
    add_files("src/cpu/*.cpp")
    add_files("src/test.cpp")
    add_packages("gtest")
    add_packages("sfml")
