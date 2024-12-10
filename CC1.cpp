#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct {
    int *stack;       
    int *minStack;    
    int top;         
    int capacity;     
} MinStack;

MinStack* createStack(int capacity) {
    MinStack* minStack = (MinStack*)malloc(sizeof(MinStack));
    minStack->stack = (int*)malloc(capacity * sizeof(int));
    minStack->minStack = (int*)malloc(capacity * sizeof(int));
    minStack->top = -1;
    minStack->capacity = capacity;
    return minStack;
}

int isEmpty(MinStack* minStack) {
    return minStack->top == -1;
}

int isFull(MinStack* minStack) {
    return minStack->top == minStack->capacity - 1;
}

void push(MinStack* minStack, int value) {
    if (isFull(minStack)) {
        printf("Overflow: Stack is full!\n");
        return;
    }
    minStack->top++;
    minStack->stack[minStack->top] = value;
    if (minStack->top == 0) {
        minStack->minStack[minStack->top] = value;
    } else {
        minStack->minStack[minStack->top] = (value < minStack->minStack[minStack->top - 1]) 
                                            ? value : minStack->minStack[minStack->top - 1];
    }
    printf("Pushed %d onto the stack.\n", value);
}

void pop(MinStack* minStack) {
    if (isEmpty(minStack)) {
        printf("Underflow: Stack is empty!\n");
        return;
    }
    printf("Popped %d from the stack.\n", minStack->stack[minStack->top]);
    minStack->top--;
}

int top(MinStack* minStack) {
    if (isEmpty(minStack)) {
        printf("The stack is empty.\n");
        return INT_MIN;
    }
    return minStack->stack[minStack->top];
}

int getMin(MinStack* minStack) {
    if (isEmpty(minStack)) {
        printf("The stack is empty. No minimum element.\n");
        return INT_MIN;
    }
    return minStack->minStack[minStack->top];
}

void display(MinStack* minStack) {
    if (isEmpty(minStack)) {
        printf("The stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= minStack->top; i++) {
        printf("%d ", minStack->stack[i]);
    }
    printf("\n");
}

void freeStack(MinStack* minStack) {
    free(minStack->stack);
    free(minStack->minStack);
    free(minStack);
}

// Driver code
int main() {
    int capacity;
    printf("Enter the capacity of the stack: ");
    scanf("%d", &capacity);

    MinStack* stack = createStack(capacity);

    int choice, value;
    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Push element\n");
        printf("2. Pop element\n");
        printf("3. Display top element\n");
        printf("4. Retrieve minimum element\n");
        printf("5. Display stack\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &value);
                push(stack, value);
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                value = top(stack);
                if (value != INT_MIN) {
                    printf("Top element: %d\n", value);
                }
                break;
            case 4:
                value = getMin(stack);
                if (value != INT_MIN) {
                    printf("Minimum element: %d\n", value);
                }
                break;
            case 5:
                display(stack);
                break;
            case 6:
                printf("Exiting program.\n");
                freeStack(stack);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

