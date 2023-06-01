//
// Created by Riccardo Becciolini on 22/02/23.
//
#include "gtest/gtest.h"
#include "../ListaSpesa.h"



class ListaSpesaTest : public ::testing::Test {
public:

    void SetUp() override {
        l.addProd(p1, "Utente1");
        l.addProd(p2,"Utente2");
    }

protected:
    ListaSpesa l = ListaSpesa("La mia lista");
    std::shared_ptr<Prodotto> p1 = std::make_shared<Prodotto>("Formaggio", "Latticini", 1);
    std::shared_ptr<Prodotto> p2 = std::make_shared<Prodotto>("Fagioli", "Legumi", 3);
    std::shared_ptr<Prodotto> p3 = std::make_shared<Prodotto>("Insalata", "Oraraggi", 4 );
};


TEST_F(ListaSpesaTest, addProd) {

    l.addProd(p3, "Utente1");
    ASSERT_EQ(l.getSize(), 3);
}

TEST_F(ListaSpesaTest, removeProd) {

    ASSERT_EQ(l.removeProd(p1, "Utenete2"), 0);
    ASSERT_EQ(l.getSize(), 1);

    ASSERT_EQ(l.removeProd(p3, "Utente2"), 1);

}

TEST_F(ListaSpesaTest, modify){
    ASSERT_EQ(l.modifyQuantity(p1, 4, "Utente1"), 0);
    auto it = l.getProducts().begin();

    ASSERT_EQ(l.getSize(), 2);
    ASSERT_EQ((*it)->getQuantity(), 4);

    ASSERT_EQ(l.modifyQuantity(p3, 8, "Utente1"), 1);
}

TEST_F(ListaSpesaTest, buyProd) {
    ASSERT_EQ(l.buyProd(p1, "Utente2"), 0);
    auto it = l.getProducts().begin();
    ASSERT_TRUE((*it)->isBought1());

    ASSERT_EQ(l.buyProd(p1, "Utente2"), 1);
    ASSERT_EQ(l.buyProd(p3, "Utente2"), 2);
}