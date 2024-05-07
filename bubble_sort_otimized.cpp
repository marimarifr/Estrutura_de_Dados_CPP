#include <iostream>
#include <cstdlib>
#include <chrono>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

typedef struct Node
{
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
    
} Node;


Node* createNode(int);
void insertEnd(Node**, int);
void displayList(Node*);
void deleteAll(Node**);


void swapValuesList(Node* , Node*);
void bubbleSortList(Node** , int);
void optimizedBubbleSortList(Node** , int);

long long int findMean(long long int[], int);
long long int calculateSD(long long int[], int, long long int);

int main(){
    
    
    cout << "============== TESTANDO AS FUNÇÕES COM LISTAS PEQUENAS ==============" << endl;
    
    // Cria o nó do primeiro elemento da lista 
    Node* head = nullptr;
    
    // Adiciona elementos à ela
    insertEnd(&head,5);
    insertEnd(&head,4);
    insertEnd(&head,3);
    insertEnd(&head,2);
    insertEnd(&head,1);
    insertEnd(&head,0);
    
    //Imprime os elementos
    displayList(head);
    
    cout << "==============" << endl;
    
    //Testando o bubble sort para a lista desordenada, passando o endereço do primeiro 
    bubbleSortList(&head, 6);
    cout<<"Resultado não otimizado para lista não ordenada>"<< endl;
    displayList(head);
    
    //Testando para a lista já ordenada
    bubbleSortList(&head, 6);
    cout<< "Resultado não otimizado para lista já ordenada>"<< endl;
    displayList(head);
    
    //Deletando toda a lista
    deleteAll(&head);
    
    cout << "=========== fim do não otimizado" << endl;
    
    // Node* head = nullptr;
    
    
    //Reiniciando nossa lista não ordenada
    insertEnd(&head,5);
    insertEnd(&head,4);
    insertEnd(&head,3);
    insertEnd(&head,2);
    insertEnd(&head,1);
    insertEnd(&head,0);
    displayList(head);
    
    cout << "==============" << endl;
    
    // Testando o bubble sort otimizado
    //para lista não ordenada
    optimizedBubbleSortList(&head, 6);
    cout<< "Resultado otimizado para lista não ordenada>"<< endl;
    displayList(head);
    
    cout << "==============" << endl;
    
    //Testando para uma lista já ordenada
    optimizedBubbleSortList(&head, 6);
    cout<< "Resultado otimizado para lista já ordenada>"<< endl;
    displayList(head);
    
    //Deletando toda a lista
    deleteAll(&head);
    
    cout << "=========== fim do otimizado" << endl;
    
    
    ///////////////////////////////////////////////////////////////////////////////////
    
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0.0, 100000.0);
    
    
    //Inicializando a lista vazia
    head = nullptr;
    displayList(head);
    
    cout << "============================================================================" << endl;
    cout << "Teste 1" << endl;

    // Incrementando 30000 elementos aleatórios na lista 
    for (int i = 0; i < 30000; i++) 
    {
        int n = dist(mt); 
        insertEnd(&head,n);
    }
    
    auto timeStart = high_resolution_clock::now();
    // Teste na função não otimizada 
    bubbleSortList(&head, 30000);
    auto timeStop = high_resolution_clock::now();
    
    auto timeStart1 = high_resolution_clock::now();
    // Teste na função otimizada
    optimizedBubbleSortList(&head, 30000);
    auto timeStop1 = high_resolution_clock::now();
    
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    auto timeDuration1 = duration_cast<nanoseconds>(timeStop1 - timeStart1);
    cout << "Tempo utilizado algoritmo sem otimização: " << timeDuration.count() << " nanosegundos" << endl;
    cout << "Tempo utilizado otimizado: " << timeDuration1.count() << " nanosegundos" << endl;
    deleteAll(&head);
    
    // Repetimos todo o processo do teste 1 cinco vezes para meio de comparação de tempos de execução
    cout << "==============" << endl;
    cout << "Teste 2" << endl;


    for (int i = 0; i < 30000; i++) 
    {
        int n = dist(mt); 
        insertEnd(&head,n);
    }
    
    timeStart = high_resolution_clock::now();
    bubbleSortList(&head, 30000);
    timeStop = high_resolution_clock::now();
    
    timeStart1 = high_resolution_clock::now();
    optimizedBubbleSortList(&head, 30000);
    timeStop1 = high_resolution_clock::now();
    
    auto timeDuration2 = duration_cast<nanoseconds>(timeStop - timeStart);
    auto timeDuration3 = duration_cast<nanoseconds>(timeStop1 - timeStart1);
    cout << "Tempo utilizado algoritmo sem otimização: " << timeDuration2.count() << " nanosegundos" << endl;
    cout << "Tempo utilizado otimizado: " << timeDuration3.count() << " nanosegundos" << endl;
    deleteAll(&head);
    
    cout << "==============" << endl;
    cout << "Teste 3" << endl;
    

    for (int i = 0; i < 30000; i++) 
    {
        int n = dist(mt); 
        insertEnd(&head,n);
    }
    
    timeStart = high_resolution_clock::now();
    bubbleSortList(&head, 30000);
    timeStop = high_resolution_clock::now();
    
    timeStart1 = high_resolution_clock::now();
    optimizedBubbleSortList(&head, 30000);
    timeStop1 = high_resolution_clock::now();
    
    auto timeDuration4 = duration_cast<nanoseconds>(timeStop - timeStart);
    auto timeDuration5 = duration_cast<nanoseconds>(timeStop1 - timeStart1);
    cout << "Tempo utilizado algoritmo sem otimização: " << timeDuration4.count() << " nanosegundos" << endl;
    cout << "Tempo utilizado otimizado: " << timeDuration5.count() << " nanosegundos" << endl;
    deleteAll(&head);
    
    cout << "==============" << endl;
    cout << "Teste 4" << endl;


    for (int i = 0; i < 30000; i++) 
    {
        int n = dist(mt); 
        insertEnd(&head,n);
    }
    
    timeStart = high_resolution_clock::now();
    bubbleSortList(&head, 30000);
    timeStop = high_resolution_clock::now();
    
    timeStart1 = high_resolution_clock::now();
    optimizedBubbleSortList(&head, 30000);
    timeStop1 = high_resolution_clock::now();
    
    auto timeDuration6 = duration_cast<nanoseconds>(timeStop - timeStart);
    auto timeDuration7 = duration_cast<nanoseconds>(timeStop1 - timeStart1);
    cout << "Tempo utilizado algoritmo sem otimização: " << timeDuration6.count() << " nanosegundos" << endl;
    cout << "Tempo utilizado otimizado: " << timeDuration7.count() << " nanosegundos" << endl;
    deleteAll(&head);
    
    cout << "==============" << endl;
    cout << "Teste 5" << endl;


    for (int i = 0; i < 30000; i++) 
    {
        int n = dist(mt); 
        insertEnd(&head,n);
    }
    
    timeStart = high_resolution_clock::now();
    bubbleSortList(&head, 30000);
    timeStop = high_resolution_clock::now();
    
    timeStart1 = high_resolution_clock::now();
    optimizedBubbleSortList(&head, 30000);
    timeStop1 = high_resolution_clock::now();
    
    auto timeDuration8 = duration_cast<nanoseconds>(timeStop - timeStart);
    auto timeDuration9 = duration_cast<nanoseconds>(timeStop1 - timeStart1);
    cout << "Tempo utilizado algoritmo sem otimização: " << timeDuration8.count() << " nanosegundos" << endl;
    cout << "Tempo utilizado otimizado: " << timeDuration9.count() << " nanosegundos" << endl;
    deleteAll(&head);
    
    
    cout << "##########################################################################" << endl;
    
    cout << "Medidas de análise do tempo" << endl;
    
    long long int temposNaoOtimo[5] = {timeDuration.count(), timeDuration2.count(), timeDuration4.count(), timeDuration6.count(), timeDuration8.count()};
    long long int temposOtimo[5] = {timeDuration1.count(), timeDuration3.count(), timeDuration5.count(), timeDuration7.count(), timeDuration9.count()};
    
    
    long long int meanOptim = findMean(temposOtimo, 5);
    long long int meanNotOptim = findMean(temposNaoOtimo, 5);
    
    long long int stdOptim = calculateSD(temposOtimo, 5, meanOptim);
    long long int stdNotOptim = calculateSD(temposNaoOtimo, 5, meanNotOptim);
    
    cout << "Média não otimizada: " << meanNotOptim << endl;
    cout << "Média otimizada: " << meanOptim << endl;
    
    cout << "Desvio padrão não otimizada: " << stdNotOptim << endl;
    cout << "Desvio padrão otimizada: " << stdOptim << endl;
    
    
    return 0;
}


