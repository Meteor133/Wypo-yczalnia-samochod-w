//
// Created by Mateusz on 18.03.2026.
//

#ifndef UNTITLED3_SAMOCHÓD_H
#define UNTITLED3_SAMOCHÓD_H


class Samochód {
public:
    [[nodiscard]] String marka1() const {
        return marka;
    }

    void set_marka(const String &marka) {
        this->marka = marka;
    }

    [[nodiscard]] String model1() const {
        return model;
    }

    void set_model(const String &model) {
        this->model = model;
    }

    [[nodiscard]] int rok_produkcji() const {
        return rokProdukcji;
    }

    void set_rok_produkcji(int rok_produkcji) {
        rokProdukcji = rok_produkcji;
    }

    [[nodiscard]] int przebieg1() const {
        return przebieg;
    }

    void set_przebieg(int przebieg) {
        this->przebieg = przebieg;
    }

    [[nodiscard]] int cena_wypożyczenia() const {
        return cenaWypożyczenia;
    }

    void set_cena_wypożyczenia(int cena_wypożyczenia) {
        cenaWypożyczenia = cena_wypożyczenia;
    }

    Samochód(const String &marka, const String &model, int rok_produkcji, int przebieg, int cena_wypożyczenia)
        : marka(marka),
          model(model),
          rokProdukcji(rok_produkcji),
          przebieg(przebieg),
          cenaWypożyczenia(cena_wypożyczenia) {
    }

private:
    String marka;
    String model;
    int rokProdukcji;
    int przebieg;
    int cenaWypożyczenia;


};


#endif //UNTITLED3_SAMOCHÓD_H