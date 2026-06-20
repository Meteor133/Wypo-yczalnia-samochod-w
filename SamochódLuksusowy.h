#include "Samochód.h"
#pragma once
class SamochódLuksusowy : public Samochód {
public:
    SamochódLuksusowy(std::string ma, std::string mo, int r, int p, double c, std::string kat)
        : Samochód(ma, mo, r, p, c, kat) {

    }

    std::string getTypNapedu() const override {
        return "Spalinowy";
    }
    void wyswietl() const override {
        Samochód::wyswietl();
        std::cout << " [Spalinowy]" << std::endl; }
};