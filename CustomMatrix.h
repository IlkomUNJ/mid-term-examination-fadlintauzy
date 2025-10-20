#ifndef CUSTOMMATRIX_H
#define CUSTOMMATRIX_H

#include <iostream>

using namespace std;

class CustomMatrix{
public:
    bool mat[10][10] = {false};
    CustomMatrix(){

    }

    CustomMatrix(const bool m[10][10]){
        // Hardcode the dimensions 10x10 for the copy loop
        for (int i=0; i < 10; i++) {
            for(int j=0; j < 10; j++){
                // Copy the value
                mat[i][j] = m[i][j];
            }
        }
    }

    // **CHANGED**: The fillMatrix function now handles a 10x10 array
    void fillMatrix(const bool m[10][10]){
        // Hardcode the dimensions 10x10 for the copy loop
        for (int i=0; i < 10; i++) {
            for(int j=0; j < 10; j++){
                // Copy the value
                mat[i][j] = m[i][j];
            }
        }
    }
};

#endif // CUSTOMMATRIX_H
