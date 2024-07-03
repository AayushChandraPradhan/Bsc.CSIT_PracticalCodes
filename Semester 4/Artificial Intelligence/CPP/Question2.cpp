// 2. Write a program to implement towers of Hanoi.

#include <iostream>

using namespace std;

void tower(int n, char from, char aux, char to) {
    if (n == 1) {
        cout << "\t\tMove disk 1 from " << from << " to " << to << "\n";
        return;
    } else {
        tower(n - 1, from, to, aux); // Move n-1 disks from A to C using B as auxiliary
        cout << "\t\tMove disk " << n << " from " << from << " to " << to << "\n";
        tower(n - 1, aux, from, to); // Move n-1 disks from B to A using C as auxiliary
    }
}

int main() {
    int n;
    cout << "\n\t\t***** Tower of Hanoi *****\n";
    cout << "\t\tEnter number of discs: ";
    cin >> n;

    tower(n, 'A', 'B', 'C'); // A is the starting rod, B and C are auxiliary and destination

    return 0;
}
