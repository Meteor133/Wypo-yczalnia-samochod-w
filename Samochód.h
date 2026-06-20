#include <iostream>
#pragma once
#include "Termin.h"

class Samochód {
protected:
    std::string marka;
    std::string model;
    int rocznik;
    int przebieg;
    double cenaZaDobe;
    std::string kategoria;
    std::vector<Termin> zarezerwowaneTerminy;
public:
    Samochód(std::string ma, std::string mo, int r, int p, double c, std::string kat)
        : marka(ma), model(mo), rocznik(r), przebieg(p), cenaZaDobe(c), kategoria(kat) {

    }

    virtual ~Samochód() {

    }


    virtual void wyswietl() const {
        std::cout << marka << " " << model << " (" << rocznik << ") | Kat: " << kategoria
             << " | Przebieg: " << przebieg << " km | Cena: " << cenaZaDobe << " zl/dobe";
    }

    virtual std::string getTypNapedu() const = 0;

    std::string getMarka() const {
        return marka;
    }
    std::string getModel() const {
        return model;
    }
    std::string getKategoria() const {
        return kategoria;
    }
    double getCena() const {
        return cenaZaDobe;
    }

    bool czyWolny(const Termin& nowyTermin) const {
        for (const auto& t : zarezerwowaneTerminy) {
            if (t == nowyTermin) return false;
        }
        return true;
    }

    void dodajTermin(const Termin& t) {
        zarezerwowaneTerminy.push_back(t);
    }
};
