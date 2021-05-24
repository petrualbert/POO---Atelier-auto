//
// Created by Not Your Problem on 24.05.2021.
//

#ifndef POO___ATELIER_AUTO_ATELIER_H
#define POO___ATELIER_AUTO_ATELIER_H


#include <string>

class Atelier {

public:
    Atelier(const std::string &nume_atelier, int cont_curent, int rating);
    vector<Angajat*>angajat;
};


#endif //POO___ATELIER_AUTO_ATELIER_H
