#include <iostream>
#include "Database.h"


int main() {
    ViolationDatabase db;

    db.addViolation("AA1234BB", Violation("Speeding", 800, "2025-06-09"));
    db.addViolation("AA1234BB", Violation("Incorrect stop", 700, "2025-07-01"));
    db.addViolation("BC5678CD", Violation("Driving on red", 1000, "2025-06-25"));

    cout << "\n--- Complete database ---\n";
    db.printAll();

    cout << "\n--- Violation for AA1234BB ---\n";
    db.printByCarNumber("AA1234BB");

    cout << "\n--- Amount of unpaid fines ---\n";
    cout << "Sum: " << db.calculateTotalFine("AA1234BB") << " UAH\n";

    cout << "\n--- Payment of fines ---\n";
    db.payFines("AA1234BB");

    cout << "\n--- Amount after payment ---\n";
    cout << "Sum: " << db.calculateTotalFine("AA1234BB") << " UAH\n";

    cout << "\n--- Search by period ---\n";
    db.searchByDateRange("2025-06-01", "2025-06-30");
    return 0;
}
