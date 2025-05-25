//
// Created by Chris Salch on 5/24/25.
//
#include <iostream>
#include "tester.h"

int main(int argc, char **argv) {

   bool success = true;

   int totalTestSuites = 0;
   int expectedTestsCases = 0;

   int totalExecutedTests = 0;
   int totalFailedTests = 0;

   std::cout << "Starting Test Run:" << std::endl;

   for (totalTestSuites = 0; testSuiteList[totalTestSuites] != nullptr ; totalTestSuites++) {
      expectedTestsCases += testSuiteList[totalTestSuites]->getTestCaseCount();
   }

   std::cout << "Suites: " << totalTestSuites << " Cases: " << expectedTestsCases << std::endl;

   for (int i = 0; i < totalTestSuites; i++) {
      const ToyTesting::TestSuitePtr &testSuite = testSuiteList[i];

      int executed = testSuite->run();

      std::list<std::string> failedTests = testSuite->getFailureMessages();

      totalFailedTests += testSuite->getFailedTestCount();

      if (!failedTests.empty() || testSuite->getFailedTestCount() > 0) {
         for (auto & failedTest : failedTests) {
            std::cout << failedTest << std::endl;
         }
      }

      totalExecutedTests += executed;
   }

   if (expectedTestsCases != totalExecutedTests) {
      std::cout << "FAILED: Expected " << expectedTestsCases << " but only ran " << totalExecutedTests << " tests!\n";
      success = false;
   }

   if (totalFailedTests > 0) {
      std::cout << "FAILED: " << totalFailedTests << " out of " << totalExecutedTests << " failed." << std::endl;
      success = false;
   }

   if (success) {
      return EXIT_SUCCESS;
   }

   return EXIT_FAILURE;
}