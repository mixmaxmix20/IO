#if !defined(_KLIENT_H)
#define _KLIENT_H

#include "IKlient.h"
#include "Wypozyczenie.h"
#include "Rezerwacja.h"
#include <string>
#include <vector>

using namespace std;

class Wypozyczenie;
class Rezerwacja;
class Pracownik;

class Klient : public IKlient {
private:
    string imie;
    string nazwisko;
    string haslo;
    int stan_konta;
    vector<Rezerwacja> lista_zarezerwowanych;
    vector<Wypozyczenie> lista_wypozyczonych;

public:
    Klient(string imie, string nazwisko, string haslo, int stan_konta);
    Samochod* przegladajSamochody(Katalog_samochodowy* katalog_samochodowy);
    Rezerwacja* rezerwujSamochod(Klient* klient, Samochod* samochod, int ilosc_dni);
    Wypozyczenie* wynajmijSamochod(Klient* klient, Samochod* samochod, int ilosc_dni);
    void poprosORozliczenieRezerwacji(Pracownik* pracownik, Rezerwacja* rezerwacja);
    void poprosORozliczenieWypozyczenia(Pracownik* pracownik, Wypozyczenie* wypozyczenie);

    void dodajDoListyWypozyczonych(Wypozyczenie wypozyczenie);
    void dodajDoListyZarezerwowanych(Rezerwacja rezerwacja);

    string getImie();
    string getNazwisko();
    string getHaslo();
    int getStan_konta();
    void getLista_zarezerwowanych();
    void getLista_wypozyczonych();

    void setImie(string imie);
    void setNazwisko(string nazwisko);
    void setStan_konta(int stan_konta);
};
#endif  //_KLIENT_H