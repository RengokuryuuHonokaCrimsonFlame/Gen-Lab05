// Customer.cpp
#include <sstream>
#include <vector>
#include "Customer.h"

using std::ostringstream;
using std::vector;

using namespace std;

string Customer::statement()
{
    double totalAmount = 0;
    int frequentRenterPoints = 0;
    ostringstream result;
    result << "Rental Record for " << getName() << "\n";
    for (auto rental : _rentals) {

        const Movie * video = rental.getMovie();
        double thisAmount = 0;
        // determine amounts for each line
        thisAmount += video->getBaseAmount() ;
        if(rental.getDaysRented() > video->getMaxDay()){
            thisAmount += (rental.getDaysRented() - video->getMaxDay()) * video->getFeePerExpendDay();
        }

        // add frequent renter points
        frequentRenterPoints++;
        // add bonus for a two day new release rental
        if ( video->hasBonus()
             && rental.getDaysRented() > 1 ) frequentRenterPoints++;

        // show figures for this rental
        result << "\t" << video->getTitle() << "\t"
               << thisAmount << "\n";
        totalAmount += thisAmount;
    }
    // add footer lines
    result << "Amount owed is " << totalAmount << "\n";
    result << "You earned " << frequentRenterPoints
           << " frequent renter points";
    return result.str();
}