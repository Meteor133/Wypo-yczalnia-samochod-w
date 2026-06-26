#include "Użytkownik.h"
#pragma once

class Admin : public Użytkownik {
public:
    Admin(std::string l, std::string h) : Użytkownik(l, h, "Pracownik") {

    }

    void wyswietlMenu() const override {
        std::cout << "--- MENU PRACOWNIKA ---" << std::endl;
        std::cout << "1. Wyswietl pelna liste floty pojadow"<<std::endl;
        std::cout << "2. Dodaj nowy pojazd do systemu"<<std::endl;
        std::cout << "0. Wyloguj się "<<std::endl;
        std::cout<< "Wybor: "<<std::endl;
    }
};
