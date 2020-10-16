#include <stdio.h>
#include <stdlib.h>

struct noh {
	int dado;
	struct noh *ant, *prox;
};

typedef struct noh *LDDE;

void criaLista(LDDE *L);
void insereInicio(LDDE *L, int valor);
void removeInicio(LDDE *L);
void mostraLista(LDDE L);
void removeFinal(LDDE *L);
void concatenaLista (LDDE *lp, LDDE *ls);

int main (){
    LDDE lista1, lista2;
    int vr;
    
    criaLista(&lista1);
    criaLista(&lista2);
    
    printf("\nInsira valores para a Lista 1\n");
    	
    printf("\nValor a ser Inserido:");
    scanf("%d", &vr);
	insereInicio(&lista1,vr);
	
	printf("\nValor a ser Inserido:");
    scanf("%d", &vr);
	insereInicio(&lista1,vr);
	
	printf("\nValor a ser Inserido:");
    scanf("%d", &vr);
	insereInicio(&lista1,vr);
	
	printf("\nValor a ser Inserido:");
    scanf("%d", &vr);
	insereInicio(&lista1,vr);
	
	mostraLista(lista1);
	
	printf("\nInsira valores para a Lista 2\n");
	
	printf("\nValor a ser Inserido:");
    scanf("%d", &vr);
	insereInicio(&lista2,vr);
	
	printf("\nValor a ser Inserido:");
    scanf("%d", &vr);
	insereInicio(&lista2,vr);
	
	printf("\nValor a ser Inserido:");
    scanf("%d", &vr);
	insereInicio(&lista2,vr);
	
	printf("\nValor a ser Inserido:");
    scanf("%d", &vr);
	insereInicio(&lista2,vr);
	
	mostraLista(lista2);
	
	concatenaLista (&lista1, &lista2);
}

void criaLista(LDDE *L){
	*L = NULL;
}

void mostraLista(LDDE L){
	if(L){
		LDDE aux = L;
		if(aux != NULL){
			printf("[%d] ",aux->dado);
			mostraLista(aux->prox);
		}else{
			printf("\n");
		}
	}	
}

void insereInicio(LDDE *L, int valor){
	LDDE aux=*L;
	LDDE novo = (LDDE) malloc(sizeof(struct noh));
	if(*L){
		novo->dado = valor;		
		novo->prox=aux;
		aux->ant=novo;
		novo->ant = NULL;
		*L = novo;	
	}else{
		if(*L == NULL){
			novo->dado = valor;
			novo->prox =NULL;
			novo->ant = NULL;
			*L = novo;
		}
	}
}

void removeInicio(LDDE *L){
	LDDE aux = *L;
	if((*L) != NULL){ 
		*L = aux->prox;

		if(aux->prox != NULL)
			aux->prox->ant = NULL;
	free(aux);		
	}
}

void removeFinal(LDDE *L){
	LDDE aux = *L;

	if((*L) != NULL){
		while(aux->prox != NULL) aux = aux->prox;

		if(aux->ant == NULL)
			*L = aux->prox;

		else
			aux->ant->prox = NULL;

		free(aux);
	}
}

void concatenaLista (LDDE *lp, LDDE *ls){
	LDDE aux = *lp;
	
	while(aux->prox != NULL)
		aux = aux->prox;
		
	aux->prox = *ls;
	(*ls) = NULL;
}
