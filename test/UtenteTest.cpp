//
// Created by Riccardo Becciolini on 22/02/23.
//

#include "gtest/gtest.h"
#include "../Utente.h"


class UtenteTest : public ::testing::Test {
public:
    void SetUp() override {
        l1 = new ListaSpesa("Lista1");
        l2 = new ListaSpesa("Lista2");
        u = new Utente("Riccardo");
        u->attach(l1);
        u->attach(l2);
    }

    void TearDown() override {
        delete l1;
        delete l2;
        delete u;
    }

    ListaSpesa* l1;
    ListaSpesa* l2;
    Utente* u;

};

TEST_F(UtenteTest, GetterSetter){
    ASSERT_EQ(u->getName(), "Riccardo");
    u->setName("Marco");
    ASSERT_EQ(u->getName(), "Marco");
}

TEST_F(UtenteTest, AddRemove){
    Prodotto p("Prosciutto", "Affettati", 2);

    u->add(l1, &p);
    ASSERT_EQ(l1->getSize(), 1);

    u->remove(l1, &p);
    ASSERT_EQ(l1->getSize(), 0);
}



