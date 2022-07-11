#include <iostream>

using namespace std;

struct Point {
    int x, y;
};

struct Array {
    Point elem[3];
};

Array shift(Array a, Point p) {
    for (int i = 0; i != 3; i++) {
        a.elem[i].x += p.x;
        a.elem[i].y += p.y;
    };

    return a;
};

int main() {
    Point points[3] {
        {1, 2},
        {3, 4},
        {5, 6}
    };
    int x = points[2].x;

    Array points2 {{
        {1, 2},
        {3, 4},
        {5, 6}
    }};

    int y = points2.elem[2].y;

    cout << x << endl;
    cout << y << endl;

    return 1;
}