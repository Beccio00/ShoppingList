
#include <iostream>
#include "Utente.h"
#include "Prodotto.h"
#include "ListaSpesa.h"

using namespace std;

int main() {
    shared_ptr<ListaSpesa> l1 = make_shared<ListaSpesa>("My List 1");
    shared_ptr<ListaSpesa> l2 = make_shared<ListaSpesa>("My List 2");

    Utente u1("Bob");
    Utente u2("Alice");

    shared_ptr<Prodotto> p1 = make_shared<Prodotto>("Latte", "Latticio", 3);
    shared_ptr<Prodotto> p2 =  make_shared<Prodotto>("Pasta", "Carboidrato", 4);
    shared_ptr<Prodotto> p3 =  make_shared<Prodotto>("Arancie", "Frutta", 6);
    shared_ptr<Prodotto> p4 = make_shared<Prodotto>("Sale", "Spezia", 1);
    shared_ptr<Prodotto> p5 = make_shared<Prodotto>("Succo", "Bevande", 4);
    shared_ptr<Prodotto> p6 = make_shared<Prodotto>("Tè", "Bevande", 2);

    u1.attach(l1.get());
    u1.attach(l2.get());
    u2.attach(l1.get());
    u2.attach(l2.get());

    u1.add(l1, p1);
    u2.add(l2, p2);
    u2.add(l1, p3);
    u1.add(l1, p4);
    u2.remove(l1, p1);
    u1.add(l1, p5);
    u2.add(l2, p5);
    u1.add(l2, p6);

    u1.displayList(l1);
    u2.displayList(l2);

    u1.buy(l1, p3);
    u2.buy(l1, p4);
    u1.modify(l1, p3, 2);

    u1.displayList(l1);

    return 0;
}
