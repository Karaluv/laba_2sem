#include <iostream>
#include <cstring>

using namespace std;
//  1. Create
//  2. insert
//    2.1 insert_front O(1)
//    2.2 insert_after O(1)
//    2.3 insert_before O(N)
//  3. delete O(N)
//  4. find O(N)

struct list_data {
  const char *name;
  double dvalue;
};

struct forward_list {
  list_data data;
  forward_list *next;
};

bool equal(list_data const &left, list_data const &right){
  return left.dvalue == right.dvalue && strcmp(left.name, right.name) == 0; //TODO: use strcmp for char*
}

void free_data(list_data &data){
  //
}

forward_list *create_node(list_data data) {
  auto node = new forward_list;
  node->data = data;
  node->next = nullptr;
  return node;
}

forward_list *insert_front(forward_list *head, forward_list *node) {
  node->next = head;
  return node;
}

forward_list *insert_after(forward_list *after, forward_list *node) {
  if (after == nullptr)
    return insert_front(after, node);

  node->next = after->next;
  after->next = node;
  return node;
}

forward_list *insert_before(forward_list *head, forward_list *before, forward_list *node) {
  if (head == before)
    return insert_front(head, node);

  node->next = before;
  auto it = head;
  for (;it != nullptr && it->next != before;
       it = it->next){
  }

  if (it == nullptr){
    cerr << "Wrong insert!" << endl;
    exit(-10);
  }

  it->next = node;
  return node;
}

forward_list* find(forward_list* head, list_data data){
  auto it = head;
  while (it != nullptr && !equal(it->data, data)){
    it = it->next;
  }
  return it;
}

void print_list(forward_list const *head) {
  auto it = head;
  while (it != nullptr) {
    cout << it->data.name << " " << it->data.dvalue << endl;
    it = it->next;
  }
}

forward_list* delete_node(forward_list *head, forward_list *node){
  if (head == node){
    auto next_head = head->next;
    free_data(node->data);
    delete node;
    return next_head;
  }

  auto it = head;
  while (it != nullptr && it->next != node){
    it = it->next;
  }
  if (it == nullptr){
    cerr << "Wrong node for delete!\n";
    exit(-10);
  }
  it->next = node->next;

  free_data(node->data);
  delete node;
  return head;
}

int main() {
  forward_list *head = nullptr;

  auto node_1 = create_node({"Pi", 3.14});
  auto node_2 = create_node({"E", 2.7});

  head = insert_front(head, node_2);
  head = insert_front(head, node_1);

  auto node_3 = create_node({"g", 9.8});
  insert_after(node_1, node_3);

  auto node_4 = create_node({"hbar", 6.63e-31});
  insert_before(head, node_3, node_4);

  print_list(head);

  auto res = find(head, {"hbar", 6.63e-31});
  delete_node(head, res);

  cout << "-------------------\n";
  print_list(head);

  while (head != nullptr)
    head = delete_node(head, head);

  cout << "-------------------\n";
  print_list(head);
  return 0;
}
