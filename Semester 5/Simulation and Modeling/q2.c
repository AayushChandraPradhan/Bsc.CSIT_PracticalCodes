#include <stdio.h>

int main() {
    double Y1 = 80;
    double G[5] = {20, 25, 30, 35, 40};
    double I, Y, T, C;
    
    double I_values[5], Y_values[5], T_values[5], C_values[5];
    
    for (int year = 0; year < 5; year++) {
        I = 2 + 0.1 * Y1;
        I_values[year] = I;
        
        Y = 45.45 + 2.27 * (I + G[year]);
        Y_values[year] = Y;
        
        T = 0.2 * Y;
        T_values[year] = T;
        
        C = 20 + 0.7 * (Y - T);
        C_values[year] = C;
        
        Y1 = Y;
    }
    
    printf("Year\tI\t\tY\t\tT\t\tC\n");
    for (int year = 0; year < 5; year++) {
        printf("%d\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", year + 1, I_values[year], Y_values[year], T_values[year], C_values[year]);
    }
    
    return 0;
}
