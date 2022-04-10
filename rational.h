#pragma once

#include <stdexcept>

class RationalDivisionByZero : public std::runtime_error {
 public:
  RationalDivisionByZero() : std::runtime_error("RationalDivisionByZero") {
  }
};

class Rational {
 private:
  int numenator_, denominator_;

  void Reduction();

 public:
  Rational();
  Rational(int n);  // NOLINT
  Rational(int n, int d);

  int GetNumerator() const;
  int GetDenominator() const;
  void SetNumerator(const int &numerator);
  void SetDenominator(const int &denominator);

  Rational operator+() const;
  Rational operator-() const;

  Rational &operator++();
  Rational &operator--();
  Rational operator++(int);
  Rational operator--(int);

  Rational operator+(const Rational &other) const;
  Rational operator-(const Rational &other) const;
  Rational operator*(const Rational &other) const;
  Rational operator/(const Rational &other) const;

  friend Rational operator+(const int &integer, const Rational &rational);
  friend Rational operator-(const int &integer, const Rational &rational);
  friend Rational operator*(const int &integer, const Rational &rational);
  friend Rational operator/(const int &integer, const Rational &rational);

  Rational &operator+=(const Rational &other);
  Rational &operator-=(const Rational &other);
  Rational &operator*=(const Rational &other);
  Rational &operator/=(const Rational &other);

  bool operator==(const Rational &other) const;
  bool operator!=(const Rational &other) const;
  bool operator>(const Rational &other) const;
  bool operator<(const Rational &other) const;
  bool operator>=(const Rational &other) const;
  bool operator<=(const Rational &other) const;

  friend bool operator==(const int &integer, const Rational &rational);
  friend bool operator!=(const int &integer, const Rational &rational);
  friend bool operator<(const int &integer, const Rational &rational);
  friend bool operator>(const int &integer, const Rational &rational);
  friend bool operator<=(const int &integer, const Rational &rational);
  friend bool operator>=(const int &integer, const Rational &rational);

  friend std::ostream &operator<<(std::ostream &out, const Rational &r);
  friend std::istream &operator>>(std::istream &in, Rational &r);
};