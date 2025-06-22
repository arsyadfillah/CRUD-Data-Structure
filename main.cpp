#include <iostream>
#include "TUBES.h"
using namespace std;
int main()
{
    List L;
        createList(L);
        int opsi = Menu();
        pilihan(opsi,L);
    return 0;
};
