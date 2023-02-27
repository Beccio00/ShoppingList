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

bool Prodotto::isBought1() const {
    return isBought;
}

void Prodotto::setIsBought(bool isBought) {
    Prodotto::isBought = isBought;
}

