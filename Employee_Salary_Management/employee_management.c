#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TASKS 50

struct employee{
    char name[100];
    int id;
    float basic_salary;
    float allownces;
    float deductions;
    float net_salary;
    float bonus;
};
void input(struct employee e[] , int n);
void calculateNetSalary(struct employee *e);
void update_salary(struct employee *e);
void bonus(struct employee *e , float basic_salary);
void display(struct employee e[] , int n);

int main(){

    struct employee e[MAX_TASKS];
    int n , index , choice;
    printf("Enter No of employees: ");
    scanf("%d" , &n);
    getchar();

    while(1){
    printf("\n=====Employee Form=====\n");
    printf("1. Input\n");
    printf("2. Update Salary\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter Choice (1-4): ");
    scanf("%d" , &choice);
    switch(choice){
case 1:
    getchar();
    input(e , n);
    break;
case 2:
    printf("Enter task index (1 to %d) " , n);
    scanf("%d" , &index);
    update_salary(&e[index-1]);
    break;
case 3:
    for(int i=0 ; i<n ; i++){
    bonus(&e[i] , e[i].basic_salary);
    calculateNetSalary(&e[i]);
    }
    display(e,n);
    break;
case 4:
    printf("Thankyou!");
    return 0;
    break;
default:
    printf("Invalid!");
    break;
    }
    }
}
void input(struct employee e[] , int n){
    for(int i=0  ; i<n ; i++){
            printf("\n");
    printf("Enter name: ");
    fgets(e[i].name ,sizeof(e[i].name) , stdin );
    e[i].name[strcspn(e[i].name , "\n")]='\0';

    printf("Enter Id: ");
    scanf("%d" , &e[i].id);

    printf("Basic Salary: ");
    scanf("%f" , &e[i].basic_salary);

    printf("Enter Allownce: ");
    scanf("%f" , &e[i].allownces);

    printf("Enter Deductions: ");
    scanf("%f" , &e[i].deductions);
    getchar();
 }}
void calculateNetSalary(struct employee *e){
    e->bonus = 0;
    bonus(e, e->basic_salary);
    e->net_salary = e->basic_salary + e->allownces + e->bonus - e->deductions;
}
void update_salary(struct employee *e){
    printf("Enter New Basic Salary: ");
    scanf("%f" , &e->basic_salary);

    printf("Enter New Allownce: ");
    scanf("%f" , &e->allownces);

    printf("Enter New Deductions: ");
    scanf("%f" , &e->deductions);}

void bonus(struct employee *e , float basic_salary){
    if(basic_salary<10000) return;
    e->bonus+=1000;
    bonus(e , basic_salary-=10000);
}
void display(struct employee e[] , int n){
    for(int i =0 ; i< n ; i++){
    printf("\n=====Employee %d=====\n\n" , i+1);
    printf("Name : %s\n" , e[i].name);
    printf("Id : %d\n" , e[i].id);
    printf("Basic Salary: %.2f\n" , e[i].basic_salary);
    printf("Allownce: %.2f\n" , e[i].allownces);
    printf("Dedudctions: %.2f\n" , e[i].deductions);
    printf("Bonus: %.2f\n" , e[i].bonus);
    printf("Net Salary: %.2f\n" , e[i].net_salary);
    }
}
