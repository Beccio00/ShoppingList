//
// Created by Riccardo Becciolini on 22/02/23.
//

#include "gtest/gtest.h"
#include "../Utente.h"

TEST(Utente, GetterSetter){
    Utente u("Riccardo");
    ASSERT_EQ(u.getName(), "Riccardo");
    u.setName("Marco");
    ASSERT_EQ(u.getName(), "Marco");
}
