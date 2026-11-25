#include <cstddef>
#include <cstring>


struct Stack {
  struct Node {
    char *string;
    Node *prev;
    Node(const char* str, Node* prv) : string(new char[std::strlen(str) + 1]), prev(prv) {
      std::strcpy(string, str);
    }
    ~Node() {
      delete[] string;
    };
  };

  std::size_t size;
  Node* top;

  Stack() : size(0), top(nullptr) {}

  ~Stack() {
    while(this->top != nullptr) {
      Node* old_top = top;
      top = top->prev;
      delete old_top;
    }
  }
};


void Push(Stack *stack, const char* str) {
  Stack::Node* new_top = new Stack::Node(str, stack->top);
  stack->top = new_top;
  stack->size++;
}


void Pop(Stack *stack) {
  if (stack->top == nullptr)
    return;
  Stack::Node* old_top = stack->top;
  stack->top = stack->top->prev;
  delete old_top;
  stack->size--;
}


const char* Top(const Stack *stack) {
  if (stack->top == nullptr)
    return nullptr;
  return stack->top->string;
}


std::size_t Size(const Stack *stack) {
  return stack->size;
}


void Clear(Stack *stack) {
  while(stack->top != nullptr)
    Pop(stack);
}
