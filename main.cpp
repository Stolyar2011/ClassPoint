#include <iostream>
#include <cmath>

using namespace std;

class Point{
    long long x, y;
public:
    Point(long long new_x, long long new_y){x = new_x; y = new_y; }
    Point(){x = 0; y = 0; }
    long long get_x(){return x; }
    long long get_y(){return y; }
    void set_x(long long new_x) {x = new_x; }
    void set_y(long long new_y) {y = new_y; }

    Point operator+(Point);
    Point operator-(Point);
    Point operator*(long long);
    long long operator*(Point);
    long long operator%(Point);
    bool operator==(Point);
    bool operator!=(Point);
    friend ostream operator<<(ostream&, const Point&);
    long long lenght() { return x * x + y * y; }
};

Point Point::operator+(Point a) {
    return Point(x + a.x, y + a.y);
}

Point Point::operator-(Point b) {
    return Point(x - a.x, y - a.y);
}

Point Point::operator*(long long k) {
    return Point(x * k, y * k);
}

long long Point::operator*(Point a) {
    return x * a.x + y * a.y;
}

long long Point::operator%(Point a) {
    return x * a.y - y * a.x;
}

ostream& operator<<(ostream& out, const Point& a) {
    return out << '(' << a.x << ", " << a.y << ')';
}

bool Point::operator==(Point a) {
    if (a.x == x && a.y == y) {
        return true;
    }
    return false;
}

bool Point::operator!=(Point a) {
    if (a.x == x && a.y == y) {
        return false;
    }
    return true;
}

double get_angle(Point& a, Point& b) {
    int x1 = a.get_x(), y1 = a.get_y();
    int x2 = b.get_x(), y2 = b.get_y();
    return atan2(y2, x2) - atan2(y1, x1);
}

int main() {
    Point a;
    Point b;
    int ax, ay, bx, by;
    cout << "Введите координаты первого вектора: ";
    c
}