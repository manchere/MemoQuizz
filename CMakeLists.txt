cmake_minimum_required(VERSION 3.20) #Require at least CMake 3.20

project(MemoQuizz VERSION 1.0 ) #Set the project name and version

set(CMAKE_CXX_STANDARD) #Set the C++ standard to use

set(CMAKE_CXX_STANDARD_REQUIRED True) #Require the standard

if(NOT CMAKE_TOOLCHAIN_FILE) #If no toolchain file is set
	set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/emscripten.cmake" CACHE STRING "Emscripten toolchain file")
endif()

#Add source files
set(SOURCES 
	src/main.cpp
	src/question.cpp
	src/helper.cpp
	src/quizzmanager.cpp
)

qt_add_qml_module(memoQuizzApp
	URI MemoQuizz
	VERSION 1.0
	QML_FILES main.qml QuizzManager.qml QuizzPage.qml
)

target_link_libraries(memoQuizzApp
	PRIVATE Qt6::Quick
)

#create executable target
add_executable(memo_quizz ${SOURCES})

set_target_properties(memo_quizz PROPERTIES 
	OUTPUT_NAME "memo_quizz"
	SUFFIX ".html" #generate html file
)

# Emscripten-specific flags for WebAssembly
target_compile_options(memo_quizz PRIVATE
	"-s WASM=1"                     # Enable WebAssembly output
    "-s EXPORTED_FUNCTIONS=['_main']" # Exported functions
    "-s EXTRA_EXPORTED_RUNTIME_METHODS=['ccall', 'cwrap']"
)

# enable optimizations for smaller file size
if(CMAKE_BUILD_TYPE STREQUAL "Release")
	target_compile_options(memo_quizz PRIVATE "-O3")
endif()

#Copy the output to a deployment folder
add_custom_command(TARGET memo_quizz POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E make_directory ${DEPLOY_DIR}
	COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:memo_quizz> ${DEPLOY_DIR}/
)

#Optionally, enable optimizations for smaller file size
if(CMAKE_BUILD_TYPE STREQUAL "Release")
	target_compile_options(memo_quizz PRIVATE "-Oz") #Optimize for size
endif()

# Copy the output to a deployment folder
set(DEPLOY_DIR "${CMAKE_BINARY_DIR}/deploy")}
add_custom_command(TARGET memo_quizz POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E make_directory ${DEPLOY_DIR}
	COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:memo_quizz> ${DEPLOY_DIR}/
)