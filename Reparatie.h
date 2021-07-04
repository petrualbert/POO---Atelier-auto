#ifndef POO___ATELIER_AUTO_REPARATIE_H
#define POO___ATELIER_AUTO_REPARATIE_H

#include "masina.h"
#include <string>
#include "mecanic.h"
#include "Atelier.h"
#include <vector>
#include <ostream>

class Reparatie {
private:
    Masina* m_masina;
    Mecanic* m_mecanic;
    Atelier* m_atelier;
    int m_pret_total;
    std::vector<std::string> m_componente;
    bool m_plataEfectuata = false;

public:
    Reparatie(Atelier* atelier, Masina *mMasina, Mecanic *mMecanic, int mPretTotal, const std::vector<std::string> &mComponente,
              bool mPlataEfectuata);

    Masina *getMMasina() const;

    Atelier *getMAtelier() const;

    void setMAtelier(Atelier *mAtelier);

    void setMMasina(Masina *mMasina);

    Mecanic *getMMecanic() const;

    void setMMecanic(Mecanic *mMecanic);

    int getMPretTotal() const;


    void setMPretTotal(int mPretTotal);

    const std::vector<std::string> &getMComponente() const;

    void setMComponente(const std::vector<std::string> &mComponente);

    bool isMPlataEfectuata() const;

    void setMPlataEfectuata(bool mPlataEfectuata);


    void taxeazaClientul();

    friend std::ostream &operator<<(std::ostream &os, const Reparatie &reperatie);
};


#endif //POO___ATELIER_AUTO_REPARATIE_H
