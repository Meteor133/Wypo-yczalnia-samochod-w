#include <vector>
#pragma once
#include "Termin.h"
#include "Samochód.h"
#include "Użytkownik.h"

class Klient : public Użytkownik {
private:
    std::vector<Samochód*> wypożyczonePojazdy;
public:
    Klient(std::string l, std::string h) : Użytkownik(l, h, "Klient") {

    }

    const std::vector<Samochód*>& getWypożyczonePojazdy() const {
        return wypożyczonePojazdy;
    }


    bool zarezerwujPojazd(Samochód* p, Termin t) {
        if (p->czyWolny(t)) {
            p->dodajTermin(t);
            wypożyczonePojazdy.push_back(p);
            return true;
        }
        return false;
    }

    void wyswietlMenu() const override {
        std::cout << "--- MENU KLIENTA ---" << std::endl;
        std::cout << "1. Przegladaj katalog samochodów" <<std::endl;
        std::cout << "2. Zarezerwuj samochód na wybrany okres"<<std::endl;
        std::cout << "3. Wyświetl moje aktywne wypożyczenia"<<std::endl;
        std::cout << "0. Wyloguj sie "<<std::endl;
        std::cout <<"Wybór: "<<std::endl;
    }
};
