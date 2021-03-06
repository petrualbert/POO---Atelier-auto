#include <iostream>
#include "Atelier.h"
#include "Client.h"
#include "Reparatie.h"

int main() {

    Client client("Popescu Andrei",25,2500);

    Masina masina(&client,"Dacia","Logan",2006,200000);
    Mecanic mecanic("Bogdan Tatar", 45, 3100, 20);

    Angajat angajat("Maria Toader", 24, "casier", 2000, 2);

    Atelier atelier("Compact Team Service Auto", 5000,
                    {new Angajat(mecanic), new Angajat(angajat)});


    Mecanic mecanic2("Marian Neculai", 52, 3500, 25);
    atelier.adaugaAngajat(mecanic2);


    Reparatie reparatie(&atelier, &masina, &mecanic, 1700, {"baie ulei", "bloc motor"}, false);
    Reparatie reparatie2(&atelier, &masina, &mecanic2, 2000, {"pompe servodirectie"}, false);

    std::cout << atelier << '\n';
    std::cout << client << '\n';
    std::cout << reparatie2 << '\n';
    std::cout << reparatie << '\n';

    reparatie.taxeazaClientul();
    reparatie2.taxeazaClientul();
    std::cout << std::boolalpha;
    std::cout << "Prima reparatie achitata integral: " << reparatie.isMPlataEfectuata() << '\n';
    std::cout << "A doua reparatie achitata integral: " << reparatie2.isMPlataEfectuata() << '\n';

    atelier.adaugaRating(8);
    atelier.adaugaRating(9);

    std::cout << atelier << '\n';



    Atelier atelier_dupa_vanzare(atelier);
    atelier_dupa_vanzare.setMNumeAtelier("E AUTO Shop");
    atelier_dupa_vanzare.concediazaAngajat(mecanic2);
    atelier_dupa_vanzare.platesteSalariiAngajati();


    atelier = atelier_dupa_vanzare;
    std::cout << atelier << '\n';

    atelier.platesteSalariiAngajati();
    atelier.setMNumeAtelier("Compact 0 Team Service Auto");
    atelier.adaugaRating(1);
    std::cout << atelier << '\n';


    return 0;
}