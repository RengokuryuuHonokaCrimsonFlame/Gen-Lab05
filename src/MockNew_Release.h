//
// Created by Rod Julien on 14.06.2019.
//

#ifndef GEN_LAB05_MOCKNEW_RELEASE_H
#define GEN_LAB05_MOCKNEW_RELEASE_H

#include "New_Release.h"
class MockNew_Release : public New_Release{
public:
    MOCK_CONST_METHOD0(getBaseAmount, double());
    MOCK_CONST_METHOD1(getMaxDay, int());
    MOCK_CONST_METHOD0(getFeePerExpendDay, double());
    MOCK_CONST_METHOD2(hasBonus, bool());
};
#endif //GEN_LAB05_MOCKNEW_RELEASE_H
