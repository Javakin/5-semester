#####################################################
# Template for building RobWork dependent console application
#
# You should edit directly in this file to add extra source 
# files and when configuring your project.  
#####################################################

#
# Test CMake version
#
CMAKE_MINIMUM_REQUIRED(VERSION 2.6.0)

# The name of the project. (EDIT THIS)
PROJECT(UGE1)

# Used to resolve absolute path names
SET(ROOT ${CMAKE_CURRENT_SOURCE_DIR})


# Set the output dir for generated libraries and binaries
IF(MSVC)
	SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${ROOT}" CACHE PATH "Runtime directory" FORCE)
	SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${ROOT}" CACHE PATH "Library directory" FORCE)
	SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${ROOT}" CACHE PATH "Archive directory" FORCE)
ELSE()
	SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${ROOT}" CACHE PATH "Runtime directory" FORCE)
	SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${ROOT}" CACHE PATH "Library directory" FORCE)
	SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${ROOT}" CACHE PATH "Archive directory" FORCE)
ENDIF()

# And now we add any targets that we want
add_executable(readpgmtest readpgmtest.cpp PPMLoader.cpp Image.cpp)


