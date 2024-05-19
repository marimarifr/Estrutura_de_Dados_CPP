#include <iostream>
#include <cstdlib>
// #include <chrono>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// using std::chrono::high_resolution_clock;
// using std::chrono::duration_cast;
// using std::chrono::nanoseconds;


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

void swapValue(Node*, Node*);
void insertionSort(LinkedList*);
void mostraLista(LinkedList* const);
void mostraLista(LinkedList* const );
void adicionaFinal(LinkedList*, int);
LinkedList* novaLista();
Node* newNode(int);

int main()
{
    LinkedList* teste = novaLista();
    
    cout << "Testando a ordenação:" << endl;
    adicionaFinal(teste, 100);
    adicionaFinal(teste, 99);
    adicionaFinal(teste, 200);
    adicionaFinal(teste, 10);
    adicionaFinal(teste, 57);
    // cout << teste->ptrFirst->ptrNext->ptrPrev->iPayload << endl;
    
    mostraLista(teste);
    insertionSort(teste);
    mostraLista(teste);

    return 0;
}

void insertionSort(LinkedList* lista)
{
    Node* outerLoop = lista->ptrFirst->ptrNext;

    int iInsertValue = 0;

    while(outerLoop)
    {
        iInsertValue = outerLoop->iPayload;
        Node* innerLoop = outerLoop->ptrPrev;

        while(innerLoop && iInsertValue < innerLoop->iPayload)
        {
            swapValue(innerLoop->ptrNext, innerLoop);
            innerLoop = innerLoop->ptrPrev;
        }

        outerLoop = outerLoop->ptrNext;
    }
    return;
}

void swapValue(Node* elemento1, Node* elemento2)
{
    int iValor1 = elemento1->iPayload;
    
    elemento1->iPayload = elemento2->iPayload;
    elemento2->iPayload = iValor1;
}

// Exibição da lista no console
void mostraLista(LinkedList* const lista)
{
    // Se lista vazia
    if (lista->ptrFirst == NULL)
    {
        cout << "Lista vazia!" << endl;
        return;
    }
    
    // Inicializando no primeiro nó
    Node* temp = lista->ptrFirst;
    cout << "Elementos na lista: ";
    
    // Iterando até acabar a lista
    while(temp != NULL)
    {
        cout << temp->iPayload << " ";
        temp = temp->ptrNext;
    }
    cout << endl;
    return;
}

void adicionaFinal(LinkedList* lista, int iValor)
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
// Criação da lista
LinkedList* novaLista()
{
    LinkedList* temp = (LinkedList*) malloc(sizeof(LinkedList));
    temp->ptrFirst = NULL;

    return temp;
}

Node* newNode(int iValue)
{
    Node* temp = (Node*) malloc(sizeof(Node));

    temp->iPayload = iValue;
    temp->ptrNext = NULL;
    temp->ptrPrev = NULL;
    return temp;
}

// Tarefa: adaptar para lista, uma lista com muitos eleentos, só precisa de print e insert e deleteAll
