#include "Katalog_samochodowy.h"
#include <iostream>

Katalog_samochodowy::Katalog_samochodowy(std::vector<Samochod*> listaSamochodow)
        : listaSamochodow(listaSamochodow) {}

std::vector<Samochod*> Katalog_samochodowy::getListaSamochodow() {
    return listaSamochodow;
}

void Katalog_samochodowy::returnListaSamochodow() {
    std::cout<<"Katalog samochodowy:"<<std::endl;
    for(int i=0; i<listaSamochodow.size(); ++i){
        std::cout<<"Indeks samochodu - "<<i<<std::endl<<listaSamochodow[i]->getKategoriaSamochodu()<<std::endl<<listaSamochodow[i]->getMarka()<<" "<<listaSamochodow[i]->getModel()<<" "<<listaSamochodow[i]->getRok_produkcji()<<"rok"<<std::endl;
        std::cout<<"Cena za rezerwacje: "<<listaSamochodow[i]->getCenaZaRezerwacje()<<"zl. Cena za wynajem: "<<listaSamochodow[i]->getCenaZaWynajecie()<<"zl."<<std::endl;
        if(listaSamochodow[i]->getCzyDostepny())
            std::cout<<"Dostepny"<<std::endl;
        else
            std::cout<<"Niedostepny"<<std::endl;
        std::cout<<std::endl;
    }
    std::cout<<std::endl<<std::endl;
}

void Katalog_samochodowy::returnListaSamochodowPoFiltrach(std::string filtr) {
    std::cout<<"Katalog samochodowy z filtrem "<<filtr<<":"<<std::endl;
    for(int i=0; i<listaSamochodow.size(); ++i){
        if(listaSamochodow[i]->getKategoriaSamochodu()==filtr || (filtr=="Dostepne" && listaSamochodow[i]->getCzyDostepny()) || (filtr=="Niedostepne" && !listaSamochodow[i]->getCzyDostepny())) {
            std::cout <<"Indeks samochodu - "<<i<<std::endl << listaSamochodow[i]->getMarka() << " " << listaSamochodow[i]->getModel() << " "
                      << listaSamochodow[i]->getRok_produkcji() << "rok" << std::endl;
            std::cout << "Cena za rezerwacje: " << listaSamochodow[i]->getCenaZaRezerwacje() << "zl. Cena za wynajem: "
                      << listaSamochodow[i]->getCenaZaWynajecie() << "zl." << std::endl;
            if (listaSamochodow[i]->getCzyDostepny())
                std::cout << "Dostepny" << std::endl;
            else
                std::cout << "Niedostepny" << std::endl;
            std::cout << std::endl;
        }
    }
    std::cout<<std::endl<<std::endl;
}

void Katalog_samochodowy::pushBackListaSamochodow(Samochod* samochod) {
    std::cout<<"Dodano pojazd do katalogu."<<std::endl<<std::endl;
    listaSamochodow.push_back(samochod);
}