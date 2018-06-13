#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
#include <math.h>

using namespace std;

int height(const unique_ptr<BinaryTreeNode<int>>& node){
    if(node == nullptr) return 0;

    int left = height(node->left);
    int right = height(node->right);

    if(left == -1 || right == -1 || abs(left - right) > 1) return -1;
    else return max(left, right) + 1;

}

bool IsBalanced(const unique_ptr<BinaryTreeNode<int>>& tree) {
  // TODO - you fill in here.
  if(height(tree) == -1) return false;
  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_balanced.cc", "is_tree_balanced.tsv",
                         &IsBalanced, DefaultComparator{}, param_names);
}
