all: carrera

carrera: carrera.cpp
    g++ -std=c++11 -pthread carrera.cpp -o carrera

clean:
    rm -f carrera
