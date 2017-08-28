#include <iostream>
#include "funcs.h"
#include "TrianglePrinter.h"

using namespace std;

int main()
{
    TrianglePrinter t;

    for(unsigned int i = 0; i < 10; i++)
    {
        cout << factorial(i) << endl;
    }

    // Pascal's Triangle
    for(unsigned int i = 0; i < 8; i++)
    {
        t.newrow();
        for(unsigned int k = 0; k <= i; k++)
        {
            t.add(combination(i, k));
        }
    }


    t.print();

    return 0;
}
