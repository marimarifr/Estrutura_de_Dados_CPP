#include "sort_algorithms.h"
#include <iostream>
#include <chrono>
#include <random>

using namespace std;

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
    
    //Testando o SHELL SORT para a lista desordenada, passando o endereço do primeiro 
    shellSort(&head, 6);
    cout<<"Resultado não otimizado para lista não ordenada>"<< endl;
    displayNodes(head);
    
    //Testando para a lista já ordenada
    shellSort(&head, 6);
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

    // Para geração de números aleatórios entre 0 e 100000
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0.0, 100.0);
    
    // O algoritmo realmente está ordenando agora vamos analisar
    // sua eficiência com uma sobrecarga de dados
    head = NULL;
    
    int tempos[1000];
    
    for( int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 10000; j++) 
        {
            int n = dist(mt); 
            insertEnd(&head,n);
        }
                
        auto timeStart = high_resolution_clock::now();
        shellSort(&head, 10000);
        auto timeStop = high_resolution_clock::now();
        
        auto timeDuration = duration_cast<microseconds>(timeStop - timeStart);

        cout << "Teste " << i << ", tempo não otimizado: " << timeDuration.count() << " microsegundos" << endl;

        // Esvaziando a lista para mais testes
        deleteNodes(&head);
        
        tempos[i] = timeDuration.count();
    }
    
    // Calculando média
    float meanTempos = findMean(tempos, 1000);
    
    // Calculando o desvio padrão
    float stdTempos = calculateSD(tempos, 1000, meanTempos);
  
    // Exibindo os resultados
    cout << "Média: " << meanTempos << endl;
    
    cout << "Desvio padrão: " << stdTempos << endl;
 
    return 0;
}