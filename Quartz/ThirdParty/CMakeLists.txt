cmake_minimum_required(VERSION 3.0)

project(QuartzDependencies)

include(CMakeAddToFolder)

option(LIBC "..." ON)


if(NOT EXISTS ${CMAKE_CURRENT_LIST_DIR}/luamod/include)
	message("It seems like the Git Submodules have not been initialised and cloned, they will now be initialised and cloned as required.")
	execute_process(COMMAND git submodule update --init
			WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	)
endif()

add_subdirectory_with_folder("QuartzDependencies/Lua" luamod)

set_target_properties(buildvm liblua luajit minilua PROPERTIES FOLDER QuartzDependencies/Lua/LuaJIT)

if (WIN32)
	set_target_properties(wluajit PROPERTIES FOLDER QuartzDependencies/Lua/LuaJIT)
endif()

add_subdirectory_with_folder("QuartzDependencies/SDL" SDL2)
add_subdirectory_with_folder("QuartzDependencies/Graphics" glad)
add_subdirectory_with_folder("QuartzDependencies/Graphics" imgui)
