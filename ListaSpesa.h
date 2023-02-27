//
// Created by Riccardo Becciolini on 19/02/23.
//

#ifndef PROJECTLAB_LISTASPESA_H
#define PROJECTLAB_LISTASPESA_H

#include <iostream>
#include <list>
#include <algorithm>
#include <iomanip>
#include "Subject.h"
#include "Prodotto.h"
#include "Observer.h"


class ListaSpesa : public Subject{
public:
    explicit ListaSpesa(std::string n): name(n){};

    void addProd(Prodotto* p, std::string u);

    void removeProd(Prodotto* p, std::string u);

    void modifyQuantity(Prodotto* p, int q, std::string u);

    void buyProd(Prodotto* p, std::string u);

    void subscribe(Observer* o) override;

    void unsubscribe(Observer* o) override;

    void notify(int num, std::string u) override;

    const std::string &getName() const;

    void setName(const std::string &name);

    void display();

    int getSize();

    const std::list<Prodotto *> &getProducts() const;




private:
    std::string name;
    std::list<Prodotto* > products;
    std::list<Observer*> observers;
};


#endif //PROJECTLAB_LISTASPESA_H
