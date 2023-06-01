//
// Created by Riccardo Becciolini on 22/02/23.
//

#include "gtest/gtest.h"
#include "../Utente.h"


class UtenteTest : public ::testing::Test {
public:
    void SetUp() override {
        u.attach(l1.get());
        u.add(l1, p1);
    }

protected:
    std::shared_ptr<Prodotto> p1 = std::make_shared<Prodotto>("Uova", "Proteine", 6);
    std::shared_ptr<Prodotto> p2 = std::make_shared<Prodotto>("Latte", "Latticino", 2);

    std::shared_ptr<ListaSpesa> l1 =  std::make_shared<ListaSpesa>("Lista1");
    std::shared_ptr<ListaSpesa> l2= std::make_shared<ListaSpesa>("Lista2");
    Utente u = Utente("Riccardo");

};

TEST_F(UtenteTest, GetterSetter){
    ASSERT_EQ(u.getName(), "Riccardo");
    u.setName("Marco");
    ASSERT_EQ(u.getName(), "Marco");
}

TEST_F(UtenteTest, AddRemove){

    ASSERT_EQ(u.add(l1, p2), 0);
    ASSERT_EQ(l1->getSize(), 2);

    ASSERT_EQ(u.add(l2, p2), 1);
    ASSERT_EQ(l1->getSize(), 2);

    ASSERT_EQ(u.remove(l2, p2), 1);
    ASSERT_EQ(l1->getSize(), 2);

    ASSERT_EQ(u.remove(l1, p2), 0);
    ASSERT_EQ(l1->getSize(), 1);
}

TEST_F(UtenteTest, AttachDetach) {
    u.attach(l2.get());
    ASSERT_EQ(u.getSubjects().size(), 2);

    u.detach(l2.get());
    ASSERT_EQ(u.getSubjects().size(), 1);
}

TEST_F(UtenteTest, Buy) {
    ASSERT_EQ(u.buy(l1, p1), 0);
    ASSERT_TRUE(p1->isBought1());

    ASSERT_EQ(u.buy(l2, p1), 1);
}

TEST_F(UtenteTest, Modify) {
    ASSERT_EQ(u.modify(l1, p1, 4), 0);

    ASSERT_EQ(u.modify(l2, p1, 4), 1);
}

TEST_F(UtenteTest, DisplayList) {
    ASSERT_EQ(u.displayList(l1), 0);

    ASSERT_EQ(u.displayList(l2), 1);
}
