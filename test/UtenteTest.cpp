//
// Created by Riccardo Becciolini on 22/02/23.
//

#include "gtest/gtest.h"
#include "../Utente.h"


class UtenteTest : public ::testing::Test {
public:
    void SetUp() override {
        u.attach(&l1);
        u.add(&l1, &p1);
    }

protected:
    Prodotto p1 = Prodotto("Uova", "Proteine", 6);
    Prodotto p2 = Prodotto("Latte", "Latticino", 2);

    ListaSpesa l1 =  ListaSpesa("Lista1");
    ListaSpesa l2= ListaSpesa("Lista2");
    Utente u = Utente("Riccardo");

};

TEST_F(UtenteTest, GetterSetter){
    ASSERT_EQ(u.getName(), "Riccardo");
    u.setName("Marco");
    ASSERT_EQ(u.getName(), "Marco");
}

TEST_F(UtenteTest, AddRemove){

    u.add(&l1, &p2);
    ASSERT_EQ(l1.getSize(), 2);

    u.remove(&l1, &p2);
    ASSERT_EQ(l1.getSize(), 1);
}

TEST_F(UtenteTest, AttachDetach) {
    u.attach(&l2);
    ASSERT_EQ(u.getSubjects().size(), 2);

    u.detach(&l2);
    ASSERT_EQ(u.getSubjects().size(), 1);
}

TEST_F(UtenteTest, Buy) {
    u.buy(&l1, &p1);

    ASSERT_TRUE(p1.isBought1());
}

