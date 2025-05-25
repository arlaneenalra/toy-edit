//
// Created by Chris Salch on 5/24/25.
//

#include "TestAsserter.h"

using namespace ToyTesting;

void TestAsserter::addFailure(const std::string &message, const std::source_location &location) const {
    std::string locationMessage = "File: ";
    locationMessage += location.file_name();
    locationMessage += "@("  + std::to_string(location.line()) + ")\n";
    locationMessage += "\t" + message;

    suite->_failureMessages.push_back(locationMessage);
}

void TestAsserter::assertTrue(const bool condition, const std::string &message, const std::source_location &location) {
    asserted = true;

    if (condition) {
        return;
    }

    failed = true;
    addFailure(
        message.empty() ? "Expected True but was False" : message,
        location);
}
