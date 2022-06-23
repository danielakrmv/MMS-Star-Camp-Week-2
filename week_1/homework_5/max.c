#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <float.h>


double maxNum(unsigned,...);
double minNum(unsigned,...);

int main(){
    printf("%.2lf\n", maxNum(3, 10.2, 20, 2));
    printf("%.2lf\n", minNum(3, 10.2, 20.23, 2));
    return 0;
}

double maxNum(unsigned n, ...){
    double max = DBL_MIN;
    va_list argl;
    va_start(argl, n);
    for(int i = 0; i < n; i++){
        
        double num = va_arg(argl, double);
        if(num > max){
            max = num;
        }
    }
    va_end(argl);
    return max;
}

double minNum(unsigned n, ...){
    double min = DBL_MAX;
    va_list argl;
    va_start(argl, n);
    for(int i = 0; i < n; i++){
        double num = va_arg(argl, double);
        if(num < min){
            min = num;
        }
    }
    va_end(argl);
    return min;
}