#include "tree_functions.h"
using namespace treeListFunctions;
#include <iostream>
#include <chrono>
#include <random>

using namespace std;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::microseconds;

int main()
{
    Node* root = nullptr;
    
    root = insertNode(root, 42);
    root = insertNode(root, 13);
    root = insertNode(root, 11);
    root = insertNode(root, 10);
    root = insertNode(root, 28);
    root = insertNode(root, 51);
    root = insertNode(root, 171);
    
    cout << "BFS Traversal: ";
    bfsTraversal(root);
    cout << endl;
    
    cout << "Tree hight: " << treeHeightDLL(root) <<endl;
    
    Node* no = bfsSearch(root, 171);
    
    deleteTree(root);
    
    cout <<"============================="<<endl;
    
    ///////////////////////Teste com 100 elementos na árvore///////////////
    
    int lenght = 100;

    Node* newRoot = nullptr;
    int temposTreeCreat[lenght];

    for(int m = 0; m<100; m++)
    {
        auto timeStart = high_resolution_clock::now();

        for( int i = 0; i < lenght; i++)
        {        
            insertNode(newRoot, i);
                        
        }
        auto timeStop = high_resolution_clock::now();
            
        auto timeDuration = duration_cast<microseconds>(timeStop - timeStart);
        cout << "Teste " << m << ", tempo utilizado: " << timeDuration.count() << " microsegundos" << endl;
        
        // Esvaziando a árvore para mais testes
        deleteTree(newRoot);
        
        temposTreeCreat[m] = timeDuration.count();
    }
    
    ///////////////////////Teste com 100 elementos na lista///////////////

    // Criando a lista dos nós
    NodeSimpleList* newList = nullptr;
    int temposListCreat[lenght];
    
    for(int m = 0; m<100; m++)
    {
        auto timeStart = high_resolution_clock::now();

        for( int i = 0; i < lenght; i++)
        {
            adicionaFinalSL(&newList, i);
        }

        auto timeStop = high_resolution_clock::now();
            
        auto timeDuration = duration_cast<microseconds>(timeStop - timeStart);
        cout << "Teste " << m << ", tempo utilizado: " << timeDuration.count() << " microsegundos" << endl;
        
        // Esvaziando a árvore para mais testes
        deleteNodes(&newList);
        
        temposListCreat[m] = timeDuration.count();
    }

    // Calculando média
    float meanTree = findMean(temposTreeCreat, 100);
    
    // Calculando o desvio padrão
    float stdTree = calculateSD(temposTreeCreat, 100, meanTree);
    
    // Exibindo os resultados
    cout << "Média Tree: " << meanTree << endl;
    cout << "Desvio padrão Tree: " << stdTree << endl;


    // Calculando média
    float meanList = findMean(temposListCreat, 100);
    
    // Calculando o desvio padrão
    float stdList = calculateSD(temposListCreat, 100, meanList);
    
    // Exibindo os resultados
    cout << "Média lista: " << meanList << endl;
    cout << "Desvio padrão lista: " << stdList << endl;
    
    
    return 0;
}
