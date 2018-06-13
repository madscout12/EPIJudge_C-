#include <vector>
#include "test_framework/generic_test.h"
using std::vector;
using std::priority_queue;

struct comp{
    bool operator()(const int& a, const int& b) const{
      return a > b;
    }
};

vector<int> MergeSortedArrays(const vector<vector<int>>& sorted_arrays) {
  // TODO - you fill in here.
  priority_queue<int, vector<int>, struct comp> q;
  vector<int> ret;

  for(vector<int> v : sorted_arrays){
    for(int i : v){
      q.push(i);
    }
  }

  while(!q.empty()){
    ret.push_back(q.top());
    q.pop();
  }

  return ret;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"sorted_arrays"};
  return GenericTestMain(args, "sorted_arrays_merge.cc",
                         "sorted_arrays_merge.tsv", &MergeSortedArrays,
                         DefaultComparator{}, param_names);
}
