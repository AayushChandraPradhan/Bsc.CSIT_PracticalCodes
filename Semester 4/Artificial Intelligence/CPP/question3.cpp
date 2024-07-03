#include <iostream>
#include <limits> 
#include <iomanip>
using namespace std;

int xCapacity;
int yCapacity;

void display(int x, int y, int step) {
    cout << setw(20) << x << setw(20) << y << setw(15) << step << endl;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int steps(int n) {
    int x = 0, y = 0, step = 0;

    cout << setw(20) << "Vessel A" << setw(20) << "Vessel B" << setw(15) << "Steps" << endl;

    while (x != n) {
        if (x == 0) {
            x = xCapacity;
            step++;
            cout << "Fill X";
            display(x, y, step);
        } else if (y == yCapacity) {
            y = 0;
            step++;
            cout << "Empty Y";
            display(x, y, step);
        } else {
            int temp = min(yCapacity - y, x);
            y += temp;
            x -= temp;
            step++;
            cout << "Pour X in Y";
            display(x, y, step);
        }
    }

    return step;
}

int main() {
    int n, stepsRequired;

    cout << "Enter the liters (GOAL) of water required to be filled in Vessel 1: ";
    cin >> n;

    cout << "Enter the capacity of the vessel: ";
    cin >> xCapacity;

    if (xCapacity < n) {
        cout << "The capacity of Vessel 1 must be at least as much as the goal.\n";
        return 1; 
    }

    cout << "Enter the capacity of the second vessel: ";
    cin >> yCapacity;

    stepsRequired = steps(n);

    cout << "Steps Required: " << stepsRequired << endl;

    return 0;
}
