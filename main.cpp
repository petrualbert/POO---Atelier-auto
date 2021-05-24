#include <iostream>
#include "Atelier.h"
#include "Client.h"
#include "Reperatie.h"
#include "Persoana.h"

int main() {
    Atelier a("nume", 5000, 10 );  // nume, cont_curent si rating
    Client c("nume");
    Masina m("marca", 100000);
    Reperatie r("piesa", 1000);
    Mecanic mc;



    c.cere_pret();

    //a.atribuie_mecanic(); asta dupa ce mai dezvolt aplicatia

    std::cout << "Reparatia costa" << r.pret_total();

    mc.repara_masina(m); // creste contul curent al firmei

    c.lasa_rating(a);// creste ratingul atelierului sau scade, vom face o medie daca vor exista mai multe

    std::cout << "Reparatia costa";


    return 0;
}