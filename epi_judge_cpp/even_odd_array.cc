#include <set>
#include <vector>
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"
using std::vector;

void EvenOdd(vector<int>* A_ptr) {
  // TODO - you fill in here.
  vector<int>& A = *A_ptr;

  int even_edge = 0, odd_edge = A_ptr->size() - 1;

  while(even_edge < odd_edge){
    if(A[even_edge] % 2 == 0) even_edge++;
    else if(A[odd_edge] % 2 == 1) odd_edge--;
    else{
      std::swap(A[even_edge], A[odd_edge]);
    }
  }
  return;
}
void EvenOddWrapper(TimedExecutor& executor, vector<int> A) {
  std::multiset<int> before(begin(A), end(A));

  executor.Run([&] { EvenOdd(&A); });

  bool in_odd = false;
  for (int a : A) {
    if (a % 2 == 0) {
      if (in_odd) {
        throw TestFailure("Even elements appear in odd part");
      }
    } else {
      in_odd = true;
    }
  }

  std::multiset<int> after(begin(A), end(A));
  if (before != after) {
    throw TestFailure("Elements mismatch");
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "A"};
  return GenericTestMain(args, "even_odd_array.cc", "even_odd_array.tsv",
                         &EvenOddWrapper, DefaultComparator{}, param_names);
}
