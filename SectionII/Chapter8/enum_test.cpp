#include <iostream>

using namespace std;

enum class Traffic_light { red, yellow, green };
enum class Warning { green, yellow, orange, red };
enum class Printer_flags {
    none = 0,
    acknowledge=1,
    paper_empty=2,
    busy=4,
    out_of_black=8,
    out_of_color=16,
};

int main() {
    Warning w = Warning::red;

    cout << static_cast<int>(Printer_flags::out_of_black) << endl;
    cout << static_cast<int>(Printer_flags::out_of_color) << endl;

    return 1;
}