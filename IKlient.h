#ifndef IKLIENT_H
#define IKLIENT_H

#include <string>
#include "Katalog_samochodowy.h"
#include "Rezerwacja.h"
#include "Klient.h"
#include "Samochod.h"
#include "Wypozyczenie.h"
#include "Pracownik.h"

using namespace std;

class Wypozyczenie;

class Pracownik;

class Rezerwacja;

class IKlient {
public:
    virtual ~IKlient() = default;

    virtual Samochod* przegladajSamochody(Katalog_samochodowy* katalog_samochodowy) = 0;
    virtual Rezerwacja* rezerwujSamochod(Klient* klient, Samochod* samochod, int ilosc_dni) = 0;
    virtual Wypozyczenie* wynajmijSamochod(Klient* klient, Samochod* samochod, int ilosc_dni) = 0;
    virtual void poprosORozliczenieRezerwacji(Pracownik* pracownik, Rezerwacja* rezerwacja) = 0;
    virtual void poprosORozliczenieWypozyczenia(Pracownik* pracownik, Wypozyczenie* wypozyczenie) = 0;

    virtual string getImie() = 0;
    virtual string getNazwisko() = 0;
    virtual int getStan_konta() = 0;
    virtual void getLista_zarezerwowanych() = 0;
    virtual void getLista_wypozyczonych() = 0;

    virtual void setImie(string imie) = 0;
    virtual void setNazwisko(string nazwisko) = 0;
    virtual void setStan_konta(int stan_konta) = 0;
};

#endif // IKLIENT_H