#include <iostream>
#include <cstdlib>
#include <cmath>

#pragma once

typedef struct Node
{
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
} Node;

typedef struct LinkedList
{
    Node* ptrFirst;

}LinkedList;

namespace sortAlgorithms {
// Manipulação da lista
void mostraLista(LinkedList*);
void deleteAll(LinkedList*);
LinkedList* novaLista();

void displayNodes(Node*);
void deleteNodes(Node**);

// Ordenação da lista
// Selection
void selectionsort(LinkedList*);
void optimizedSelectionSort(LinkedList*);

// Bubble Sort
void bubbleSortList(Node**, int);
void optimizedBubbleSortList(Node**, int);

// Insertion
void insertionSort(LinkedList*);

// Shell sort
void shellSort (Node**, int);


// Funções com template
// Criação do nó 
template<typename T>
Node* newNode(T iValue)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->ptrPrev = NULL;

    temp->iPayload = iValue;
    temp->ptrNext = NULL;
    return temp;
}

// Adiciona elemento 
template<typename T>
void adicionaFinal(LinkedList *lista, T iValor)
{
    Node* temp = newNode(iValor);

    // Se lista vazia, adiciona no primeiro
    if ( lista->ptrFirst == NULL)
    {
        lista->ptrFirst = temp;
        return;
    }

    Node* atual = lista->ptrFirst;

    // Encontra o último aluno
    while(atual->ptrNext != NULL)
    {
        atual = atual->ptrNext;
    }

    // Adiciona após o último
    atual->ptrNext = temp;
    temp->ptrPrev = atual;
    return;

}

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

// ===============================================================
template<typename T>
void insertEnd(Node** head, T iPayload)
{
  Node* newNode = createNode(iPayload);
  //newNode -> ptrNext = nullptr;
  
  if (*head == nullptr)
  {
      //newNode -> ptrNext = nullptr; Essa linha não é obrigatória pois já definimos anteriormente
      (*head) = newNode;
      return;
      
  }
  
  Node* temp = (*head);
  
  //Percorremos a lista até seu fim(ptrNext do ultimo nó é NULL)
  while(temp -> ptrNext != nullptr) temp = temp -> ptrNext;
  
  newNode -> ptrPrev = temp; //newNode aponta para o fim da lista
  temp -> ptrNext = newNode; //Antigo último elemento aponta para o novo nó
}

template<typename T>
Node* createNode(T iPayload)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp -> iPayload = iPayload;
    temp -> ptrNext = nullptr;
    temp -> ptrPrev = nullptr;
    
    return temp;
}

}


