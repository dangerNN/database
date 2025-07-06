#include "Database.h"
#include <iostream>


void ViolationDatabase::addViolation(const string& carNumber, const Violation& violation) {
    database[carNumber].push_back(violation);
}

void ViolationDatabase::printAll() const {
    if (database.empty()) {
        cout << "Database is empty..\n";
        return;
    }

    for (const auto& pair : database) {
        cout << "Car: " << pair.first << "\n";
        for (const auto& v : pair.second) {
            cout << "  Description: " << v.getDescription()
                << ", Fine: " << v.getFine()
                << ", Date: " << v.getDate()
                << ", Paid: " << (v.isPaid() ? "Yes" : "No") << "\n";
        }
        cout << "------------------------\n";
    }
}

void ViolationDatabase::printByCarNumber(const string& carNumber) const {
    auto it = database.find(carNumber);
    if (it != database.end()) {
        cout << "Violation for " << carNumber << ":\n";
        for (const auto& v : it->second) {
            cout << "  Description: " << v.getDescription()
                << ", Fine: " << v.getFine()
                << ", Date: " << v.getDate()
                << ", Paid: " << (v.isPaid() ? "Yes" : "No") << "\n";
        }
    }
    else {
        cout << "Car " << carNumber << " not found.\n";
    }
}

double ViolationDatabase::calculateTotalFine(const string& carNumber) const {
    double total = 0;
    auto it = database.find(carNumber);
    if (it != database.end()) {
        for (const auto& v : it->second) {
            if (!v.isPaid()) {
                total += v.getFine();
            }
        }
    }
    return total;
}

void ViolationDatabase::payFines(const string& carNumber) {
    auto it = database.find(carNumber);
    if (it != database.end()) {
        for (auto& v : it->second) {
            v.setPaid(true);
        }
        cout << "All fines for " << carNumber << " have been paid.\n";
    }
    else {
        cout << "Car not found.\n";
    }
}

void ViolationDatabase::searchByDateRange(const string& fromDate, const string& toDate) const {
    cout << "Violations in the period from " << fromDate << " to  " << toDate << ":\n";
    for (const auto& pair : database) {
        for (const auto& v : pair.second) {
            if (v.getDate() >= fromDate && v.getDate() <= toDate) {
                cout << "Car: " << pair.first
                    << ", Description: " << v.getDescription()
                    << ", Date: " << v.getDate()
                    << ", Fine: " << v.getFine()
                    << ", Paid: " << (v.isPaid() ? "Yes" : "No") << "\n";
            }
        }
    }
}
