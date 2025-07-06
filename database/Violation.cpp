#include "Violation.h"

Violation::Violation(string desc, double f, string d, bool p)
	: description(desc), fine(f), date(d), paid(p)
{
}

string Violation::getDescription() const
{
	return description;
}

double Violation::getFine() const
{
	return fine;
}

string Violation::getDate() const
{
	return date;
}

bool Violation::isPaid() const
{
	return paid;
}

void Violation::setPaid(bool value)
{
	paid = value;
}
