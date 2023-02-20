//
// Created by Riccardo Becciolini on 19/02/23.
//

#ifndef PROJECTLAB_UTENTE_H
#define PROJECTLAB_UTENTE_H

#include "Observer.h"
#include "ListaSpesa.h"
#include <iostream>
#include <list>
#include <algorithm>

class Utente : public Observer{
public:
    Utente(std::string& n, std::string& s): name(n), surname(s){};

    void attach(Subject* list) override;

    void detach(Subject* list) override;

    void update(Subject* list) override;

    void add(ListaSpesa* l, Prodotto& p);

    void remove(ListaSpesa* l, Prodotto& p);

    void modify(ListaSpesa* l, Prodotto& p);



private:
    std::string name;
    std::string surname;
    std::list<Subject*> subjects;

};


#endif //PROJECTLAB_UTENTE_H
