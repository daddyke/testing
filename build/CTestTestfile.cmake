# CMake generated Testfile for 
# Source directory: C:/Users/yunke/Downloads/P1/project1-daddyke-final
# Build directory: C:/Users/yunke/Downloads/P1/project1-daddyke-final/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(00_Install "C:/Program Files/CMake/bin/cmake.exe" "--build" "C:/Users/yunke/Downloads/P1/project1-daddyke-final/build" "--target" "install")
add_test(unittests "unittests")
subdirs("tests")
