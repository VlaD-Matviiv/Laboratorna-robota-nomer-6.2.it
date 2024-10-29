
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

// Функція для генерації масиву
void generateArray(std::vector<int>& array, int min_value, int max_value) {
    for (int i = 0; i < array.size(); ++i) {
        array[i] = std::rand() % (max_value - min_value + 1) + min_value;
    }
}

// Функція для виведення масиву
void printArray(const std::vector<int>& array) {
    for (int num : array) {
        std::cout << std::setw(3) << num;  // Форматування виведення
    }
    std::cout << std::endl;
}

// Функція для обробки масиву
void processArray(std::vector<int>& array, int& count, int& total_sum) {
    count = 0;
    total_sum = 0;
    for (int i = 0; i < array.size(); ++i) {
        if (array[i] % 2 == 0 && array[i] <= 0) {  // Критерій: парні, крім додатніх
            count++;
            total_sum += array[i];
            array[i] = 0;  // Замінюємо на 0
        }
    }
}

// Головна функція
int main() {
    const int size = 24;
    const int min_value = -15;
    const int max_value = 75;
    std::vector<int> array(size);

    // Ініціалізація генератора випадкових чисел
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Генерація масиву
    generateArray(array, min_value, max_value);

    // Виведення оригінального масиву
    std::cout << "Оригінальний масив:\n";
    printArray(array);

    // Змінні для підрахунку
    int count = 0;
    int total_sum = 0;

    // Обробка масиву
    processArray(array, count, total_sum);

    // Виведення результатів
    std::cout << "\nКількість елементів, що задовольняють критерію: " << count << std::endl;
    std::cout << "Сума елементів, що задовольняють критерію: " << total_sum << std::endl;

    // Виведення модифікованого масиву
    std::cout << "\nМодифікований масив:\n";
    printArray(array);

    return 0;
}
