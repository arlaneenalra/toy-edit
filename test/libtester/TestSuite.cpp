//
// Created by Chris Salch on 5/24/25.
//

#include <iostream>
#include "TestSuite.h"
#include "TestAsserter.h"

int ToyTesting::TestSuite::run() {

    int executedTestCases = 0;

    std::cout << "RUNNING: '" << this->_name << "' TESTS CASES: " << this->_testCaseCount << std::endl;
    for (auto it = _testCaseList.begin(); it != _testCaseList.end(); ++it) {
        TestAsserter asserter(this);

        (*it)(asserter);

        if (!asserter.hasAsserted()) {
            std::string failure = "Test case #" + std::to_string(executedTestCases) + " did not assert!";
            _failureMessages.push_back(failure);
            _failureCount++;
        }

        if (asserter.hasFailed()) {
            _failureCount++;
        }

        executedTestCases++;
    }

    std::cout << "DONE: '" << this->_name << "' Failures: " << _failureCount << std::endl;

    return executedTestCases;
}

