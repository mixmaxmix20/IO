#if !defined(_REZERWACJA_H)
#define _REZERWACJA_H

#include "Klient.h"
#include "Samochod.h"

class Klient;

class Rezerwacja {
private:
    Klient *wlasciciel_rezerwacji;
    Samochod *samochod;
    int okres_wynajmu;
public:
    Rezerwacja(Klient* wlasciciel_rezerwacji, Samochod* samochod, int okres_wynajmu);

    Klient* getWlasciciel_rezerwacji();
    Samochod* getSamochod();
    int getOkres_wynajmu();
};

#endif  //_REZERWACJA_H
