//
// Created by Riccardo Becciolini on 22/02/23.
//
#include "gtest/gtest.h"
#include "../ListaSpesa.h"



class ListaSpesaTest : public ::testing::Test {
public:

    void SetUp() override {
        l.addProd(&p1, "Utente1");
        l.addProd(&p2,"Utente2");
    }

protected:
    ListaSpesa l = ListaSpesa("La mia lista");
    Prodotto p1 = Prodotto("Formaggio", "Latticini", 1);
    Prodotto p2 = Prodotto("Fagioli", "Legumi", 3);
    Prodotto p3 = Prodotto("Insalata", "Oraraggi", 4 );
};


TEST_F(ListaSpesaTest, addProd) {

    l.addProd(&p3, "Utente1");
    ASSERT_EQ(l.getSize(), 3);
}

TEST_F(ListaSpesaTest, removeProd) {

    l.removeProd(&p1, "Utenete2");
    ASSERT_EQ(l.getSize(), 1);

}

TEST_F(ListaSpesaTest, modify){
    l.modifyQuantity(&p1, 4, "Utente1");
    auto it = l.getProducts().begin();
    ASSERT_EQ(l.getSize(), 2);
    ASSERT_EQ((*it)->getQuantity(), 4);
}

TEST_F(ListaSpesaTest, buyProd) {
    l.buyProd(&p1, "Utente2");
    auto it = l.getProducts().begin();
    ASSERT_TRUE((*it)->isBought1());
}