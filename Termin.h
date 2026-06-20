#pragma once
class Termin {
private:
    int dzienStart;
    int dzienKoniec;
public:
    Termin(int start = 0, int koniec = 0) : dzienStart(start), dzienKoniec(koniec) {

    }

    int getStart() const {
        return dzienStart;
    }
    int getKoniec() const {
        return dzienKoniec;
    }


    bool operator==(const Termin& inny) const {
        return !(dzienKoniec < inny.dzienStart || dzienStart > inny.dzienKoniec);
    }
};