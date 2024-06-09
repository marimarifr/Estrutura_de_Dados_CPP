#include <iostream>
#include <cstdlib>
#include <cmath>

#pragma once

typedef struct Node
{
    int iPayload;
    Node* ptrLeft;
    Node* ptrRight;
} Node;

// Nó da lista encadeada
typedef struct NodeDll
{
    Node* nodeTree;
    NodeDll* ptrNext;
    NodeDll* ptrPrev;
} NodeDll;
 
// Lista encadeada
typedef struct LinkedList
{
    NodeDll* ptrFirst;
} LinkedList;

typedef struct NodeSimpleList
{
    int iPayload;
    NodeSimpleList* ptrNext;
    NodeSimpleList* ptrPrev;
} NodeSimpleList;



namespace treeArrayFunctions {

///////////Funções para árvore em array/////////////////////////////
Node* createNode(int);
Node* insertNode(Node*, int);
void bfsTraversal(Node*);
int treeHeight(Node*);


Node* dfsSearch(Node*, int);
Node* lesserLeaf(Node*);
Node* deleteNode(Node*, int);

void traversePreOrder(Node*);
void traverseInOrder(Node*);
void traversePostOrder(Node*);
}

namespace treeListFunctions{



//////////Funções para ávore em lista//////////////////////////////

// Criação e manipulação da árvore
Node* createNode(int);
Node* insertNode(Node*, int);
void bfsTraversal(Node*);
int treeHeight(Node*);
Node* searchNode(Node* , int );
void deleteTree(Node*);
Node* bfsSearch(Node* , int );
int treeHeightDLL(Node*);

// Criação e manipulação da lista
LinkedList* novaLista();
void adicionaFinal(LinkedList*, Node*);
NodeDll* newNode(int);
void liberaLista(LinkedList* );
void deleteNodes(NodeSimpleList** )


// ===============================================================
// // Estatísticas descritivas
// Calculando a média
template<typename T>    
float findMean(T lista[], int iTam)
{
    int i = 0;
    float mean = 0.0;
    
    // Iterando sobre os elementos 
    for (i =0; i<iTam; i++)
    {
        mean += lista[i];
    }
    
    // Normalizando a soma total
    mean = mean/iTam;
    
    return mean;
}

// Calculando o desvio padrão
template<typename T>
float calculateSD(T lista[], int iTam, float mean) 
{ 
    float standardDeviation = 0.0; 
    int i = 0;
    
    // Iterando sobre todos elementos
    for (int i = 0; i < iTam; i++) 
    { 
        // Calculando a diferença ao quadrado com a média
        standardDeviation += pow(lista[i] - mean, 2); 
    } 

    return sqrt(standardDeviation / iTam); 
} 


// Funções com template
// Criação do nó 
template<typename T>
NodeSimpleList* newNodeSL(T iValue)
{
    NodeSimpleList* temp = (NodeSimpleList*) malloc(sizeof(NodeSimpleList));
    temp->ptrPrev = NULL;

    temp->iPayload = iValue;
    temp->ptrNext = NULL;
    return temp;
}
// Adiciona elemento 
template<typename T>
void adicionaFinalSL(NodeSimpleList** head, T iValor)
{
    NodeSimpleList* newNode = newNodeSL(iValor);

    if (*head == nullptr)
     {
      (*head) = newNode;
      return;
    }

    NodeSimpleList* atual = (*head);

    // Encontra o último aluno
    while(atual->ptrNext != NULL)
    {
        atual = atual->ptrNext;
    }

    newNode -> ptrPrev = atual; //newNode aponta para o fim da lista
    atual -> ptrNext = newNode; //Antigo último elemento aponta para o novo nó
    return;

}

// ===============================================================
}