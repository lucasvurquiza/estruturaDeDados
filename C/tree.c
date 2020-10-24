#include <stdio.h>
#include <stdlib.h>
#define COUNT 10

typedef struct nodeTree {
   int value;
   struct nodeTree* left;
   struct nodeTree* right;
    
} nodeTree;


nodeTree* creatreNull(){
   return NULL;   
}


nodeTree* create(int value, nodeTree* treeLeft, nodeTree* treeRight){
   nodeTree* t=(nodeTree*) malloc(sizeof(nodeTree));
   if(!t) {
      printf("Erro: não há espaço na memória!");
      exit(1);
   }
   
   t->value = value;
   t->left = treeLeft;
   t->right = treeRight;
   
   return t;
   
}

void insert(nodeTree **t, int value){
    if(*t == NULL){
        *t=create(value, NULL, NULL);
    } else {
        if(value > (*t)->value){
            insert(&((*t)->right), value);
        } else {
            insert(&((*t)->left), value);
        }
    }
}




int treeClear(nodeTree*  t){
    return t == NULL;
}

nodeTree* clearTree(nodeTree*  t){
   if(!treeClear(t)){
       clearTree(t->left);
       clearTree(t->right);
       free(t);
   }
   return NULL;
}

int findNode(nodeTree*  t, int value){
    if(treeClear(t)){
        return 0;
    }
    
    return t->value==value || findNode(t->left, value) || findNode(t->right, value);
}

void printTree(nodeTree*  t){
    if(!treeClear(t)){
        printf("Nó: %i ",t->value);  //raiz */
        printTree(t->left);/* mostra sae*/
        printTree(t->right);/* mostra sad*/
    }
}



void printEmOrdem(nodeTree *t){
    if(t != NULL){
        printEmOrdem(t->left);
        printf("\n%i", t->value);
        printEmOrdem(t->right);
    }    
}


void printPosOrdem(nodeTree *t){
    if(t != NULL){
        printPosOrdem(t->left);
        printPosOrdem(t->right);
        printf("\n%i", t->value);
    }    
}


void printPreOrdem(nodeTree *t){
    if(t != NULL){
        printf("\n%i", t->value);
        printPreOrdem(t->left);
        printPreOrdem(t->right);
    }    
}

int countNode(nodeTree *t){
   if(t == NULL)
        return 0;
   else
        return 1 + countNode(t->left) + countNode(t->right);
}

int maior(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}



int altura(nodeTree *t){
   if((t == NULL) || (t->left == NULL && t->right == NULL))
       return 0;
   else
       return 1 + maior(altura(t->left), altura(t->right));
}

int contarFolhas(nodeTree *t){
   if(t == NULL)
        return 0;
   if(t->left == NULL && t->right == NULL)
        return 1;
   return contarFolhas(t->left) + contarFolhas(t->right);
}

void print2DUtil(nodeTree *root, int space){
    if(root == NULL){
        return;
    }
    space += COUNT;
    print2DUtil(root->right, space);
    printf("\n");
    for(int i = COUNT; i<space; i++){
        printf(" ");
    }
    printf("%d \n", root->value);
    print2DUtil(root->left, space); 
}

void print2D(nodeTree *root){
    print2DUtil(root, 0);
}

nodeTree *maiorNoDireita(nodeTree **t){
    
    if((*t)->right != NULL) {
       return maiorNoDireita(&(*t)->right);
    }  else {
       nodeTree *tTemp = *t;
       
       if((*t)->left != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da esquerda!
        {
          *t = (*t)->left;
        } else {
            *t = NULL;
            return tTemp;
        }
    }
}

nodeTree *menorNoEsquerda(nodeTree **t)
{
    if((*t)->left != NULL)
    {
       return menorNoEsquerda(&(*t)->left);
    }
    else
    {
        nodeTree *tTemp = *t; 
        if((*t)->right != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da direita!
        {
          *t = (*t)->right;
        }
        else
        {
          *t = NULL;
        }
        return tTemp;
    }
}


void removeNode(nodeTree **root, int value){
    if(*root == NULL){   // esta verificacao serve para caso o numero nao exista na arvore.
       printf("Valor não encontrado: %i!\n", value);
       return;
    }
    if(value < (*root)->value)
       removeNode(&(*root)->left, value);
    else 
       if(value > (*root)->value)
          removeNode(&(*root)->right, value);
       else{    // se nao eh menor nem maior, logo, eh o numero que estou procurando! :)
          nodeTree *pAux = *root;     // quem programar no Embarcadero vai ter que declarar o pAux no inicio do void! :[
          if (((*root)->left == NULL) && ((*root)->right == NULL)){         // se nao houver filhos...
                free(pAux);
                (*root) = NULL; 
               }
          else{     // so tem o filho da direita
             if ((*root)->left == NULL){
                (*root) = (*root)->right;
                pAux->right = NULL;
                free(pAux); pAux = NULL;
                }
             else{            //so tem filho da esquerda
                if ((*root)->right == NULL){
                    (*root) = (*root)->left;
                    pAux->left = NULL;
                    free(pAux); pAux = NULL;
                    }
                else{       //Escolhi fazer o maior filho direito da subarvore esquerda.
                   pAux = maiorNoDireita(&(*root)->left); //se vc quiser usar o Menor da esquerda, so o que mudaria seria isso:
                   pAux->left = (*root)->left;          //        pAux = MenorEsquerda(&(*root)->right);
                   pAux->right = (*root)->right;
                   (*root)->left = (*root)->right = NULL;
                   free((*root));  *root = pAux;  pAux = NULL;   
                   }
                }
             }
          }
}

int main(){
    nodeTree* t = NULL;
    insert(&t, 23);
    insert(&t, 10);
    insert(&t, 2);
    insert(&t, 1);
    insert(&t, 90);
    insert(&t, 5);
    printf("\n");
    printf("\n");
    print2D(t);
    printf("\n");
    printf("\n");
    printf("\nEm ordem: \n");
    printEmOrdem(t);
    printf("\n");
    printf("\nPós ordem: \n");
    printPosOrdem(t);
    printf("\n");
    printf("\nPré ordem: \n");
    printPreOrdem(t);
    printf("\n");
    printf("\n Quantidade nós: %i \n", countNode(t));
    printf("\n Altura nós: %i \n", altura(t));
    printf("\n Quantidade folhas: %i \n",  contarFolhas(t));
    printf("\n");
    
    removeNode(&t, 90);
    removeNode(&t, 10);
    removeNode(&t, 2);
    
    printf("\n");
    printf("\n");
    print2D(t);
    printf("\n");
    printf("\n");

    printf("\nEm ordem: \n");
    printEmOrdem(t);
    printf("\n");
    
    return 0;   
}