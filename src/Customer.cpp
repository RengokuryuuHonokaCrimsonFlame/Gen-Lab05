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
    frequentRenterPoints = 0;
    record.clear();
    record << "Rental Record for " << getName() << "\n";
    for (const Rental * rental : _rentals) {
        totalAmount += updateRecordWithRental(rental);
    }
    return addFooterLines(totalAmount);
}

double Customer::updateRecordWithRental(const Rental *rental) {
    double result = rental->determineAmountsForEachLine();
    frequentRenterPoints += (rental->addBonusForATwoDayNewReleaseRental()) ? 2 : 1;
    record << "\t" << rental->getMovieName() << "\t" << result << "\n";
    return result;
}


std::string Customer::addFooterLines(double amount){
    record << "Amount owed is " << amount << "\n"
           << "You earned " << frequentRenterPoints
           << " frequent renter points";
    return record.str();
}