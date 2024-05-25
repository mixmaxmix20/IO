#if !defined(_KATALOG_SAMOCHODOWY_H)
#define _KATALOG_SAMOCHODOWY_H

#include <vector>
#include "Samochod.h"

class Katalog_samochodowy {
private:
	std::vector<Samochod*> listaSamochodow;
public:
    Katalog_samochodowy(std::vector<Samochod*> listaSamochodow);

    std::vector<Samochod*> getListaSamochodow();
    void returnListaSamochodow();
    void returnListaSamochodowPoFiltrach(std::string filtr);

    void pushBackListaSamochodow(Samochod* samochod);
};

#endif  //_KATALOG_SAMOCHODOWY_H
