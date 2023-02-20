//
// Created by Riccardo Becciolini on 19/02/23.
//

#ifndef PROJECTLAB_LISTASPESA_H
#define PROJECTLAB_LISTASPESA_H

#include <iostream>
#include <list>
#include <algorithm>
#include "Subject.h"
#include "Prodotto.h"
#include "Observer.h"

class ListaSpesa : public Subject{
public:
    ListaSpesa(std::string& n): name(n){};

    void addProd(Prodotto& p);

    void removeProd(Prodotto& p);

    void subscribe(Observer* o) override;

    void unsubscribe(Observer* o) override;

    void notify() override;

    const std::string &getName() const;

    void setName(const std::string &name);

    void modifyQuantity(Prodotto& p);


private:
    std::string name;
    std::list<Prodotto> products;
    std::list<Observer*> observers;

};


#endif //PROJECTLAB_LISTASPESA_H
