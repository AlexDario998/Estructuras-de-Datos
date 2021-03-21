#include <iostream>
#include<bits/stdc++.h> 
#include "getGold.h"

using namespace std; 
// Solucion del problema de La Mina de Oro

int main(int argc, char** argv) {
    int gold[MAX][MAX]= { {1, 3, 1, 5}, 
        {2, 2, 4, 1}, 
        {5, 0, 2, 3}, 
        {0, 6, 1, 2} 
    }; 
    int m = 4, n = 4; 
   // cout<<"m = "<<m<<"\nn = "<<n<<"\n";
    cout << "El resultado es: "<<getMaxGold(gold, m, n); 
    return 0; 
}  
