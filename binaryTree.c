#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t
{
  int data;
  struct Node_t *leftNode;
  struct Node_t *rightNode;
} Node;

Node *newNode(int data)
{
  Node *new_node = malloc(sizeof(Node));
  new_node->data = data;
  new_node->leftNode = NULL;
  new_node->rightNode = NULL;
  return new_node;
}

int main()
{
  Node *root = newNode(12);

  root->leftNode = newNode(13);
  root->rightNode = newNode(14);

  root->leftNode->rightNode = newNode(15);

  printf("%i\n", root->leftNode->rightNode->data); // prints 15
  return 0;
}