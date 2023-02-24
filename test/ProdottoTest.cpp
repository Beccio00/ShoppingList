//
// Created by Riccardo Becciolini on 22/02/23.
//

#include "gtest/gtest.h"
#include "../Prodotto.h"

TEST(ProdottoTest, Getter) {
    Prodotto p = Prodotto("Mele", "Frutta", 10);

    ASSERT_EQ(p.getName(), "Mele");
    ASSERT_EQ(p.getCategory(), "Frutta");
    ASSERT_EQ(p.getQuantity(), 10);
}

TEST(ProdottoTest, Setter) {
    Prodotto p = Prodotto("Mele", "Frutta", 10);

    p.setQuantity(5);

    ASSERT_EQ(p.getQuantity(), 5);
}

TEST(ProdottoTest, Operator) {
    Prodotto p1 = Prodotto("Mele", "Frutta", 10);
    Prodotto p2 = Prodotto("Mele", "Frutta", 10);
    Prodotto p3 = Prodotto("Latte", "Latticino", 2);

    ASSERT_TRUE(p1 == p2);
    ASSERT_FALSE(p1 == p3);
}