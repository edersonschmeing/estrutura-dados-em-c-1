#include "lista_ligada.h"
#include <stdio.h>
#include <stdlib.h> 


int main() { 
    
   printf("\n--- Lista Ligada ---\n\n");
   
   No *lista = criar_lista();

   imprimir_lista(lista);

   adicionar_inicio_lista(&lista, 10);
   adicionar_inicio_lista(&lista, 33);
   adicionar_inicio_lista(&lista, 99);

   imprimir_lista(lista);

   remover_valor_lista(&lista, 99);

   imprimir_lista(lista);
   
   
   return 0;

}