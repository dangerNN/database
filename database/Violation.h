#pragma once
#include <iostream>
#include <string>

using namespace std;
class Violation {
private:
    string description;
    double fine;
    string date; // ������ YYYY-MM-DD
    bool paid;

public:
    Violation(string desc, double f, string d, bool p = false);

    string getDescription() const;
    double getFine() const;
    string getDate() const;
    bool isPaid() const;

    void setPaid(bool value);
};
