#include <iostream>
#include <string>
#include <numeric>
#include "rational.h"

void Rational::Reduction() {
  int gcd = std::gcd(numerator_, denominator_);
  numerator_ /= gcd;
  denominator_ /= gcd;
  if (denominator_ < 0) {
    numerator_ *= -1;
    denominator_ *= -1;
  }
}

Rational::Rational() {
  numerator_ = 0;
  denominator_ = 1;
}

Rational::Rational(int n) {  // NOLINT
  numerator_ = n;
  denominator_ = 1;
}

Rational::Rational(int n, int d) {
  if (!d) {
    throw RationalDivisionByZero{};
  }
  numerator_ = n;
  denominator_ = d;
  Reduction();
}

int Rational::GetNumerator() const {
  return numerator_;
}

int Rational::GetDenominator() const {
  return denominator_;
}

void Rational::SetNumerator(const int &numerator) {
  numerator_ = numerator;
  Reduction();
}

void Rational::SetDenominator(const int &denominator) {
  if (denominator == 0) {
    throw RationalDivisionByZero{};
  };
  denominator_ = denominator;
  Reduction();
}

Rational Rational::operator+() const {
  return *this;
}

Rational Rational::operator-() const {
  return *this * -1;
}

Rational &Rational::operator++() {
  return (*this += Rational(1));
}

Rational &Rational::operator--() {
  return (*this -= Rational(1));
}

Rational Rational::operator++(int) {
  Rational old = *this;
  ++(*this);
  return old;
}

Rational Rational::operator--(int) {
  Rational old = *this;
  --(*this);
  return old;
}

Rational Rational::operator+(const Rational &other) const {
  int n = this->numerator_ * other.denominator_ + other.numerator_ * this->denominator_;
  int d = this->denominator_ * other.denominator_;

  return Rational(n, d);
}

Rational Rational::operator-(const Rational &other) const {
  return *this + (-other);
}

Rational Rational::operator*(const Rational &other) const {
  int n = this->numerator_ * other.numerator_;
  int d = this->denominator_ * other.denominator_;
  return Rational(n, d);
}

Rational Rational::operator/(const Rational &other) const {
  if (other.numerator_ == 0) {
    throw RationalDivisionByZero{};
  }
  int n = this->numerator_ * other.denominator_;
  int d = this->denominator_ * other.numerator_;
  return Rational(n, d);
}

Rational operator+(const int &integer, const Rational &rational) {
  return Rational(integer) + rational;
}

Rational operator-(const int &integer, const Rational &rational) {
  return Rational(integer) - rational;
}

Rational operator*(const int &integer, const Rational &rational) {
  return Rational(integer) * rational;
}

Rational operator/(const int &integer, const Rational &rational) {
  return Rational(integer) / rational;
}

Rational &Rational::operator+=(const Rational &other) {
  *this = *this + other;
  return *this;
}

Rational &Rational::operator-=(const Rational &other) {
  *this = *this - other;
  return *this;
}

Rational &Rational::operator*=(const Rational &other) {
  *this = *this * other;
  return *this;
}

Rational &Rational::operator/=(const Rational &other) {
  *this = *this / other;
  return *this;
}

bool Rational::operator==(const Rational &other) const {
  return numerator_ == other.numerator_ && denominator_ == other.denominator_;
}

bool Rational::operator!=(const Rational &other) const {
  return !(*this == other);
}

bool Rational::operator>(const Rational &other) const {
  return numerator_ * other.denominator_ > other.numerator_ * denominator_;
}

bool Rational::operator<(const Rational &other) const {
  return other > *this;
}

bool Rational::operator>=(const Rational &other) const {
  return !(*this < other);
}

bool Rational::operator<=(const Rational &other) const {
  return !(*this > other);
}

bool operator==(const int &integer, const Rational &rational) {
  return (Rational(integer) == rational);
}

bool operator!=(const int &integer, const Rational &rational) {
  return (Rational(integer) != rational);
}

bool operator<(const int &integer, const Rational &rational) {
  return (Rational(integer) < rational);
}

bool operator>(const int &integer, const Rational &rational) {
  return (Rational(integer) > rational);
}

bool operator<=(const int &integer, const Rational &rational) {
  return (Rational(integer) <= rational);
}

bool operator>=(const int &integer, const Rational &rational) {
  return (Rational(integer) >= rational);
}

std::ostream &operator<<(std::ostream &out, const Rational &r) {
  r.denominator_ != 1 ? out << r.numerator_ << "/" << r.denominator_ : out << r.numerator_;
  return out;
}

std::istream &operator>>(std::istream &in, Rational &r) {
  std::string rs;
  in >> rs;

  auto div = rs.find('/');
  if (div != std::string::npos) {
    r = Rational(std::stoi(rs.substr(0, div)), std::stoi(rs.substr(div + 1, rs.length() - 1 - div)));
  } else {
    r = Rational(std::stoi(rs));
  }

  return in;
}
