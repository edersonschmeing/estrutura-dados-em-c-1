#include "lista_ligada.h"
#include <stdio.h>
#include <stdlib.h> 


int main() { 
    
   printf("\n--- Lista Ligada ---\n\n");
   
   No *lista = criar_lista();

   No *lista02 = criar_lista();
   

   imprimir_lista(lista);

  // adicionar_inicio_lista(&lista, 10);
  // imprimir_lista(lista);

  //  adicionar_inicio_lista(&lista, 33);
  // imprimir_lista(lista);

  // adicionar_inicio_lista(&lista, 99);
  // imprimir_lista(lista);

  // adicionar_inicio_lista(&lista, 17);
  //  imprimir_lista(lista);

  adicionar_inicio_lista(&lista02, 1);
  adicionar_inicio_lista(&lista02, 2);
  adicionar_inicio_lista(&lista02, 3);

  imprimir_lista(lista);
  imprimir_lista(lista02);

  juntar_lista(&lista, &lista02);

  imprimir_lista(lista);
  imprimir_lista(lista02);
  
 
  /*
   remover_valor_lista(&lista, 99);
   imprimir_lista(lista);
   
   adicionar_fim_lista(&lista, 44);
   imprimir_lista(lista);

   remover_fim_lista(&lista);
   imprimir_lista(lista);

*/

   return 0;

}