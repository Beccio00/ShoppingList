//
// Created by Riccardo Becciolini on 19/02/23.
//

#ifndef PROJECTLAB_UTENTE_H
#define PROJECTLAB_UTENTE_H

#include "Observer.h"
#include <iostream>
#include <list>

class Utente {
public:
    Utente(std::string n, std::string s): name(n), surname(s){};


private:
    std::string name;
    std::string surname;
    std::list<Subject*> subjects;

};


#endif //PROJECTLAB_UTENTE_H
