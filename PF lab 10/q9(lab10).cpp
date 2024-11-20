#include<stdio.h>
#include<string.h>

struct Employee{
	int ID;
	char Name[50];
	char Department[50];
	float Salary;	
};

int main(){
	int num, choice;
	struct Employee details[num];

	printf("\nEnter the number of employees to add their details:");
	scanf("%d", &num);
	for(int i = 0; i < num; i++){
		printf("\nEnter details of Employee [%d]\n", i+1);
		printf("Enter employee ID: ");
		scanf("%d", &details[i].ID);
		getchar();
		printf("Enter employee name: ");
		fgets(details[i].Name, 50, stdin);
		details[i].Name[strcspn(details[i].Name, "\n")] = '\0';
		printf("Enter department: ");
		fgets(details[i].Department, 50, stdin);
		details[i].Department[strcspn(details[i].Name, "\n")] = '\0';
		printf("Enter employee salary: ");
		scanf("%f", &details[i].Salary);
	}
	for(int i = 0; i < num; i++){
			printf("\nDetails of Employee [%d]\n", i+1);
			printf("Employee ID: %d\n", details[i].ID);
			printf("Employee name: %s\n", details[i].Name);
			printf("Department: %s\n", details[i].Department);
			printf("Employee salary: $%.2f\n\n",details[i].Salary);
	}
	
	return 0;
}
