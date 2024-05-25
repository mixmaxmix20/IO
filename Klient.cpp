#include <iostream>

#include "Rezerwacja.h"
#include "Wypozyczenie.h"
#include "Klient.h"

#include <string>

using namespace std;


Klient::Klient(string imie, string nazwisko, string haslo, int stan_konta) {
    Klient::imie = imie;
    Klient::nazwisko = nazwisko;
    Klient::haslo = haslo;
    Klient::stan_konta = stan_konta;
}

void Klient::dodajDoListyZarezerwowanych(Rezerwacja rezerwacja) {
    lista_zarezerwowanych.push_back(rezerwacja);
}

void Klient::dodajDoListyWypozyczonych(Wypozyczenie wypozyczenie) {
    lista_wypozyczonych.push_back(wypozyczenie);
}

string Klient::getImie() {
    return imie;
}
string Klient::getNazwisko() {
    return nazwisko;
}
int Klient::getStan_konta() {
    return stan_konta;
}

string Klient::getHaslo() {
    return haslo;
}
void Klient::getLista_zarezerwowanych() {
    if(lista_zarezerwowanych.size()>0) {
        std::cout<<"Lista zarezerwowanych:"<<std::endl;
        for (int i = 0; i < lista_zarezerwowanych.size(); ++i) {
            std::cout<<lista_zarezerwowanych[i].getSamochod()->getKategoriaSamochodu()<<std::endl<<lista_zarezerwowanych[i].getSamochod()->getMarka()<<" "<<lista_zarezerwowanych[i].getSamochod()->getModel()<<" "<<lista_zarezerwowanych[i].getSamochod()->getRok_produkcji()<<"rok"<<std::endl;
            std::cout<<"Pozostale dni rezerwacji: "<<lista_zarezerwowanych[i].getOkres_wynajmu()<<". Cena za wynajem: "<<lista_zarezerwowanych[i].getSamochod()->getCenaZaWynajecie()<<"zl."<<std::endl;
        }
    }
    else
        cout<<"Brak samochodow na liscie zarezerwowanych"<<endl;
}
void Klient::getLista_wypozyczonych() {
    if(lista_wypozyczonych.size()>0) {
        for (int i = 0; i < lista_wypozyczonych.size(); ++i) {
            std::cout<<lista_wypozyczonych[i].getSamochod()->getKategoriaSamochodu()<<std::endl<<lista_wypozyczonych[i].getSamochod()->getMarka()<<" "<<lista_wypozyczonych[i].getSamochod()->getModel()<<" "<<lista_wypozyczonych[i].getSamochod()->getRok_produkcji()<<"rok"<<std::endl;
            std::cout<<"Pozostale dni wypozyczenia: "<<lista_wypozyczonych[i].getOkres_wynajmu()<<"."<<std::endl;
        }
    }
    else
        cout<<"Brak samochodow na liscie wypozyczonych"<<endl;
}

void Klient::setImie(string imie) {
    Klient::imie=imie;
}
void Klient::setNazwisko(string nazwisko) {
    Klient::nazwisko=nazwisko;
}
void Klient::setStan_konta(int stan_konta) {
    Klient::stan_konta += stan_konta;
}

Samochod* Klient::przegladajSamochody(Katalog_samochodowy* katalog_samochodowy) {
    string filtry="Osobowe-1, Sportowe-2, SUV-3, Dostepne-4";
    cout<<"Czy chcesz uzyc filtrow wyszukiwania? ("<<filtry<<" / jesli nie wpisz 0)"<<endl;
    int choice;
    cin>>choice;

    if(choice==0){
        katalog_samochodowy->returnListaSamochodow();
    } else if (choice==1){
        katalog_samochodowy->returnListaSamochodowPoFiltrach("Osobowe");
    } else if (choice==2){
        katalog_samochodowy->returnListaSamochodowPoFiltrach("Sportowe");
    } else if (choice==3){
        katalog_samochodowy->returnListaSamochodowPoFiltrach("SUV");
    } else if (choice==4){
        katalog_samochodowy->returnListaSamochodowPoFiltrach("Dostepne");
    }
    cout<<"Aby wybrac samochod, wpisz jego indeks: "<<endl;
    int carChoice;
    cin>>carChoice;

    vector<Samochod*> tempLista = katalog_samochodowy->getListaSamochodow();
    return tempLista[carChoice];
}

Rezerwacja* Klient::rezerwujSamochod(Klient* klient, Samochod* samochod, int ilosc_dni) {
    if (samochod->getCzyDostepny() == false) {
        cout << "Wybrany samochod jest niedostepny." << std::endl;
        return nullptr;
    }
    if(klient->stan_konta >= samochod->getCenaZaRezerwacje()*ilosc_dni) {
        klient->setStan_konta(-samochod->getCenaZaRezerwacje()*ilosc_dni);
        cout<<"Pomyslnie zarezerwowano."<<endl;
        cout<<"Stan konta po wynajeciu: "<<klient->stan_konta<<"zl"<<endl;
        Rezerwacja *rezerwacja = new Rezerwacja(klient, samochod, ilosc_dni);
        dodajDoListyZarezerwowanych(*rezerwacja);
        samochod->setCzyDostepny(false);
        return rezerwacja;
    }
    else {
        cout<<"Zbyt mala ilosc pieniedzy na koncie"<<endl;
        return nullptr;
    }
}

Wypozyczenie* Klient::wynajmijSamochod(Klient *klient, Samochod *samochod, int ilosc_dni) {
    if (samochod->getCzyDostepny() == false) {
        cout << "Wybrany samochod jest niedostepny." << std::endl;
        return nullptr;
    }
    if(klient->stan_konta >= samochod->getCenaZaWynajecie()*ilosc_dni) {
        klient->setStan_konta(-samochod->getCenaZaWynajecie()*ilosc_dni);
        cout<<"Pomyslnie wynajeto."<<endl;
        cout<<"Stan konta po wynajeciu: "<<klient->stan_konta<<"zl"<<endl;
        Wypozyczenie *wypozyczenie = new Wypozyczenie(klient, samochod, ilosc_dni);
        dodajDoListyWypozyczonych(*wypozyczenie);
        samochod->setCzyDostepny(false);
        return wypozyczenie;
    }
    else {
        cout<<"Zbyt mala ilosc pieniedzy na koncie"<<endl;
        return nullptr;
    }
}

void Klient::poprosORozliczenieRezerwacji(Pracownik *pracownik, Rezerwacja *rezerwacja) {
    pracownik->wystawRozliczenieRezerwacji(*rezerwacja);
}

void Klient::poprosORozliczenieWypozyczenia(Pracownik *pracownik, Wypozyczenie *wypozyczenie) {
    pracownik->wystawRozliczenieWypozyczenia(*wypozyczenie);
}