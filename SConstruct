#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct")

# For reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

# tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(CPPPATH=[
	"src/",
	"src/player_files/",
	"src/items_files/",
	"src/weapon_files/",
	"src/enemy_files/",
	"src/gamesys_files/"])
sources = (
	Glob("src/*.cpp") +
	Glob("src/player_files/*.cpp") +
	Glob("src/items_files/*.cpp") +
	Glob("src/weapon_files/*.cpp") +
	Glob("src/enemy_files/*.cpp") +
	Glob ("src/gamesys_files/*.cpp") +
	Glob ("src/weapon_files/projectiles/*.cpp"))


plus = Environment()
plus.Replace(CC = "g++")

if env["platform"] == "macos":
    library = env.SharedLibrary(
        "demo/bin/libgdexample.{}.{}.framework/libgdexample.{}.{}".format(
            env["platform"], env["target"], env["platform"], env["target"]
        ),
        source=sources,
    )
else:
    library = env.SharedLibrary(
        "demo/bin/libgdexample{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )

Default(library)
