#include "Persoana.h"


Persoana::Persoana() {
this->m_nume = "Fara nume";
}

const std::string &Persoana::getMNume() const {
    return m_nume;
}

void Persoana::setMNume(const std::string &mNume) {
    m_nume = mNume;
}

std::ostream &operator<<(std::ostream &os, const Persoana &persoana) {
    os << "Persoana " << persoana.getMNume() << " cu varsta de " << persoana.getMVarsta() << " ani";
    return os;
}

Persoana::Persoana(const std::string &mNume, int mVarsta) : m_nume(mNume), m_varsta(mVarsta) {}

int Persoana::getMVarsta() const {
    return m_varsta;
}

void Persoana::setMVarsta(int mVarsta) {
    m_varsta = mVarsta;
}
