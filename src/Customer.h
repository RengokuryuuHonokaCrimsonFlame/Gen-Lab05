// Customer.h
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <memory>
#include <vector>
#include "Rental.h"

class Customer {
public:
    explicit Customer( const std::string& name );
    virtual ~Customer();

    virtual void addRental( const Rental * arg );
    virtual std::string getName() const;
    virtual std::string statement();
    virtual double updateRecordWithRental(const Rental *rental);
    virtual std::string addFooterLines(double amount);

private:
    std::string _name;
    std::vector< const Rental * > _rentals;
    int frequentRenterPoints = 0;
    std::ostringstream record;
};

inline Customer::
Customer( const std::string& name )
        : _name( name ) {}

inline Customer::~Customer() = default;

inline void Customer::
addRental( const Rental * arg ) { _rentals.push_back( arg ); }

inline std::string Customer::
getName() const { return _name; }

#endif // CUSTOMER_H