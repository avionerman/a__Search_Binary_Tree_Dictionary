#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define w 16 // Default amount of chars for a word [ it can be easily modified as its user wants to].



/*  
    SCOPE OF THIS PROJECT IS THE MATCHING OF TWO FILES AND THE SEARCHING OF THEIR DIFFERENCE. FOR THIS, DATA STRUCTURES OF 'BINARY SEARCH TREES' USED. ENJOY!
*/


// SOS Info! ==> The file of the dictionary MUST have the first line EMPTY! This is to be compatible for the script's format. <=== SOS Info! //

 
typedef char BinTreeElementType[w];
 
typedef struct BinTreeNode *BinTreePointer;
 struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;
 
typedef enum
{ FALSE, TRUE
} boolean;
 
// Create a Binary Search Tre
void CreateBST(BinTreePointer *Root); e.

// Checking if the given (from the user) BST is empty or not.
boolean EmptyBST(BinTreePointer Root); 

// Inserting inside the BST values
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item); 

// Search the BST if it is having a mathcing value with the given (from the user).
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr); 

// Creation of a dictionary (given from the user) as a file.
void dictionary(BinTreePointer *Root); 

/*  
    Finally, checking if the file is equals with the dictionary. If not, their difference will be printed. 
    From the printed data the engineers can understand which part of code or content added from the old version of the file.
*/
void check(BinTreePointer *Root); 
 
int main()
{
 
 
    BinTreePointer Root; 
    CreateBST(&Root); //Creation of the BST root.
    dictionary(&Root); //Creation of the dictionary.
    check(&Root); // Checking the file with the dictionary.
 
    return 0;
}
 
void CreateBST(BinTreePointer *Root)
/* Functionality: Creates an empty BST.
   Return:  The NULL index of Root.
*/
{
    *Root = NULL;
}
 
boolean EmptyBST(BinTreePointer Root)
/* Input:   One BST with the variable 'Root' being the index of its root.
  Functioncality: Checking if the BST is empty.
  Return: TRUE if the BST is empty and FALSE in any other case.
*/
{   return (Root == NULL);
}
 
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
One BST with its index Root aiming in its root and also one variable named KeyValue.
One BST with its index Root aiming in its root and also one variable named KeyValue.
/* Input:   One BST with its index Root aiming in its root and also one variable named Item.
   Functionality:  Insert the variable Item into the BST.
   Return: The modified BST with its 'Root' index aiming in its root.
*/
{
    BinTreePointer LocPtr, Parent;
    boolean Found;
 
    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;
        if (strcmp(Item,LocPtr->Data)==-1)
            LocPtr = LocPtr ->LChild;
        else if (strcmp(Item,LocPtr->Data)==1)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("%s It's already in the tree \n", Item);
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));//Create a specific place, because I know the exactly space that I need.
        strcpy(LocPtr->Data,Item);
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (strcmp(Item,Parent->Data)==-1)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}
 
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
                BinTreePointer *LocPtr)
/* Input:         One BST with its index Root aiming in its root and also one variable named KeyValue.
   Functionality: Searching in the BST for a node which is going to has the value 'KeyValue' in its key field.
   Return:        The variable Found is TRUE and the index LocPtr targeting the node which
                    has the value of 'KeyValue', only if the search is correct.
                    In any other case, the variable Found is going to FALSE
*/
{
 
    (*LocPtr) = Root;
    (*Found) = FALSE;
    while (!(*Found) && (*LocPtr) != NULL)
    {
        if (strcmp(KeyValue,(*LocPtr)->Data)==-1)
            (*LocPtr) = (*LocPtr)->LChild;
        else
            if (strcmp(KeyValue,(*LocPtr)->Data)==1)
                (*LocPtr) = (*LocPtr)->RChild;
            else (*Found) = TRUE;
    }
}
 
void dictionary(BinTreePointer *Root)// Insert the dictionary which is responsible to be compared with the source code file.
{
    FILE *fp;
    char word[w];
 
    fp = fopen("example_file_1.txt","r");// Read the first given file, which must be compared with the dictionary.
    if(fp == NULL)
        printf("Can't open %s\n", "example_file_1.txt");
    else
    {
        while(TRUE)
        {
            if(fgets(word, w, fp) == NULL)
                break;
            BSTInsert(Root, word);
        }
    }
 
    fclose(fp);
}
 
void check(BinTreePointer *Root)// Testify the content of the dictionary concerning the given file.
{
    FILE *fp;
    BinTreePointer LocPtr;
    char word[w];
    boolean found;
 
    fp = fopen("example_file_2.txt", "r");// Read the second file.
    if(fp == NULL)
        printf("Can't open %s\n", "example_file_2.txt");
    else
    {
        while(TRUE)
        {
            if(fgets(word, w, fp) == NULL)
                break;
            BSTSearch(*Root,word, &found, &LocPtr);
            if(found == FALSE)
                printf("%s", word);
                printf("\n\n");
 
        }
    }
 
    fclose(fp);
}
