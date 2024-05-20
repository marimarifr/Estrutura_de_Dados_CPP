#include <iostream>
#include <chrono>
#include <random>

using std::cout;
using std::cin;
using std::endl;
using std::string;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

// Definindo as estruturas necessárias
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

// Assinaturas das funções definidas
// Manipulação da lista
void adicionaFinal(LinkedList* , int );
void mostraLista(LinkedList* const);
void deleteAll(LinkedList* const);
LinkedList* novaLista();
Node* newNode(int);

// Ordenação da lista
void swapValue(Node* , Node*);
void selectionsort(LinkedList* const);
void optimizedSelectionSort(LinkedList* const);

// Análise do tempo
long long int findMean(long long int[], int);
long long int calculateSD(long long int[], int, long long int);

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
    
    cout << "==================" << endl;
    cout << "Teste 1" << endl;
    
    LinkedList* lista = novaLista();
    
    // Gerando os elementos aleatórios
    for (int i = 0; i < 30000; i++) 
    {
        int n = dist(mt); 
        adicionaFinal(lista, n);
    }
    
    // Sem otimização 
    auto timeStart = high_resolution_clock::now();
    selectionsort(lista);
    auto timeStop = high_resolution_clock::now();
    
    // Com otimização
    auto timeStart1 = high_resolution_clock::now();
    optimizedSelectionSort(lista);
    auto timeStop1 = high_resolution_clock::now();
    
    // Tempo das implementações
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    auto timeDuration1 = duration_cast<nanoseconds>(timeStop1 - timeStart1);
    cout << "Tempo utilizado algoritmo sem otimização: " << timeDuration.count() << " nanosegundos" << endl;
    cout << "Tempo utilizado otimizado: " << timeDuration1.count() << " nanosegundos" << endl;
    // Esvaziando a lista para mais testes
    deleteAll(lista);
    
    cout << "==================" << endl;
    // Novo teste
    cout << "Teste 2" << endl;

    // Gerando novos elementos
    for (int i = 0; i < 30000; i++) 
    {
        int n = dist(mt); 
        adicionaFinal(lista, n);
    }
    
    // Sem otimização
    timeStart = high_resolution_clock::now();
    selectionsort(lista);
    timeStop = high_resolution_clock::now();
    
    // Com otimização
    timeStart1 = high_resolution_clock::now();
    optimizedSelectionSort(lista);
    timeStop1 = high_resolution_clock::now();
    
    auto timeDuration2 = duration_cast<nanoseconds>(timeStop - timeStart);
    auto timeDuration3 = duration_cast<nanoseconds>(timeStop1 - timeStart1);
    cout << "Tempo utilizado algoritmo sem otimização: " << timeDuration2.count() << " nanosegundos" << endl;
    cout << "Tempo utilizado otimizado: " << timeDuration3.count() << " nanosegundos" << endl;
    // Esvaziando a lista
    deleteAll(lista);
    
    cout << "==================" << endl;
    // Novo teste
    cout << "Teste 3" << endl;

    // Novos elementos aleatórios
    for (int i = 0; i < 30000; i++) 
    {
        int n = dist(mt); 
        adicionaFinal(lista, n);
    }
    
    // Sem otimização
    timeStart = high_resolution_clock::now();
    selectionsort(lista);
    timeStop = high_resolution_clock::now();
    
    // Com otimização
    timeStart1 = high_resolution_clock::now();
    optimizedSelectionSort(lista);
    timeStop1 = high_resolution_clock::now();
    
    // Tempo das implementações
    auto timeDuration4 = duration_cast<nanoseconds>(timeStop - timeStart);
    auto timeDuration5 = duration_cast<nanoseconds>(timeStop1 - timeStart1);
    cout << "Tempo utilizado algoritmo sem otimização: " << timeDuration4.count() << " nanosegundos" << endl;
    cout << "Tempo utilizado otimizado: " << timeDuration5.count() << " nanosegundos" << endl;
    // Esvaziando a lista
    deleteAll(lista);
    
    cout << "==================" << endl;
    // Novo teste
    cout << "Teste 4" << endl;

    // Gerando novos elementos
    for (int i = 0; i < 30000; i++) 
    {
        int n = dist(mt); 
        adicionaFinal(lista, n);
    }
    
    // Sem otimização
    timeStart = high_resolution_clock::now();
    selectionsort(lista);
    timeStop = high_resolution_clock::now();
    
    // com otimização
    timeStart1 = high_resolution_clock::now();
    optimizedSelectionSort(lista);
    timeStop1 = high_resolution_clock::now();
    
    //Tempo das implementações
    auto timeDuration6 = duration_cast<nanoseconds>(timeStop - timeStart);
    auto timeDuration7 = duration_cast<nanoseconds>(timeStop1 - timeStart1);
    cout << "Tempo utilizado algoritmo sem otimização: " << timeDuration6.count() << " nanosegundos" << endl;
    cout << "Tempo utilizado otimizado: " << timeDuration7.count() << " nanosegundos" << endl;
    
    // Esvaziando a lista
    deleteAll(lista);
    
    cout << "==================" << endl;
    // Último teste
    cout << "Teste 5" << endl;

    // Gerando novos elementos
    for (int i = 0; i < 30000; i++) 
    {
        int n = dist(mt); 
        adicionaFinal(lista, n);
    }
    
    // Sem otimização
    timeStart = high_resolution_clock::now();
    selectionsort(lista);
    timeStop = high_resolution_clock::now();
    
    // Com otimização
    timeStart1 = high_resolution_clock::now();
    optimizedSelectionSort(lista);
    timeStop1 = high_resolution_clock::now();
    
    // Tempo das implementações
    auto timeDuration8 = duration_cast<nanoseconds>(timeStop - timeStart);
    auto timeDuration9 = duration_cast<nanoseconds>(timeStop1 - timeStart1);
    cout << "Tempo utilizado algoritmo sem otimização: " << timeDuration8.count() << " nanosegundos" << endl;
    cout << "Tempo utilizado otimizado: " << timeDuration9.count() << " nanosegundos" << endl;
    
    // Esvaziando a lista e liberando memória
    deleteAll(lista);
    free(lista);
    
    cout << "#################" << endl;
    // Analisando a eficiência entre as versões do algoritmo com e sem otimização
    
    cout << "Medidas de análise do tempo" << endl;

    // Agrupando os tempos armazenandos em um vetor
    long long int temposNaoOtimo[5] = {timeDuration.count(), timeDuration2.count(), timeDuration4.count(), timeDuration6.count(), timeDuration8.count()};
    long long int temposOtimo[5] = {timeDuration1.count(), timeDuration3.count(), timeDuration5.count(), timeDuration7.count(), timeDuration9.count()};
    
    // Calculando média
    long long int meanOptim = findMean(temposOtimo, 5);
    long long int meanNotOptim = findMean(temposNaoOtimo, 5);
    
    // Calculando o desvio padrão
    long long int stdOptim = calculateSD(temposOtimo, 5, meanOptim);
    long long int stdNotOptim = calculateSD(temposNaoOtimo, 5, meanNotOptim);
    
    // Exibindo os resultados
    cout << "Média não otimizada: " << meanNotOptim << endl;
    cout << "Média otimizada: " << meanOptim << endl;
    
    cout << "Desvio padrão não otimizada: " << stdNotOptim << endl;
    cout << "Desvio padrão otimizada: " << stdOptim << endl;
    

    return 0;
}

// Troca os valores entre os nós
void swapValue(Node* elemento1, Node* elemento2)
{
    int iValor1 = elemento1->iPayload;
    
    elemento1->iPayload = elemento2->iPayload;
    elemento2->iPayload = iValor1;
}

// Ordenação sem otimização
void selectionsort(LinkedList* const lista)
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
    int iSwapIndex = 0;
    
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

// Adiciona elemento 
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

// Esvaziando a lista 
void deleteAll(LinkedList* const lista)
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

// Calculando a média
long long int findMean(long long int lista[], int iTam)
{
    int i = 0;
    long long int mean = 0;
    
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
long long int calculateSD(long long int lista[], int iTam, long long int mean) 
{ 
    long long int standardDeviation = 0.0; 
    int i = 0;
    
    // Iterando sobre todos elementos
    for (int i = 0; i < iTam; i++) 
    { 
        // Calculando a diferença ao quadrado com a média
        standardDeviation += pow(lista[i] - mean, 2); 
    } 

    return sqrt(standardDeviation / iTam); 
} 