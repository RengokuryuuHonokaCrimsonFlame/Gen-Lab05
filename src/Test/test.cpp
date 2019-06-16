//
// Created by Rod Julien on 17.05.2019.
//

// Tests statement method
#include <Customer.h>
#include "gtest/gtest.h"
#include <gmock/gmock.h>
#include "memory.h"

using ::testing::Return;

class MockMovie : public Movie{
public:
    MOCK_CONST_METHOD0(getBaseAmount, double() );
    MOCK_CONST_METHOD0(getMaxDay, int());
    MOCK_CONST_METHOD0(getFeePerExpendDay, double());
    MOCK_CONST_METHOD0(hasBonus, bool());
};

class MockNew_Release : public New_Release{
public:
    MOCK_CONST_METHOD0(getBaseAmount, double());
    MOCK_CONST_METHOD0(getMaxDay, int());
    MOCK_CONST_METHOD0(getFeePerExpendDay, double());
    MOCK_CONST_METHOD0(hasBonus, bool());
};

class MockChildren : public Children{
public:
    MOCK_CONST_METHOD0(getBaseAmount, double());
    MOCK_CONST_METHOD0(getMaxDay, int());
    MOCK_CONST_METHOD0(getFeePerExpendDay, double());
    MOCK_CONST_METHOD0(hasBonus, bool());
};

class MockRental : public Rental{
public:
    MOCK_METHOD0(getDaysRented, int());
    MOCK_METHOD0(getMovie, const Movie*());
    MOCK_CONST_METHOD0(addBonusForATwoDayNewReleaseRental, bool());
    MOCK_CONST_METHOD2(showFiguresForThisRental, void (std::ostringstream& result, double amount));
};



TEST(CustomerTest, StatementTest) {
    Customer customer("Olivier");

    Movie * kk = new Movie("Karate Kid");
    Movie * ae = new New_Release( "Avengers: Endgame");
    Movie * sw = new Children("Snow White");

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

TEST(CustomerTest, DetermineAmountsTest) {

    Customer customer("Julien");
    Movie * m = new Movie("Test Movies");
    ASSERT_EQ(customer.determineAmountsForEachLine(5, *m), 6.5);
    delete m;

    New_Release * nr = new New_Release( "Test New Releases");
    ASSERT_EQ(customer.determineAmountsForEachLine(4, *nr), 12);
    delete nr;

    Children * c = new Children("Test Children");
    ASSERT_EQ(customer.determineAmountsForEachLine(5, *c), 4.5);
    delete c;
}

TEST(CustomerTest, MovieTest) {
   Movie m = Movie("Test");
   ASSERT_EQ("Test", m.getTitle());
   ASSERT_EQ(2, m.getBaseAmount());
   ASSERT_EQ(2, m.getMaxDay());
   ASSERT_EQ(1.5, m.getFeePerExpendDay());
   ASSERT_EQ(false, m.hasBonus());
}

TEST(CustomerTest, ChildrenTest) {
    Children m = Children("Massacre à la tronçonneuse");
    ASSERT_EQ("Massacre à la tronçonneuse", m.getTitle());
    ASSERT_EQ(1.5, m.getBaseAmount());
    ASSERT_EQ(3, m.getMaxDay());
    ASSERT_EQ(1.5, m.getFeePerExpendDay());
    ASSERT_EQ(false, m.hasBonus());
}

TEST(CustomerTest, NewReleaseTest) {
    New_Release m = New_Release("Me and the boys");
    ASSERT_EQ("Me and the boys", m.getTitle());
    ASSERT_EQ(0, m.getBaseAmount());
    ASSERT_EQ(0, m.getMaxDay());
    ASSERT_EQ(3, m.getFeePerExpendDay());
    ASSERT_EQ(true, m.hasBonus());
}


TEST(CustomerTest, AddFooterLinesTest){
    Customer c = Customer("Jupiter");
    std::ostringstream os;
    c.addFooterLines(os,5.5,3);
    ASSERT_EQ("Amount owed is 5.5\nYou earned 3 frequent renter points", os.str());
}

TEST(CustomerTest, AddBonusForATwoDayNewReleaseRentalTest) {
    std::unique_ptr<MockMovie> m(new MockMovie());
    std::unique_ptr<MockNew_Release> m2(new MockNew_Release());

    EXPECT_CALL(*m,hasBonus()).WillRepeatedly(Return(false));
    EXPECT_CALL(*m2, hasBonus()).WillRepeatedly(Return(true));

    Rental r(*m,20);
    Rental r2(*m2,20);

    ASSERT_EQ(false, r.addBonusForATwoDayNewReleaseRental());
    ASSERT_EQ(true, r2.addBonusForATwoDayNewReleaseRental());
}
