//
// Created by Riccardo Becciolini on 19/02/23.
//

#ifndef PROJECTLAB_LISTASPESA_H
#define PROJECTLAB_LISTASPESA_H

#include <iostream>
#include <list>
#include "Subject.h"
#include "Prodotto.h"
#include "Observer.h"

class ListaSpesa : public Subject{
public:
    ListaSpesa(std::string n): name(n){};



private:
    std::string name;
    std::list<Prodotto> prodotti;
    std::list<Observer*> observers;

};


#endif //PROJECTLAB_LISTASPESA_H
