#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cmath>
const double PI = 3.14159265358979323846;

using namespace std;

class Circle {
private:
    double x;
    double y;
    double rad;
    string color;

public:
    Circle(double cordx, double cordy, double r, string c) {
        x = cordx;
        y = cordy;
        rad = r;
        color = c;
    }

    void get_info() {
        cout << "X: " << x << ". Y: " << y << ". Radius: " << rad << ". Color: " << color << endl;
    }

    void calculate_and_print() {
        cout << "Длина окружности: " << 2 * PI * rad << endl;
        cout << "Площадь окружности: " << PI * pow(rad, 2) << endl;
    }

    void print_to_file(const std::string& файл) {
        std::ofstream outputFile(файл);
        if (outputFile.is_open()) {
            outputFile << "Circle Information:" << std::endl;
            outputFile << "Center Coordinates: (" << x << ", " << y << ")" << std::endl;
            outputFile << "Radius: " << rad << std::endl;
            outputFile << "Color: " << color << std::endl;
            calculate_and_print();
            outputFile.close();
        }
        else {
            std::cerr << "Не удалось открыть файл " << файл << std::endl;
        }
    }
};

string random_color() {
    const char* colors[] = { "Красный", "Синий", "Зеленый", "Белый", "Фиолетовый", "Желтый" };
    int numColors = sizeof(colors) / sizeof(colors[0]);
    int randomInd = rand() % numColors;
    return colors[randomInd];
}

int main() {
    srand(time(0));

    Circle big(0.0, 17.3, 17.3, "Красный");
    big.get_info();
    big.calculate_and_print();

    Circle small(1.0, 3.5, 2.5, "Синий");
    small.get_info();
    small.calculate_and_print();

    big.print_to_file("circle_info.txt");
    small.print_to_file("circle_info.txt");

    return 0;
}