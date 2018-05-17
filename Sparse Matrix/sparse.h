//
//  sparse.h
//  Sparse Matrix
//
//  Created by Ajay Raj Nelapudi on 17/05/18.
//  Copyright © 2018 Ajay Raj Nelapudi. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include <cstdlib>
#include <assert.h>
#define r1 5
#define c1 5
#define r2 5
#define c2 5

class SparseMatrix {
    int **a, **b;
    int rowsA, columnsA, rowsB, columnsB;
    int **tripletA, **tripletB;
    int **product;
public:
    SparseMatrix(int rr1, int cc1, int rr2, int cc2) {
        assert(c1 == r2);
        
        rowsA = rr1;
        columnsA = cc1;
        
        rowsB = rr2;
        columnsB = cc2;
        
        a = new int*[r1];
        for (int i=0; i<r1; i++) {
            a[i] = new int[c1];
        }
        
        b = new int*[r2];
        for (int i=0; i<r2; i++) {
            b[i] = new int[c2];
        }
        
        tripletA = new int*[r1 * c1];
        for (int i=0; i<r1*c1; i++) {
            tripletA[i] = new int[3];
        }
        
        tripletB = new int*[r2 * c2];
        for (int i=0; i<r2*c2; i++) {
            tripletB[i] = new int[3];
        }
        
        product = new int*[r1];
        for (int i=0; i<r1; i++) {
            product[i] = new int[c2];
        }
    }
    
    void formatTriplets(int a[r1][c1], int b[r2][c2]) {
        int elements = 0;
        for (int i=0; i<rowsA; i++) {
            for (int j=0; j<columnsA; j++) {
                if (a[i][j] == 0)
                    continue;
                
                elements++;
                tripletA[elements][0] = i;
                tripletA[elements][1] = j;
                tripletA[elements][2] = a[i][j];
            }
        }
        tripletA[0][0] = rowsA;
        tripletA[0][1] = columnsA;
        tripletA[0][2] = elements;
        
        elements = 0;
        for (int i=0; i<rowsB; i++) {
            for (int j=0; j<columnsB; j++) {
                if (b[i][j] == 0)
                    continue;
                
                elements++;
                tripletB[elements][0] = i;
                tripletB[elements][1] = j;
                tripletB[elements][2] = b[i][j];
            }
        }
        tripletB[0][0] = rowsB;
        tripletB[0][1] = columnsB;
        tripletB[0][2] = elements;
    }
    
    int** multiply() {
        for (int i=1; i<=tripletA[0][2]; i++) {
            for (int j=1; j<=tripletB[0][2]; j++) {
                if (tripletA[i][1] == tripletB[j][0]) {
                    product[tripletA[i][0]][tripletB[j][1]]+= tripletA[i][2] * tripletB[j][2];
                }
            }
        }
        return product;
    }
};

#endif /* Header_h */