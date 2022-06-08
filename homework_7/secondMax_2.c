#include <stdio.h>

int secondMax(const int*, size_t, int*);

int main(){
    int sm;
    int arr[100];
    unsigned size;
    do{
        printf("Enter size:\n");
        scanf("%u", &size);
    }while(size<0 || size>10);

    for(int i=0; i < size; i++){
        printf("Enter element:\n");
        scanf("%d", &arr[i]);
    }


    printf("Second max is: %d\n", secondMax(arr, size, &sm));
    
    return 0;
}

int secondMax(const int* arr, size_t n, int* secondMax){
    int firstmax = *arr; //zadavam purviqt max el da e purviq el v masiva
    *secondMax = *(arr + 1); //vtoriqt max da e vtoriq element v masiva

    if(n == 0){
        fprintf(stderr, "Array has zero elements!\n"); //masivut da nqma elementi
        return -1;
    }else if(n == 1){
        fprintf(stderr, "Array has only 1 element!\n");
        return *arr;
    }

    for(int i=1; i < n; i++){
        if(*(arr + i) > firstmax){
            *secondMax = firstmax; // za da moje vinagi firstmax da e po-golqm
            firstmax = *(arr + i);
        }else if(*(arr + i) > *secondMax){
            *secondMax = *(arr + i);
        }
    }
    if(firstmax == *secondMax){
        fprintf(stderr, "First max el is equal with second\n");
    }
    return *secondMax;
}