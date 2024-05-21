#include "sort_algorithms.h"
#include <iostream>
#include <chrono>
#include <random>

using std::cout;
using std::endl;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::microseconds;

int main()
{
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
    displayNodes(head);
    
    cout << "==============" << endl;
    
    //Testando o bubble sort para a lista desordenada, passando o endereço do primeiro 
    bubbleSortList(&head, 6);
    cout<<"Resultado não otimizado para lista não ordenada>"<< endl;
    displayNodes(head);
    
    //Testando para a lista já ordenada
    bubbleSortList(&head, 6);
    cout<< "Resultado não otimizado para lista já ordenada>"<< endl;
    displayNodes(head);
    
    //Deletando toda a lista
    deleteNodes(&head);
    
    cout << "=========== fim do não otimizado" << endl;
    
    // Node* head = nullptr;
    
    
    //Reiniciando nossa lista não ordenada
    insertEnd(&head,5);
    insertEnd(&head,4);
    insertEnd(&head,3);
    insertEnd(&head,2);
    insertEnd(&head,1);
    insertEnd(&head,0);
    displayNodes(head);
    
    cout << "==============" << endl;
    
    // Testando o bubble sort otimizado
    //para lista não ordenada
    optimizedBubbleSortList(&head, 6);
    cout<< "Resultado otimizado para lista não ordenada>"<< endl;
    displayNodes(head);
    
    cout << "==============" << endl;
    
    //Testando para uma lista já ordenada
    optimizedBubbleSortList(&head, 6);
    cout<< "Resultado otimizado para lista já ordenada>"<< endl;
    displayNodes(head);
    
    //Deletando toda a lista
    deleteNodes(&head);
    
    cout << "=========== fim do otimizado" << endl;
    
    // Para geração de números aleatórios entre 0 e 100000
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0.0, 100.0);
    
    // O algoritmo realmente está ordenando agora vamos analisar
    // sua eficiência com uma sobrecarga de dados
    head = NULL;
    
    int temposNaoOtimo[1000];
    int temposOtimo[1000];
    
    for( int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 10000; j++) 
        {
            int n = dist(mt); 
            insertEnd(&head,n);
        }
                
        auto timeStart = high_resolution_clock::now();
        bubbleSortList(&head, 10000);
        auto timeStop = high_resolution_clock::now();
        
        auto timeStart1 = high_resolution_clock::now();
        optimizedBubbleSortList(&head, 10000);
        auto timeStop1 = high_resolution_clock::now();
        
        auto timeDuration = duration_cast<microseconds>(timeStop - timeStart);
        auto timeDuration1 = duration_cast<microseconds>(timeStop1 - timeStart1);
        cout << "Teste " << i << ", tempo não otimizado: " << timeDuration.count() << " microsegundos" << endl;
        cout << "Teste " << i << ", tempo otimizado: " << timeDuration1.count() << " microsegundos" << endl;
        
        // Esvaziando a lista para mais testes
        deleteNodes(&head);
        
        temposNaoOtimo[i] = timeDuration.count();
        temposOtimo[i] = timeDuration1.count();
    }
    
    // Calculando média
    float meanNotOptim = findMean(temposNaoOtimo, 1000);
    float meanOptim = findMean(temposOtimo, 1000);
    
    // Calculando o desvio padrão
    float stdNotOptim = calculateSD(temposNaoOtimo, 1000, meanNotOptim);
    float stdOptim = calculateSD(temposOtimo, 1000, meanOptim);
  
    // Exibindo os resultados
    cout << "Média não otimizada: " << meanNotOptim << endl;
    cout << "Média otimizada: " << meanOptim << endl;
    
    cout << "Desvio padrão não otimizado: " << stdNotOptim << endl;
    cout << "Desvio padrão otimizado: " << stdOptim << endl;
 
    return 0;
}