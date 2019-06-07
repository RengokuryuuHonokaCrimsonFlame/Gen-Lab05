#include <iostream>

#include "Customer.h"

int main() {

    Customer customer("Olivier");

    Movie * kk = new Movie("Karate Kid");
    New_Release * ae = new New_Release( "Avengers: Endgame");
    Children * sw = new Children("Snow White");

    customer.addRental( Rental( *kk, 7));
    customer.addRental( Rental( *ae, 5));
    customer.addRental( Rental( *sw, 3 ));

    std::cout << customer.statement() << std::endl;

    delete kk;
    delete ae;
    delete sw;

    return 0;
}