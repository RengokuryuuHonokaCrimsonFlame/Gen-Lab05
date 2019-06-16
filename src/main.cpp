#include <iostream>

#include "Customer.h"

public static void main() {

    Customer customer("Olivier");

    Movie * kk = new Movie("Karate Kid");
    NewRelease * ae = new NewRelease( "Avengers: Endgame");
    Children * sw = new Children("Snow White");

    Rental r1(*kk, 7);
    Rental r2(*ae, 5);
    Rental r3 (*sw, 3);

    customer.addRental(&r1);
    customer.addRental(&r2);
    customer.addRental(&r3);

    std::cout << customer.statement() << std::endl;

    delete kk;
    delete ae;
    delete sw;

    return 0;
}