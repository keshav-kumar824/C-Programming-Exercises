
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TASKS 25

/*making structue*/
struct Task{
    char title[100];
    char description[200];
    int priority;
    int taskStatus;
};

void input(struct Task t[] , int n);
void updateStatus(struct Task *t);
void modifyPriority(struct Task *t);
void adjustPriority(struct Task *t);
void display(struct Task t[] , int n);

int main(){

    struct Task t[MAX_TASKS];
    int n;
    int index;
    int choice;
    printf("No of task: ");
    scanf("%d" , &n);

    while(1){
    printf("\n=====To do list=====\n");
    printf("1. Input\n");
    printf("2. Update Status\n");
    printf("3. Update priority\n");
    printf("4. Display\n");
    printf("5. Exit\n");
    printf("Enter Choice (1-5): ");
    scanf("%d" , &choice);
    switch(choice){
case 1:
    getchar();
    input(t , n);
    break;
case 2:
    printf("Enter task index (1 to %d) " , n);
    scanf("%d" , &index);
    updateStatus(&t[index-1]);
    break;
case 3:
    printf("Enter task index (1 to %d) " , n);
    scanf("%d" , &index);
    modifyPriority(&t[index-1]);
    break;
case 4:
    display(t,n);
    break;
case 5:
    printf("Thankyou!");
    return 0;
    break;
default:
    printf("Invalid!");
    break;
    }
    }
    return 0;
}

void input(struct Task t[], int n) {

    for (int i = 0; i < n; i++) {
        printf("\n");

        printf("Title: ");
        fgets(t[i].title, sizeof(t[i].title), stdin);
        t[i].title[strcspn(t[i].title, "\n")] = '\0';

        printf("Description: ");
        fgets(t[i].description, sizeof(t[i].description), stdin);
        t[i].description[strcspn(t[i].description, "\n")] = '\0';

        printf("Priority: ");
        scanf("%d", &t[i].priority);

        printf("Task Status (0 or 1): ");
        scanf("%d", &t[i].taskStatus);

        getchar(); // clear newline for next iteration
    }
}
void updateStatus(struct Task *t){
    int newstatus;
    printf("Update Task Status: ");
    scanf("%d" , &newstatus);
    t->taskStatus = newstatus;
    printf("Task Updated Succesfully!");
}
void modifyPriority(struct Task *t){
    int newpriority;
    printf("Modify Priority: ");
    scanf("%d" , &newpriority);
    t->priority=newpriority;
    adjustPriority(t);
}
void adjustPriority(struct Task *t){
     if (t->priority < 0) {
        t->priority++;
        adjustPriority(t);
    }
    else if (t->priority > 10) {
        t->priority--;
        adjustPriority(t);
    }
}void display(struct Task t[] , int n){
    for(int i=0 ; i<n ;i++){
        adjustPriority(&t[i]);
        printf("\n=====Task %d=====\n" , i+1);
        printf("Title: %s\n" , t[i].title);
        printf("Description: %s\n" , t[i].description);
        printf("Priority: %d\n" , t[i].priority);
        if(t[i].taskStatus==0)
        printf("Task Status: Incomplete\n");
        else if(t[i].taskStatus==1)
        printf("Task Status: Complete\n");
        else
            printf("invalid status\n");
    }
}


