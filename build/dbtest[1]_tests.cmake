add_test([=[dbtest.testingtestlol]=]  /Users/nuharahman/desktop/cs180-22-jester/build/dbtest [==[--gtest_filter=dbtest.testingtestlol]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[dbtest.testingtestlol]=]  PROPERTIES WORKING_DIRECTORY /Users/nuharahman/desktop/cs180-22-jester/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  dbtest_TESTS dbtest.testingtestlol)
