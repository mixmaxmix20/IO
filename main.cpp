#include <iostream>
#include <vector>
#include <string>
#include "Pracownik.h"
#include "Samochod.h"
#include "Klient.h"
#include "Katalog_samochodowy.h"
#include "Rezerwacja.h"
#include "Wypozyczenie.h"

Klient* zalogujKlient(std::vector<Klient*> listaKlientow) {
    std::string imie;
    std::string nazwisko;
    std::string haslo;
    int attempts = 3;
    while(attempts) {
        std::cout << "===============================================" << std::endl;
        std::cout << "Podaj imie, nazwisko oraz haslo aby sie zalogowac." << std::endl;
        std::cin >> imie >> nazwisko >> haslo;
        for (int i = 0; i < listaKlientow.size(); i++) {
            if (listaKlientow[i]->getImie() == imie && listaKlientow[i]->getNazwisko() == nazwisko && listaKlientow[i]->getHaslo() == haslo) {
                std::cout << "Pomyslnie zalogowano" << std::endl;
                return listaKlientow[i];
            }
        }
        if (attempts == 3) std::cout << "Podano nieprawidlowe dane. Pozostaly " << attempts-1 << " proby." << std::endl;
        else if (attempts == 2) std::cout << "Podano nieprawidlowe dane. Pozostala " << attempts-1 << " proba." << std::endl;
        else std::cout << "Podano nieprawidlowe dane. Pozostalo " << attempts-1 << " prob." << std::endl;
        attempts--;
    }
    return nullptr;
}

Pracownik* zalogujPracownik(std::vector<Pracownik*> listaPracownikow) {
    std::string imie;
    std::string nazwisko;
    int identyfikator;
    int attempts = 3;
    while(attempts) {
        std::cout << "===============================================" << std::endl;
        std::cout << "Podaj imie, nazwisko oraz identyfikator aby sie zalogowac." << std::endl;
        std::cin >> imie >> nazwisko >> identyfikator;
        for (int i = 0; i < listaPracownikow.size(); i++) {
            if (listaPracownikow[i]->getImie() == imie && listaPracownikow[i]->getNazwisko() == nazwisko && listaPracownikow[i]->getIdentyfikator() == identyfikator) {
                std::cout << "Pomyslnie zalogowano" << std::endl;
                return listaPracownikow[i];
            }
        }
        if (attempts == 3) std::cout << "Podano nieprawidlowe dane. Pozostaly " << attempts-1 << " proby." << std::endl;
        else if (attempts == 2) std::cout << "Podano nieprawidlowe dane. Pozostala " << attempts-1 << " proba." << std::endl;
        else std::cout << "Podano nieprawidlowe dane. Pozostalo " << attempts-1 << " prob." << std::endl;
        attempts--;
    }
    return nullptr;
}



