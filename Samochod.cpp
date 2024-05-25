#include "Samochod.h"
#include <iostream>

Samochod::Samochod(std::string marka, std::string model, int rok_produkcji, std::string kategoriaSamochodu, bool czyDostepny, bool stan, int cenaZaRezerwacje, int cenaZaWynajecie)
        : marka(marka), model(model), rok_produkcji(rok_produkcji), kategoriaSamochodu(kategoriaSamochodu), czyDostepny(czyDostepny), stan(stan), cenaZaRezerwacje(cenaZaRezerwacje), cenaZaWynajecie(cenaZaWynajecie) {}

std::string Samochod::getMarka() {
    return marka;
}
std::string Samochod::getModel() {
    return model;
}
int Samochod::getRok_produkcji() {
    return rok_produkcji;
}
std::string Samochod::getKategoriaSamochodu() {
    return kategoriaSamochodu;
}
bool Samochod::getCzyDostepny() {
    return czyDostepny;
}
bool Samochod::getStan() {
    return stan;
}
int Samochod::getCenaZaRezerwacje() {
    return cenaZaRezerwacje;
}
int Samochod::getCenaZaWynajecie() {
    return cenaZaWynajecie;
}

void Samochod::setStan(bool stan) {
    this->stan=stan;
}

void Samochod::setCzyDostepny(bool dostepnosc) {
    this->czyDostepny=dostepnosc;
}