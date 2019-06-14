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

        double thisAmount = 0;
        thisAmount += determineAmountsForEachLine(rental.getDaysRented(), *rental.getMovie());


        frequentRenterPoints++;

        // add bonus for a two day new release rental
        if (addBonusForATwoDayNewReleaseRental(rental)) frequentRenterPoints++;

        showFiguresForThisRental(result, *rental.getMovie(), thisAmount);
        totalAmount += thisAmount;
    }

    addFooterLines(result, totalAmount, frequentRenterPoints);

    return result.str();
}

double Customer::determineAmountsForEachLine(int daysRented, const Movie& video){
    double result = video.getBaseAmount();
    if(daysRented > video.getMaxDay()){
        result += (daysRented - video.getMaxDay()) * video.getFeePerExpendDay();
    }
    return result;
}

void Customer::showFiguresForThisRental(ostringstream& result, const Movie& video, double amount){
    result << "\t" + video.getTitle() << "\t" << amount << "\n";
}

void Customer::addFooterLines(std::ostringstream& result, double amount, int frequentRenterPoints){
    result << "Amount owed is " << amount << "\n"
           << "You earned " << frequentRenterPoints
           << " frequent renter points";
}

bool Customer::addBonusForATwoDayNewReleaseRental(Rental rental){
    return  rental.getMovie()->hasBonus() && rental.getDaysRented() > 1;
}