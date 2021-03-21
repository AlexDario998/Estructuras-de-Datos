#include <iostream>
#include<bits/stdc++.h> 

using namespace std;

const int MAX = 100; 
  
// Devuelve la cantidad máxima de oro que se puede recolectar
// cuando el viaje comenzó desde la primera columna y se mueve
// permitidos son el derecho, el derecho hacia arriba y el derecho hacia abajo
int getMaxGold(int gold[][MAX], int m, int n) 
{ 
	// Crea una tabla para almacenar resultados intermedios
     // e inicializar todas las celdas a 0. La primera fila de
     // goldMineTable da el máximo de oro que el minero
     // puede recolectar cuando comienza esa fila
    int goldTable[m][n]; 
    memset(goldTable, 0, sizeof(goldTable)); 
  
    for (int col=n-1; col>=0; col--) 
    { 
        for (int row=0; row<m; row++) 
        { 
			// Oro recogido al ir a la celda de la derecha (->)
            int right = (col==n-1)? 0: goldTable[row][col+1]; 
  
           // Oro recogido al ir a la celda para subir (/)
            int right_up = (row==0 || col==n-1)? 0: 
                            goldTable[row-1][col+1]; 
  
           // Oro recogido al ir a la celda a la derecha hacia abajo (\)
            int right_down = (row==m-1 || col==n-1)? 0: 
                             goldTable[row+1][col+1]; 
  
			// Max de oro recolectado al tomar cualquiera de los
             // por encima de 3 rutas	
            goldTable[row][col] = gold[row][col] + 
                              max(right, max(right_up, right_down));                                                      
        } 
    } 
  
	// La cantidad máxima de oro recolectada será la máxima
     // valor en la primera columna de todas las filas
    int res = goldTable[0][0]; 
    for (int i=1; i<m; i++) 
        res = max(res, goldTable[i][0]); 
    return res; 
} 
  
