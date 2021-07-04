#ifndef POO___ATELIER_AUTO_MECANIC_H
#define POO___ATELIER_AUTO_MECANIC_H

#include <ostream>
#include "Angajat.h"

class Mecanic: public Angajat {
public:
    Mecanic();

    Mecanic(const std::string &mNume, int mVarsta, int mSalariu, int mVechimeAni);

    friend std::ostream &operator<<(std::ostream &os, const Mecanic &mecanic);

};


#endif //POO___ATELIER_AUTO_MECANIC_H
