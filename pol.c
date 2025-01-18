 
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int coef;
    int expo;
    struct node* n;
} node;

node* readpol(int t, node** s) {
    node* temp = *s;
    for (int i = 0; i < t; i++) {
        struct node* p = (struct node*)malloc(sizeof(struct node));
        p->n = NULL;
        printf("Enter the exponent and coefficient of term %d\n", i + 1);
        scanf("%d %d", &p->expo, &p->coef);
        if (*s == NULL) {
            *s = p;
            temp = *s;
        } else {
            temp->n = p;
            temp = temp->n;
        }
    }
    return *s;
}

void printpol(node* s) {
    if (s == NULL) {
        printf("Empty polynomial!!\n");
    } else {
        while (s != NULL) {
            printf("%dX^%d", s->coef, s->expo);
            if (s->n != NULL) {
                printf(" + ");
            }
            s = s->n;
        }
        printf("\n");
    }
}

node* addpol(node* p1, node* p2) {
    node* result = NULL;
    node* temp = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->expo == p2->expo) {
            node* new_node = (node*)malloc(sizeof(node));
            new_node->coef = p1->coef + p2->coef;
            new_node->expo = p1->expo;
            new_node->n = NULL;

            if (result == NULL) {
                result = new_node;
                temp = result;
            } else {
                temp->n = new_node;
                temp = temp->n;
            }
            p1 = p1->n;
            p2 = p2->n;
        } else if (p1->expo > p2->expo) {
            node* new_node = (node*)malloc(sizeof(node));
            new_node->coef = p1->coef;
            new_node->expo = p1->expo;
            new_node->n = NULL;

            if (result == NULL) {
                result = new_node;
                temp = result;
            } else {
                temp->n = new_node;
                temp = temp->n;
            }
            p1 = p1->n;
        } else {
            node* new_node = (node*)malloc(sizeof(node));
            new_node->coef = p2->coef;
            new_node->expo = p2->expo;
            new_node->n = NULL;

            if (result == NULL) {
                result = new_node;
                temp = result;
            } else {
                temp->n = new_node;
                temp = temp->n;
            }
            p2 = p2->n;
        }
    }

    while (p1 != NULL) {
        node* new_node = (node*)malloc(sizeof(node));
        new_node->coef = p1->coef;
        new_node->expo = p1->expo;
        new_node->n = NULL;

        if (result == NULL) {
            result = new_node;
            temp = result;
        } else {
            temp->n = new_node;
            temp = temp->n;
        }
        p1 = p1->n;
    }

    while (p2 != NULL) {
        node* new_node = (node*)malloc(sizeof(node));
        new_node->coef = p2->coef;
        new_node->expo = p2->expo;
        new_node->n = NULL;

        if (result == NULL) {
            result = new_node;
            temp = result;
        } else {
            temp->n = new_node;
            temp = temp->n;
        }
        p2 = p2->n;
    }

    return result;
}

int main() {
    int t1, t2;
    printf("Enter the number of terms of polynomial 1: \n");
    scanf("%d", &t1);
    node* s1 = NULL;
    s1 = readpol(t1, &s1);
    printf("Polynomial 1: ");
    printpol(s1);

    printf("Enter the number of terms of polynomial 2: \n");
    scanf("%d", &t2);
    node* s2 = NULL;
    s2 = readpol(t2, &s2);
    printf("Polynomial 2: ");
    printpol(s2);

    node* result = addpol(s1, s2);
    printf("Resultant Polynomial: ");
    printpol(result);

    return 0;
}
