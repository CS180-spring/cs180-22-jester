if(EXISTS "/Users/nuharahman/Desktop/cs180-22-jester/build/tabletest[1]_tests.cmake")
  include("/Users/nuharahman/Desktop/cs180-22-jester/build/tabletest[1]_tests.cmake")
else()
  add_test(tabletest_NOT_BUILT tabletest_NOT_BUILT)
endif()
