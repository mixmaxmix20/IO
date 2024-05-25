#include "Rezerwacja.h"
#include <iostream>

Rezerwacja::Rezerwacja(Klient* wlasciciel_rezerwacji, Samochod* samochod, int okres_wynajmu)
        : wlasciciel_rezerwacji(wlasciciel_rezerwacji), samochod(samochod), okres_wynajmu(okres_wynajmu) {}

Klient* Rezerwacja::getWlasciciel_rezerwacji() {
    return wlasciciel_rezerwacji;
}
Samochod* Rezerwacja::getSamochod() {
    return samochod;
}
int Rezerwacja::getOkres_wynajmu() {
    return okres_wynajmu;
}