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
        std::cout << "1. Przegladaj katalog samochodow" <<std::endl;
        std::cout << "2. Zarezerwuj samochod na wybrany okres"<<std::endl;
        std::cout << "3. Wyswietl moje aktywne wypozyczenia"<<std::endl;
        std::cout << "0. Wyloguj sie "<<std::endl;
        std::cout <<"Wybor: "<<std::endl;
    }
};
