#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 20

struct st{
	int info[TAMANHO];
	int topo;
};

typedef struct st PILHA;

void iniciar_Pilha(PILHA *st);
void pop(PILHA *st);
int top(PILHA st);
int full(PILHA st);
int empty(PILHA st);
void push(PILHA *st, int vr);
void show(PILHA *st);

int main (){
    PILHA pilha;
    int valor;

    iniciar_Pilha(&pilha);
	printf("Pilha Iniciada!\n");
	printf("\n");

    printf("Digite um Valor inteiro para Inserir na Pilha:");
	scanf("%d", &valor); 
	if(!full(pilha)) push(&pilha,valor);
	else printf("OverFlow!\n");
	printf("\n");

    printf("Digite um Valor inteiro para Inserir na Pilha:");
	scanf("%d", &valor); 
	if(!full(pilha)) push(&pilha,valor);
	else printf("OverFlow!\n");
	printf("\n");

    printf("Digite um Valor inteiro para Inserir na Pilha:");
	scanf("%d", &valor); 
	if(!full(pilha)) push(&pilha,valor);
	else printf("OverFlow!\n");
	printf("\n");

    printf("Digite um Valor inteiro para Inserir na Pilha:");
	scanf("%d", &valor); 
	if(!full(pilha)) push(&pilha,valor);
	else printf("OverFlow!\n");
	printf("\n");

    printf("Digite um Valor inteiro para Inserir na Pilha:");
	scanf("%d", &valor); 
	if(!full(pilha)) push(&pilha,valor);
	else printf("OverFlow!\n");
	printf("\n");

    printf("Digite um Valor inteiro para Inserir na Pilha:");
	scanf("%d", &valor); 
	if(!full(pilha)) push(&pilha,valor);
	else printf("OverFlow!\n");
	printf("\n");

    show(&pilha);

    if(!empty(pilha)) pop(&pilha);
	else printf("UnderFlow ! - Topo:[%i]\n", pilha.topo);
	printf("\n");

    show(&pilha);
}

void iniciar_Pilha(PILHA *st){ // Inicia a Pilha
	(*st).topo=-1;
}

void pop(PILHA *st){ // Remover Elemento
	st->topo--;
}

int top(PILHA st){ // Elemento do Topo
	return st.info[st.topo];
}

int full(PILHA st){ // Pilha Cheia
	return !((TAMANHO -1)-st.topo); 
}

int empty(PILHA st){
	return !(st.topo+1); // Negação qualquer valor diferente de 1 vai ser 0, caso saia 0 a negação retorna 1
}

void push(PILHA *st, int vr){ // Insere na Pilha
		if(!full(*st)){
		(*st).info[++((*st).topo)] = vr;
		}
}

void show(PILHA *st){
    int i;
    if(empty(*st)){
        printf("Pilha vazia");
        return;
    }
    for(i=st->topo; i>=0; i--){
        printf("%d->", st->info[i]);
    }
    printf("\n");
}

PILHA* buscar(PILHA *pilha, int vr) {
    PILHA *atual = pilha;
    while (atual != NULL) {
        if(atual->top == vr) {
            return atual;
        }
        atual = atual->top--;
    }
    return NULL;
}