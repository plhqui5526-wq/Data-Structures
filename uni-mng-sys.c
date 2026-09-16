typedef struct {
    char id[10];
    char name[50];
    float gpa;
    int credits;
} Student;

void displayStudents(Student students[], int studentCount) {
    if(studentCount == 0) {
        printf("There is no student.");
        return;
    }

    for(int i = 0; i < studentCount; i++) {
        printf("----------\n");
        printf("Student ID: ", students[i].id);
        printf("\nStudent's name: ", students[i].name);
        printf("\nStudent's GPA: ", students[i].gpa);
        printf("\nStudent's credits: ", students[i].credits);
        printf("----------\n");
    }
}

int findStudentById(Student students[], int studentCount, char id[]) {
    if(studentCount == 0) {
        printf("There is no student.");
        return;
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
        return;
    }

    int bestIndex = 0;

    for(int i = 1; i < studentCount; i++) {
        if(students[i].gpa > students[bestIndex].gpa) {
            bestIndex = i;
        }
    }

    return bestIndex;
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

    printf("%d", studentCount);

    return 0;
}