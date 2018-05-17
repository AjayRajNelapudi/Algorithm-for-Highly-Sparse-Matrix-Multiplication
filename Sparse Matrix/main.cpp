//
//  main.cpp
//  Sparse Matrix
//
//  Created by Ajay Raj Nelapudi on 17/05/18.
//  Copyright © 2018 Ajay Raj Nelapudi. All rights reserved.
//

#include <iostream>
#include <ctime>
#include "sparse.h"
using namespace std;

int a[r1][c1];
int b[r2][c2];
int res[r1][c2];

void multiply() {
    for (int i=0; i<r1; i++) {
        for (int j=0; j<c2; j++) {
            for (int k=0; k<r2; k++) {
                res[i][j]+= a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    clock_t start, stop;
    int **product;

    const int limit = 6;
    
    for (int i=0; i<r1; i++) {
        for (int j=0; j<c1; j++) {
            //if (i == j) {
                a[i][j] = rand() % limit;
            //} else {
                //a[i][j] = 0;
            //}
        }
    }
    
    for (int i=0; i<r2; i++) {
        for (int j=0; j<c2; j++) {
            //if (i == j) {
                b[i][j] = rand() % limit;
            //} else {
                //b[i][j] = 0;
            //}
        }
    }
    
    start = clock();
    SparseMatrix matrix(r1, c1, r2, c2);
    matrix.formatTriplets(a, b);
    product = matrix.multiply();
    stop = clock();
    double time = (double)(stop - start) / CLOCKS_PER_SEC;
    cout << time << endl;
    
    start = clock();
    multiply();
    stop = clock();
    time = (double)(stop - start) / CLOCKS_PER_SEC;
    cout << time << endl;
    
    for (int i=0; i<r1; i++) {
        for (int j=0; j<c2; j++) {
            cout << product[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl << endl;
    
    for (int i=0; i<r1; i++) {
        for (int j=0; j<c2; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}