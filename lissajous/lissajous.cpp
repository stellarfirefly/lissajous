#include <iostream>
#include <algorithm>
using namespace std;

double poly(double x) {
    if (abs(x) < 0.1) {
        x = x + pow(x, 3.0) / 6.0 + 0.75 * pow(x, 5.0) + pow(x, 7.0) / 22.4;
        return x;
    }
    x = poly(x / (sqrt(1.0 + x) + sqrt(1.0 - x)));
    x *= 2.0;
    return x;
}

void output(int tab) {
    for (int i = 0; i < tab; ++i){
        cout << " ";
    }
    cout << "*";
}

int main()
{
    int xFreq, yFreq;
    double dxFreq, dyFreq, yPhase;
    const double PI = 3.141592653589793238462643383279502884;
    const int height = 18;       // width of lissajous, positive integer

        // for a demo, try values: 5, 7, 0
    cout << "Relative frequency for X (integer): ";
    cin >> xFreq;
    dxFreq = (double) xFreq * 2.0 * PI;
    cout << "Relative frequency for Y (integer): ";
    cin >> yFreq;
    dyFreq = (double) yFreq * 2.0 * PI;
    cout << "Y phase as a multiple of pi (decimal): ";
    cin >> yPhase;
    yPhase *= PI;

    for (int x1 = -height; x1 <= height; ++x1) {
        double x = poly((double)x1 / (double)height);
        double t1 = x, t2 = PI - x;
        int* y = new int[2 * xFreq];

        for (int i = 0; i < xFreq; ++i) {
            double t3 = (t1 + 2.0 * (double)i * PI) / dxFreq;
            double t4 = (t2 + 2.0 * (double)i * PI) / dxFreq;
            double y1 = 30.0 * sin(dyFreq * t3 + yPhase);
            double y2 = 30.0 * sin(dyFreq * t4 + yPhase);
            y[2 * i] = (int)round(y1) + height * 2;
            y[2 * i + 1] = (int)round(y2) + height * 2;
        }
        sort(y, y + xFreq * 2);

        int prev;
        for (int i = 0; i < 2 * xFreq; ++i) {
            if (i) {
                int diff = y[i] - prev;
                if (diff) {
                    output(diff);
                }
            }
            else {
                output(y[i]);
            }
            prev = y[i];
        }
        cout << endl;
        delete[] y;
    }
}
