//
// Created by Riccardo Becciolini on 19/02/23.
//

#ifndef PROJECTLAB_LISTASPESA_H
#define PROJECTLAB_LISTASPESA_H

#include <iostream>
#include <list>
#include <algorithm>
#include <iomanip>
#include <memory>
#include "Subject.h"
#include "Prodotto.h"
#include "Observer.h"


class ListaSpesa : public Subject{
public:
    explicit ListaSpesa(const std::string& n): name(n){};

    void addProd(std::shared_ptr<Prodotto> p, const std::string& u);

    void removeProd(std::shared_ptr<Prodotto> p, const std::string& u);

    void modifyQuantity(std::shared_ptr<Prodotto> p, int q, const std::string& u);

    void buyProd(std::shared_ptr<Prodotto> p, const std::string& u);

    void subscribe(Observer* o) override;

    void unsubscribe(Observer* o) override;

    void notify(int num, const std::string& u) override;

    const std::string &getName() const;

    void setName(const std::string &name);

    void display();

    int getSize();

    const std::list<Prodotto *> &getProducts() const;




private:
    std::string name;
    std::list<std::shared_ptr<Prodotto> > products;
    std::list<Observer*> observers;
};


#endif //PROJECTLAB_LISTASPESA_H
