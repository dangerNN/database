#pragma once
#include <map>
#include <vector>
#include <string>
#include "Violation.h"

using namespace std;
class ViolationDatabase {
private:
    map<string, vector<Violation>> database;

public:
    void addViolation(const string& carNumber, const Violation& violation);
    void printAll() const;
    void printByCarNumber(const string& carNumber) const;
    double calculateTotalFine(const string& carNumber) const;
    void payFines(const string& carNumber);
    void searchByDateRange(const string& fromDate, const string& toDate) const;
};
