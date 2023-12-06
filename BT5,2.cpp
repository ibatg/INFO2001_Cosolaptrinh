#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    char name[50];
    int id;
    float gpa;
} Student;


void sortByName(Student students[], int numStudents) {
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = i + 1; j < numStudents; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}


void sortByGPA(Student students[], int numStudents) {
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = i + 1; j < numStudents; j++) {
            if (students[i].gpa < students[j].gpa) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}


int searchByName(Student students[], int numStudents, const char* name) {
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, name) == 0) {
            return i; 
        }
    }
    return -1; 
}


int searchById(Student students[], int numStudents, int id) {
    for (int i = 0; i < numStudents; i++) {
        if (students[i].id == id) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    Student students[MAX_STUDENTS]; 
    int numStudents = 0; 

    

    
    sortByName(students, numStudents);

    
    sortByGPA(students, numStudents);

    
    char searchName[50];
    printf("Enter the name of the student to search: ");
    scanf(" %[^\n]s", searchName);
    int foundIndex = searchByName(students, numStudents, searchName);
    if (foundIndex != -1) {
        printf("Found the student at position %d.\n", foundIndex);
        
    } else {
        printf("Student not found.\n");
    }

    
    int searchId;
    printf("Enter the ID of the student to search: ");
    scanf("%d", &searchId);
    foundIndex = searchById(students, numStudents, searchId);
    if (foundIndex != -1) {
        printf("Found the student at position %d.\n", foundIndex);
        
    } else {
        printf("Student not found.\n");
    }

    return 0;
}
