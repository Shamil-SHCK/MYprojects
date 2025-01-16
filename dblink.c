#include <stdio.h>
#include <stdlib.h>

struct dnode {
    int data;
    struct dnode *next;
    struct dnode *prev;
} *head = NULL;

// Function prototypes (assumed to be declared elsewhere)
void display();
void InsertAtFront(int k);
void InsertAtEnd(int k);
void insertAfter(int key);
void insertbefore(int key);
void deletekey(int key);
void Deleteatfront();
void Deleteatend();

int main(void) {
    int choice, k;
    printf("===== Doubly Linked List =====\n");
    
    do {
        printf("\n1. Display 2. Insert At Front 3. Insert At End 4. Insert After 5. Insert Before 6. Delete Node 7. Delete At Front 8. Delete At End 0. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: 
                printf("\nDisplaying List\n\n");
                display(); 
                break;
            case 2:
                printf("\nInsert at Front\n\n");
                printf("Enter the value to be inserted: ");
                scanf("%d", &k);
                InsertAtFront(k);
                break;
            case 3:
                printf("\nInsert at End\n\n");
                printf("Enter the value to be inserted: ");
                scanf("%d", &k);
                InsertAtEnd(k);
                break;
            case 4:
                printf("\nInsert After\n\n");
                printf("Enter the key to be searched: ");
                scanf("%d", &k);
                insertAfter(k);
                break;
            case 5:
                printf("\nInsert Before\n\n");
                printf("Enter the key to be searched: ");
                scanf("%d", &k);
                insertbefore(k);
                break;
            case 6:
                printf("\nDelete Node\n\n");
                printf("Enter the key to be deleted: ");
                scanf("%d", &k);
                deletekey(k);
                break;
            case 7:
                printf("\nDelete at Front\n\n");
                Deleteatfront();
                break;
            case 8:
                printf("\nDelete at End\n\n");
                Deleteatend();
                break;
            case 0:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nWrong Choice\n");
        }
    } while (choice != 0);
    
    return 0;
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct dnode *temp = head;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void InsertAtFront(int k) {
    struct dnode *newNode = (struct dnode*)malloc(sizeof(struct dnode));
    newNode->data = k;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

void InsertAtEnd(int k) {
    struct dnode *newNode = (struct dnode*)malloc(sizeof(struct dnode));
    newNode->data = k;
    newNode->next = NULL;
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        struct dnode *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void insertAfter(int key) {
    struct dnode *temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Key not found.\n");
        return;
    }
    struct dnode *newNode = (struct dnode*)malloc(sizeof(struct dnode));
    printf("Enter value to be inserted: ");
    scanf("%d", &newNode->data);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void insertbefore(int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->data == key) {
        InsertAtFront(key);
        return;
    }
    struct dnode *temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Key not found.\n");
        return;
    }
    struct dnode *newNode = (struct dnode*)malloc(sizeof(struct dnode));
    printf("Enter value to be inserted: ");
    scanf("%d", &newNode->data);
    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
}

void deletekey(int key) {
    struct dnode *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (temp->data == key) {
        head = temp->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Key not found.\n");
        return;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

void Deleteatfront() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct dnode *temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
}

void Deleteatend() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct dnode *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }
    free(temp);
}