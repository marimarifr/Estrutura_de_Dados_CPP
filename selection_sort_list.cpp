#include "sort_algorithms.h"
using namespace sortAlgorithms;
#include <iostream>
#include <chrono>
#include <random>

using std::cout;
using std::endl;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;

int main()
{
    // Para geração de números aleatórios entre 0 e 100000
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0.0, 100.0);
    
    // Testando o algoritmo de ordenação
    LinkedList* teste = novaLista();
    
    cout << "Testando a ordenação:" << endl;
    adicionaFinal(teste, 100);
    adicionaFinal(teste, 99);
    adicionaFinal(teste, 200);
    adicionaFinal(teste, 10);
    adicionaFinal(teste, 57);
    
    mostraLista(teste);
    optimizedSelectionSort(teste);
    mostraLista(teste);
    deleteAll(teste);
    free(teste);
    
    // Testando com um lista já ordenada 
    cout << "Lista já ordenada:" << endl;
    LinkedList* ordem = novaLista();
    adicionaFinal(ordem, 1);
    adicionaFinal(ordem, 2);
    adicionaFinal(ordem, 3);
    adicionaFinal(ordem, 4);
    adicionaFinal(ordem, 5);
    
    mostraLista(ordem);
    optimizedSelectionSort(ordem);
    mostraLista(ordem);
    deleteAll(ordem);
    free(ordem);
    
    // O algoritmo realmente está ordenando agora vamos analisar
    // sua eficiência com uma sobrecarga de dados
    LinkedList* lista = novaLista();
    int temposNaoOtimo[100];
    int temposOtimo[100];
    
    for( int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 10000; j++) 
        {
            int n = dist(mt); 
            adicionaFinal(lista, n);
        }
        
        auto timeStart = high_resolution_clock::now();
        selectionsort(lista);
        auto timeStop = high_resolution_clock::now();
        
        auto timeStart1 = high_resolution_clock::now();
        optimizedSelectionSort(lista);
        auto timeStop1 = high_resolution_clock::now();
        
        auto timeDuration = duration_cast<milliseconds>(timeStop - timeStart);
        auto timeDuration1 = duration_cast<milliseconds>(timeStop1 - timeStart1);
        cout << "Teste " << i << ", tempo não otimizado: " << timeDuration.count() << " milisegundos" << endl;
        cout << "Teste " << i << ", tempo otimizado: " << timeDuration1.count() << " milisegundos" << endl;
        
        // Esvaziando a lista para mais testes
        deleteAll(lista);
        
        temposNaoOtimo[i] = timeDuration.count();
        temposOtimo[i] = timeDuration1.count();
    }
    
    // Calculando média
    float meanNotOptim = findMean(temposNaoOtimo, 100);
    float meanOptim = findMean(temposOtimo, 100);
    
    // Calculando o desvio padrão
    float stdNotOptim = calculateSD(temposNaoOtimo, 100, meanNotOptim);
    float stdOptim = calculateSD(temposOtimo, 100, meanOptim);
    
    // Exibindo os resultados
    cout << "Média não otimizada: " << meanNotOptim << endl;
    cout << "Média otimizada: " << meanOptim << endl;
    
    cout << "Desvio padrão não otimizado: " << stdNotOptim << endl;
    cout << "Desvio padrão otimizado: " << stdOptim << endl;
    

    return 0;
}