#include <stdio.h>
#include <stdlib.h>

#define MaxItems 100
#define MaxBoxes 100

struct Box {
    int weight;
    int items[MaxItems];
    int itemCount;
    struct Box* nestedBox;
};

int TotalWeight(struct Box* box) {
    int total = box->weight;
    
    for (int i = 0; i < box->itemCount; i++) {
        total += box->items[i];
    }
    
    if (box->nestedBox != NULL) {
        total += TotalWeight(box->nestedBox);
    }
    
    return total;
}

struct Box* createNewBox() {
    struct Box* newBox = (struct Box*)malloc(sizeof(struct Box));
    newBox->nestedBox = NULL;

    printf("Enter the weight of this box: ");
    scanf("%d", &newBox->weight);

    printf("Enter the number of items in this box: ");
    scanf("%d", &newBox->itemCount);
    if (newBox->itemCount > 0) {
        newBox->nestedBox = NULL;
    } else {
        printf("\nDoes this box contain another box? Enter 1 for yes or 0 for no: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nCreating nested box:\n");
            newBox->nestedBox = createNewBox();
        }
    }
    
    for (int i = 0; i < newBox->itemCount; i++) {
        printf("Enter weight of item %d: ", i + 1);
        scanf("%d", &newBox->items[i]);
    }

    return newBox;
}

int main() {
    printf("Creating the larger box!\n");
    struct Box* mainBox = createNewBox();

    int total = TotalWeight(mainBox);
    printf("\nTotal weight of the box including all the nested boxes is: %d\n", total);
    return 0;
}
