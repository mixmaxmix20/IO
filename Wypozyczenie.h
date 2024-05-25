#if !defined(_WYPOZYCZENIE_H)
#define _WYPOZYCZENIE_H


#include "Klient.h"
#include "Samochod.h"

class Klient;

class Wypozyczenie {
private:
	Klient *wlasciciel_wypozyczenia;
	Samochod *samochod;
	int okres_wynajmu;
public:
    Wypozyczenie(Klient* wlasciciel_wypozyczenia, Samochod* samochod, int okres_wynajmu);

    Klient* getWlasciciel_wypozyczenia();
    Samochod* getSamochod();
    int getOkres_wynajmu();
};

#endif  //_WYPOZYCZENIE_H
