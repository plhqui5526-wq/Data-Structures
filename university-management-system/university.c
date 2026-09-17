#include<stdio.h>
#include<string.h>

typedef struct {
    char id[10];
    char name[50];
    float gpa;
    int credits;
} Student;

void displayStudent(Student students[], int index) {
    printf("----------\n");
    printf("Student ID: %s", students[index].id);
    printf("\nStudent's name: %s", students[index].name);
    printf("\nStudent's GPA: %.2f", students[index].gpa);
    printf("\nStudent's credits: %d", students[index].credits);
    printf("\n----------\n");
}

void displayStudents(Student students[], int studentCount) {
    if(studentCount == 0) {
        printf("There is no student.");
        return;
    }

    for(int i = 0; i < studentCount; i++) {
        displayStudent(students, i);
    }
}

int findStudentById(Student students[], int studentCount, char id[]) {
    if(studentCount == 0) {
        printf("There is no student.");
        return -1;
    }

    int index = -1;

    for(int i = 0; i < studentCount; i++) {
        if(strcmp(students[i].id, id) == 0) {
            index = i;
        }
    }

    return index;
}

int findHighestGPA(Student students[], int studentCount) {
    if(studentCount == 0) {
        printf("There is no student.");
        return -1;
    }

    int bestIndex = 0;

    for(int i = 1; i < studentCount; i++) {
        if(students[i].gpa > students[bestIndex].gpa) {
            bestIndex = i;
        }
    }

    return bestIndex;
}

float averageGPA(Student students[], int studentCount) {
    if(studentCount == 0) {
        printf("There is no student.");
        return -1;
    }

    float total = 0;

    for(int i = 0; i < studentCount; i++) {
        total += students[i].gpa;
    }

    return (total / studentCount);
}

int main() {
    Student students[] = {
        {"S001", "Nguyen An", 3.20, 65},
        {"S002", "Tran Binh", 3.75, 82},
        {"S003", "Le Chi", 2.95, 58},
        {"S004", "Pham Dung", 3.90, 91},
        {"S005", "Hoang Giang", 3.45, 76}
    };

    int studentCount = sizeof(students) / sizeof(Student);

    displayStudents(students, studentCount);

    char input[1];
    printf("Do you want to find a student? (Y or N): ");
    scanf("%s", input);

    if(strcmp(input, "Y") == 0) {
        printf("Please input the student's ID: ");
        char idInput[10];
        scanf("%s", idInput);
        int index = findStudentById(students, studentCount, idInput);
        if(index != -1) {
            printf("-----Found the student-----\n");
            displayStudent(students, index);
            printf("\n-----End search-----\n");
        } else {
            printf("Student not found.\n");
        }
    } else {
        printf("\nCancelled search. Please proceed.\n");
    }

    printf("Do you want to find the student with the highest GPA? (Y or N): ");
    scanf("%s", input);

    //I made some changes, if I type scanf("%c", &input), the program will have errors.

    if(strcmp(input, "Y") == 0) { //If I typed if(input == "Y") with the above being scanf("%c", &input), the program will tell me I'm comparing pointer with integer?
        int ind = findHighestGPA(students, studentCount);
        if(ind != -1) {
            printf("-----Found the student-----\n");
            displayStudent(students, ind);
            printf("\n-----End search-----\n");
        } else {
            printf("Student not found.\n");
        }
    } else {
        printf("\nCancelled search. Please proceed.\n");
    }

    printf("The average GPA of all students is: %.2f\n", averageGPA(students, studentCount));

    printf("Program ended.");

    return 0;
}