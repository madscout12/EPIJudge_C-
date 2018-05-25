#include <climits>
#include "test_framework/generic_test.h"
short Parity(unsigned long long x) {
  // TODO - you fill in here.

  size_t shift = sizeof(unsigned long long) * 8 / 2;
  unsigned long long max = ULLONG_MAX >> shift;


  while(x && shift > 0){
      x = (x >> shift) ^ (x & max);
      shift = shift / 2;
      max = max >> shift;
  }

    return (short) x;
}


  /*
  int parity = 0;

  while(x){
      parity += x & 1;
      x = x >> 1;
  }

  return (short) parity % 2;

  */

  /*
  while(shift > 1 && x != 0){
    unsigned long long top = x >> shift;
    x = mask & x;
    x = x ^ top;
    shift /= 2;
    mask = mask >> shift;
  }


  if(x) return (short) 1;
  else return (short) 0;

   */


int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "parity.cc", "parity.tsv", &Parity,
                         DefaultComparator{}, param_names);
}
