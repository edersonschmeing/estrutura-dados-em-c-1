#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>  


#include "grafos.h" 


struct grafo {
	   
    bool ponderado;
    int numero_de_vertices; 
    int numero_maximo_de_arestas;
    int** arestas;
    float** pesos; 
    int* grau;
};


Grafo *criar_grafo(int numero_de_vertices, int numero_maximo_de_arestas, bool ponderado) {
     
     return NULL;
}

void destruir_grafo(Grafo *ptr_grafo) { 


}

void inserir_aresta_grafo(Grafo *ptr_grafo, int vertice_origem, int vertice_destino, bool direcionado, float peso) { 


}


void remover_aresta_grafo(Grafo *ptr_grafo, int vertice_origem, int vertice_destino, bool direcionado) { 

}



    