#include <string>
#include "test_framework/generic_test.h"
using std::string;

bool IsPalindrome(const string& s) {
  int begin = 0;
  int end = s.size() - 1;

  while(begin < end){
    while(ispunct(s[begin]) || s[begin] == ' ' && begin < end) begin++;
    while(ispunct(s[end]) || s[end] == ' ' && begin < end) end--;
    if(begin >= end) return true;
    if(tolower(s[begin]) != tolower(s[end])) return false;
    begin++;
    end--;
  }

  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  return GenericTestMain(args, "is_string_palindromic_punctuation.cc",
                         "is_string_palindromic_punctuation.tsv", &IsPalindrome,
                         DefaultComparator{}, param_names);
}
