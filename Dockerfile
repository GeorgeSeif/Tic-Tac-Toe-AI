FROM gcc:latest as base

RUN apt-get update
RUN apt-get install cmake -y
# RUN apt-get install libgtest-dev -y


COPY . /usr/src/cpp_test

WORKDIR /usr/src/cpp_test
RUN mkdir -p build

# RUN g++ -I . -o Game Source.cpp
# RUN g++ -I . -o test test.cpp -lgtest -pthread

RUN chmod +x ./scripts/prereqs.sh
RUN chmod +x ./scripts/build.sh

RUN ./scripts/prereqs.sh
RUN ./scripts/build.sh
# RUN ./scripts/test.sh
# RUN ./scripts/build.sh
# RUN ./scripts/run.sh


# CMD ["./Game"]
