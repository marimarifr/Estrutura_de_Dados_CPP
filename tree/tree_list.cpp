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

    // Para geração de números aleatórios entre 0 e 100
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0.0, 100.0);
    
    Node* newRoot = nullptr;
    int temposTreeCreat[100];
    
    for( int i = 0; i < 100; i++)
    {
        auto timeStart = high_resolution_clock::now();
        
        for (int j = 0; j < 10000; j++) 
        {
            int n = dist(mt); 
            insertNode(newRoot, n);
        }
        
        auto timeStop = high_resolution_clock::now();
        
        auto timeDuration = duration_cast<microseconds>(timeStop - timeStart);
        cout << "Teste " << i << ", tempo utilizado: " << timeDuration.count() << " microsegundos" << endl;
        
        // Esvaziando a árvore para mais testes
        deleteTree(newRoot);
        
        temposTreeCreat[i] = timeDuration.count();
    }
    
    // Calculando média
    float meanTree = findMean(temposTreeCreat, 100);
    
    // Calculando o desvio padrão
    float stdTree = calculateSD(temposTreeCreat, 100, meanTree);
    
    // Exibindo os resultados
    cout << "Média Tree: " << meanTree << endl;
    cout << "Desvio padrão Tree: " << stdTree << endl;
    
    
    return 0;
}
