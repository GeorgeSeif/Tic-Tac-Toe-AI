!/bin/bash
# https://github.com/google/googletest/blob/master/googletest/README.md
# https://gist.github.com/kedestin/4fbf48266b2972ee1974af671250cb36

# To uninstall, run:
# sudo rm -rf /usr/lib/libgtest.a /usr/include/gtest

RELEASE="release-1.8.1.tar.gz"
ROOT_DIR="googletest-release-1.8.1"
CXX_STANDARD="c++14"

cleanup() {
        rm goog* release* -rf gtesttest
}

echo " -- Downloading Google Test "
{ wget https://github.com/google/googletest/archive/${RELEASE}; } 2>/dev/null

if [ ! -f "${RELEASE}" ]; then
        { curl -O https://github.com/google/googletest/archive/release-1.8.1.tar.gz; } 2>/dev/null
fi

if [ ! -f "${RELEASE}" ]; then
        echo "Could not download Google Test"
        cleanup
        exit 1
fi

echo " -- Extracting Google Test"
{ tar -xzvf ${RELEASE}; } >/dev/null

echo " -- Compiling Google Test"
(
        cd ${ROOT_DIR}/googletest &&
                g++ -std=c++11 -isystem ./include -I . -pthread -c src/gtest-all.cc &&
                # script command hides ar's output
                (script -qefc "ar -rv libgtest.a gtest-all.o" /dev/null >/dev/null) &&
                rm gtest-all.o
) 2>/dev/null

if [ ! -f "${ROOT_DIR}/googletest/libgtest.a" ]; then
        echo "Compilation failed"
        cleanup
        exit 1
fi

echo " -- Installing Google Test at /usr/lib and /usr/include (needs sudo)"
(
        cd ${ROOT_DIR}/googletest &&
                mv libgtest.a /usr/lib && # Move lib to system path
                mv include/gtest /usr/include # Move includes to system path
)
if [ $? -ne 0 ]; then
        echo "Could not install"
        cleanup
        exit 1
fi