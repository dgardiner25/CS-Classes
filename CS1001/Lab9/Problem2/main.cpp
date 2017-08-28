#include <iostream>
#include "dtor.h"
#include "plain.h"

using namespace std;

int main()
{
  plain* plain_var = new plain;
  plain* plain_array = new plain[5];

  dtor* dtor_var = new dtor;
  dtor* dtor_array = new dtor[5];

  return 0;
}
