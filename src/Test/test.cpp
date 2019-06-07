//
// Created by Rod Julien on 17.05.2019.
//

// Tests statement method
#include <Customer.h>
#include "gtest/gtest.h"

TEST(CustomerTest, StatementTest) {
    Customer customer("Olivier");

    Movie * kk = new Movie("Karate Kid");
    New_Release * ae = new New_Release( "Avengers: Endgame");
    Children * sw = new Children("Snow White");

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
