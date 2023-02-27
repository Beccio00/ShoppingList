//
// Created by Riccardo Becciolini on 22/02/23.
//

#include "gtest/gtest.h"
#include "../Utente.h"


class UtenteTest : public ::testing::Test {
public:
    void SetUp() override {
        u.attach(&l1);
    }

protected:
    Prodotto p = Prodotto("Latte", "Latticino", 2);
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

    u.add(&l1, &p);
    ASSERT_EQ(l1.getSize(), 1);

    u.remove(&l1, &p);
    ASSERT_EQ(l1.getSize(), 0);
}

TEST_F(UtenteTest, AttachDetach) {
    u.attach(&l2);
    ASSERT_EQ(u.getSubjects().size(), 2);

    u.detach(&l2);
    ASSERT_EQ(u.getSubjects().size(), 1);
}

