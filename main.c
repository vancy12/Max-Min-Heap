#include "tree.c"

int main() {

    tree T1;
    T1 = initBST(T1, 7);
    printf("size of tree: %d\n", T1.size);

    // T1 = insertBST(T1, 20);
    // T1 = insertBST(T1, 30);
    // T1 = insertBST(T1, 40);
    // T1 = insertBST(T1, 25);
    // T1 = insertBST(T1, 10);
    // T1 = insertBST(T1, 15);
    // T1 = insertBST(T1, 5);
    
    int choice, data;
    do {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Max heap\n");
        printf("3. Min Heap\n");
        printf("4. Level-wise Traversal\n");
        printf("5. Max Heap Sort\n");
        printf("6. Min Heap Sort\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                T1 = insert(T1, data);
                break;
            case 2:
                printf("Converting to Max Heap... ");
                T1 = maxHeap(T1);
                printf("Call Max Heap Sort to view max heap\n");
                break;
            case 3:
                printf("Converting to Min Heap... \n");
                T1 = minHeap(T1);
                printf("Call Min Heap Sort to view min heap\n");
                break;

            case 4:
                printf("Level-wise Traversal: ");
                levelwise(T1);
                
                printf("\n");
                break;
            case 5:
                printf("Maximum heap Sort: ");
                heapSortMax(T1);
                
                printf("\n");
                break;
            case 6:
                printf("Minimum heap Sort: ");
                heapSortMin(T1);
                
                printf("\n");
                break;
            
            case 7:
                free(T1.root);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 7.\n");
        }
    } while(choice != 7);
 
    return 0;
}