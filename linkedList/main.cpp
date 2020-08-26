//
//  main.cpp
//  linkedList
//
//  Created by Antoine Smith on 9/10/19.
//  Copyright © 2019 Antoine Smith. All rights reserved.
//

#include <iostream>
#include "unsortedList.hpp"
using namespace std;

int main(int argc, const char * argv[])
{
    unsortedList<int> uslInt;
    
    uslInt.putItem(22);
    uslInt.putItem(11);
    uslInt.putItem(7);
    uslInt.putItem(33);
//    uslInt.putItem(15);
    
    uslInt.printList();
    
//    uslInt.deleteItem(7);
//    uslInt.deleteItem(99);
//    
//    uslInt.putItem(99);
//    uslInt.printList();
//
//    uslInt.deleteItem(99);
//    uslInt.printList();

    return 0;
}
