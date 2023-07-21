#include <iostream>
#include <map>
#include <cmath>

using namespace std;

map<string, int> colorValues = {
    {"black", 0},
    {"brown", 1},
    {"red", 2},
    {"orange", 3},
    {"yellow", 4},
    {"green", 5},
    {"blue", 6},
    {"violet", 7},
    {"gray", 8},
    {"white", 9}
};

double resistanceValue(int band1, int band2, int multiplier) {
    double value = (band1 * 10 + band2) * pow(10, multiplier);
    return value;
}

int main() {
    string color1, color2, color3;
    cout << "Enter the colors of the first, second, and third band of the resistor (in lowercase): ";
    cin >> color1 >> color2 >> color3;
    int band1 = colorValues[color1];
    int band2 = colorValues[color2];
    int multiplier = colorValues[color3];
    double value = resistanceValue(band1, band2, multiplier);
    cout << "The resistance value is " << value << " ohms." << endl;
    return 0;
}
