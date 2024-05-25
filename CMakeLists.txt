cmake_minimum_required(VERSION 3.27)
project(ProjektIO)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProjektIO main.cpp
        Pracownik.cpp
        Wypozyczenie.cpp
        Samochod.cpp
        Katalog_samochodowy.cpp
        Rezerwacja.cpp
        Klient.cpp
        IKlient.cpp
)
