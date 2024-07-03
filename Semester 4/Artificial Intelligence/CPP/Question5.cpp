// 5. Write a program to implement heuristic search procedure. 

#include <iostream> 
using namespace std; 

int main()
{
    string a, b, c, d, e;
    int t, u, v, w, z, p, q, r;
    
    cout << "Enter the root node: ";
    cin >> a;
    
    cout << "Enter the value of root node: ";
    cin >> t;
    
    cout << "Enter child 1: ";
    cin >> b;
    
    cout << "Enter value from root to child 1: ";
    cin >> u;
    
    cout << "Enter value from child 1 to terminal: ";
    cin >> p;
    
    cout << "Enter child 2: ";
    cin >> c;
    
    cout << "Enter value of child 2: ";
    cin >> v;
    
    cout << "Enter value from child 2 to terminal: ";
    cin >> q;
    
    cout << "Enter child 3: ";
    cin >> d;
    
    cout << "Enter value of child 3: ";
    cin >> w;
    
    cout << "Enter value from child 3 to terminal: ";
    cin >> r;
    
    cout << "Enter terminal node: ";
    cin >> e;
    
    if ((u + p) < (v + q) && (u + p) < (w + r))
    {
        cout << "Heuristic path is from " << a << " to " << b << " to " << e << endl;
        cout << "Total value is " << t + u + p << endl;
    }
    else if ((v + q) < (u + p) && (v + q) < (w + r))
    {
        cout << "Heuristic path is from " << a << " to " << c << " to " << e << endl;
        cout << "Total value is " << t + v + q << endl;
    }
    else if ((w + r) < (u + p) && (w + r) < (v + q))
    {
        cout << "Heuristic path is from " << a << " to " << d << " to " << e << endl;
        cout << "Total value is " << t + w + r << endl;
    }
    
    return 0;
}


