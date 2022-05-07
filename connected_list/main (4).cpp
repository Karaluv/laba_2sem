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

struct dual_list {
  list_data data;
  dual_list *next;
  dual_list *prev;
};

bool equal(list_data const &left, list_data const &right){
  return left.dvalue == right.dvalue && strcmp(left.name, right.name) == 0; //TODO: use strcmp for char*
}

void free_data(list_data &data){
  delete[] data.name;
}

dual_list *create_node(list_data data) {
  auto node = new dual_list;
  node->data = data;
  node->next = node;
  node->prev = node;
  return node;
}

dual_list *insert_front(dual_list *head, dual_list *node) {
  if(head == nullptr){
    return node;
  }
  node->next = head;
  node->prev = head->prev;
  head->prev->next = node;
  head->prev = node;
  return node;
}

dual_list *insert_after(dual_list *head, dual_list *after, dual_list *node) {
  if(head == nullptr){
    return node;
  }
  if (after == head)
    return insert_front(after, node);

  node->next = after->next;
  node->prev = after;
  after->next->prev = node;
  after->next = node;
  return node;
}

dual_list *insert_before(dual_list *head, dual_list *before, dual_list *node) {
  if(head == nullptr){
    return node;
  }
  if (before == head->prev)
    return insert_front(before, node);
  if (head == before)
    return insert_front(head, node);

  node->prev = before->prev;
  node->next = before;
  before->prev->next = node;
  before->prev = node;
  return node;
}

dual_list* find(dual_list* head, list_data data){
  auto it = head;
  if(equal(it->data, data)){
    return it;
  }
  it = it->next;
  while (it != head && !equal(it->data, data)){
    it = it->next;
  }
  return it;
}

void print_list(dual_list const *head) {
  if(head == nullptr){
    return;
  }
  auto it = head;
  while (true) {
    cout << it->data.name << " " << it->data.dvalue << endl;
    it = it->next;
    if(it == head){
        break;
    }
  }
}

dual_list * delete_node(dual_list *head, dual_list *node){
  if(head->next == head){
    return nullptr;
  }
  if(head == nullptr){
    return nullptr;
  }
  auto new_head = head;
  if(node == head){
    new_head = node->next;
  }
  node->next->prev = node->prev;
  node->prev->next = node->next;
  free_data(node->data);
  delete node;
  return new_head;
}

dual_list *stack_pop(dual_list *queue){
    return delete_node(queue, queue->prev);
}

dual_list * stack_push(dual_list *queue, dual_list *new_item){
    return insert_before(queue, queue, new_item);
}

double stack_top(dual_list *queue){
    if(queue != nullptr)
        return (*queue).data.dvalue;
    return 0;
}

int main() {
  dual_list *queue = nullptr;

  auto node_1 = create_node({"Pi", 3.14});
  auto node_2 = create_node({"E", 2.7});
  auto node_3 = create_node({"g", 9.8});
  auto node_4 = create_node({"hbar", 6.63e-31});

  queue = stack_push(queue, node_2);
  queue = stack_push(queue, node_1);
  queue = stack_push(queue, node_3);
  print_list(queue);
  cout <<endl;

  queue = stack_pop(queue);

  print_list(queue);
  cout <<endl;

  cout <<stack_top(queue);
  return 0;
}

