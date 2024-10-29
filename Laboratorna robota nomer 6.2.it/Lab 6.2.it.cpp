
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

// ������� ��� ��������� ������
void generateArray(std::vector<int>& array, int min_value, int max_value) {
    for (int i = 0; i < array.size(); ++i) {
        array[i] = std::rand() % (max_value - min_value + 1) + min_value;
    }
}

// ������� ��� ��������� ������
void printArray(const std::vector<int>& array) {
    for (int num : array) {
        std::cout << std::setw(3) << num;  // ������������ ���������
    }
    std::cout << std::endl;
}

// ������� ��� ������� ������
void processArray(std::vector<int>& array, int& count, int& total_sum) {
    count = 0;
    total_sum = 0;
    for (int i = 0; i < array.size(); ++i) {
        if (array[i] % 2 == 0 && array[i] <= 0) {  // �������: ����, ��� �������
            count++;
            total_sum += array[i];
            array[i] = 0;  // �������� �� 0
        }
    }
}

// ������� �������
int main() {
    const int size = 24;
    const int min_value = -15;
    const int max_value = 75;
    std::vector<int> array(size);

    // ����������� ���������� ���������� �����
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // ��������� ������
    generateArray(array, min_value, max_value);

    // ��������� ������������ ������
    std::cout << "����������� �����:\n";
    printArray(array);

    // ���� ��� ���������
    int count = 0;
    int total_sum = 0;

    // ������� ������
    processArray(array, count, total_sum);

    // ��������� ����������
    std::cout << "\nʳ������ ��������, �� ������������� �������: " << count << std::endl;
    std::cout << "���� ��������, �� ������������� �������: " << total_sum << std::endl;

    // ��������� �������������� ������
    std::cout << "\n������������� �����:\n";
    printArray(array);

    return 0;
}
