#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include "Matrix.h"

int main() {
    system("chcp 65001 > nul");
    std::srand(std::time(nullptr));

    Matrix m1;
    Matrix m2(3);
    Matrix m3(3, 4);
    Matrix m4(2, 3);

    std::cout << "M2 (единичная 3x3):\n"; m2.print();
    std::cout << "M3 (3x4 нули):\n";      m3.print();
    std::cout << "M4 (2x3 нули):\n";      m4.print();

    for (int i = 0; i < m2.getRows(); ++i) {
        for (int j = 0; j < m2.getCols(); ++j) {
            m2.set(i, j, i * j);
        }
    }
    std::cout << "M2 после формулы i*j:\n"; m2.print();

    m3.fillRandom();
    std::cout << "M3 случайная:\n"; m3.print();

    std::cout << "Введите 6 чисел для M4 (через пробел):\n";
    m4.inputFromKeyboard();
    std::cout << "M4:\n"; m4.print();

    std::cout << "Сумма элементов M3 = " << m3.sum() << '\n';

    try {
        Matrix bad(-1, 5);
    } catch (const std::invalid_argument& e) {
        std::cout << "Поймали ошибку: " << e.what() << '\n';
    }

    try {
        m3.get(100, 100);
    } catch (const std::out_of_range& e) {
        std::cout << "Поймали ошибку: " << e.what() << '\n';
    }

    return 0;
}