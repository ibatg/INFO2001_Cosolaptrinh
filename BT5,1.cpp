#include <stdio.h>
#define MAX_STUDENTS 100

typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

int main() {
    Student students[MAX_STUDENTS]; 
    int numStudents = 0;

    int choice;
    do {
        printf("\n===== Student List Management =====\n");
        printf("1. Add Student\n");
        printf("2. Display Student List\n");
        printf("3. Update Student's Information\n");
        printf("0. Exit\n");
        printf("Insert Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                if (numStudents < MAX_STUDENTS) {
                    printf("\nType In Student's Information:\n");
                    printf(": ");
                    scanf(" %[^\n]s", students[numStudents].name);
                    printf("Age: ");
                    scanf("%d", &students[numStudents].age);
                    printf("Average Score: ");
                    scanf("%f", &students[numStudents].gpa);

                    numStudents++;
                    printf("Successfully Added Student.\n");
                } else {
                    printf("Student List Is Full, Cannot Add New Student.\n");
                }
                break;

            case 2: 
                if (numStudents > 0) {
                    printf("\Student List:\n");
                    printf("%-30s %-10s %-10s\n", "Name", "Age", "Average Score");
                    for (int i = 0; i < numStudents; i++) {
                        printf("%-30s %-10d %-10.2f\n", students[i].name, students[i].age, students[i].gpa);
                    }
                } else {
                    printf("List Is Empty.\n");
                }
                break;

            case 3: 
                if (numStudents > 0) {
                    int studentIndex;
                    printf("Insert Position Needed To Update(0 - %d): ", numStudents - 1);
                    scanf("%d", &studentIndex);

                    if (studentIndex >= 0 && studentIndex < numStudents) {
                        printf("\nType In Student's Information:\n");
                        printf("Name: ");
                        scanf(" %[^\n]s", students[studentIndex].name);
                        printf("Age: ");
                        scanf("%d", &students[studentIndex].age);
                        printf("Average Score: ");
                        scanf("%f", &students[studentIndex].gpa);

                        printf("Successfully Updated.\n");
                    } else {
                        printf("Invalid Position.\n");
                    }
                } else {
                    printf("List Is Empty.\n");
                }
                break;

            case 0: 
                printf("Exit Program.\n");
                break;

            default:
                printf("Invalid Choose. Please Choose Again.\n");
        }
    } while (choice != 0);

    return 0;
}
