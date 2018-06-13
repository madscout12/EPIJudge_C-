#include <vector>
#include "test_framework/generic_test.h"
using std::vector;
using std::priority_queue;

struct comp{
    bool operator()(const int& a, const int& b) const{
      return a > b;
    }
};

int FindKthLargestUnknownLength(vector<int>::const_iterator stream_begin,
                                const vector<int>::const_iterator& stream_end,
                                int k) {
  // TODO - you fill in here.
  priority_queue<int, vector<int>, struct comp> q;

  while(stream_begin != stream_end){
    if(q.size() < k){
      q.push(*stream_begin);

    }
    else if(q.size() == k && *stream_begin > q.top()){
      q.pop();
      q.push(*stream_begin);
    }

    stream_begin++;
  }

  return q.top();
}
int FindKthLargestUnknownLengthWrapper(const vector<int>& stream, int k) {
  return FindKthLargestUnknownLength(stream.cbegin(), stream.cend(), k);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"stream", "k"};
  return GenericTestMain(args, "kth_largest_element_in_long_array.cc",
                         "kth_largest_element_in_long_array.tsv",
                         &FindKthLargestUnknownLengthWrapper,
                         DefaultComparator{}, param_names);
}
