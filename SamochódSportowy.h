#pragma once
class SamochódSportowy : public Samochód {
public:
    SamochódSportowy(std::string ma, std::string mo, int r, int p, double c, std::string kat)
        : Samochód(ma, mo, r, p, c, kat) {

    }

    std::string getTypNapedu() const override { return "Elektryczny"; }
    void wyswietl() const override {
        Samochód::wyswietl();
        std::cout << " [Elektryczny]" << std::endl; }
};