#include<stdio.h>
#include<string.h>

struct Employee{
    char Name[20];
    char DOB[15];
    char employeeID[10];
    char Department[20];
    float Salary;
};

void AddEmployee(struct Employee details[], int *currentCount, int maxCount){
    if (*currentCount >= maxCount){
        printf("No more data can be stored!!\n");
        return;
    } 
    int i = *currentCount;
    
    printf("\nEnter data for employee %d: \n\n", i+1);
    
    printf("Enter name: ");
    getchar();
    fgets(details[i].Name, 20, stdin);
    details[i].Name[strcspn(details[i].Name, "\n")] = '\0';
    
    printf("Enter date of birth (DD-MM-YYYY):");
    fgets(details[i].DOB, 15, stdin);
    details[i].DOB[strcspn(details[i].DOB, "\n")] = '\0';

    printf("Enter ID: ");
    fgets(details[i].employeeID, 10, stdin);
    details[i].employeeID[strcspn(details[i].employeeID, "\n")] = '\0';
    
    printf("Enter department name: ");
    fgets(details[i].Department, 20, stdin);
    details[i].Department[strcspn(details[i].Department, "\n")] = '\0';
    
    printf("Enter Salary: ");
    scanf("%f", &details[i].Salary);
    getchar();
    
    (*currentCount)++;
    printf("\n");
}


void DelEmployee(struct Employee details[], int *currentCount){
    char userID[10];
    int found = 0;
    
    if(*currentCount == 0){
        printf("No record to delete!");
        return;
    }
    printf("Enter employee ID to delete an employee record: ");
    fgets(userID, 10, stdin);
    userID[strcspn(userID, "\n")] = '\0';
    
    for (int i = 0; i < *currentCount; i++){
        if (strcmp(userID, details[i].employeeID) == 0){
            for (int j = i; j < *currentCount - 1; j++) {
                details[j] = details[j + 1];
            }
            found = 1;
            (*currentCount)--;
            printf("Record deleted successfully!!");
            break;
        }
    }
    if (!found){
        printf("No such record found!!\n");
    }
    return;
}

void Display(struct Employee details[], int currentCount){
    if (currentCount == 0){
        printf("\nNo employee data to display!!\n");
        return;
    } else {
        for (int i = 0; i < currentCount; i++){
            printf("\nData of Employee %d: \n\n", i+1);
            printf("Name: %s \n", details[i].Name);
            printf("Date of Birth: %s \n", details[i].DOB);
            printf("Employee ID: %s \n", details[i].employeeID);
            printf("Department: %s \n", details[i].Department);
            printf("Salary: %.2f \n\n", details[i].Salary);     
        }
    }
}

int main(){
    int maxCount, choice;
    printf("Enter the maximum number of employees: ");
    scanf("%d", &maxCount);
    getchar();
    
    struct Employee details[maxCount];
    int currentCount = 0;
    
    do{
        printf("\n1.Add an Employee\n");
        printf("2.Delete an Employee\n");
        printf("3.Display All Employees\n");
        printf("4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        
        if (choice ==1) {
            AddEmployee(details, &currentCount, maxCount);
        } else if (choice == 2){
            DelEmployee(details, &currentCount);
        } else if (choice == 3){
            Display(details, currentCount);
        } else if (choice == 4){
            printf("Exiting...\n");
        } else {
            printf("Invalid Choice!!\n");
        }
    } while(choice != 4);
    
    return 0;
}
