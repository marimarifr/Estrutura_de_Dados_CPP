#include "tree_functions.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

namespace treeArrayFunctions {

///////////Funções para árvore em array/////////////////////////////
Node* createNode(int iValue)
{
    Node* tmp = (Node*) malloc(sizeof(Node));
    
    if (tmp == nullptr)
    {
        cerr << "Erro em createNode: malloc" << endl;
        exit(1);
    }
    
    tmp->iPayload = iValue;
    tmp->ptrLeft = nullptr;
    tmp->ptrRight = nullptr;
    
    return tmp;
}

Node* insertNode(Node* startingNode, int iData)
{
    if(startingNode == nullptr)
    {
        return createNode(iData);
    }
    
    if(iData < startingNode->iPayload)
    {
        startingNode->ptrLeft = insertNode(startingNode->ptrLeft, iData);
    }
    else
    {
        startingNode->ptrRight = insertNode(startingNode->ptrRight, iData);
    }
    
    return startingNode;
}
///////////////////////DFS/////////////////////////////////////////


// //Função de busca usando profundidade
Node* dfsSearch(Node* startingNode, int iData)
{
    if(startingNode == nullptr) return nullptr;
    
    else if(iData == startingNode->iPayload) 
    {
        cout<<"Nó encontrado"<< endl;
        return startingNode;
    }
    else if(iData < startingNode->iPayload) return dfsSearch(startingNode->ptrLeft, iData);
    else return dfsSearch(startingNode->ptrRight, iData);
}

Node* lesserLeaf(Node* startingNode)
{
    Node* ptrCurrent = startingNode;
 
    while (ptrCurrent && ptrCurrent->ptrLeft != nullptr) ptrCurrent = ptrCurrent->ptrLeft;
    
    return ptrCurrent;
}

Node* deleteNode(Node* startingNode, int iData) 
{
    if(startingNode == nullptr) return nullptr;
    
    if(iData < startingNode->iPayload) startingNode->ptrLeft = deleteNode(startingNode->ptrLeft, iData);
    else if(iData < startingNode->iPayload) startingNode->ptrRight = deleteNode(startingNode->ptrRight, iData);
    else
    {
        Node* ptrTemp = nullptr;
        
        if(startingNode->ptrLeft == nullptr)
        {
            ptrTemp = startingNode->ptrRight;
            free(startingNode);
            return ptrTemp;
        }
        else if(startingNode->ptrRight == nullptr)
        {
            ptrTemp = startingNode->ptrLeft;
            free(startingNode);
            return ptrTemp;
        }
        
        ptrTemp = lesserLeaf(startingNode->ptrRight);
        
        startingNode->iPayload = ptrTemp->iPayload;
        
        startingNode-> ptrRight = deleteNode(startingNode->ptrRight, ptrTemp->iPayload);
    
    }
    
    return startingNode;
}

void traversePreOrder(Node* ptrStartingNode)
{
    if (ptrStartingNode != nullptr)
    {
        cout << " " << ptrStartingNode->iPayload;
        traversePreOrder(ptrStartingNode->ptrLeft);
        traversePreOrder(ptrStartingNode->ptrRight);
    }
}

void traverseInOrder(Node* ptrStartingNode)
{
    if (ptrStartingNode != nullptr)
    {
        traverseInOrder(ptrStartingNode->ptrLeft);
        cout << " " << ptrStartingNode->iPayload;
        traverseInOrder(ptrStartingNode->ptrRight);
    }
}

void traversePostOrder(Node* ptrStartingNode)
{
    if (ptrStartingNode != nullptr)
    {
        traversePostOrder(ptrStartingNode->ptrLeft);
        traversePostOrder(ptrStartingNode->ptrRight);
        cout << " " << ptrStartingNode->iPayload;
    }
}


///////////////////////BFS////////////////////////////////////////

void bfsTraversal(Node* startingNode)
{
    if (startingNode==nullptr) return;
    
    //Parte 1 do trabalho: Alterar para lista Encadeada
    Node* nodeQueue[100];
    int iQueueFront = 0;
    int iQueueRear = 0;
    
    nodeQueue[iQueueRear] = startingNode;
    iQueueRear++;
    
    
    // Condição-> indice do rear diferente do iQueueFront
    // Pegamos o filho, colocamos na fila, imprime o primeiro, anda o rear, verifica se tem filhos e assim por diante
    while(iQueueFront < iQueueRear)
    {
        Node* currentNode = nodeQueue[iQueueFront];
        iQueueFront++;
        
        cout << currentNode-> iPayload <<" ";
        
        if(currentNode->ptrLeft!=nullptr)
        {
            nodeQueue[iQueueRear] = currentNode->ptrLeft;
            iQueueRear++;
        }
        if(currentNode->ptrRight!=nullptr)
        {
            nodeQueue[iQueueRear] = currentNode->ptrRight;
            iQueueRear++;
        }
    }
}

// Parte 3 do trabalho: Moitorar o desempenho de busca em árvore utilizamos DFS e BFS
// Parte 4 do trabalho: Monitorar o desempenho de criação de listas
// Parte 5 do trabalho: Monitorar o desempenho de criação de árvores



int treeHeight(Node* startingNode)
{
    if (startingNode == nullptr) return 0 ;
    else
    {
        int iLeftHeight = treeHeight(startingNode->ptrLeft);
        int iRightHeight = treeHeight(startingNode->ptrRight);
        
        return max(iLeftHeight, iRightHeight) + 1 ; 
    }
};

}






