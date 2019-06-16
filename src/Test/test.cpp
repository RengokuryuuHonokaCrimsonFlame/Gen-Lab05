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

class MockNewRelease : public NewRelease{
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
    MOCK_CONST_METHOD0(determineAmountsForEachLine, double());
    MOCK_CONST_METHOD0(getMovieName, std::string());
};



TEST(CustomerTest, StatementTest) {
    Customer customer("Olivier");

    std::unique_ptr<MockRental> r1(new MockRental);
    EXPECT_CALL(*r1, getMovieName()).WillRepeatedly(Return("Karate Kid"));
    EXPECT_CALL(*r1, determineAmountsForEachLine()).WillRepeatedly(Return(9.5));

    std::unique_ptr<MockRental> r2(new MockRental);
    EXPECT_CALL(*r2, getMovieName()).WillRepeatedly(Return("Avengers: Endgame"));
    EXPECT_CALL(*r2, determineAmountsForEachLine()).WillRepeatedly(Return(15));

    std::unique_ptr<MockRental> r3(new MockRental);
    EXPECT_CALL(*r3, getMovieName()).WillRepeatedly(Return("Snow White"));
    EXPECT_CALL(*r3, determineAmountsForEachLine()).WillRepeatedly(Return(1.5));

    customer.addRental(*r1);
    customer.addRental(*r2);
    customer.addRental(*r3);

    std::string exceptedOutput = "Rental Record for Olivier\n"
                                 "\tKarate Kid\t9.5\n"
                                 "\tAvengers: Endgame\t15\n"
                                 "\tSnow White\t1.5\n"
                                 "Amount owed is 26\n"
                                 "You earned 4 frequent renter points";

    ASSERT_EQ(customer.statement(), exceptedOutput);
}


TEST(CustomerTest, AddFooterLinesTest){
    Customer c = Customer("Jupiter");
    std::ostringstream os;
    c.addFooterLines(os,5.5,3);
    ASSERT_EQ("Amount owed is 5.5\nYou earned 3 frequent renter points", os.str());
}

TEST(RentalTest, DetermineAmountsTest) {

    std::unique_ptr<MockMovie> m (new MockMovie());
    EXPECT_CALL(*m, getBaseAmount()).WillRepeatedly(Return(2));
    EXPECT_CALL(*m, getMaxDay()).WillRepeatedly(Return(2));
    EXPECT_CALL(*m, getFeePerExpendDay()).WillRepeatedly(Return(1.5));

    Rental r1(*m, 5);
    ASSERT_EQ(r1.determineAmountsForEachLine(), 6.5);

    std::unique_ptr<MockNewRelease> nr (new MockNewRelease());
    EXPECT_CALL(*nr, getBaseAmount()).WillRepeatedly(Return(0));
    EXPECT_CALL(*nr, getMaxDay()).WillRepeatedly(Return(0));
    EXPECT_CALL(*nr, getFeePerExpendDay()).WillRepeatedly(Return(3));

    Rental r2(*nr, 4);
    ASSERT_EQ(r2.determineAmountsForEachLine(), 12);

    std::unique_ptr<MockChildren> c(new MockChildren());
    EXPECT_CALL(*c, getBaseAmount()).WillRepeatedly(Return(1.5));
    EXPECT_CALL(*c, getMaxDay()).WillRepeatedly(Return(3));
    EXPECT_CALL(*c, getFeePerExpendDay()).WillRepeatedly(Return(1.5));

    Rental r3(*c, 5);
    ASSERT_EQ(r3.determineAmountsForEachLine(), 4.5);
}


TEST(RentalTest, AddBonusForATwoDayNewReleaseRentalTest) {
    std::unique_ptr<MockMovie> m(new MockMovie());
    std::unique_ptr<MockNewRelease> m2(new MockNewRelease());

    EXPECT_CALL(*m,hasBonus()).WillRepeatedly(Return(false));
    EXPECT_CALL(*m2, hasBonus()).WillRepeatedly(Return(true));

    Rental r(*m,20);
    Rental r2(*m2,20);

    ASSERT_EQ(false, r.addBonusForATwoDayNewReleaseRental());
    ASSERT_EQ(true, r2.addBonusForATwoDayNewReleaseRental());
}

TEST(MovieTest, MovieTest) {
    Movie m = Movie("Test");
    ASSERT_EQ("Test", m.getTitle());
    ASSERT_EQ(2, m.getBaseAmount());
    ASSERT_EQ(2, m.getMaxDay());
    ASSERT_EQ(1.5, m.getFeePerExpendDay());
    ASSERT_EQ(false, m.hasBonus());
}

TEST(ChildrenTest, ChildrenTest) {
    Children m = Children("Massacre à la tronçonneuse");
    ASSERT_EQ("Massacre à la tronçonneuse", m.getTitle());
    ASSERT_EQ(1.5, m.getBaseAmount());
    ASSERT_EQ(3, m.getMaxDay());
    ASSERT_EQ(1.5, m.getFeePerExpendDay());
    ASSERT_EQ(false, m.hasBonus());
}

TEST(NewReleaseTest, NewReleaseTest) {
    NewRelease m = NewRelease("Me and the boys");
    ASSERT_EQ("Me and the boys", m.getTitle());
    ASSERT_EQ(0, m.getBaseAmount());
    ASSERT_EQ(0, m.getMaxDay());
    ASSERT_EQ(3, m.getFeePerExpendDay());
    ASSERT_EQ(true, m.hasBonus());
}
