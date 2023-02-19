//
// Created by Riccardo Becciolini on 19/02/23.
//

#ifndef PROJECTLAB_PRODOTTO_H
#define PROJECTLAB_PRODOTTO_H

#include <iostream>

class Prodotto {
public:
    Prodotto(std::string& n, std::string& c, int q): name(n), category(c), quantity(q) {}


    const std::string &getName() const {
        return name;
    }

    const std::string &getCategory() const {
        return category;
    }

    int getQuantity() const {
        return quantity;
    }

    void setQuantity(int quantity) {
        Prodotto::quantity = quantity;
    }

private:
    std::string name;
    std::string category;
    int quantity;
};


#endif //PROJECTLAB_PRODOTTO_H
