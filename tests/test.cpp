#include "../include/CoreNumeric.h"
#include "../include/Coordenada.h"
#include "../include/Vector3D.h"
#include "../include/Esfera.h"
#include <vector>
#include <list>
#include <string>

void test_sum() {
    std::cout << "--- TEST SUM ---\n";
    
    std::vector<int> v1{1, 2, 3, 4, 5};
    std::vector<double> v2{1.5, 2.5, 3.5};
    std::list<float> l1{1.0f, 2.0f, 3.0f};
    
    std::cout << CoreNumeric::sum(v1) << "\n";
    std::cout << CoreNumeric::sum(v2) << "\n";
    std::cout << CoreNumeric::sum(l1) << "\n";
    
    std::vector<Coordenada> coords{{1, 2}, {3, 4}};
    std::vector<Vector3D> vecs{{1, 2, 3}, {4, 5, 6}};
    std::vector<Esfera> esferas{Esfera(1.0), Esfera(2.0)};
    
    std::cout << CoreNumeric::sum(coords) << "\n";
    std::cout << CoreNumeric::sum(vecs) << "\n";
    std::cout << CoreNumeric::sum(esferas) << "\n";
    
    // std::vector<std::string> strings{"hello", "world"}; 
    // CoreNumeric::sum(strings); // no compila porque string no tiene operator+
    
    std::cout << "\n";
}

void test_mean() {
    std::cout << "--- TEST MEAN ---\n";
    
    std::vector<int> v1{10, 20, 30};
    std::vector<double> v2{1.5, 2.5, 3.5};
    
    std::cout << CoreNumeric::mean(v1) << "\n";
    std::cout << CoreNumeric::mean(v2) << "\n";
    
    std::vector<Coordenada> coords{{2, 4}, {4, 8}};
    std::vector<Esfera> esferas{Esfera(2.0), Esfera(4.0)};
    
    std::cout << CoreNumeric::mean(coords) << "\n";
    std::cout << CoreNumeric::mean(esferas) << "\n";
    
    // std::vector<std::string> strings{"abc", "def"};
    // CoreNumeric::mean(strings); // falla Divisible
    
    std::cout << "\n";
}

void test_variance() {
    std::cout << "--- TEST VARIANCE ---\n";
    
    std::vector<int> v1{1, 2, 3, 4, 5};
    std::vector<double> v2{1.0, 2.0, 3.0};
    
    std::cout << CoreNumeric::variance(v1) << "\n";
    std::cout << CoreNumeric::variance(v2) << "\n";
    
    // std::vector<Coordenada> coords{{1, 1}, {2, 2}};
    // std::cout << CoreNumeric::variance(coords) << "\n"; // falla porque std::pow no acepta Coordenada
    
    // std::vector<Esfera> esferas{Esfera(1.0), Esfera(3.0)};
    // std::cout << CoreNumeric::variance(esferas) << "\n"; // falla porque std::pow no acepta Esfera
    
    // std::vector<std::string> strings{"a", "b"};
    // CoreNumeric::variance(strings); // falla Subtractable y Multipliable 
    
    std::cout << "\n";
}

void test_max() {
    std::cout << "--- TEST MAX ---\n";
    
    std::vector<int> v1{5, 2, 9, 1};
    std::vector<double> v2{3.5, 1.2, 8.9};
    std::list<float> l1{4.5f, 2.1f, 9.8f};
    
    std::cout << CoreNumeric::max(v1) << "\n";
    std::cout << CoreNumeric::max(v2) << "\n";
    std::cout << CoreNumeric::max(l1) << "\n";
    
    std::vector<Esfera> esferas{Esfera(3.0), Esfera(1.0), Esfera(5.0)};
    std::cout << CoreNumeric::max(esferas) << "\n";
    
    // std::vector<Coordenada> coords{{1, 2}, {3, 4}};
    // CoreNumeric::max(coords); // falla porque Comparable no tiene operator>
    
    std::cout << "\n";
}

void test_transform_reduce() {
    std::cout << "--- TEST TRANSFORM_REDUCE ---\n";
    
    std::vector<int> v1{1, 2, 3, 4};
    std::cout << CoreNumeric::transform_reduce(v1, [](int x) { return x * x; }) << "\n";
    
    std::vector<double> v2{1.5, 2.5};
    std::cout << CoreNumeric::transform_reduce(v2, [](double x) { return x * 2; }) << "\n";
    
    std::vector<Coordenada> coords{{1, 2}, {3, 4}};
    std::cout << CoreNumeric::transform_reduce(coords, [](Coordenada c) { return c * c; }) << "\n";
    
    std::cout << "\n";
}

void test_variadic() {
    std::cout << "--- TEST VARIADIC ---\n";
    
    std::cout << CoreNumeric::sum_variadic(1, 2, 3, 4) << "\n";
    std::cout << CoreNumeric::mean_variadic(10, 20, 30) << "\n";
    std::cout << CoreNumeric::variance_variadic(1, 2, 3, 4) << "\n";
    std::cout << CoreNumeric::max_variadic(5, 2, 9, 1) << "\n";
    
    std::cout << CoreNumeric::sum_variadic(1.0, 2.0, 3.0) << "\n";
    std::cout << CoreNumeric::mean_variadic(10.0, 20.0, 30.0) << "\n";
    std::cout << CoreNumeric::variance_variadic(1.0, 2.0, 3.0) << "\n";
    
    // CoreNumeric::sum_variadic("hello", "world"); // falla porque const char* no soporta +
    
    std::cout << "\n";
}

int main() {
    test_sum();
    test_mean();
    test_variance();
    test_max();
    test_transform_reduce();
    test_variadic();
    
    return 0;
}
