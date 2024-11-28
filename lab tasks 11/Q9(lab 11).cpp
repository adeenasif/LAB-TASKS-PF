#include<stdio.h>
#include<string.h>

struct student {
    char name[50];
    int rollNo;
    float marks;
};
struct instructor {
    char name[50];
};
struct course {
    char ID[10];
    char courseName[50];
    struct instructor instructorDetails;
    int credits;
    struct student students[50];
    int noOfStudents;
};
struct department {
    char departmentName[50];
    struct course courses[10];
    int noOfCourses;
};

void AddDepartment(struct department* info) {
    printf("Enter department name: ");
    fgets(info->departmentName, 50, stdin);
    info->departmentName[strcspn(info->departmentName, "\n")] = '\0';
    info->noOfCourses = 0;
    printf("Department added successfully!\n");
}

void AddCourse(struct department* info) {
    if (info->noOfCourses < 10) {
        printf("Enter course ID: ");
        fgets(info->courses[info->noOfCourses].ID, 10, stdin);
        info->courses[info->noOfCourses].ID[strcspn(info->courses[info->noOfCourses].ID, "\n")] = '\0';

        printf("Enter course name: ");
        fgets(info->courses[info->noOfCourses].courseName, 50, stdin);
        info->courses[info->noOfCourses].courseName[strcspn(info->courses[info->noOfCourses].courseName, "\n")] = '\0';

        printf("Enter instructor name: ");
        fgets(info->courses[info->noOfCourses].instructorDetails.name, 50, stdin);
        info->courses[info->noOfCourses].instructorDetails.name[strcspn(info->courses[info->noOfCourses].instructorDetails.name, "\n")] = '\0';

        printf("Enter course credits: ");
        scanf("%d", &info->courses[info->noOfCourses].credits);
        getchar();

        info->courses[info->noOfCourses].noOfStudents = 0; // Initialize student count
        info->noOfCourses++;
        printf("Course added successfully!\n");
    } else {
        printf("Department is full, cannot add more courses!\n");
    }
}
void AddStudent(struct course* courseInfo) {
    if (courseInfo->noOfStudents < 50) {
        printf("Enter student name: ");
        fgets(courseInfo->students[courseInfo->noOfStudents].name, 50, stdin);
        courseInfo->students[courseInfo->noOfStudents].name[strcspn(courseInfo->students[courseInfo->noOfStudents].name, "\n")] = '\0';

        printf("Enter roll number: ");
        scanf("%d", &courseInfo->students[courseInfo->noOfStudents].rollNo);
        getchar();
        printf("Enter marks: ");
        scanf("%f", &courseInfo->students[courseInfo->noOfStudents].marks);
        getchar();

        courseInfo->noOfStudents++;
        printf("Student added successfully!\n");
    } else {
        printf("Course is full, cannot add more students!\n");
    }
}

void DisplayDepartment(struct department info) {
    printf("\nDepartment: %s\n", info.departmentName);
    for (int i = 0; i < info.noOfCourses; i++) {
        struct course* c = &info.courses[i];
        printf("\n  Course ID: %s\n", c->ID);
        printf("  Course Name: %s\n", c->courseName);
        printf("  Instructor: %s\n", c->instructorDetails.name);
        printf("  Credits: %d\n", c->credits);
        printf("  Enrolled Students:\n");
        for (int j = 0; j < c->noOfStudents; j++) {
            struct student* s = &c->students[j];
            printf("    %d. %s (Roll No: %d, Marks: %.2f)\n", j + 1, s->name, s->rollNo, s->marks);
        }
    }
}

int CalcTotalCredits(struct department info) {
    int totalCredits = 0;
    for (int i = 0; i < info.noOfCourses; i++) {
        totalCredits += info.courses[i].credits;
    }
    return totalCredits;
}
int main() {
    struct department university[10];
    int numDepartments = 0;
    int departmentIndex, courseIndex;
    int choice;

    do {
        printf("\nUniversity Management System\n");
        printf("1. Add a Department\n");
        printf("2. Add a Course to a Department\n");
        printf("3. Add a Student to a Course\n");
        printf("4. Display Details of a Department\n");
        printf("5. Display All Departments and Courses\n");
        printf("6. Calculate Total Credits for a Department\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            if (numDepartments < 10) {
                AddDepartment(&university[numDepartments]);
                numDepartments++;
            } else {
                printf("Maximum number of departments added!\n");
            }
        } else if (choice == 2) {
            printf("Enter department index (0 to %d): ", numDepartments - 1);
            scanf("%d", &departmentIndex);
            getchar();
            if (departmentIndex >= 0 && departmentIndex < numDepartments) {
                AddCourse(&university[departmentIndex]);
            } else {
                printf("Invalid department index!\n");
            }
        } else if (choice == 3) {
            printf("Enter department index (0 to %d): ", numDepartments - 1);
            scanf("%d", &departmentIndex);
            getchar();
            if (departmentIndex >= 0 && departmentIndex < numDepartments) {
                printf("Enter course index (0 to %d): ", university[departmentIndex].noOfCourses - 1);
                scanf("%d", &courseIndex);
                getchar();
                if (courseIndex >= 0 && courseIndex < university[departmentIndex].noOfCourses) {
                    AddStudent(&university[departmentIndex].courses[courseIndex]);
                } else {
                    printf("Invalid course index!\n");
                }
            } else {
                printf("Invalid department index!\n");
            }
        } else if (choice == 4) {
            printf("Enter department index (0 to %d): ", numDepartments - 1);
            scanf("%d", &departmentIndex);
            getchar();
            if (departmentIndex >= 0 && departmentIndex < numDepartments) {
                DisplayDepartment(university[departmentIndex]);
            } else {
                printf("Invalid department index!\n");
            }
        } else if (choice == 5) {
            for (int i = 0; i < numDepartments; i++) {
                DisplayDepartment(university[i]);
            }
        } else if (choice == 6) {
            printf("Enter department index (0 to %d): ", numDepartments - 1);
            scanf("%d", &departmentIndex);
            getchar();
            if (departmentIndex >= 0 && departmentIndex < numDepartments) {
                int totalCredits = CalcTotalCredits(university[departmentIndex]);
                printf("Total Credits in %s Department: %d\n", university[departmentIndex].departmentName, totalCredits);
            } else {
                printf("Invalid department index!\n");
            }
        } else if (choice == 7) {
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid choice!\n");
        }
    } while (choice != 7);

    return 0;
}