void swapValuesList(Node* ptrLocation1, Node* ptrLocation2 ){

    
    int iTemp = ptrLocation1 -> iPayload;
    ptrLocation1 -> iPayload = ptrLocation2 -> iPayload;
    ptrLocation2 -> iPayload = iTemp;
    
};


Node* createNode(int iPayload)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp -> iPayload = iPayload;
    temp -> ptrNext = nullptr;
    temp -> ptrPrev = nullptr;
    
    return temp;
}

void displayList(Node* node)
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

void deleteAll(Node** head)
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


void bubbleSortList(Node** head, int iLength)
{
    Node* temp = *head;
    
   for(int iOuterLoop = 0; iOuterLoop < iLength-1 ; iOuterLoop++){
       
        for(int iInnerLoop = 0; iInnerLoop < iLength-1 ; iInnerLoop++){
            
            if(temp->iPayload > temp->ptrNext->iPayload){
        
                swapValuesList(temp, temp -> ptrNext);
                
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
                swapValuesList(temp, temp -> ptrNext);
                
                // Se entramos no loop, então ela ainda não está ordenada
                bUnordered = true;
                
                // Se trocamos o valor passamo para o nó seguinte
                temp = temp -> ptrNext;
            }
            
            // Se não há troca de valor, também passamos para o seguinte
            else temp = temp -> ptrNext;
        }
        
        // A cada loop extermo, retornamos o temp para o primeiro
        temp = *head;
        
        // se ela já está ordenada paramos a iteração
        if(bUnordered == false) break;
        
        
   }
   
};





long long int findMean(long long int lista[], int iTam)
{
    int i = 0;
    long long int mean = 0;
    for (i =0; i<iTam; i++)
    {
        mean += lista[i];
    }
    
    mean = mean/iTam;
    
    return mean;
}

long long int calculateSD(long long int lista[], int iTam, long long int mean) 
{ 
    long long int standardDeviation = 0.0; 
    int i = 0;
    
    for (int i = 0; i < iTam; i++) 
    { 
        standardDeviation += pow(lista[i] - mean, 2); 
    } 
  
    // Calculate the square root of the variance to get the 
    // standard deviation 
    return sqrt(standardDeviation / iTam); 
} 



