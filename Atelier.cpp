#include "Atelier.h"
#include <iostream>
#include <algorithm>
const std::string &Atelier::getMNumeAtelier() const {
    return m_nume_atelier;
}

void Atelier::setMNumeAtelier(const std::string &mNumeAtelier) {
    m_nume_atelier = mNumeAtelier;
}

int Atelier::getMCont() const {
    return m_cont;
}

void Atelier::setMCont(int mCont) {
    m_cont = mCont;
}

float Atelier::getMRating() const {
    return m_rating;
}

void Atelier::adaugaRating(int nota){
    m_note_primite.push_back(nota);
    int sum = 0;
    for(auto nota : m_note_primite)
    {
        sum += nota;
    }
    m_rating = sum / m_note_primite.size();
}

const std::vector<Angajat *> &Atelier::getMAngajati() const {
    return m_angajati;
}

void Atelier::setMAngajati(const std::vector<Angajat *> &mAngajati) {
    m_angajati = mAngajati;
}

std::ostream &operator<<(std::ostream &os, const Atelier &atelier) {
    os << "Atelierul " << atelier.m_nume_atelier << " are cont valutar de " << atelier.m_cont << " LEI"
     << ", rating " << atelier.m_rating << " si " << atelier.m_angajati.size() << " angajati";

    return os;
}

Atelier::~Atelier() {
    for(int i=0;i<m_angajati.size();i++)
        delete m_angajati[i];
    m_angajati.clear();
}

void Atelier::platesteSalariiAngajati() {
    int i = 0;
    for (auto &ang : m_angajati)
    {
        if (m_cont - ang->getMSalariu() > 0)
        {
            m_cont -= ang->getMSalariu();
            i++;
        }
    }
    if(i==0)
        std::cout << "Nu mai sunt bani pentru plata salariilor!" << '\n';
    else
        std::cout << "Plata salariilor efectuata!" << '\n';
}

Atelier& Atelier::operator=(const Atelier &ob) {
    if(this == &ob)
        return *this;
    for(int i=0;i<m_angajati.size();i++)
        delete m_angajati[i];
    m_angajati.clear();
//     deep copy
    for(auto a : ob.m_angajati)
    {
        m_angajati.push_back(new Angajat(*a));
    }

    m_cont = ob.m_cont;
    m_nume_atelier = ob.m_nume_atelier;
    m_rating = ob.m_rating;
    m_note_primite = ob.m_note_primite;
    return *this;
}

Atelier::Atelier(const Atelier &ob)
{
    for(int i=0;i<m_angajati.size();i++)
        delete m_angajati[i];
    m_angajati.clear();
    // deep copy
    for(auto a : ob.m_angajati)
    {
        this->m_angajati.push_back(new Angajat(*a));
    }

    m_cont = ob.m_cont;
    m_nume_atelier = ob.m_nume_atelier;
    m_rating = ob.m_rating;
    m_note_primite = ob.m_note_primite;
}


Atelier::Atelier(const std::string &mNumeAtelier, int mCont, const std::vector<Angajat *> &mAngajati) : m_nume_atelier(
        mNumeAtelier), m_cont(mCont), m_angajati(mAngajati) {}



void Atelier::concediazaAngajat(const Angajat &angajat) {

    auto nume = angajat.getMNume();
    auto pred = [&nume](auto item) -> bool
    {
        return (item->getMNume() == nume);
    };
    m_angajati.erase(std::remove_if(m_angajati.begin(), m_angajati.end(), pred), m_angajati.end());

  /*
   * VARIANTA 2
   */
//    std::vector<Angajat *>::iterator it;
//    for (std::vector<Angajat *>::iterator it = m_angajati.begin(); it != m_angajati.end(); ++it) {
//        Angajat *p = *it;
//        if (p->getMNume() == angajat.getMNume()) {
//            it = m_angajati.erase(it);
//            --it;
//        }
//    }

}

void Atelier::adaugaAngajat(Angajat &angajat) {
    Angajat *p = new Angajat(angajat);
    m_angajati.push_back(p);
}
