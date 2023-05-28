#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

typedef struct {
    int sir[MAX];
    int n;
} sir;



void concat(sir *a0, sir *a1, sir *a){
    int i;
    for(i=0; i<a0->n; i++){
        a->sir[i] = a0->sir[i];
    }
    for(i=0; i<a1->n; i++){
        a->sir[i+a0->n] = a1->sir[i];
    }
    a->n = a0->n + a1->n;
}

int pow(int a, int b){
    int i, p=1;
    for(i=0; i<b; i++){
        p*=a;
    }
    return p;
}

void separate(sir *a0, sir *a1, sir *a, int k){
    int i, j0=0, j1=0;
    for(i=0; i<a->n; i++){
        if(a->sir[i] < pow(2, k)){
            a0->sir[j0++] = a->sir[i];
        } else {
            a1->sir[j1++] = a->sir[i];
        }
    }
    a0->n = j0;
    a1->n = j1;
}

void substractIntegerFromSir(sir *a, int k){
    int i;
    for(i=0; i<a->n; i++){
        a->sir[i] -= pow(2, k);
    }
}

void addIntegerToSir(sir *a, int k){
    int i;
    for(i=0; i<a->n; i++){
        a->sir[i] += pow(2, k);
    }
}

void print(sir *a){
    int i;
    for(i=0; i<a->n; i++){
        printf("%d ", a->sir[i]);
    }
    printf("\n");
}


void sort(sir *a, int k){

    sir a0, a1;
    separate(&a0, &a1, a, k);
    //printf("k=%d\n", k);
    //print(&a0);
    //print(&a1);
    substractIntegerFromSir(&a1, k-1);

    if(k>0){
        sort(&a0, k-1);
        sort(&a1, k-1);
    }
    addIntegerToSir(&a1, k-1);

    concat(&a0, &a1, a);
}


void generateNumbers(sir *a, int n, int k){
    int i;
    for(i=0; i<n; i++){
        a->sir[i] = rand() % pow(2, k+1);
    }
    a->n = n;
}

int main() {
    srand(time(NULL));
    sir a;
    int k=3;
    generateNumbers(&a, 5, k);
//    //print(&a);
//    sir a0, a1;
//    generateNumbers(&a0, 5, k);
//    print(&a0);
//    generateNumbers(&a1, 5, k);
//    print(&a1);
//    //separate(&a0, &a1, &a, k);
//    concat(&a0, &a1, &a);
    print(&a);
//    print(&a0);
//    print(&a1);
    sort(&a, k);
    print(&a);
    sir a0, a1;
    separate(&a0, &a1, &a, k);
    concat(&a0, &a1, &a);
    return 0;
}
