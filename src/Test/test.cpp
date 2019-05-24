//
// Created by Rod Julien on 17.05.2019.
//

// Tests statement method
#include <Customer.h>
#include "gtest/gtest.h"

TEST(CustomerTest, StatementTest) {
    Customer customer("Olivier");
    customer.addRental( Rental( Movie("Karate Kid"), 7));
    customer.addRental( Rental( Movie( "Avengers: Endgame", Movie::NEW_RELEASE ), 5));
    customer.addRental( Rental( Movie("Snow White", Movie::CHILDRENS), 3 ));
    std::string exceptedOutput = "Rental Record for Olivier\n"
                                 "\tKarate Kid\t9.5\n"
                                 "\tAvengers: Endgame\t15\n"
                                 "\tSnow White\t1.5\n"
                                 "Amount owed is 26\n"
                                 "You earned 4 frequent renter points";
    ASSERT_EQ(customer.statement(), exceptedOutput);
}
