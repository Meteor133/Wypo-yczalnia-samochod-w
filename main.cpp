#include "BazaDanych.h"
#include "Klient.h"
#pragma once

int main() {
    BazaDanych wp;
    wp.wczytajBazeZPliku();
    wp.inicjalizujSamochody();

    Użytkownik* zalogowany = nullptr;

    std::cout << " SYSTEM REZERWACJI I WYPOZYCZALNI " << std::endl;
    std::cout << "1. Zaloguj się"<<std::endl;
    std::cout << "2. Zarejestruj konto klienta" << std::endl;
    std::cout << "Wybór: "<< std::endl;
    int start; std::cin >> start;

    if (start == 2) {
        std::string l, h;
        std::cout << "Podaj login: ";
        std::cin >> l;
        std::cout << "Podaj haslo: ";
        std::cin >> h;
        wp.użytkownicy.push_back(new Klient(l, h));
        wp.zapiszBazeDoPliku();
        std::cout << "Rejestracja pomyślna! Uruchom program ponownie, aby sie zalogować." << std::endl;
        return 0;
    }

    std::string l, h;
    std::cout << "Login: ";
    std::cin >> l;
    std::cout << "Hasło: ";
    std::cin >> h;

    for (auto u : wp.użytkownicy) {
        if (u->getLogin() == l && u->getHasło() == h) {
            zalogowany = u;
            break;
        }
    }

    if (!zalogowany) {
        std::cout << "Błędne dane logowania!" << std::endl;
        return 0;
    }

    std::cout << "Zalogowano jako: " << zalogowany->getLogin() << " [" << zalogowany->getRola() << "]" << std::endl;

    int wybor = 0;
    do {
        zalogowany->wyswietlMenu();
        std::cin >> wybor;

        if (zalogowany->getRola() == "Pracownik") {
            if (wybor == 1) {
                for (auto s : wp.flota) s->wyswietl();
            }
            else if (wybor == 2) {
                std::string ma, mo, kat; int r, p; double c;
                std::cout << "Marka: "; std::cin >> ma;
                std::cout << "Model: "; std::cin >> mo;
                std::cout << "Rocznik: "; std::cin >> r;
                std::cout << "Przebieg: "; std::cin >> p;
                std::cout << "Cena za dobe: "; std::cin >> c;
                std::cout << "Kategoria (Osobowy/SUV/Dostawczy): "; std::cin >> kat;
                wp.flota.push_back(new SamochódLuksusowy(ma, mo, r, p, c, kat));
                std::cout << "Pojazd został pomyślnie dodany do floty przez pracownika!" << std::endl;
            }
        }
        else {
            Klient* aktualnyKlient = dynamic_cast<Klient*>(zalogowany);

            if (wybor == 1) {
                for (auto s : wp.flota) s->wyswietl();
            }
            else if (wybor == 2) {
                int indeks, startD, koniecD;
                std::cout << "Wybierz ID samochodu (0-" << wp.flota.size() - 1 << "): "; std::cin >> indeks;
                std::cout << "Dzień rozpoczecia (1-365): "; std::cin >> startD;
                std::cout << "Dzień zakonczenia (1-365): "; std::cin >> koniecD;

                Termin nowyTermin(startD, koniecD);

                if (aktualnyKlient && aktualnyKlient->zarezerwujPojazd(wp.flota[indeks], nowyTermin)) {
                    wp.zapiszLogRezerwacji(aktualnyKlient->getLogin(), wp.flota[indeks]->getMarka(), wp.flota[indeks]->getModel(), nowyTermin);
                    std::cout << "Sukces! Pojazd został zarezerwowany." << std::endl;
                } else {
                    std::cout << "Bląd! Samochód jest zajęty w podanym terminie." << std::endl;
                }
            }
            else if (wybor == 3) {
                if (aktualnyKlient) {
                    std::cout << "--- TWOJA LISTA AUT ---" << std::endl;
                    if (aktualnyKlient->getWypożyczonePojazdy().empty()) std::cout << "Brak wypozyczeń." << std::endl;
                    for (auto p : aktualnyKlient->getWypożyczonePojazdy()) p->wyswietl();
                }
            }
        }
    } while (wybor != 0);

    return 0;
}
