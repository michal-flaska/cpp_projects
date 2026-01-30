GTest example PR #1 created by @martin-flaska

To install GTest:

```
sudo apt-get install libgtest-dev
cd /usr/src/googletest/
sudo mkdir build
cd build
sudo cmake ..
sudo make
sudo make install
```

Build the example #10:

```
martin@vm-vantage:~/Dev/repos/Misko/cpp_projects/practice-tests/10/build$ cmake ..
-- The C compiler identification is GNU 13.3.0
-- The CXX compiler identification is GNU 13.3.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found GTest: /usr/local/lib/cmake/GTest/GTestConfig.cmake (found version "1.14.0")  
-- Configuring done (1.3s)
-- Generating done (0.0s)
-- Build files have been written to: /home/martin/Dev/repos/Misko/cpp_projects/practice-tests/10/build
martin@vm-vantage:~/Dev/repos/Misko/cpp_projects/practice-tests/10/build$ make
[ 25%] Building CXX object CMakeFiles/first_unique.dir/first_unique.cpp.o
[ 50%] Linking CXX static library libfirst_unique.a
[ 50%] Built target first_unique
[ 75%] Building CXX object CMakeFiles/first_unique-test.dir/first_unique-test.cpp.o
[100%] Linking CXX executable first_unique-test
[100%] Built target first_unique-test
martin@vm-vantage:~/Dev/repos/Misko/cpp_projects/practice-tests/10/build$ make test
Running tests...
Test project /home/martin/Dev/repos/Misko/cpp_projects/practice-tests/10/build
    Start 1: FirstUnique.BasicTest
1/4 Test #1: FirstUnique.BasicTest ....................................................................   Passed    0.01 sec
    Start 2: FirstUniqueTestCases/FirstUniqueTest.ReturnsCorrectValue/("hello", 'h' (104, 0x68))
2/4 Test #2: FirstUniqueTestCases/FirstUniqueTest.ReturnsCorrectValue/("hello", 'h' (104, 0x68)) ......   Passed    0.01 sec
    Start 3: FirstUniqueTestCases/FirstUniqueTest.ReturnsCorrectValue/("leetcode", 'l' (108, 0x6C))
3/4 Test #3: FirstUniqueTestCases/FirstUniqueTest.ReturnsCorrectValue/("leetcode", 'l' (108, 0x6C)) ...   Passed    0.01 sec
    Start 4: FirstUniqueTestCases/FirstUniqueTest.ReturnsCorrectValue/("aabbcc", ' ' (32, 0x20))
4/4 Test #4: FirstUniqueTestCases/FirstUniqueTest.ReturnsCorrectValue/("aabbcc", ' ' (32, 0x20)) ......   Passed    0.01 sec

100% tests passed, 0 tests failed out of 4

Total Test time (real) =   0.04 sec
```
