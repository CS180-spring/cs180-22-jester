# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/nuharahman/desktop/cs180-22-jester/build/_deps/googletest-src"
  "/Users/nuharahman/desktop/cs180-22-jester/build/_deps/googletest-build"
  "/Users/nuharahman/Desktop/cs180-22-jester/build/_deps/googletest-subbuild/googletest-populate-prefix"
  "/Users/nuharahman/Desktop/cs180-22-jester/build/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "/Users/nuharahman/Desktop/cs180-22-jester/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "/Users/nuharahman/Desktop/cs180-22-jester/build/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "/Users/nuharahman/Desktop/cs180-22-jester/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/nuharahman/Desktop/cs180-22-jester/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/nuharahman/Desktop/cs180-22-jester/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
