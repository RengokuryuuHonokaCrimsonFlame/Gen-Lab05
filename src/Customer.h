// Customer.h
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>
#include "Rental.h"

class Customer {
public:
    Customer();
    explicit Customer( const std::string& name );
    virtual ~Customer();

    virtual void addRental( const Rental& arg );
    virtual std::string getName() const;
    virtual std::string statement();

    virtual double determineAmountsForEachLine(int daysRented, const Movie& movie);
    virtual void addFooterLines(std::ostringstream& result, double amount, int frequentRenterPoints);

private:
    std::string _name;
    std::vector< Rental > _rentals;
};

inline Customer::
Customer() {}

inline Customer::
Customer( const std::string& name )
        : _name( name ) {}

inline Customer::~Customer() {}

inline void Customer::
addRental( const Rental& arg ) { _rentals.push_back( arg ); }

inline std::string Customer::
getName() const { return _name; }

#endif // CUSTOMER_H