// #include "Matrix.h"
// #include <iostream>
// using namespace std;

// int main(void) {
//     int r = 3;
//     int c = 6;
//     Matrix mat(r, c);
//     for(int i = 0 ; i < mat.getRows() ; i++)
//         for(int j = 0 ; j < mat.getCols() ; j++)
//             mat.elem(i, j) = i + j ;
//     mat.print();
    
//     cout << endl;
//     int** data = mat.getMartix();
//     for(int i = 0 ; i < r ; i++) {
//         for(int j = 0 ; j < c ; j++) {
//             cout << data[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }