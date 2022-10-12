1] Fold of Linked list
Given a singly linkedlist : l0 -> l1 -> l2 -> l3 -> l4 -> l5 -> l6 ..... -> ln-1 -> ln 
reorder it : l0 -> ln -> l1 -> ln-1 -> l2 -> ln-2 -> l3 -> ln-3 -> ..... 

  Code -
  
#include <iostream>
using namespace std;

class ListNode
{
public:
  int val = 0;
  ListNode* next = nullptr;

  ListNode(int val)
  {
    this->val = val;
  }
};

ListNode* midpoint(ListNode* head) {
  if (head == NULL || head->next == NULL){
      return head;
  }
  ListNode* slow = head;
  ListNode* fast = head;
  while (fast->next != NULL && fast->next->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

ListNode* reversell(ListNode* head) {
  if (head == NULL || head->next == NULL){
      return head;
  }
  ListNode* prev = NULL;
  ListNode* curr = head;
  ListNode* fwrd = NULL;
  while (curr != NULL) {
    fwrd = curr->next;
    curr->next = prev;
    prev = curr;
    curr = fwrd;
  }
  return prev;
}


void fold(ListNode* head)
{
  if (head == NULL || head->next == NULL){
      return;
  }
  ListNode* mid = midpoint(head);
  ListNode* nhead = mid->next;
  mid->next=NULL;
  nhead = reversell(nhead);
  ListNode* c1 = head;
  ListNode* c2 = nhead;
  ListNode* f1 = NULL;
  ListNode* f2 = NULL;
  while (c2!=NULL&&c1!=NULL) {
    f1 = c1->next;
    f2 = c2->next;

    c1->next = c2;
    c2->next = f1;

    c1 = f1;
    c2 = f2;
  }
  ListNode* curr = head;
  return;
}

void printList(ListNode* node)
{
  ListNode* curr = node;
  while (curr != nullptr)
  {
    cout << curr->val << " ";
    curr = curr->next;
  }
  cout << endl;
}

int main()
{
  int n;
  cin >> n;
  ListNode* dummy = new ListNode(-1);
  ListNode* prev = dummy;
  while (n-- > 0)
  {
    int val;
    cin >> val;
    prev->next = new ListNode(val);
    prev = prev->next;
  }

  ListNode* head = dummy->next;
  fold(head);
  printList(head);

  return 0;
}
