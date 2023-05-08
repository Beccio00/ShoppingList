//
// Created by Riccardo Becciolini on 19/02/23.
//

#include "Prodotto.h"

bool Prodotto::operator==(const Prodotto &p) {
    if(this->name == p.name)
        return true;
    else
        return false;
}