int main() {
    std::vector<Pracownik*> listaPracowników;
    std::vector<Klient*> listaKlientow;
    std::vector<Samochod*> listaSamochodow;


    //staly pracownik
    Pracownik* pracownik = new Pracownik("Jan", "Kowalski", 123);

    //staly klient do testow
    Klient* klient=new Klient("Klient", "Testowy", "123", 1000);

    //staly samochod ktory zawsze bedzie w katalogu
    Samochod* samochod=new Samochod("Subaru", "Lesnik", 2014, "SUV", true, true, 20, 100);

    //katalog samochodow

    listaPracowników.push_back(pracownik);
    listaKlientow.push_back(klient);
    listaSamochodow.push_back(samochod);
    Katalog_samochodowy* katalogSamochodowy=new Katalog_samochodowy(listaSamochodow);
    while(true) {
        std::cout << "===============================================" << std::endl;
        std::cout << "Wybierz opcje logowania:" << std::endl;
        std::cout << "# 1 - Klient" << std::endl;
        std::cout << "# 2 - Pracownik" << std::endl;
        std::cout << "# 0 - Wyjdz" << std::endl;
        int choiceLogowanie;
        std::cin >> choiceLogowanie;
        if (choiceLogowanie == 1) {
            Klient* zalogowanyKlient = zalogujKlient(listaKlientow);
            if (zalogowanyKlient == nullptr) return 0;
            while(true) {
                int choiceMain;
                std::cout << "===============================================" << std::endl;
                std::cout << "Wybierz co chcesz zrobic:" << std::endl;
                std::cout << "# 1 - Wyswietl katalog pojazdow" << std::endl;
                std::cout << "# 2 - Wyswietl liste zarezerwowanych pojazdow" << std::endl;
                std::cout << "# 3 - Wyswietl liste wypozyczonych pojazdow" << std::endl;
                std::cout << "# 4 - Wyswietl stan konta" << std::endl;
                std::cout << "# 5 - Dodaj srodki do konta" << std::endl;
                std::cout << "# 0 - Wyloguj" << std::endl;
                std::cin >> choiceMain;

                if (choiceMain == 0) {
                    std::cout << "Wylogowano" << std::endl;
                    break;
                }
                switch (choiceMain) {
                    case 1: {
                        Samochod* WybranySamochod=zalogowanyKlient->przegladajSamochody(katalogSamochodowy);
                        std::cout << "===============================================" << std::endl;
                        std::cout << "Wybierz co chcesz zrobic:" << std::endl;
                        std::cout << "# 1 - Zarezerwuj" << std::endl;
                        std::cout << "# 2 - Wynajmij" << std::endl;
                        std::cout << "# 0 - Wyjdz" << std::endl;
                        int choiceKatalog;
                        std::cin >> choiceKatalog;
                        switch (choiceKatalog) {
                            case 1: {
                                int iloscDni;
                                std::cout << "Podaj liczbe dni:";
                                std::cin >> iloscDni;
                                Rezerwacja* nowaRezerwacja=zalogowanyKlient->rezerwujSamochod(zalogowanyKlient, WybranySamochod, iloscDni);
                                if (nowaRezerwacja == nullptr) {
                                    break;
                                }
                                zalogowanyKlient->poprosORozliczenieRezerwacji(pracownik, nowaRezerwacja);
                                break;
                            }

                            case 2: {
                                int iloscDni;
                                std::cout << "Podaj liczbe dni:";
                                std::cin >> iloscDni;
                                Wypozyczenie* noweWypozyczenie=zalogowanyKlient->wynajmijSamochod(zalogowanyKlient, WybranySamochod, iloscDni);
                                if (noweWypozyczenie == nullptr) {
                                    break;
                                }
                                zalogowanyKlient->poprosORozliczenieWypozyczenia(pracownik, noweWypozyczenie);
                                break;
                            }

                            case 0: {
                                break;
                            }
                        }
                        break;
                    }

                    case 2: {
                        zalogowanyKlient->getLista_zarezerwowanych();
                        break;
                    }
                    case 3: {
                        zalogowanyKlient->getLista_wypozyczonych();
                        break;
                    }

                    case 4: {
                        std::cout << "Aktualny stan konta wynosi: ";
                        std::cout << zalogowanyKlient->getStan_konta();
                        std::cout << "zl" << std::endl;
                        break;
                    }

                    case 5: {
                        int kwota;
                        std::cout << "Podaj kwote doladowania: ";
                        std::cin >> kwota;
                        zalogowanyKlient->setStan_konta(kwota);
                        break;
                    }
                }

            }
        } else if (choiceLogowanie == 2) {
            Pracownik* zalogowanyPracownik = zalogujPracownik(listaPracowników);
            if (zalogowanyPracownik == nullptr) return 0;

            while(true) {
                int choiceMain;
                std::cout << "===============================================" << std::endl;
                std::cout << "Wybierz co chcesz zrobic:" << std::endl;
                std::cout << "# 1 - Dodaj klienta" << std::endl;
                std::cout << "# 2 - Dodaj samochod" << std::endl;
                std::cout << "# 0 - Wyloguj" << std::endl;
                std::cin >> choiceMain;
                if (choiceMain == 0) {
                    std::cout << "Wylogowano" << std::endl;
                    break;
                }
                switch (choiceMain) {
                    case 1: {
                        std::string imie, nazwisko, haslo;
                        int stanKonta;
                        std::cout << "Podaj dane klienta:" << std::endl;
                        std::cout << "Imie:";
                        std::cin >> imie;
                        std::cout << "Nazwisko:";
                        std::cin >> nazwisko;
                        std::cout << "Haslo:";
                        std::cin >> haslo;
                        std::cout << "Stan konta:";
                        std::cin >> stanKonta;
                        Klient* nowyKlient = new Klient(imie, nazwisko, haslo, stanKonta);
                        zalogowanyPracownik->dodajKlienta(listaKlientow, nowyKlient);
                        break;
                    }

                    case 2: {
                        std::string marka, model, kategoria;
                        int rokProdukcji, cenaZaWynajecie, cenaZaRezerwacje;
                        std::cout << "Podaj atrybuty samochodu:" << std::endl;
                        std::cout << "Marka:";
                        std::cin >> marka;
                        std::cout << "Model:";
                        std::cin >> model;
                        std::cout << "Kategoria:";
                        std::cin >> kategoria;
                        std::cout << "Rok produkcji:";
                        std::cin >> rokProdukcji;
                        std::cout << "Cena za wynajecie:";
                        std::cin >> cenaZaWynajecie;
                        std::cout << "Cena za rezerwacje:";
                        std::cin >> cenaZaRezerwacje;
                        Samochod* nowySamochod = new Samochod(marka, model, rokProdukcji, kategoria, true, true, cenaZaRezerwacje, cenaZaWynajecie);
                        zalogowanyPracownik->dodajSamochod(nowySamochod, katalogSamochodowy);
                        break;
                    }
                }
            }
        } else if (choiceLogowanie == 0) {
            return 0;
        }
    }






    // // TESTY DLA KLASY PRACOWNIK -----------------------------------------------------------
    //
    // //test dla funkcji wystawRozliczenieWypozyczenia
    // Wypozyczenie wypozyczenie(klient, samochod, 5);
    // pracownik->wystawRozliczenieWypozyczenia(wypozyczenie);
    //
    // //test dla funkcji wystawRozliczenieRezerwacji
    // Rezerwacja rezerwacja(klient, samochod, 3);
    // pracownik->wystawRozliczenieRezerwacji(rezerwacja);
    //
    // //test dla funkcji dodajSamochod
    // Samochod* tempSamochod=new Samochod("Toyota", "Prius", 2000, "Osobowe", true, true, 5, 40);
    // pracownik->dodajSamochod(tempSamochod, katalogSamochodowy);
    //
    // //test dla funkcji zmienStanPojazdu
    // pracownik->zmienStanPojazdu(samochod, false);
    // std::cout<<samochod->getStan();
    //
    // // KONIEC TESTOW DLA KLASY PRACOWNIK ---------------------------------------------------
    //
    // // TESTY DLA KLASY KATALOG_SAMOCHODOWY -------------------------------------------------
    //
    // //test wypisania katalogu
    // katalogSamochodowy->returnListaSamochodow();
    // //dodatkowy test z podanym filtrem
    // katalogSamochodowy->returnListaSamochodowPoFiltrach("Dostepne");
    //
    // // KONIEC TESTOW DLA KLASY KATALOG_SAMOCHODOWY -----------------------------------------
    //
    // // TESTY DLA KLASY KLIENT --------------------------------------------------------------
    //
    // Samochod* testWybranySamochod=klient->przegladajSamochody(katalogSamochodowy);
    // Rezerwacja* testRezerwacja=klient->rezerwujSamochod(klient, testWybranySamochod, 3);
    // klient->poprosORozliczenieRezerwacji(pracownik, testRezerwacja);
    //
    // // KONIEC TESTOW DLA KLASY KLIENT ------------------------------------------------------

}
