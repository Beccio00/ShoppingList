//
// Created by Riccardo Becciolini on 22/02/23.
//

#include "gtest/gtest.h"
#include "../Utente.h"

TEST(UtenteTest, GetterSetter){
    Utente u("Riccardo");
    ASSERT_EQ(u.getName(), "Riccardo");
    u.setName("Marco");
    ASSERT_EQ(u.getName(), "Marco");
}


TEST(UtenteTest, AddRemove){
    Prodotto p("Pasta", "Primo", 2);
    ListaSpesa l("La Mia Lista");
    Utente u("Marco");

    u.add(&l, p);
    ASSERT_EQ(l.getSize(), 1);

    //u.remove(&l, p);
    //ASSERT_EQ(l.getSize(), 0);
}

