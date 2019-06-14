//
// Created by Rod Julien on 17.05.2019.
//

// Tests statement method
#include <Customer.h>
#include "gtest/gtest.h"

TEST(CustomerTest, StatementTest) {
    Customer customer("Olivier");

    Movie * kk = new Movie("Karate Kid");
    Movie * ae = new New_Release( "Avengers: Endgame");
    Movie * sw = new Children("Snow White");

    customer.addRental( Rental( *kk, 7));
    customer.addRental( Rental( *ae, 5));
    customer.addRental( Rental( *sw, 3 ));
    std::string exceptedOutput = "Rental Record for Olivier\n"
                                 "\tKarate Kid\t9.5\n"
                                 "\tAvengers: Endgame\t15\n"
                                 "\tSnow White\t1.5\n"
                                 "Amount owed is 26\n"
                                 "You earned 4 frequent renter points";

    ASSERT_EQ(customer.statement(), exceptedOutput);

    delete kk;
    delete ae;
    delete sw;
}

TEST(CustomerTest, DetermineAmountsTest) {

    Customer customer("Julien");
    Movie * m = new Movie("Test Movies");
    ASSERT_EQ(customer.determineAmountsForEachLine(5, *m), 6.5);
    delete m;

    New_Release * nr = new New_Release( "Test New Releases");
    ASSERT_EQ(customer.determineAmountsForEachLine(4, *nr), 12);
    delete nr;

    Children * c = new Children("Test Children");
    ASSERT_EQ(customer.determineAmountsForEachLine(5, *c), 4.5);
    delete c;
}

TEST(CustomerTest, MovieTest) {
   Movie m = Movie("Test");
   ASSERT_EQ("Test", m.getTitle());
   ASSERT_EQ(2, m.getBaseAmount());
   ASSERT_EQ(2, m.getMaxDay());
   ASSERT_EQ(1.5, m.getFeePerExpendDay());
   ASSERT_EQ(false, m.hasBonus());
}

TEST(CustomerTest, ChildrenTest) {
    Children m = Children("Massacre à la tronçonneuse");
    ASSERT_EQ("Massacre à la tronçonneuse", m.getTitle());
    ASSERT_EQ(1.5, m.getBaseAmount());
    ASSERT_EQ(3, m.getMaxDay());
    ASSERT_EQ(1.5, m.getFeePerExpendDay());
    ASSERT_EQ(false, m.hasBonus());
}

TEST(CustomerTest, NewReleaseTest) {
    New_Release m = New_Release("Me and the boys");
    ASSERT_EQ("Me and the boys", m.getTitle());
    ASSERT_EQ(0, m.getBaseAmount());
    ASSERT_EQ(0, m.getMaxDay());
    ASSERT_EQ(3, m.getFeePerExpendDay());
    ASSERT_EQ(true, m.hasBonus());
}

TEST(CustomerTest, AddFooterLinesTest){

}

TEST(CustomerTest, AddBonusForATwoDayNewReleaseRentalTest) {

}


