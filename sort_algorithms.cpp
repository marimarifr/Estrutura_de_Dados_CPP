#include "sort_algorithms.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

using std::cout;
using std::endl;


// Criação da lista
LinkedList* novaLista()
{
    LinkedList* temp = (LinkedList*) malloc(sizeof(LinkedList));
    temp->ptrFirst = NULL;

    return temp;
}

// Criação do nó 
Node* newNode(int iValue)
{
    Node* temp = (Node*) malloc(sizeof(Node));

    temp->iPayload = iValue;
    temp->ptrNext = NULL;
    temp->ptrPrev = NULL;
    return temp;
}
// Adiciona elemento 
void adicionaFinal(LinkedList *lista, int iValor)
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


// Esvaziando a lista 
void deleteAll(LinkedList* lista)
{
    Node* temp = lista->ptrFirst;
    
    // Se lista vazia
    if (lista == NULL || temp == NULL)
    {
        cout << "Lista já esta vazia" << endl;
    }
    
    // Iterando para o próximo 
    Node* next = temp->ptrNext;
    free(temp);
    lista->ptrFirst = NULL;
    
    // Liberando a memória do nó atual
    while(next)
    {
        Node* current = next;
        next = next->ptrNext;
        free(current);
    }  

    cout << "Lista esta vazia" << endl;
}


// Troca os valores entre os nós
void swapValue(Node* elemento1, Node* elemento2)
{
    int iValor1 = elemento1->iPayload;
    
    elemento1->iPayload = elemento2->iPayload;
    elemento2->iPayload = iValor1;
}

// ===============================================================

// Ordenação sem otimização
void selectionsort(LinkedList*  lista)
{
    // Nó atual iterado
    Node* nodeOuter =  lista->ptrFirst;
    
    while (nodeOuter)
    {
        // Inicializando as comparações a partir do ponto que estivermos
        Node* nodeInner = nodeOuter->ptrNext; 
        while(nodeInner)
        {
            // Comparação entre os valores
            if ( nodeOuter->iPayload > nodeInner->iPayload)
            {
                // Caso maior  então trocar valores
                swapValue(nodeOuter, nodeInner);
            }
            // Comparar com o próximo
            nodeInner = nodeInner->ptrNext;
        }
        // Iterar para o próximo
        nodeOuter = nodeOuter->ptrNext;
    }
}

void optimizedSelectionSort(LinkedList* const lista)
{
    // Armazenando o nó com menor valor
    int minValue = 0;
    
    // Nó iterado  
    Node* nodeOuter =  lista->ptrFirst;
    
    while (nodeOuter)
    {
        // Inicializando com omenor valor
        minValue = nodeOuter->iPayload;
        Node* swapNode = nodeOuter;
        // Inicializando as comparações a partir do ponto que estivermos
        Node* nodeInner = nodeOuter->ptrNext; 
        
        while(nodeInner)
        {
            // Procurando por um valor menor que o já armazenado
            if ( minValue > nodeInner->iPayload)
            {
                minValue = nodeInner->iPayload;
                swapNode = nodeInner;
            }
            // Iterando para o próximo
            nodeInner = nodeInner->ptrNext;
        }
        
        // Se encntrar um valor menor do que a posição que estamos iterando então troca
        if (nodeOuter->iPayload != minValue)
        {
            swapValue(nodeOuter, swapNode);
        }
        // Itera para o próximo elemento
        nodeOuter = nodeOuter->ptrNext;
    }
}

// ===============================================================

void bubbleSortList(Node** head, int iLength)
{
    Node* temp = *head;
    
   for(int iOuterLoop = 0; iOuterLoop < iLength-1 ; iOuterLoop++){
       
        for(int iInnerLoop = 0; iInnerLoop < iLength-1 ; iInnerLoop++){
            
            if(temp->iPayload > temp->ptrNext->iPayload){
        
                swapValue(temp, temp -> ptrNext);
                
                temp = temp -> ptrNext;
                
            }
            
            else temp = temp -> ptrNext;
        
        }
        
        temp = *head;
   }
   
};

