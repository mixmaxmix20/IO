#include "Wypozyczenie.h"
#include <iostream>

Wypozyczenie::Wypozyczenie(Klient* wlasciciel_wypozyczenia, Samochod* samochod, int okres_wynajmu)
        : wlasciciel_wypozyczenia(wlasciciel_wypozyczenia), samochod(samochod), okres_wynajmu(okres_wynajmu) {}

Klient* Wypozyczenie::getWlasciciel_wypozyczenia() {
    return wlasciciel_wypozyczenia;
}
Samochod* Wypozyczenie::getSamochod() {
    return samochod;
}
int Wypozyczenie::getOkres_wynajmu() {
    return okres_wynajmu;
}