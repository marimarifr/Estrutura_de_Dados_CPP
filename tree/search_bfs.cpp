#include <iostream>
#include <cstdlib>

using namespace std;

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
 
typedef struct LinkedList
{
    NodeDll* ptrFirst;
} LinkedList;

// Criação e manipulação da árvore
Node* createNode(int);
Node* insertNode(Node*, int);
void bfsTraversal(Node*);
int treeHeight(Node*);
Node* searchNode(Node* , int );

// Criação e manipulação da lista
LinkedList* novaLista();
void adicionaFinal(LinkedList*, Node*);
NodeDll* newNode(int);



int main()
{
    
   Node* root = NULL;
   
   root = insertNode(root, 42);
   root = insertNode(root, 13);
   root = insertNode(root, 11);
   root = insertNode(root, 10);
   root = insertNode(root, 28);
   root = insertNode(root, 51);
   root = insertNode(root, 171);
   
   cout << "BFS Traversal: " << endl;
   bfsTraversal(root);

   return 0;
}

Node* createNode(int iValue)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    
    if (temp == NULL)
    {
        cerr << "Erro em createNode: malloc" << endl;
        exit(1);
    }
    
    temp->iPayload = iValue;
    temp->ptrRight = NULL;
    temp->ptrLeft = NULL;
    
    return temp;
}

Node* insertNode(Node* startingNode, int iData)
{
    if (startingNode == NULL)
    {
        return createNode(iData);
    }

    if (iData < startingNode->iPayload)
    {
        startingNode->ptrLeft = insertNode(startingNode->ptrLeft, iData);
    }
    else
    {
        startingNode->ptrRight = insertNode(startingNode->ptrRight, iData);
    }

    return startingNode;
}

void bfsTraversal(Node* startingNode)
{
    // Testa lista vazia
    if (startingNode == NULL) return;
    
    // Criando a lista dos nós
    LinkedList* listaTree = novaLista();
    adicionaFinal(listaTree, startingNode);
    
    // Inicializando o primeiro como o primeiro da lista
    Node* frontNode = listaTree->ptrFirst->nodeTree; 
    NodeDll* nodeList = listaTree->ptrFirst;
    
    
    while (nodeList)
    {
        // Nó que está sendo atendido
        Node* currentNode = nodeList->nodeTree;
        // Exibindo o nó atual
        cout << currentNode->iPayload << " ";
        // Adicionando os filhos a esquerda e direita na lista
        if (currentNode->ptrLeft != NULL)
        {
            adicionaFinal(listaTree, currentNode->ptrLeft);
        }
        if (currentNode->ptrRight != NULL)
        {
            adicionaFinal(listaTree, currentNode->ptrRight);
        }
        // Atualizando para atender o próximo da lista
        nodeList = nodeList->ptrNext;
    }
    cout << endl; 
}


// Trabalho
// Parte 2: Elaborar busca utilizando bfs (sem ddl)
// Parte 3: Monitorar o desempenho em busca em árvore utilizando DFS e bfs
// Tem que fazer template e colocar os tempos na main

// Parte 4: Monitorar o desempenho de criação de lista (sem agregação)
// Parte 5: Monitorar o desempenho de criação de árvores

LinkedList* novaLista()
{
    LinkedList* temp = (LinkedList*) malloc(sizeof(LinkedList));
    temp->ptrFirst = NULL;

    return temp;
}

NodeDll* newNode(Node* iValue)
{
    NodeDll* temp = (NodeDll*) malloc(sizeof(NodeDll));
    temp->ptrPrev = NULL;

    temp->nodeTree = iValue;
    temp->ptrNext = NULL;
    return temp;
}

void adicionaFinal(LinkedList *lista, Node* iValor)
{
    NodeDll* temp = newNode(iValor);

    // Se lista vazia, adiciona no primeiro
    if ( lista->ptrFirst == NULL)
    {
        lista->ptrFirst = temp;
        return;
    }

    NodeDll* atual = lista->ptrFirst;

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