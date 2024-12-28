#include <stdio.h>
#include <stdlib.h>

struct node {
   struct node *rep;  // Representative (leader) of the set
   struct node *next; // Next element in the set
   int data;          // Data of the node
} *heads[50], *tails[50];

static int countRoot = 0;  // Track number of sets

void makeSet(int x) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->rep = new;  // Set itself as its own representative
    new->next = NULL;
    new->data = x;
    heads[countRoot] = new;  // Store head of the set
    tails[countRoot] = new;  // Store tail of the set
    countRoot++;
}

struct node* find(int a) {
    for (int i = 0; i < countRoot; i++) {
        struct node *tmp = heads[i];
        while (tmp != NULL) {
            if (tmp->data == a)
                return tmp->rep;  // Return the representative
            tmp = tmp->next;
        }
    }
    return NULL;  // Not found
}

void unionSets(int a, int b) {
    struct node *rep1 = find(a);
    struct node *rep2 = find(b);
    
    if (rep1 == NULL || rep2 == NULL) {
        printf("\nElement(s) not present in the DS\n");
        return;
    }
    
    // If the representatives are different, merge the sets
    if (rep1 != rep2) {
        // Remove the set of `b` from the disjoint set list
        int pos = -1;
        for (int i = 0; i < countRoot; i++) {
            if (heads[i] == rep2) {
                pos = i;
                break;
            }
        }
        
        if (pos != -1) {
            // Remove set `b` from the list
            for (int i = pos; i < countRoot - 1; i++) {
                heads[i] = heads[i + 1];
                tails[i] = tails[i + 1];
            }
            countRoot--;
        }
        
        // Attach `rep2`'s set to `rep1`'s set
        tails[pos]->next = rep2;  // Connect the last node of `rep1` to the first node of `rep2`
        
        // Update the representative of `rep2`'s nodes to `rep1`
        while (rep2 != NULL) {
            rep2->rep = rep1;
            rep2 = rep2->next;
        }
    }
}

int search(int x) {
    for (int i = 0; i < countRoot; i++) {
        struct node *tmp = heads[i];
        while (tmp != NULL) {
            if (tmp->data == x)
                return 1;
            tmp = tmp->next;
        }
    }
    return 0;
}

void printSets() {
    for (int i = 0; i < countRoot; i++) {
        printf("Set %d: { ", i + 1);
        struct node *temp = heads[i];
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("}\n");
    }
}

int main() {
    int choice, x, y, flag = 0;

    do {
        printf("\n1. Make Set\n2. Display Set Representatives\n3. Union\n4. Find Set\n5. Display Sets\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter new element: ");
                scanf("%d", &x);
                if (search(x) == 1)
                    printf("\nElement already present in the disjoint set DS\n");
                else
                    makeSet(x);
                break;
            case 2:
                printf("\nSet Representatives:\n");
                for (int i = 0; i < countRoot; i++) {
                    printf("Set %d representative: %d\n", i + 1, heads[i]->data);
                }
                break;
            case 3:
                printf("\nEnter first element: ");
                scanf("%d", &x);
                printf("Enter second element: ");
                scanf("%d", &y);
                unionSets(x, y);
                break;
            case 4:
                printf("\nEnter the element: ");
                scanf("%d", &x);
                struct node *rep = find(x);
                if (rep == NULL)
                    printf("\nElement not present in the DS\n");
                else
                    printf("\nThe representative of %d is %d\n", x, rep->data);
                break;
            case 5:
                printSets();
                break;
            case 6:
                exit(0);
            default:
                printf("\nWrong choice\n");
                break;
        }
    } while (1);

    return 0;
}
