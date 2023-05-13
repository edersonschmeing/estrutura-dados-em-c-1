#include <stdio.h>
#include <stdlib.h> 

#include "arvore_rubro_negra_caida_para_esquerda.h" 

enum cor_do_no { PRETO, VERMELHO }; // 0 = PRETO 1 = VERMELHO 

struct no {
	int chave;
    No *ptr_no_esquerda;
    No *ptr_no_direita;
    Cor cor;
};

No *criar_no_LLRB(int chave) { 

    No *ptr_no = (No*) malloc(sizeof(No));
    
    ptr_no->ptr_no_esquerda = NULL;
    ptr_no->ptr_no_direita = NULL;
    ptr_no->chave = chave;    
    ptr_no->cor = VERMELHO;

    return ptr_no;

}

No **criar_LLRB() { 

    No **ptr_no_raiz = (No**) malloc(sizeof(No*));
    if (ptr_no_raiz != NULL) 
        *ptr_no_raiz = NULL; 
   
    return ptr_no_raiz;

}

void destruir_no_LLRB(No *ptr_no) { 

    if (ptr_no == NULL)
        return; 

    destruir_no_LLRB(ptr_no->ptr_no_esquerda);
    destruir_no_LLRB(ptr_no->ptr_no_direita);
    free(ptr_no);
    ptr_no = NULL;
        
}

void destruir_LLRB(No **ptr_ptr_no_raiz) { 

    if (ptr_ptr_no_raiz == NULL)
        return;

    destruir_no_LLRB(*ptr_ptr_no_raiz);
    free(ptr_ptr_no_raiz);

}

void adicionar_LLRB(No **ptr_no, int chave) { 

    if (*ptr_no == NULL) { 
        
        No *no_novo = criar_no_LLRB(chave);
        *ptr_no = no_novo;

    } else if (chave < (*ptr_no)->chave) {
        
        adicionar_LLRB( &(*ptr_no)->ptr_no_esquerda, chave);
    
    } else if (chave > (*ptr_no)->chave) {

        adicionar_LLRB( &(*ptr_no)->ptr_no_direita, chave);
    } else {

        //corrigir a árvore 

    } 
}

void imprime_no_LLRB(int valor, int nivel, int cor) {
    
    for (int i = 0; i < nivel; i++)
        printf("-");
    printf("%2d (%d)\n", valor, cor);
}

void imprime_LLRB(No *ptr_no, int nivel) {
    
    if (ptr_no == NULL) 
        return;

    imprime_LLRB(ptr_no->ptr_no_direita, nivel + 1);
    imprime_no_LLRB(ptr_no->chave, nivel, ptr_no->cor);
    imprime_LLRB(ptr_no->ptr_no_esquerda, nivel + 1);
    
}


void pre_ordem_LLRB(No *ptr_no) { 
     
    if (ptr_no == NULL)
       return;

    printf("%d -> ", ptr_no->chave);
    pre_ordem_LLRB(ptr_no->ptr_no_esquerda);
    pre_ordem_LLRB(ptr_no->ptr_no_direita);
}

void em_ordem_LLRB(No *ptr_no) { 
     
    if (ptr_no == NULL)
       return;
        
    em_ordem_LLRB(ptr_no->ptr_no_esquerda);
    printf("%d -> ", ptr_no->chave);
    em_ordem_LLRB(ptr_no->ptr_no_direita);
}

void pos_ordem_LLRB(No *ptr_no) { 
     
    if (ptr_no == NULL)
       return;

    pos_ordem_LLRB(ptr_no->ptr_no_esquerda);
    pos_ordem_LLRB(ptr_no->ptr_no_direita);
    printf("%d -> ", ptr_no->chave);
}


No *buscar_recursivo_LLRB(No *ptr_no, int chave){
    
    if (ptr_no == NULL || ptr_no->chave == chave)
        return ptr_no;
    
    if (chave < ptr_no->chave)
       return buscar_recursivo_LLRB(ptr_no->ptr_no_esquerda, chave); 
    
    else 
       return buscar_recursivo_LLRB(ptr_no->ptr_no_direita, chave);
  
}

No *buscar_iterativo_LLRB(No *ptr_no, int chave) {

    if (ptr_no == NULL) 
        return NULL;
    
    No *prt_no_atual = ptr_no; //raiz 
        
    while (prt_no_atual != NULL) {
        
        if (chave == prt_no_atual->chave) 
            return ptr_no;

        if (chave < prt_no_atual->chave) 
           prt_no_atual = prt_no_atual->ptr_no_esquerda;      
        
        else
           prt_no_atual = prt_no_atual->ptr_no_direita;      

    }
    return NULL; // não encontrou a chave.

}



 //funcao utilizada para pegar o nó mais a direita da subarvore esquerda do nó que será removido
No* maior_direita_da_sub_arvore_esquerda(No **ptr_no) {    //  Maior Direita da sub árvore esquerda, receber raiz->esquerda
    
    if ((*ptr_no)->ptr_no_direita != NULL)
        return maior_direita_da_sub_arvore_esquerda(&(*ptr_no)->ptr_no_direita);
    else {
        No *aux = *ptr_no; //se tiver filho a esquerda, move no lugar do maior a direta que será o sucessor do no.
        if( (*ptr_no)->ptr_no_esquerda != NULL)
            *ptr_no = (*ptr_no)->ptr_no_esquerda;
        else
            *ptr_no = NULL;
        return (aux);    
    } 
}
    
 //funcao utilizada para pegar o nó mais a esquerda da subarvore direia do nó que será removido
No *menor_esquerda_da_sub_arvore_direita(No **ptr_no) { //  menorEsquerda da sub árvore direita, receber raiz->direita

    if ((*ptr_no)->ptr_no_esquerda != NULL)
        return menor_esquerda_da_sub_arvore_direita(&(*ptr_no)->ptr_no_esquerda);
    else {
        No *aux = *ptr_no; // //se tiver filho a diretia, move no lugar do menor a esquerada que será o sucessor do no.
        if( (*ptr_no)->ptr_no_direita != NULL) 
            *ptr_no = (*ptr_no)->ptr_no_direita;
        else
            *ptr_no = NULL;
       
        return (aux);    
    } 
}

void remover_LLRB(No **ptr_no, int chave) {

}

    