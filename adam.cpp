#include <iostream>
#include <iomanip>
#include <cmath>

double f(double x, double y){
    return (y - x) / (y + x);
}
int main()
{
    double x[1000] = {0.55, 0.6, 0.65};
    double y[1000] = {-0.0553741496599, -0.123555830425, -0.209486619073};
    double h = 0.05;
    double x_final = 1;

    int i = 2;
    std::cout << "Adams' method, where 0.65 <= x <= 1, y0=" << y[0] << ", h=" << h << std::endl;
    while (x[i] <= x_final+1)
    {
        double k1 = f(x[i],y[i]) * h;
        double k2 = f(x[i-1],y[i-1]) * h;
        double k3 = f(x[i-2],y[i-2]) * h;

        y[i+1] += y[i] + (23 * k1 - 16 * k2 + 5 * k3) / 12;
        //y[i+1] += y[i] + h * (-1 * k1 + 8 * k2 + 5 * k3) / 12; // Another way of calculating
        std::cout << "Step " << std::setprecision(12) << i-1 << std::setw(12) << "x[" << i-2 << "]=" << x[i] << std::setw(12) << "y[" << i-2 << "]=" << y[i] << std::endl;
        x[i+1] = x[i] + h;
        i++;
    }
    return 0;
}
