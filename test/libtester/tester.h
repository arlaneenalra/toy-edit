//
// Created by Chris Salch on 5/24/25.
//

#ifndef TESTER_H
#define TESTER_H

namespace ToyTesting {
    class TestSuite;
    class TestAsserter;

    typedef TestSuite *TestSuitePtr;
    typedef void (*TestCasePtr)(TestAsserter &test);
}

#include "TestSuite.h"
#include "TestAsserter.h"


extern ToyTesting::TestSuitePtr testSuiteList[];

#define TEST_SUITE(args...)  \
    ToyTesting::TestSuitePtr testSuiteList[] = { args, nullptr }; \
}

#define TEST_CASES(name, args...)  { \
    new ToyTesting::TestSuite(name, { args, nullptr }) \
}


#endif //TESTER_H
