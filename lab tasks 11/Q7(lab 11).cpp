#include<stdio.h>
#include<string.h>

struct course{
	char ID[10];
	char courseName[50];
	char instructorName[10];
	int credits;
};
struct department{
    char departmentName[50];
	struct course Courses[10];
	int noOfCourses;
};

void AddDepartment(struct department* info) {
    printf("Enter department name: ");
    fgets(info->departmentName, 50, stdin);
    info->departmentName[strcspn(info->departmentName, "\n")] = '\0';
    info->noOfCourses = 0;
    printf("Department added!!\n");
}
void addCourse(struct department* info){
	if (info->noOfCourses < 10) {
    	printf("Enter course ID: ");
	    fgets(info->Courses[info->noOfCourses].ID, 10, stdin);
	    info->Courses[info->noOfCourses].ID[strcspn(info->Courses[info->noOfCourses].ID, "\n")] = '\0';

	  	printf("Enter course name: ");
	    fgets(info->Courses[info->noOfCourses].courseName, 50, stdin);
        info->Courses[info->noOfCourses].courseName[strcspn(info->Courses[info->noOfCourses].courseName, "\n")] = '\0';
        
	    printf("Enter instructor name: ");
	    fgets(info->Courses[info->noOfCourses].instructorName, 50, stdin);
        info->Courses[info->noOfCourses].instructorName[strcspn(info->Courses[info->noOfCourses].instructorName, "\n")] = '\0';
       
	    printf("Enter course credits: ");
	    scanf("%d", &info->Courses[info->noOfCourses].credits);
	    getchar(); 
		
		info->noOfCourses++;
        printf("Course added successfully!\n");
    } else {
        printf("Department is full, cannot add any more Courses!!! \n");
    }
}

void DisplayCourses(struct department info) {
    printf("\nCourses in %s Department:\n", info.departmentName);
    for (int i = 0; i < info.noOfCourses; i++) {
        printf("Course ID: %s\n", info.Courses[i].ID);
        printf("Course Name: %s\n", info.Courses[i].courseName);
        printf("Instructor: %s\n", info.Courses[i].instructorName);
        printf("Credits: %d\n\n", info.Courses[i].credits);
    }
}

int CalcTotalCredits(struct department info) {
    int TotalCredits = 0;
    for (int i = 0; i < info.noOfCourses; i++) {
        TotalCredits += info.Courses[i].credits;
    }
    return TotalCredits;
}

int main(){
	struct department university[10];
    int NumDepartments = 0;
    int DepartmentIndex;
    int choice;

	do{
        printf("\n1. Add a Department\n");
        printf("2. Add a Course to a Department\n");
        printf("3. Display All Departments and Courses\n");
        printf("4. Calculate Total Credits for a Department\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
		getchar();
        if (choice == 1){
            if (NumDepartments < 10) {
                AddDepartment(&university[NumDepartments]);
                NumDepartments++;
            } else {
                printf("Maximum number of departments added.\n");
            }
        } else if (choice == 2) {
            printf("Enter department index (0 to %d): ", NumDepartments - 1);
            scanf("%d", &DepartmentIndex);
            getchar();
            if (DepartmentIndex >= 0 && DepartmentIndex < NumDepartments) {
                addCourse(&university[DepartmentIndex]);
                } else {
                    printf("Invalid input.\n");
                }
		} else if (choice == 3){
		    for (int i = 0; i < NumDepartments; i++) {
                DisplayCourses(university[i]);
            }
        }else if (choice == 4){
	        printf("\nEnter department index between 0 to %d: ", NumDepartments - 1);
            scanf("%d", &DepartmentIndex);
            if (DepartmentIndex >= 0 && DepartmentIndex < NumDepartments) {
                int TotalCredits = CalcTotalCredits(university[DepartmentIndex]);
                printf("Total Credits in %s Department: %d\n", university[DepartmentIndex].departmentName, TotalCredits);
            } else {
                printf("Invalid index.\n");
            }
        } else if (choice == 5){
	        printf("Exiting program.\n");
            break;
    	} else {
            printf("Invalid choice!!!\n");
            break;
        }
    } while (choice != 5);
    
    return 0;
}
