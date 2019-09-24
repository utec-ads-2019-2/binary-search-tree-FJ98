#include <iostream>
#include "tester/tester.h"
#include <list>
using namespace std;

int main(int argc, char *argv[]) {
    cout << "===========================================================" << endl;
    cout << "Binary Search Tree Practice" << endl;
    cout << "===========================================================" << endl << endl;

    Tester::execute();
//    int removeElement = 15;
//    std::list<int> testList = {0, 1, 2, 2, 2, 3, 10, 13, 15, 15, 17, 18, 20, 21, 22, 24, 28, 28, 30, 31, 32, 41,
//                               41, 42, 43, 44, 47, 49, 51, 52, 52, 58, 62, 63, 64, 64, 65, 66, 71, 72, 74, 75, 76,
//                               76, 76, 80, 81, 82, 83, 95, 99, 99 };
//
//    cout << "List before delete: \n";
//    for (auto && item: testList) {cout << item << " "; } std::cout << std::endl;
//
//    BSTree<int> bTree;
//    for (int i : testList) { bTree.insert(i); }
//    cout << "Tree before delete: \n"; bTree.privateTraverseInOrder();
//    std::cout << std::endl << std::endl;
//
//    testList.remove(removeElement);
//    cout << "List after delete: \n";
//    for (auto && item: testList) {cout << item << " "; }
//    std::cout << std::endl << std::endl;
//
//    std::cout << removeElement << " was removed from the tree?: " << std::boolalpha << bTree.remove(removeElement) << "\n";
//    cout << "Tree after delete: \n";
//    bTree.privateTraverseInOrder(); std::cout << std::endl;
//
//    std::cout  << removeElement << " was founded in the tree?: " << std::boolalpha << bTree.find(removeElement) << "\n";


    return EXIT_SUCCESS;
}
