#include <iostream>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;
using std::string;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

void swapValue(int&, int&);
void printArray(int[], int);
void selectionsort(int[], int);
void optimizedSelectionSort(int[], int);

int main()
{
    int arriNumbers_1[] = {42, 7, 0, 3, 666, 1, 111, 10, 13, 137};
    int iArraySize = 10;
    
    cout << "Array original: ";
    printArray(arriNumbers_1, iArraySize);
    
    // Só usar quando o tipo auto for usado indiretamente
    // time_point<std::chrono::high_resolution_clock>
    auto timeStart = high_resolution_clock::now();
    selectionsort(arriNumbers_1, iArraySize);
    auto timeStop = high_resolution_clock::now();
    
    
    cout << "Array ordenado: ";
    printArray(arriNumbers_1, iArraySize);
    
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo utilizado: " << timeDuration.count() << " nanosegundos" << endl;
    cout << "==================" << endl;
    
    int arriNumbers_2[] = {42, 7, 0, 3, 666, 1, 111, 10, 13, 137};
    iArraySize = 10;
    
    cout << "Array original: ";
    printArray(arriNumbers_2, iArraySize);
    
    // timeStart = high_resolution_clock::now();
    // optimizedBubblesort(arriNumbers_2, iArraySize);
    // timeStop = high_resolution_clock::now();
    
    
    cout << "Array ordenado: ";
    printArray(arriNumbers_2, iArraySize);
    
    timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo utilizado: " << timeDuration.count() << " nanosegundos" << endl;
    cout << "==================" << endl;
    
    return 0;
}


void swapValue(int& iValue_1, int& iValue_2)
{
    int iTemp = iValue_1;
    iValue_1 = iValue_2;
    iValue_2 = iTemp;
}

void printArray(int arriNumbers[], int iLength)
{
    for (int i = 0; i < iLength; i++) cout << arriNumbers[i] << " ";
    cout << endl; 
}

void selectionsort(int arriNumbers[], int iLength)
{
    for (int OuterLoop = 0; OuterLoop < iLength; OuterLoop++)
    {
        for (int InnerLoop = OuterLoop+1; InnerLoop < iLength; InnerLoop++)
        {
            if ( arriNumbers[OuterLoop] > arriNumbers[InnerLoop])
            {
                swapValue(arriNumbers[OuterLoop], arriNumbers[InnerLoop]);
            }
        }
    }

}

void optimizedSelectionSort(int arriNumbers[], int iLength)
{
    int minValue = 0;
    int iSwapIndex = 0;

    for (int OuterLoop = 0; OuterLoop < iLength; OuterLoop++)
    {
        minValue = arriNumbers[OuterLoop];
        iSwapIndex = OuterLoop;

        for (int InnerLoop = OuterLoop+1; InnerLoop < iLength; InnerLoop++)
        {
            if ( minValue > arriNumbers[InnerLoop])
            {
                minValue = arriNumbers[InnerLoop];
                iSwapIndex = InnerLoop;
            }
        }
        
        swapValue(arriNumbers[OuterLoop], arriNumbers[iSwapIndex]);

    }
    
}

// Tarefa: adaptar para lista, uma lista com muitos eleentos, só precisa de print e insert e deleteAll
