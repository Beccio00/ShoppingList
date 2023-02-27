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
    explicit Utente(std::string n): name(n){};

    void attach(Subject* list) override;

    void detach(Subject* list) override;

    void update(Subject* list, std::string& s) override;

    void add(ListaSpesa* l, Prodotto* p);

    void remove(ListaSpesa* l, Prodotto* p);

    void modify(ListaSpesa* l, Prodotto* p, int q);

    void displayList(ListaSpesa* l);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::list<Subject *> &getSubjects() const;

private:
    std::string name;
    std::list<Subject*> subjects;
};


#endif //PROJECTLAB_UTENTE_H
