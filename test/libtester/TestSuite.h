//
// Created by Chris Salch on 5/24/25.
//

#ifndef TESTSUITE_H
#define TESTSUITE_H

#include "tester.h"
#include <string>
#include <list>
#include <array>

namespace ToyTesting {

class TestSuite {
    std::string _name;
    std::list<TestCasePtr> _testCaseList;

    std::list<std::string> _failureMessages;

    int _testCaseCount = 0;
    int _failureCount = 0;

public:
    TestSuite(const std::string &name, const std::list<TestCasePtr> &test_case_list)
        : _name(name),
          _testCaseList(test_case_list) {

        // Get the total number of test cases
        _testCaseCount = test_case_list.size();
    }

    [[nodiscard]] int run();

    [[nodiscard]] int getTestCaseCount() const {
        return _testCaseCount;
    }

    [[nodiscard]] std::list<std::string> getFailureMessages() const {
        return _failureMessages;
    }

    [[nodiscard]] int getFailedTestCount() const {
        return _failureCount;
    }

    friend class TestAsserter;
};

};


#endif //TESTSUITE_H
