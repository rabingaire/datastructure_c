#include <stdio.h>
#include <stdlib.h>

typedef struct Stack_t
{
  int top;
  unsigned int capacity;
  int *array;
} Stack;

int isEmpty(Stack *stack);
int isFull(Stack *stack);

Stack *constructor(unsigned int capacity)
{
  Stack *stack = malloc(sizeof(Stack));
  stack->top = -1;
  stack->capacity = capacity;
  stack->array = malloc(stack->capacity * sizeof(int));
  return stack;
}

void push(Stack *stack, int value)
{
  if (isFull(stack))
  {
    printf("Can't push anymore stack is full\n");
  }
  else
  {
    stack->top++;
    stack->array[stack->top] = value;
    printf("%d pushed to stack\n", value);
  }
}

void pop(Stack *stack)
{
  if (isEmpty(stack))
  {
    printf("Can't pop anymore stack is empty\n");
  }
  else
  {
    printf("%d popped from stack\n", stack->array[stack->top]);
    stack->top--;
  }
}

int isEmpty(Stack *stack)
{
  return stack->top == -1;
}

int isFull(Stack *stack)
{
  return stack->top == stack->capacity - 1;
}

void peek(Stack *stack)
{
  printf("%d is on the top of the stack\n", stack->array[stack->top]);
}

int main()
{
  Stack *stack = constructor(100);
  push(stack, 10);
  push(stack, 20);
  peek(stack);
  pop(stack);
  pop(stack);
  pop(stack);
  pop(stack);
  return 0;
}