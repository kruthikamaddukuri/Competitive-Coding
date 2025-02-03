#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct MinStack {
    int stack[MAX];
    int min_stack[MAX];
    int top;
};
void initStack(struct MinStack* minStack){
minStack->top = -1 ;
}
int isFull(struct MinStack* minStack)
{
    return minStack->top == MAX-1;
}
int isEmpty(struct MinStack* minStack)
{
    return minStack->top=-1;
}
void push(struct MinStack* minStack,int value) {
    if (isFull(minStack)) {
        printf("Stack Overflow\n");
        return;
}
minStack->stack[++(minStack->top)] = value;
if(minStack->top == 0){
     minStack->min_stack[minStack->top] = value; 
} else{
    int currentMin= minStack->min_stack[minStack->top-1];
  minStack->min_stack[minStack->top] = (value < currentMin) ? value :currentMin ;
}
}
int pop(struct MinStack* minStack) {
    if (isEmpty(minStack)) {
        printf("Stack Underflow\n");
        return -1;
}
int poppedValue = minStack->stack[minStack->top--];
return poppedValue;
}
int top(struct MinStack* minStack) {
     if (isEmpty(minStack)) {
        printf("Stack Underflow\n");
        return -1;
}
return minStack->stack[minStack->top];
}
int getMin(struct MinStack* minStack){
     if (isEmpty(minStack)) {
        printf("Stack underflow\n");
        return -1;
}
return minStack->min_stack[minStack->top];
} 
void display(struct MinStack* minStack) {
    if (isFull(minStack)) {
        printf("Stack empty\n");
        return;
}
printf("stack elements\n");
for(int i=0;i<=minStack->top;i++) {
    printf("%d\n",minStack->stack[i]);
}
printf("\n Minimum element so far :%d\n",getMin(minStack));
}
int main ()
{
    struct MinStack minStack;
    initStack(&minStack);
push(&minStack,10);
push(&minStack,20);
push(&minStack,5);
push(&minStack,30);
display(&minStack);
printf("Popped :%d\n",pop(&minStack));
display(&minStack);
printf("Top element :%d\n",top(&minStack));
printf("Min element :%d\n",getMin(&minStack));
pop(&minStack);
pop(&minStack);
pop(&minStack);
pop(&minStack);

return 0
};
