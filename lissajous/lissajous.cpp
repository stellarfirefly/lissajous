#include <iostream>
#include <algorithm>
using namespace std;

void blankGraph(int* graph, int xSize, int ySize) {
    for (int y = 0; y < ySize; ++y) {
        for (int x = 0; x < xSize; ++x) {
            graph[y * xSize + x] = 0;
        }
    }
}

void setGraph(int* graph, int x, int y, int xSize) {
    graph[y * xSize + x] = 1;
}

void plotGraph(int* graph, int xSize, int ySize) {
    for (int y = 0; y < ySize; ++y) {
        for (int x = 0; x < xSize; ++x) {
            if (graph[y * xSize + x]) {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

double poly(double x) {
    while (abs(x) >= 0.1) {
        x = poly(x / (sqrt(1 + x) + sqrt(1 - x)));
    }
    x = x + pow(x, 3.0) / 6.0 + 0.75 * pow(x, 5.0) + pow(x, 7.0) / 22.4;
    return x;
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
    dxFreq = xFreq * 2 * PI;
    cout << "Relative frequency for Y (integer): ";
    cin >> yFreq;
    dyFreq = yFreq * 2 * PI;
    cout << "Y phase as a multiple of pi (decimal): ";
    cin >> yPhase;
    yPhase *= PI;

    for (int x1 = -height; x1 <= height; ++x1) {
        double x = poly((double)x1 / (double)height);
        double t1 = x, t2 = PI - x;
        int* y = new int[2 * xFreq];

        for (int i = 0; i < xFreq; ++i) {
            double t3 = (t1 + 2 * i * PI) / dxFreq;
            double t4 = (t2 + 2 * i * PI) / dxFreq;
            double y1 = 30 * sin(dyFreq * t3 + yPhase);
            double y2 = 30 * sin(dyFreq * t4 + yPhase);
            y[2 * i] = (int)round(y1);
            y[2 * i + 1] = (int)round(y2);
        }
        sort(y, y + xFreq * 2);

        for (int i = 0; i < 2 * xFreq; ++i) {
            cout << y[i]+36 << ", ";
        }
        cout << endl;
        delete[] y;
    }
}
