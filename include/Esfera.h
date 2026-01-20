#ifndef ESFERA_H
#define ESFERA_H

#include <iostream>

class Esfera {
private:
    double radio = 0.0;
public:
    Esfera() = default;
    explicit Esfera(double radio) : radio(radio) {}

    friend Esfera operator+(const Esfera& a, const Esfera& b) {
        return Esfera(a.radio + b.radio);
    }

    Esfera& operator+=(const Esfera& other) {
        radio += other.radio;
        return *this;
    }

    friend Esfera operator-(const Esfera& a, const Esfera& b) {
        return Esfera(a.radio - b.radio);
    }

    friend Esfera operator*(const Esfera& a, const Esfera& b) {
        return Esfera(a.radio * b.radio);
    }

    friend Esfera operator/(const Esfera& a, std::size_t n) {
        return Esfera(a.radio / n);
    }

    friend bool operator>(const Esfera& a, const Esfera& b) {
        return a.radio > b.radio;
    }

    friend bool operator<(const Esfera& a, const Esfera& b) {
        return a.radio < b.radio;
    }

    friend bool operator==(const Esfera& a, const Esfera& b) {
        return a.radio == b.radio;
    }

    friend bool operator>=(const Esfera& a, const Esfera& b) {
        return a.radio >= b.radio;
    }

    friend bool operator<=(const Esfera& a, const Esfera& b) {
        return a.radio <= b.radio;
    }

    friend std::ostream& operator<<(std::ostream& os, const Esfera& e) {
        os << "Esfera(r=" << e.radio << ")";
        return os;
    }
};

#endif // ESFERA_H