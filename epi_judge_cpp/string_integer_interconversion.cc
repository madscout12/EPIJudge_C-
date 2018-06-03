#include <string>
#include <climits>
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
using std::string;

string IntToString(int x) {
  // TODO - you fill in here.
  string ret;
  bool neg = false;

  if(x == 0) return "0";
  if(x == INT_MIN) return "-2147483648";
  if(x < 0){
    neg = true;
    x *= -1;
  }

  while(x > 0){
    ret.push_back((x % 10) + '0');
    x /= 10;
  }
  if(neg) ret.push_back('-');
  reverse(ret.begin(), ret.end());

  return ret;

}
int StringToInt(const string& s) {
  // TODO - you fill in here.
  int ret = 0;
  int i = 0;
  int neg = 1;
  if(s.empty()) return 0;
  if(s[0] == '-') {
    i = 1;
    neg = -1;
  }

  for(;i < s.size(); i++){
    ret = ret * 10 + neg * (s[i] - '0');
  }

  return ret;
}
void Wrapper(int x, const string& s) {
  if (IntToString(x) != s) {
    throw TestFailure("Int to string conversion failed");
  }

  if (StringToInt(s) != x) {
    throw TestFailure("String to int conversion failed");
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "s"};
  return GenericTestMain(args, "string_integer_interconversion.cc",
                         "string_integer_interconversion.tsv", &Wrapper,
                         DefaultComparator{}, param_names);
}
