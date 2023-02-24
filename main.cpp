/*Classi che rappresentano una lista della spesa (es. Listonic): un utente deve avere diverse
 * liste della spesa dove segnare oggetti da acquistare che appartengono a diverse categorie ed
 * eventualmente con quantità da acquistare. Is usa Observer per aggiornare il numero di
 * oggetti da acquistare in una lista e quali questi siano. Si possono o avere più utenti che
 * condividono la stessa lista*/

#include <iostream>
#include "Utente.h"
#include "Prodotto.h"
#include "ListaSpesa.h"

using namespace std;

int main() {

    string name;
    std::string name1 = "Mario";
    std::string name2 = "Alice";

    std::string product1 = "Parmigiano";
    std::string product2 = "Mele";
    std::string product3 = "Latte";

    std::string category1 = "Latticino";
    std::string category2 = "Frutta";

    Prodotto p1(product1,category1, 3);
    Prodotto p2(product2, category2, 12);
    Prodotto p3(product3, category1, 2);

    Utente u1(name1);
    Utente u2(name2);


    ListaSpesa l("mylist");

    u1.attach(&l);
    u2.attach(&l);

    u1.add(&l, &p1);
    u2.add(&l, &p2);
    u1.add(&l, &p3);

    u1.displayList(&l);

    cout << "Inserisci il tuo nome" << endl;
    cin >> name;
    Utente u(name);






    return 0;
}
