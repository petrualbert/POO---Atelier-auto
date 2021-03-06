#include "Mecanic.h"

Mecanic::Mecanic() {

}

std::ostream &operator<<(std::ostream &os, const Mecanic &mecanic) {
    os << "Mecanicul " << mecanic.m_nume << " cu varsta de " << mecanic.m_varsta << " are vechime de " << mecanic.m_vechime_ani << " ani"
       << " salariu de " << mecanic.m_salariu << " LEI ";
    return os;
}

Mecanic::Mecanic(const std::string &mNume, int mVarsta, int mSalariu,
                 int mVechimeAni) : Angajat(mNume, mVarsta, "Mecanic", mSalariu, mVechimeAni) {}
