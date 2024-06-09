#include "tree_functions.h"
using namespace treeArrayFunctions;

using namespace std;



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
    
    cout << "Tree hight: " << treeHeight(root) <<endl;

    cout <<"============================"<< endl;
    
    return 0;
}