// Função bubble sort otimizada
void optimizedBubbleSortList(Node** head, int iLength){

    Node* temp = *head;
    
    // Para cada nó da lista percorremos afim de procurar valor maiores
   for(int iOuterLoop = 0; iOuterLoop < iLength-1 ; iOuterLoop++){
       
       bool bUnordered = false;
       
        for(int iInnerLoop = 0; iInnerLoop < iLength-iOuterLoop - 1 ; iInnerLoop++){
            
            // Se a iteração não entrar no segundo loop, então percorremos a lista sem trocar nenhum elemento,
            //então ela já está ordenada
            
            bUnordered = false;
            
            if(temp->iPayload > temp->ptrNext->iPayload){
                
                // Se o valor do seguinte é maior que temp, trocamos os valores
                // Dessa forma, carregamos o maior valor para o final sempre
                swapValue(temp, temp -> ptrNext);
                
                // Se entramos no loop, então ela ainda não está ordenada
                bUnordered = true;
                
                // Se trocamos o valor passamo para o nó seguinte
                temp = temp -> ptrNext;
            }
            
            // Se não há troca de valor, também passamos para o seguinte
            else temp = temp -> ptrNext;
        }
        
        // A cada loop externo, retornamos o temp para o primeiro
        temp = *head;
        
        // se ela já está ordenada paramos a iteração
        if(bUnordered == false) break;
        
        
   }
   
};


// ===============================================================
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

//================================================================
//Shell sort list
void shellSort(Node **head, int iLength) 
{
    if (*head == nullptr || iLength < 2) 
    {   
        cout<<"Lista de apenas 1 elemento"<< endl;
        return;
    }

    for (int gap = iLength / 2; gap > 0; gap /= 2) 
    {
        for (int i = gap; i < iLength; ++i) 
        {
            Node *temp = *head;
            
            for (int j = 0; j < i; j++) 
            {
                temp = temp->ptrNext;
            }
            
            Node *current = temp;
            
            for (int count = 0; count < gap && current != nullptr; count++) 
            {
                current = current->ptrNext;
            }

            while (current != nullptr) 
            {
                Node *inner = current;
                Node *traverse = inner;
                
                for (int count = 0; count < gap && traverse->ptrPrev != nullptr; count++) 
                {
                    traverse = traverse->ptrPrev;
                }

                while (traverse != nullptr && traverse->iPayload > inner->iPayload) 
                {
                    swapValue(inner, traverse);
                    inner = traverse;
                    
                    for (int count = 0; count < gap && traverse->ptrPrev != nullptr; count++) 
                    {
                        traverse = traverse->ptrPrev;
                    }
                }

                current = current->ptrNext;
            }
        }
    }
}


// ===============================================================
// Calculando a média
float findMean(int lista[], int iTam)
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
float calculateSD(int lista[], int iTam, float mean) 
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
void displayNodes(Node* node)
{
    if (node == nullptr)
    {
        cout << "Lista vazia: Não é possível realizar displayList" << endl;
        return; //Usa return pra sair da função, o resto do código não será executado
    }
    
    if  (node -> ptrPrev != nullptr)
    {
        cout << "Meio ou Fim da Lista: Não é possível realizar displayList" << endl;
        return;
       
    }
    
    Node* temp = node;
    cout << "Payload: ";
    while(temp != nullptr)
    {
        cout << temp -> iPayload<< " ";
        temp = temp -> ptrNext;
    }
    cout << endl;
}


void insertEnd(Node** head, int iPayload)
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

Node* createNode(int iPayload)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp -> iPayload = iPayload;
    temp -> ptrNext = nullptr;
    temp -> ptrPrev = nullptr;
    
    return temp;
}

void deleteNodes(Node** head)
{
    if (*head == nullptr )
    {
        cout << "Lista já esta vazia" << endl;
        return;
    }
    
    Node* temp = *head;

    Node* next = temp->ptrNext;
    free(temp);
    *head = NULL;

    while(next)
    {
        Node* current = next;
        next = next->ptrNext;
        // cout << current->iPayload << " ";
        free(current);
    }  

    cout << "Lista esta vazia" << endl;
}

