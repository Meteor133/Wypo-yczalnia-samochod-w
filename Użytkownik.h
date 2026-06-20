#include <iostream>
#pragma once

class Użytkownik {
protected:
    std::string login;
    std::string hasło;
    std::string rola;
public:
    Użytkownik(std::string l, std::string h, std::string r) : login(l), hasło(h), rola(r) {

    }
    virtual ~Użytkownik() {

    }

    std::string getLogin() const {
        return login;
    }
    std::string getHasło() const {
        return hasło;
    }
    std::string getRola() const {
        return rola;
    }

    virtual void wyswietlMenu() const = 0;
};


