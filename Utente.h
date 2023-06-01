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
#include <memory>

class Utente : public Observer{
public:
    explicit Utente(const std::string& n): name(n){};

    void attach(Subject* list) override;

    void detach(Subject* list) override;

    void update(const std::string& s) override;

    int add(std::shared_ptr<ListaSpesa> l, std::shared_ptr<Prodotto> p);

    int remove(std::shared_ptr<ListaSpesa> l, std::shared_ptr<Prodotto> p);

    int modify(std::shared_ptr<ListaSpesa> l, std::shared_ptr<Prodotto> p, int q);

    int buy(std::shared_ptr<ListaSpesa> l, std::shared_ptr<Prodotto> p);

    int displayList(std::shared_ptr<ListaSpesa> l);

    const std::string &getName() const;

    void setName(const std::string& name);

    const std::list<Subject *> &getSubjects() const;

private:
    std::string name;
    std::list<Subject*> subjects;
};


#endif //PROJECTLAB_UTENTE_H
