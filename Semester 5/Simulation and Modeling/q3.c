#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int linearCongruential(int Xn, int a, int c, int m) {
return (a * Xn + c) % m;
}
int main() {
int X0;
int a, c, m;
int n;
int i;
srand(time(NULL));
a = 2;
c = 3;
m = 11;
X0 = rand();
printf("Enter the number of random numbers you want to generate: ");
scanf("%d", &n);
printf("Random numbers:\n");
int current = X0;
for (i = 0; i < n; ++i) {
current = linearCongruential(current, a, c, m);
printf("%d\n", current);
}
return 0;
}