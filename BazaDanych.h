#include <fstream>
#include <iosfwd>
#include <vector>

#include "Admin.h"
#include "Klient.h"
#include "Samochód.h"
#include "SamochódLuksusowy.h"
#include "SamochódSportowy.h"
#include "Termin.h"
#include "Użytkownik.h"
#pragma once

class BazaDanych {
public:
    std::vector<Samochód*> flota;
    std::vector<Użytkownik*> użytkownicy;

    ~BazaDanych() {
        for (auto p : flota) delete p;
        for (auto u : użytkownicy) delete u;
    }

    void wczytajBazeZPliku() {
        std::ifstream plik("użytkownicy.txt");
        if (!plik.is_open()) {
            użytkownicy.push_back(new Admin("admin", "qwerty"));
            użytkownicy.push_back(new Klient("klient", "qwerty"));
            zapiszBazeDoPliku();
            return;
        }
        std::string l, h, r;
        while (plik >> l >> h >> r) {
            if (r == "Pracownik") użytkownicy.push_back(new Admin(l, h));
            else użytkownicy.push_back(new Klient(l, h));
        }
        plik.close();
    }

    void zapiszBazeDoPliku() {
        std::ofstream plik("uzytkownicy.txt");
        if (plik.is_open()) {
            for (const auto& u : użytkownicy) {
                plik << u->getLogin() << " " << u->getHasło() << " " << u->getRola() << std::endl;
            }
            plik.close();
        }
    }

    void inicjalizujSamochody() {
        flota.push_back(new SamochódLuksusowy("Mercedes-Benz", "S-Class", 2023, 650000, 367, "Limuzyna"));
        flota.push_back(new SamochódLuksusowy("BMW", "740d xDrive", 2024, 580000, 299, "Limuzyna"));
        flota.push_back(new SamochódSportowy("Ferrari", "F8 Tributo", 2022, 1400000, 720, "Sportowy"));
    }

    void zapiszLogRezerwacji(std::string login, std::string marka, std::string model, Termin t) {
        std::ofstream plik("rezerwacje.txt", std::ios::app);
        if (plik.is_open()) {
            plik << login << " " << marka << " " << model << " "
                 << t.getStart() << " " << t.getKoniec() << "\n";
            plik.close();
        }
    }
};
