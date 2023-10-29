FROM gcc:latest as base

RUN apt-get update
# RUN apt-get install libgtest-dev -y

COPY . /usr/src/cpp_test

WORKDIR /usr/src/cpp_test

RUN g++ -I . -o Game Source.cpp
RUN g++ -I . -o test test.cpp -lgtest -pthread

# RUN ./prereqs.sh
# RUN ./test.sh
# RUN ./run.sh


CMD ["./Game"]
