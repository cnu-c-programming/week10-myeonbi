#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    int score;
    struct Node* next;
};

struct Node* head = NULL;

void addStudent(char* name, int score) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

void deleteStudent(char* name) {
    struct Node* current = head;
    struct Node* previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }

            free(current);
            return;
        }

        previous = current;
        current = current->next;
    }
}

void printStudents() {
    struct Node* current = head;

    while (current != NULL) {
        printf("%s %d\n", current->name, current->score);
        current = current->next;
    }
}

void freeAll() {
    struct Node* current = head;

    while (current != NULL) {
        struct Node* nextNode = current->next;
        free(current);
        current = nextNode;
    }

    head = NULL;
}

int main() {
    char command[20];
    char name[50];
    int score;

    while (1) {
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            scanf("%s %d", name, &score);
            addStudent(name, score);
        }
        else if (strcmp(command, "delete") == 0) {
            scanf("%s", name);
            deleteStudent(name);
        }
        else if (strcmp(command, "print") == 0) {
            printStudents();
        }
        else if (strcmp(command, "quit") == 0) {
            freeAll();
            break;
        }
    }

    return 0;
}
