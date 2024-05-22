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
    insertionSort(teste);
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
    insertionSort(ordem);
    mostraLista(ordem);
    deleteAll(ordem);
    free(ordem);
    
    // O algoritmo realmente está ordenando agora vamos analisar
    // sua eficiência com uma sobrecarga de dados
    LinkedList* lista = novaLista();
    int temposInsertion[100];
    
    for( int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 10000; j++) 
        {
            int n = dist(mt); 
            adicionaFinal(lista, n);
        }
        
        auto timeStart = high_resolution_clock::now();
        insertionSort(lista);
        auto timeStop = high_resolution_clock::now();
        
        auto timeDuration = duration_cast<milliseconds>(timeStop - timeStart);
        cout << "Teste " << i << ", tempo utilizado: " << timeDuration.count() << " milisegundos" << endl;
        
        // Esvaziando a lista para mais testes
        deleteAll(lista);
        
        temposInsertion[i] = timeDuration.count();
    }
    
    // Calculando média
    float meanInsertion = findMean(temposInsertion, 100);
    
    // Calculando o desvio padrão
    float stdInsertion = calculateSD(temposInsertion, 100, meanInsertion);
    
    // Exibindo os resultados
    cout << "Média Insertion: " << meanInsertion << endl;
    cout << "Desvio padrão Insertion: " << stdInsertion << endl;
    

    return 0;
}