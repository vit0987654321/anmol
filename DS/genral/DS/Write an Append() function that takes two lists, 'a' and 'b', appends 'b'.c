#include <stdio.h>
#include <stdlib.h>
struct Lab {
  int data;
  struct Lab *next;
} *A, *B, *Mix;
void start(){
    A = B = Mix = NULL;
}
void push(struct Lab **start, int num) {
    struct Lab* newLab = (struct Lab*) malloc(sizeof(struct Lab));
    newLab->data  = num;
    newLab->next = *start;

    *start = newLab;
    printf("push num:%d\n", num);
}
struct Lab* Append(struct Lab* B, struct Lab* A){
    struct Lab *temp;
    temp = A ;
    while (temp->next != NULL) {
     temp = temp->next;
    }
    temp->next = B;
    return A;
}
void thelist(struct Lab *pointer) {
  while (pointer != NULL) {
     printf("%d", pointer->data);
     pointer = pointer->next;
     if(pointer != NULL)
         printf(",");
  }
}
int main() {
    start();
    push(&A, 12);
    push(&A, -4);
    push(&A, 22);
    push(&A, 8);
    push(&A, -3);
    thelist(A);
    printf("\n");
    push(&B, 3);
    push(&B, 5);
    push(&B, 59);
    push(&B, 87);
    push(&B, -99);
    thelist(B);
    Mix = Append(B, A);
    printf("\nB 1&2:\n");
    thelist(Mix);
    return 0;
}