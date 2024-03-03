#include <iostream>

// Node structure for the linked list
struct Node {
  int data;
  Node* next;
};

// Function prototypes
Node* createNode(int data);
void push(Node** top, int data);
int pop(Node** top);
int peek(Node* top);
bool isEmpty(Node* top);

int main() {
  Node* top = nullptr; // Initialize the top pointer to nullptr

  push(&top, 10);
  push(&top, 20);
  push(&top, 30);

  std::cout << "Top element: " << peek(top) << std::endl;  // Output: 30

  std::cout << "Popped element: " << pop(&top) << std::endl;  // Output: 30
  std::cout << "Popped element: " << pop(&top) << std::endl;  // Output: 20

  std::cout << "Is empty: " << isEmpty(top) << std::endl;  // Output: false

  std::cout << "Popped element: " << pop(&top) << std::endl;  // Output: 10
  std::cout << "Is empty: " << isEmpty(top) << std::endl;  // Output: true

  return 0;
}

// Create a new node
Node* createNode(int data) {
  Node* newNode = new Node;
  newNode->data = data;
  newNode->next = nullptr;
  return newNode;
}

// Push an element onto the stack
void push(Node** top, int data) {
  // Create a new node
  Node* newNode = createNode(data);

  // Make the new node the top node
  newNode->next = *top;

  // Update the top pointer
  *top = newNode;
}

// Pop an element from the stack
int pop(Node** top) {
  if (isEmpty(*top)) {
    std::cout << "Stack is empty" << std::endl;
    return -1; // Or throw an exception
  }

  // Store the top element
  Node* temp = *top;

  // Update the top pointer
  *top = (*top)->next;

  // Return the popped element's data
  int data = temp->data;
  delete temp; // Free the memory of the popped node
  return data;
}

// Peek at the top element without removing it
int peek(Node* top) {
  if (isEmpty(top)) {
    std::cout << "Stack is empty" << std::endl;
    return -1; // Or throw an exception
  }

  // Return the top element's data
  return top->data;
}

// Check if the stack is empty
bool isEmpty(Node* top) {
  return top == nullptr;
}
