#ifndef Coordenada_H
#define Coordenada_H

#include <iostream>

class Coordenada {
private:
    double x = 0.0;
    double y = 0.0;
public:
    Coordenada() = default;
    Coordenada(double x, double y) : x(x), y(y) {}

    friend Coordenada operator+(const Coordenada& a, const Coordenada& b) {
        return {a.x + b.x, a.y + b.y};
    }

    Coordenada& operator+=(const Coordenada& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    friend Coordenada operator-(const Coordenada& a, const Coordenada& b) {
        return {a.x - b.x, a.y - b.y};
    }

    friend Coordenada operator*(const Coordenada& a, const Coordenada& b) {
        return {a.x * b.x, a.y * b.y};
    }

    friend Coordenada operator/(const Coordenada& a, std::size_t n) {
        return {a.x / n, a.y / n};
    }

    friend std::ostream& operator<<(std::ostream& os, const Coordenada& c) {
        os << "(" << c.x << ", " << c.y << ")";
        return os;
    }
};

#endif // Coordenada_H