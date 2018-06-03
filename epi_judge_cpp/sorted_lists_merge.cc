#include "list_node.h"
#include "test_framework/generic_test.h"
shared_ptr<ListNode<int>> MergeTwoSortedLists(shared_ptr<ListNode<int>> L1,
                                              shared_ptr<ListNode<int>> L2) {
  // TODO - you fill in here.
  if(!L1) return L2;
  if(!L2) return L1;

  shared_ptr<ListNode<int>> dummy_head(new ListNode<int>);
  shared_ptr<ListNode<int>> tail = dummy_head;

  while(L1 && L2){
    tail->next = L1->data < L2->data ? L1 : L2;
    if (L1->data < L2->data) L1 = L1->next;
    else L2 = L2->next;
    tail = tail->next;

  }

  tail->next = L1 ? L1 : L2;

  return dummy_head->next;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L1", "L2"};
  return GenericTestMain(args, "sorted_lists_merge.cc",
                         "sorted_lists_merge.tsv", &MergeTwoSortedLists,
                         DefaultComparator{}, param_names);
}
