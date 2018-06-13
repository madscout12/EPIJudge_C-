#include <memory>
#include <vector>
#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
using std::unique_ptr;
using std::vector;

void build(const unique_ptr<BinaryTreeNode<int>>& node, vector<int>& ret){
  if(node == nullptr) return;
  build(node->left, ret);
  build(node->right, ret);
  ret.push_back(node->data);
}

// We use stack and previous node pointer to simulate postorder traversal.
vector<int> PostorderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree) {
  // TODO - you fill in here.
  vector<int> ret;
  build(tree, ret);
  return ret;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "tree_postorder.cc", "tree_postorder.tsv",
                         &PostorderTraversal, DefaultComparator{}, param_names);
}
