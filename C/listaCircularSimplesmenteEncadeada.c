#include <stdio.h>
#include <stdlib.h>

struct noh{
	int dado;
	struct noh *prox;
};

typedef struct noh *LLCSE;

void criaLista(LLCSE *L);
void insereFinal(LLCSE *L, int vr);
void removerFinal(LLCSE *L);
void mostraLista(LLCSE L);

int main(){
    LLCSE lista;
    int vr;
    
    criaLista(&lista);
    
    printf("Digite Valor a ser Inserido: ");
    scanf("%d", &vr);
	insereFinal(&lista,vr);
	
	printf("Digite Valor a ser Inserido: ");
    scanf("%d", &vr);
	insereFinal(&lista,vr);
	
	printf("Digite Valor a ser Inserido: ");
    scanf("%d", &vr);
	insereFinal(&lista,vr);
	
	mostraLista(lista);
	
	removerFinal(&lista);
	
	mostraLista(lista);
    
}

void criaLista(LLCSE *L){
	*L= NULL;
}

void mostraLista(LLCSE L){
	LLCSE aux = L;
	if(L != NULL){
		while(aux->prox != L){
			printf("[%d] ",aux->dado);
			aux = aux->prox;
		}
		printf("[%d]\n",aux->dado);
	}else{
		 printf("Lista Nula!\n");
	}
}

void insereFinal(LLCSE *L, int vr){
	LLCSE novo = (LLCSE) malloc(sizeof(struct noh));
	LLCSE aux = *L;
		if(novo){
			novo->dado = vr;
			if(!*L){
				*L = novo;
				novo->prox = *L;
				
			}else{
				for(aux=*L;aux->prox!= *L;aux=aux->prox);
				novo->prox = *L;
				aux->prox = novo;	
			}
		}
}

void removerFinal(LLCSE *L){
	if(*L){
		LLCSE aux=*L,aux2;
		if(aux->prox == *L){
			*L= NULL;
			free(aux);	
		}else{
			for(aux = *L; aux->prox != *L; aux=aux->prox){
				aux2 = aux;
			}
			aux2->prox = *L;
			free(aux);
		}
	}
}


