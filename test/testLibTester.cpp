//
// Created by Chris Salch on 5/24/25.
//

#include "libtester/tester.h"

void testSimple(ToyTesting::TestAsserter &asserter) {
    asserter.assertTrue(true, "");
}

ToyTesting::TestSuitePtr testSuiteList[] = {
    new ToyTesting::TestSuite("Run simple tests", {
        &testSimple
    }),

    nullptr
};