#include <stdio.h>
#include <stdlib.h>


int main() {

    int mat[3][3] = {
                     {5, 10, 30}, 
                     {20, 25, 40}, 
                     {12, 6, 22}
                    };

    printf("&mat       = %p \n", &mat);
    printf("mat        = %p \n", *mat);
    printf("&mat[0][0] = %p \n\n", &mat[0][0]);
    
    for (int i = 0;i < 3;i++){
      for (int j = 0;j < 3;j++){  
         printf("&mat[%d][%d] = %p | mat[%d][%d] = %d \n", i, j, &mat[i][j], i, j, mat[i][j]);

         printf("(*(mat + %d) + %d) = %p | *(*(mat + %d) + %d) = %d \n\n", i, j, (*(mat + i) + j), i, j, *(*(mat + i) + j) );
      }
    }

    printf("\n");
    
    // declara um ponteiro que recebe o endereço de memória da primeira posição da matriz.
    int *p = &mat[0][0];
    printf("p = %p \n", p);
    
    for (int i = 0;i < 9;i++){
        printf("(p + %d) = %p | *(p + %d) = %d \n", i, (p + i), i, *(p + i));
    }

    printf("\n");

     
    return 0;
}