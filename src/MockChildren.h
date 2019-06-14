//
// Created by Rod Julien on 14.06.2019.
//

#ifndef GEN_LAB05_MOCK_CHILDREN_H
#define GEN_LAB05_MOCKCHILDREN_H

#include "Childrens.h"

class MockChildren : public Children{
public:
    MOCK_CONST_METHOD0(getBaseAmount, double());
    MOCK_CONST_METHOD1(getMaxDay, int());
    MOCK_CONST_METHOD0(getFeePerExpendDay, double());
    MOCK_CONST_METHOD2(hasBonus, bool());
};
#endif //GEN_LAB05_MOCK_CHILDREN_H
