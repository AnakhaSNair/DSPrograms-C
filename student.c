#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    int rollNo;
    char name[50];
    float mark1, mark2, total;
};

struct Student students[MAX_STUDENTS];
int count = 0;

// Function to insert a student record
void insert() {
    if (count >= MAX_STUDENTS) {
        printf("Maximum students reached.\n");
        return;
    }
    
    printf("Enter Roll No: ");
    scanf("%d", &students[count].rollNo);
    printf("Enter Name: ");
    scanf(" %[^\n]", students[count].name);
    printf("Enter Mark1: ");
    scanf("%f", &students[count].mark1);
    printf("Enter Mark2: ");
    scanf("%f", &students[count].mark2);
    students[count].total = students[count].mark1 + students[count].mark2;
    count++;
    printf("Student record inserted.\n");
}

// Function to delete a student record by Roll No
void deleteRecord(int roll) {
    int i, found = 0;
    for (i = 0; i < count; i++) {
        if (students[i].rollNo == roll) {
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student with Roll No %d not found.\n", roll);
        return;
    }
    for (int j = i; j < count - 1; j++) {
        students[j] = students[j + 1];
    }
    count--;
    printf("Student record deleted.\n");
}

// Function to display all student records
void display() {
    if (count == 0) {
        printf("No records to display.\n");
        return;
    }
    
    printf("Roll No\tName\t\tMark1\tMark2\tTotal\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%.2f\t%.2f\t%.2f\n", students[i].rollNo, students[i].name, students[i].mark1, students[i].mark2, students[i].total);
    }
}

// Function to save records to file
void saveToFile() {
    FILE *file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d\n%s\n%.2f\n%.2f\n%.2f\n", students[i].rollNo, students[i].name, students[i].mark1, students[i].mark2, students[i].total);
    }
    fclose(file);
    printf("Records saved.\n");
}

// Function to restore records from file
void restoreFromFile() {
    FILE *file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    
    count = 0;
    while (count < MAX_STUDENTS && fscanf(file, "%d\n", &students[count].rollNo) == 1) {
        fgets(students[count].name, 50, file);
        students[count].name[strcspn(students[count].name, "\n")] = 0;
        fscanf(file, "%f\n%f\n%f\n", &students[count].mark1, &students[count].mark2, &students[count].total);
        count++;
    }
    fclose(file);
    printf("Records restored.\n");
}

int main() {
    int choice, roll;
    
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Save\n5. Restore\n6. Exit\nChoice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: insert(); break;
            case 2: 
                printf("Enter Roll No: ");
                scanf("%d", &roll);
                deleteRecord(roll);
                break;
            case 3: display(); break;
            case 4: saveToFile(); break;
            case 5: restoreFromFile(); break;
            case 6: return 0;
            default: printf("Invalid choice.\n");
        }
    }
    
    return 0;
}