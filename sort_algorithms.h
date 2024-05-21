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

// Manipulação da lista
void adicionaFinal(LinkedList *, int);
void mostraLista(LinkedList*);
void deleteAll(LinkedList*);
Node* newNode(int);
LinkedList* novaLista();
void swapValue(Node*, Node*);

void displayNodes(Node*);
void insertEnd(Node**, int);
void deleteNodes(Node**);
Node* createNode(int);

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

// Estatísticas descritivas
float findMean(int[], int);
float calculateSD(int[], int, float);


