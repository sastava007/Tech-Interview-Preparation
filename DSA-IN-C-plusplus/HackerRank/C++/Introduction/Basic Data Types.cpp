#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int a;
    long b;
    char c;
    float d;
    double e;
    
    scanf("%d %ld %c %f %lf", &a,&b, &c, &d, &e);
    printf("%d\n%ld\n%c\n%.3f\n%.9lf", a, b, c, d, e);
    
    return 0;
}
