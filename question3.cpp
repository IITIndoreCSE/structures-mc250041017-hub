#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>  

using namespace std;

struct Point {
    double x;
    double y;
};

double round_to_zero(double value, double epsilon = 1e-6) {
    return (fabs(value) < epsilon) ? 0.0 : value;
}

void print_point_rotation(double x_before, double y_before,
                          double theta, double x_after, double y_after) {
    
    x_after = round_to_zero(x_after);
    y_after = round_to_zero(y_after);

    
    cout << "Before rotation: (x=" << fixed << setprecision(0) << x_before
         << ", y=" << fixed << setprecision(0) << y_before << ")\n";
    cout << "After rotation (θ=" << fixed << setprecision(4) << theta << " rad): "
         << "(x=" << fixed << setprecision(0) << x_after << ", y=" << fixed << setprecision(0) << y_after << ")\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    ifstream input(argv[1]);
    if (!input) {
        cerr << "Error opening " << argv[1] << endl;
        return 1;
    }

    Point p, pivot;
    double theta;

    
    input >> p.x >> p.y;
    input >> theta;            
    input >> pivot.x >> pivot.y; 

    double x_after = pivot.x + (p.x - pivot.x) * cos(theta) - (p.y - pivot.y) * sin(theta);
    double y_after = pivot.y + (p.x - pivot.x) * sin(theta) + (p.y - pivot.y) * cos(theta);

    print_point_rotation(p.x, p.y, theta, x_after, y_after);

    return 0;
}
