//
// Created by Chris Salch on 5/24/25.
//

#ifndef TESTASSERTER_H
#define TESTASSERTER_H

#include "tester.h"
#include <source_location>

namespace ToyTesting {

class TestAsserter {
    bool asserted = false;
    bool failed = false;

    TestSuitePtr suite;

    public:
        explicit TestAsserter(const TestSuitePtr suite)
            : suite(suite) {
        }

        void assertTrue(bool condition, const std::string &message, const std::source_location &location = std::source_location::current());

        [[nodiscard]] bool hasAsserted() const {
            return asserted;
        }

        [[nodiscard]] bool hasFailed() const {
            return failed;
        }

    private:
        void addFailure(const std::string &message, const std::source_location &location) const;

};

} // ToyTesting

#endif //TESTASSERTER_H
