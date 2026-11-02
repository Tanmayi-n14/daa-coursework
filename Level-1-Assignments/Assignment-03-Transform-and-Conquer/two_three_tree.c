#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Necessary for bool, true, and false

// Define the structure ONLY ONCE
struct Node {
    int n;                 // number of keys
    int keys[3];           // max 3 for temporary overflow
    struct Node* child[4]; // pointers to children
    bool isLeaf;
};

struct Node* root = NULL;

// Function to create a node
struct Node* createNode(int key, bool isLeaf) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->n = 1;
    newNode->keys[0] = key;
    newNode->isLeaf = isLeaf;
    for (int i = 0; i < 4; i++) {
        newNode->child[i] = NULL;
    }
    return newNode;
}

// Search function
int search(struct Node* node, int key) {
    if (node == NULL) return 0;

    int i = 0;
    while (i < node->n && key > node->keys[i]) {
        i++;
    }

    if (i < node->n && key == node->keys[i]) {
        return 1; // Found
    }

    if (node->isLeaf) {
        return 0; // Not Found
    }

    return search(node->child[i], key);
}

// Recursive insert to handle splits bottom-up
struct Node* insertRecursive(struct Node* curr, int key, int* promotedKey) {
    if (curr->isLeaf) {
        // Simple insertion into leaf
        int i = curr->n - 1;
        while (i >= 0 && curr->keys[i] > key) {
            curr->keys[i + 1] = curr->keys[i];
            i--;
        }
        curr->keys[i + 1] = key;
        curr->n++;
    } else {
        // Find child to recurse into
        int i = 0;
        while (i < curr->n && key > curr->keys[i]) {
            i++;
        }

        int upKey;
        struct Node* newNode = insertRecursive(curr->child[i], key, &upKey);

        if (newNode != NULL) {
            // Child split, insert promoted key into current node
            int j = curr->n - 1;
            while (j >= 0 && curr->keys[j] > upKey) {
                curr->keys[j + 1] = curr->keys[j];
                curr->child[j + 2] = curr->child[j + 1];
                j--;
            }
            curr->keys[j + 1] = upKey;
            curr->child[j + 2] = newNode;
            curr->n++;
        }
    }

    // Split if overflow (3 keys)
    if (curr->n == 3) {
        *promotedKey = curr->keys[1];
        struct Node* rightNode = (struct Node*)malloc(sizeof(struct Node));
        rightNode->n = 1;
        rightNode->isLeaf = curr->isLeaf;
        rightNode->keys[0] = curr->keys[2];
        
        rightNode->child[0] = curr->child[2];
        rightNode->child[1] = curr->child[3];
        
        curr->n = 1; 
        return rightNode;
    }

    return NULL;
}

void insert(int key) {
    if (root == NULL) {
        root = createNode(key, true);
        return;
    }

    int promotedKey;
    struct Node* splitNode = insertRecursive(root, key, &promotedKey);

    // If root splits, tree grows in height
    if (splitNode != NULL) {
        struct Node* oldRoot = root;
        root = createNode(promotedKey, false);
        root->child[0] = oldRoot;
        root->child[1] = splitNode;
    }
}

int main() {
    int q;
    if (scanf("%d", &q) != 1) return 0;

    while (q--) {
        char op;
        int x;
        // The space before %c is crucial to skip whitespace/newlines
        if (scanf(" %c %d", &op, &x) != 2) break;

        if (op == 'I') {
            if (!search(root, x)) {
                insert(x);
            }
        } else if (op == 'S') {
            if (search(root, x))
                printf("Found\n");
            else
                printf("Not Found\n");
        }
    }

    return 0;
}
