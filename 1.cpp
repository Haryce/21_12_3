#include <iostream>
using namespace std;
//определитeль 2x2 матрицы
double deter(double a, double b, double c, double d) {
    return a * d - b * c;
}
void Cramer(double a[2][2], double b[2], double& x1, double& x2) {
    double D = deter(a[0][0], a[0][1], a[1][0], a[1][1]);
    if (D == 0) {
        cout << "Система уравнений не имеет единственного решения (определитель равен нулю)." << endl;
        return;
    }
    double D1 = deter(b[0], a[0][1], b[1], a[1][1]);
    double D2 = deter(a[0][0], b[0], a[1][0], b[1]);
    x1 = D1 / D;
    x2 = D2 / D;
}
int main() {
    setlocale(LC_ALL, "Russian");
    double a[2][2];
    double b[2];    
    double x1, x2;  
    cout << "Введите коэффициенты для системы уравнений 2 уравнения 2 переменные:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
        cout << "b[" << i << "] = ";
        cin >> b[i];
    }
    Cramer(a, b, x1, x2);
    cout << "Решение системы уравнений:" << endl;
    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
    return 0;
}