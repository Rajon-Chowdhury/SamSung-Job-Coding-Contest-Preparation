#include<stdio.h>
#define CAPASITY 5
int st[CAPASITY];
int top=-1;
void push(int x){
    if(top+1<CAPASITY){
        top = top + 1;
        st[top] = x;
        printf("added value %d \n",x);
    }
    else{
        printf("No space\n");
    }
}
int pop_st(){
   if(top>=0){
      int val = st[top];
      top = top-1;
      return val;
   }

}
int peek(){
   if(top>=0){

    return st[top];
   }
}
int main()
{
     push(1);
     push(4);
     pop_st();
     printf("Top element %d\n ",peek());
}
