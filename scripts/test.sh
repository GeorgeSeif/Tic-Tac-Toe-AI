echo " -- Running Test"
# Compile from stdin. - signifies stdin. -xc++ specifies language is c++
clang++ src/test.cpp -Wall -Wextra -o build/gtesttest -std=${CXX_STANDARD} -lgtest -lpthread 

./build/gtesttest

echo " -- Test Success!"

# TODO: поменять на make test <=> добавить в cmake