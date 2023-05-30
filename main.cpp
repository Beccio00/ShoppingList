
#include <iostream>
#include "Utente.h"
#include "Prodotto.h"
#include "ListaSpesa.h"

using namespace std;

int main() {
    ListaSpesa l1("My List 1");
    ListaSpesa l2("My List 2");

    Utente u1("Bob");
    Utente u2("Alice");

    Prodotto p1("Latte", "Latticio", 3);
    Prodotto p2("Pasta", "Carboidrato", 4);
    Prodotto p3("Arancie", "Frutta", 6);
    Prodotto p4("Sale", "Spezia", 1);
    Prodotto p5("Succo", "Bevande", 4);
    Prodotto p6("Tè", "Bevande", 2);

    u1.attach(&l1);
    u1.attach(&l2);
    u2.attach(&l1);
    u2.attach(&l2);

    u1.add(&l1, &p1);
    u2.add(&l2, &p2);
    u2.add(&l1, &p3);
    u1.add(&l1, &p4);
    u2.remove(&l1, &p1);
    u1.add(&l1, &p5);
    u2.add(&l2, &p5);
    u1.add(&l2, &p6);

    u1.displayList(&l1);
    u2.displayList(&l2);

    u1.buy(&l1, &p3);
    u2.buy(&l1, &p4);
    u1.modify(&l1, &p3, 2);

    u1.displayList(&l1);

    return 0;
}