namespace treeListFunctions {


//////////Funções para ávore em lista//////////////////////////////
    
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

// //Função de busca usando amplitude
Node* bfsSearch(Node* startingNode, int iData)
{
    // Testa lista vazia
    if (startingNode == NULL) {
        return NULL;
    }
    // Criando a lista dos nós
    LinkedList* listaTree = novaLista();
    adicionaFinal(listaTree, startingNode);
    
    // Inicializando o nó atual como o primeiro da lista
    NodeDll* nodeList = listaTree->ptrFirst;
    
    // Loop para percorrer a lista até encontrar o nó ou a lista terminar
    while (nodeList != NULL)
    {
        // Nó que está sendo atendido
        Node* currentNode = nodeList->nodeTree;
        
        // Verifica se o nó atual contém o valor procurado
        if (currentNode->iPayload == iData)
        {
            // Libera a lista criada antes de retornar
            liberaLista(listaTree);
            cout<<"Nó encontrado"<<endl;
            return currentNode;
        }

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
    
    // Se chegar aqui, o nó não foi encontrado
    // Libera a lista criada
    liberaLista(listaTree);
    
    cout<<"Nó não encontrado"<<endl;
    return NULL;
}

void liberaLista(LinkedList* lista)
{
    NodeDll* current = lista->ptrFirst;
    while (current != NULL)
    {
        NodeDll* next = current->ptrNext;
        free(current);
        current = next;
    }
    free(lista);
}

int treeHeightDLL(Node* startingNode)
{
    if (startingNode == nullptr) return 0 ;
    else
    {
        int iLeftHeight = treeHeightDLL(startingNode->ptrLeft);
        int iRightHeight = treeHeightDLL(startingNode->ptrRight);
        
        return max(iLeftHeight, iRightHeight) + 1 ; 
    }
}

void deleteTree(Node* startingNode)
{
    if (startingNode == NULL) return;

    // Primeiro, deletar a subárvore esquerda
    deleteTree(startingNode->ptrLeft);

    // Depois, deletar a subárvore direita
    deleteTree(startingNode->ptrRight);

    // Finalmente, deletar o nó atual
    free(startingNode);
}

void deleteNodes(NodeSimpleList** head)
{
    if (*head == nullptr )
    {
        cout << "Lista já esta vazia" << endl;
        return;
    }
    
    NodeSimpleList* temp = *head;

    NodeSimpleList* next = temp->ptrNext;
    free(temp);
    *head = NULL;

    while(next)
    {
        NodeSimpleList* current = next;
        next = next->ptrNext;
        // cout << current->iPayload << " ";
        free(current);
    }  

    cout << "Lista esta vazia" << endl;
}
}
