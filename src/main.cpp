#include <iostream>
#include <string>
#include <algorithm>
#include "tree.h"

using namespace std;


int main() {
    BST t1;
    t1.add("H");
    t1.add("B"),
    t1.add("c");
    t1.add("h");
    t1.printPostOrder();
    cout << "Höhe: " << t1.hoehe() << endl;
    cout << "Blätter: " << t1.blaetter() << endl;
    cout << "Knoten: " << t1.knoten() << endl;
    t1.clear();
  return 0;
}
