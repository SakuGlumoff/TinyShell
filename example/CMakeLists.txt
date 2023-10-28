cmake_minimum_required(VERSION 3.22.1)

project(TinyShellExample)

enable_language(C)

add_executable(${CMAKE_PROJECT_NAME})

target_sources(${CMAKE_PROJECT_NAME} PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/example.c
	${CMAKE_CURRENT_SOURCE_DIR}/../src/TinyShell.c
)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/..
)
