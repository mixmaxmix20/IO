#include <iostream>
#include "Pracownik.h"
#include "Katalog_samochodowy.h"


Pracownik::Pracownik(const std::string& imie, const std::string& nazwisko, int identyfikator)
        : imie(imie), nazwisko(nazwisko), identyfikator(identyfikator) {}

std::string Pracownik::getImie() {
    return imie;
}
std::string Pracownik::getNazwisko() {
    return nazwisko;
}
int Pracownik::getIdentyfikator() {
    return identyfikator;
}

void Pracownik::wystawRozliczenieWypozyczenia(Wypozyczenie wypozyczenie) {
    std::cout<<"Rozliczenie:"<<std::endl;
    std::cout<<"Uzytkownik: "<<wypozyczenie.getWlasciciel_wypozyczenia()->getImie()<<" "<<wypozyczenie.getWlasciciel_wypozyczenia()->getNazwisko()<<std::endl;
    std::cout<<"Wynajmuje samochod: "<<wypozyczenie.getSamochod()->getMarka()<<" "<<wypozyczenie.getSamochod()->getModel()<<" z roku "<<wypozyczenie.getSamochod()->getRok_produkcji()<<std::endl;
    std::cout<<"Na okres "<<wypozyczenie.getOkres_wynajmu()<<" dni, za cene: "<<wypozyczenie.getSamochod()->getCenaZaWynajecie()*wypozyczenie.getOkres_wynajmu()<<" zl"<<std::endl;
    std::cout<<"Wystawiono przez: "<<imie<<" "<<nazwisko<<" nr identyfikatora: "<<identyfikator<<std::endl<<std::endl;

    wypozyczenie.getSamochod()->setCzyDostepny(false);
}

void Pracownik::wystawRozliczenieRezerwacji(Rezerwacja rezerwacja) {
    std::cout<<"Rozliczenie:"<<std::endl;
    std::cout<<"Uzytkownik: "<<rezerwacja.getWlasciciel_rezerwacji()->getImie()<<" "<<rezerwacja.getWlasciciel_rezerwacji()->getNazwisko()<<std::endl; //zamiast imie i nazwisko gettery
    std::cout<<"Rezerwuje samochod: "<<rezerwacja.getSamochod()->getMarka()<<" "<<rezerwacja.getSamochod()->getModel()<<" z roku "<<rezerwacja.getSamochod()->getRok_produkcji()<<std::endl;
    std::cout<<"Na okres "<<rezerwacja.getOkres_wynajmu()<<" dni, za cene: "<<rezerwacja.getSamochod()->getCenaZaRezerwacje()*rezerwacja.getOkres_wynajmu()<<" zl"<<std::endl;
    std::cout<<"Wystawiono przez: "<<imie<<" "<<nazwisko<<" nr identyfikatora: "<<identyfikator<<std::endl<<std::endl;

    rezerwacja.getSamochod()->setCzyDostepny(false);
}

void Pracownik::dodajSamochod(Samochod* samochod, Katalog_samochodowy* katalogSamochodowy) {
    katalogSamochodowy->pushBackListaSamochodow(samochod);
    std::cout << "Dodano nowy samochod" << std::endl;
}

void Pracownik::dodajKlienta(std::vector<Klient *>& listaKlientow, Klient* klient) {
    listaKlientow.push_back(klient);
    std::cout << "Dodano nowego klienta" << std::endl;
}

void Pracownik::zmienStanPojazdu(Samochod* samochod) {
    samochod->setCzyDostepny(!samochod->getStan());
    std::cout<<"Zmieniono status pojazdu."<<std::endl<<std::endl;
}
