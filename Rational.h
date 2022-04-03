#include <iostream>
#include <stdexcept>
#include <numeric>

class RationalDivisionByZero : public std::runtime_error {
public:
    RationalDivisionByZero() : std::runtime_error("RationalDivisionByZero") {
    }
};

class Rational{
private:
    int numenator, denominator;

    void reduction() {
        int gcd = std::gcd(numenator,denominator);
        numenator /= gcd;
        denominator /= gcd;
        if (denominator < 0) {
            denominator *= -1;
            numenator *= -1;
        }
    }
public:
    Rational() {
        numenator = 0;
        denominator = 1;
    }
    Rational(int n) { //NOLINT
        numenator = n;
        denominator = 1;
    }
    Rational(int n, int d) { //NOLINT
        numenator = n;
        denominator = d;
    }

    int GetNumenator() {
        return numenator;
    }
    int GetDenominator() {
        return denominator;
    }
    void SetNumenator(int numenator) {
        this->numenator = numenator;
        reduction();
    }
    void SetDenominator(int denominator) {
        this->denominator = denominator;
        reduction();
    }
    friend const Rational& operator+(const Rational& rational);
    friend Rational operator-(Rational rational);
    friend const Rational& operator++(Rational& rational);
    friend const Rational operator--(Rational& rational);
    friend const Rational operator++(Rational& rational, int);
    friend const Rational operator--(Rational& rational, int);
    friend const Rational operator+(Rational left, const Rational& right);
    friend const Rational operator-(Rational left, const Rational& right);
    friend const Rational operator*(Rational left, const Rational& right);
    friend const Rational operator/(Rational left, const Rational& right);
    friend Rational& operator+=(Rational& left, const Rational& right);
    friend Rational& operator-=(Rational& left, const Rational& right);
    friend Rational& operator*=(Rational& left, const Rational& right);
    friend Rational& operator/=(Rational& left, const Rational& right);
    friend bool operator==(Rational& left, Rational& right);
    friend bool operator!=(Rational& left, Rational& right);
    friend bool operator>(Rational& left, Rational& right);
    friend bool operator<(Rational& left, Rational& right);
    friend bool operator>=(Rational& left, Rational& right);
    friend bool operator<=(Rational& left, Rational& right);
    friend std::ostream& operator <<(std::ostream &out, const Rational &r);
    friend std::istream& operator >>(std::istream &in, Rational &r);
};

const Rational& operator+(const Rational& rational) {
    return rational;
}

Rational operator-(Rational rational) {
    rational.numenator *= -1;
    return rational;
}

const Rational& operator++(Rational& rational) {
    rational.numenator += rational.denominator;
    return rational;
}

const Rational operator--(Rational& rational) {
    rational.numenator -= rational.denominator;
    return rational;
}

const Rational operator++(Rational& rational, int) {
    Rational old(rational);
    rational.numenator += rational.denominator;
    return old;
}

const Rational operator--(Rational& rational, int) {
    Rational old(rational);
    rational.numenator -= rational.denominator;
    return old;
}

const Rational operator+(Rational left, const Rational &right) {
    left.numenator = left.numenator * right.denominator + right.numenator * left.denominator;
    left.denominator = left.denominator * right.denominator;
    left.reduction();
    return left;
}

const Rational operator-(Rational left, const Rational &right) {
    left = left + (-right);
    return left;
}

const Rational operator*(Rational left, const Rational &right) {
    left.numenator = left.numenator * right.numenator;
    left.denominator = left.denominator * right.denominator;
    left.reduction();
    return left;
}

const Rational operator/(Rational left, const Rational &right) {
    if (right.numenator == 0) throw RationalDivisionByZero();
    left.numenator = left.numenator * right.denominator;
    left.denominator = left.denominator * right.numenator;
    left.reduction();
    return left;
}

Rational& operator+=(Rational& left, const Rational& right) {
    left = left + right;
    return left;
}

Rational& operator-=(Rational& left, const Rational& right) {
    left = left - right;
    return left;
}

Rational& operator*=(Rational& left, const Rational& right) {
    left = left * right;
    return left;
}

Rational& operator/=(Rational& left, const Rational& right) {
    left = left / right;
    return left;
}

bool operator==(Rational& left, Rational& right) {
    left.reduction();
    right.reduction();
    return left.numenator == right.numenator && left.denominator == right.denominator;
}

bool operator!=(Rational& left, Rational& right) {
    left.reduction();
    right.reduction();
    return !(left.numenator == right.numenator && left.denominator == right.denominator);
}

bool operator>(Rational& left, Rational& right) {
    left.reduction();
    right.reduction();
    return left.numenator * right.denominator > right.numenator * left.denominator;
}

bool operator<(Rational& left, Rational& right) {
    left.reduction();
    right.reduction();
    return left.numenator * right.denominator < right.numenator * left.denominator;
}

bool operator>=(Rational& left, Rational& right) {
    left.reduction();
    right.reduction();
    return left.numenator * right.denominator >= right.numenator * left.denominator;
}

bool operator<=(Rational& left, Rational& right) {
    left.reduction();
    right.reduction();
    return left.numenator * right.denominator <= right.numenator * left.denominator;
}

std::ostream &operator <<(std::ostream &out, const Rational &r) {
    r.denominator != 1 ? out << r.numenator << "/" << r.denominator : out << r.numenator;
    return out;
}

std::istream &operator >>(std::istream &in, Rational &r) {
    in >> r.numenator;
    in.ignore();
    in >> r.denominator;
    if (r.numenator == 0) r.denominator = 1;
    if (r.denominator < 0) {
        r.denominator *= -1;
        r.numenator *= -1;
    }
    if (r.denominator == 0) throw RationalDivisionByZero();
    r.reduction();
    return in;
}
