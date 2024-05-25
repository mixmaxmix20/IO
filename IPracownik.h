#ifndef IPRACOWNIK_H
#define IPRACOWNIK_H

#include <string>
#include "Pracownik.h"
#include "Wypozyczenie.h"
#include "Rezerwacja.h"
#include "Samochod.h"
#include "Katalog_samochodowy.h"

class Wypozyczenie;
class Rezerwacja;

class IPracownik {
public:
    virtual ~IPracownik() = default;

    virtual void wystawRozliczenieWypozyczenia(Wypozyczenie wypozyczenie) = 0;
    virtual void wystawRozliczenieRezerwacji(Rezerwacja rezerwacja) = 0;
    virtual void dodajSamochod(Samochod* samochod, Katalog_samochodowy* katalogSamochodowy) = 0;
    virtual void zmienStanPojazdu(Samochod* samochod) = 0;

    virtual std::string getImie() = 0;
    virtual std::string getNazwisko() = 0;
    virtual int getIdentyfikator() = 0;
};

#endif // IPRACOWNIK_H
