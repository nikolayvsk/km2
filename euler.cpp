#include <iostream>
#include <iomanip>
#include <cmath>

double f(double x, double y){
    return (y - x) / (y + x);
}
int main()
{
    double x[1000] = {0.5};
    double y[1000] = {0};
    double h = 0.05;
    double x_final = 1;
    std::cout << "Euler method, where " << x[0] << " <= x <= " << x_final << ", x0=" << x[0] << ", y0=" << y[0] << ", h=" << h << std::endl;
    int i = 0;
    while (x[i] <= x_final+1)
    {
        y[i+1] += y[i] + h * f(x[i],y[i]);

        std::cout << "Step " << std::setprecision(12) << i+1 << std::setw(12) << "x[" << i << "]=" << x[i] << std::setw(12) << "y[" << i << "]=" << y[i] << std::endl;
        x[i+1] = x[i] + h;
        i++;
    }
    return 0;
}
