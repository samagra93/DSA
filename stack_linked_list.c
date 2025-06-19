#include<stdio.h>
#include<stdlib.h>

struct stack {

    int value;
    struct stack* next;
};

struct stack* newnode(int value){

    struct stack* newnode = (struct stack*)malloc(sizeof(struct stack));
    newnode -> value = value;
    newnode -> next = NULL;
}

struct stack* push(struct stack* top, int value){

    struct stack* Newnode = newnode(value);
    Newnode -> value = value;
    Newnode -> next = top ;
    printf("Pushed");
    return Newnode;
    
    
}

struct stack* pop(struct stack* top){

    if(top == NULL){
        printf("Stack Empty");
        return NULL;
    }
    else{

        struct stack* temp = top;
        int popedval = top -> value;
        top = top ->next;
        free(temp);
        printf("Element Popped : %d",popedval);
        return top;
    }
}

void display(struct stack* top){

    if(top == NULL){

        printf("Stack Empty");
    }

    else{
        
        struct stack* temp = top;
        while(temp != NULL){

            printf("%d -> ",temp -> value);
            temp = temp -> next;

    }
    printf("NULL");


    }

}

int main(){

    struct stack* top = NULL;
    int choice,value;
    


    while(1){

        
        printf("\n1: display\n");
        printf("2: Push\n");
        printf("3: Pop\n");
        printf("4: exit\n");

        printf("Enter choice : ");
        scanf("%d",&choice);

        switch(choice){

            case 1:
                display(top);
                break;

            case 2:
                printf("Enter Value to Push : ");
                scanf("%d",&value);
                top = push(top,value);
                break;

            case 3:
                top = pop(top);
                break;

            default: 
                printf("Exiting....");
                break;


        }
        if (choice == 4)
            break;
        
    }
}