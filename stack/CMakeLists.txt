cmake_minimum_required(VERSION 2.8)
set (CMAKE_CXX_STANDARD 14)
# Options. Turn on with 'cmake -Dmyvarname=ON'.
option(test "Build all tests." ON) # Makes boolean 'test' available.

# Make PROJECT_SOURCE_DIR, PROJECT_BINARY_DIR, and PROJECT_NAME available.
set(PROJECT_NAME MyProject)
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "-g -Wall")

# force static runtime libraries for msvc builds
if(MSVC)
  set(variables 
    CMAKE_CXX_FLAGS_DEBUG
    CMAKE_CXX_FLAGS_RELEASE
	CMAKE_CXX_FLAGS_RELWITHDEBINFO
	CMAKE_CXX_FLAGS_MINSIZEREL
  )
  foreach(variable ${variables})
	if(${variable} MATCHES "/MD")
	  string(REGEX REPLACE "/MD" "/MT" ${variable} "${${variable}}")
	endif()
  endforeach()
endif()

# If you want your own include/ directory, set this, and then you can do
# include_directories(${COMMON_INCLUDES}) in other CMakeLists.txt files.
# set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)

################################
# Normal Libraries & Executables
################################
#add_library(libpriority_queue src/priority_queue.cpp)

################################
# Testing
################################
if (test)
  if (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
  endif (APPLE)

  # This adds another subdirectory, which has 'project(gtest)'.
  add_subdirectory(../../googletest googletest)

  enable_testing()

  # Include the gtest library. gtest_SOURCE_DIR is available due to
  # 'project(gtest)' above.
  include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

  ##############
  # Unit Tests
  ##############
  add_executable(runUnitTests test.cpp)

  # Standard linking to gtest stuff.
  target_link_libraries(runUnitTests gtest gtest_main)

  # Extra linking for the project.
  #target_link_libraries(runUnitTests libpriority_queue)

  # This is so you can do 'make test' to see all your tests run, instead of
  # manually running the executable runUnitTests to see those specific tests.
  #add_test(NAME test_url_parser COMMAND runUnitTests)

  # You can also omit NAME and COMMAND. The second argument could be some other
  # test executable.
  #add_test(test_url_parser runUnitTests)
endif()
