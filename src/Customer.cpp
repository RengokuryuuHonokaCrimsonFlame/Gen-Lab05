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
    for (Rental rental : _rentals) {

        double thisAmount = 0;
        thisAmount += rental.determineAmountsForEachLine();


        frequentRenterPoints++;

        if (rental.addBonusForATwoDayNewReleaseRental()) frequentRenterPoints++;

        result << "\t" << rental.getMovieName() << "\t" << thisAmount << "\n";
        totalAmount += thisAmount;
    }

    addFooterLines(result, totalAmount, frequentRenterPoints);

    return result.str();
}


void Customer::addFooterLines(std::ostringstream& result, double amount, int frequentRenterPoints){
    result << "Amount owed is " << amount << "\n"
           << "You earned " << frequentRenterPoints
           << " frequent renter points";
}