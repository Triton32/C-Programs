#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
----------------------------------------------------------
-                        AUTHOR                          -
----------------------------------------------------------
3556408 
Stefan Munnik
----------------------------------------------------------
*/


/*
----------------------------------------------------------
-                        METHOD                          -
----------------------------------------------------------
1. Read in function in main method.

2. Find the function number with function getFunctionNumber
	1 = Append
	2 = InsertAfter
	3 = InsertBefore
	4 = Push
	5 = Remove
	6 = Head
	7 = Tail
	8 = Length
	9 = PrintList

3. Execute function read by calling function executeFunction

4. All the functions, except getFunctionNumber initializes 
   a returnHead pointer node to store the appropriate head 
   node after the function is executed.
   
5. Return head node after running the function and store 
   it inside the head node at function getExecuteFunction.
   
6. Return head node inside getExecuteFunction to update it
   inside the main method.
   
7. Head node gets updated inside main method.

8. Repeat loop for next function readed in.
----------------------------------------------------------
*/


/*
----------------------------------------------------------
-                        FUNCTIONS                       -
----------------------------------------------------------
Function:    struct node* Append(struct node** head, char letter);
Description: Append a node at the end of the list.


Function:    struct node* InsertAfter(struct node** head, char letterAfter, char letterBefore);
Description: Insert variable letterBefore after variable letterAfter 
             in the linked list.


Function:    struct node* InsertBefore(struct node** head, char letterBefore, char letterAfter);
Description: Insert variable letterBefore before variable 
             letterAfter in the linked list.


Function:    struct node* Push(struct node** head, char letter);
Description: Push the letter inside variable letter at the 
             front of the linked list.
	
	    

Function:    struct node* Remove(struct node** head, char letter);
Description: Remove the first instance of the letter inside
	     variable letter.
	 

Function:    struct node* Head(struct node** head);
Description: Print the letter of the head node.
	   

Function:    struct node* Tail(struct node** head);
Description: Print the letter of the node at the end of the 
             linked list.

	   
Function:    struct node* Length(struct node** head);
Description: Print the length of the linked list.

	   
Function:    struct node* PrintList(struct node** head);
Description: Print the entire linked list.

	
Function:    int getFunctionNumber(char* function);
Description: Return the appropriate function number.


Function:    struct node* executeFunction(struct node* head, int function, char letter, char letterTwo);
Description: Execute the appropriate function after
             comparing it to the function numbers.
----------------------------------------------------------
*/


/* Initialize node to be used */
struct node{
    	char data;
    	struct node* next;
};

/*
----------------------------------------------------------
-                        Append                          -
----------------------------------------------------------
Discription:
   	1. If the parameter letter is A.
   	2. Add a node with value A to the end of the list, 
   	   empty or not.
   	3. Return head node.
Input: head node, char letter
Output: head node
Caveats: None
----------------------------------------------------------
*/

struct node* Append(struct node** head, char letter){
    	struct node* presentNode = *head;
    	struct node* returnHead = malloc(sizeof(struct node));
	
	//Initialize node to be appended
    	struct node* insertNode = malloc(sizeof(struct node));
    	insertNode->data = letter;
    	insertNode->next = NULL;

    	if (presentNode == NULL){
        	presentNode = insertNode;
        	*head = presentNode;
    	}else{
    		//Iterate through linked list
        	while (presentNode->next != NULL){
            		presentNode = presentNode->next;
        	}
        	//Add node at the end of the linked list
        	presentNode->next = insertNode;
    	}
    	returnHead = *head;
    	return returnHead;
}

/*
----------------------------------------------------------
-                      InsertAfter                       -
----------------------------------------------------------
Discription:
	1. If parameter letterAfter is A and parameter 
	   letterBefore is B. 
	2. Search the list for the node containing B.
	3. Add a node with value A to the list after the 
	   node containing B.
	4. If B does not exist, print "Input not valid" to
	   stderr.
	5. Return head node.
Input: head node, char letterAfter, char letterBefore
Output: head node, Input not valid
Caveats: If letterBefore not in the list, print "Input not
         valid to stderr"
----------------------------------------------------------
*/

struct node* InsertAfter(struct node** head, char letterAfter, char letterBefore){
    	struct node* returnHead = malloc(sizeof(struct node));
    	struct node* presentNode = *head;

	//Initialize node to be appended
    	struct node* insertNode = malloc(sizeof(struct node));
    	insertNode->data = letterAfter;
    	insertNode->next = NULL;
	
	//Error handling, if letterBefore is not in list, print "Input not valid"
    	int valid = 0;
	while (presentNode != NULL){
		if (presentNode->data == letterBefore){
			valid=1;
			break;
		}else{
			valid=0;
			presentNode = presentNode->next;
		}
	}
	if (valid == 0){
		fprintf(stderr, "Input not valid\n");
		returnHead = *head;
        	return returnHead;
	}
	
	presentNode = *head;
	//If first node is equal to letterBefore, add letterAfter after letterBefore
    	if (presentNode != NULL && (presentNode->data == letterBefore)){
        	insertNode->next= presentNode->next;
        	presentNode->next = insertNode;
    	}else{
    	//Loop till letterBefore is found
        	while (presentNode->data != letterBefore){
            		presentNode = presentNode->next;
        	}
        //If letterBefore is found, add letterAfter after letterBefore
        	insertNode->next= presentNode->next;
        	presentNode->next = insertNode;
    	}

    	returnHead = *head;
    	return returnHead;
}

/*
----------------------------------------------------------
-                     InsertBefore                       -
----------------------------------------------------------
Discription:
	1. If parameter letterBefore is A and parameter 
	   letterAfter is B.
	2. Search the list for the node containing B.
	3. Add a node with value A to the list before the 
	   node containing B.
	4. If B does not exist, print "Input not valid" to
	   stderr.
	5. Return head node.
Input: head node, char letterBefore, char letterAfter
Output: head node, Input not valid
Caveats: If letterAfter not in the list, print "Input not
         valid to stderr"
----------------------------------------------------------
*/

struct node* InsertBefore(struct node** head, char letterBefore, char letterAfter){
    	struct node* returnHead = malloc(sizeof(struct node));
    	struct node* presentNode = *head;

	//Initialize node to be appended
    	struct node* insertNode = malloc(sizeof(struct node));
    	insertNode->data = letterBefore;
    	insertNode->next = NULL;

	//Error handling, if letterAfter is not in list, print "Input not valid"
    	int valid = 0;
	while (presentNode != NULL){
		if (presentNode->data == letterAfter){
			valid=1;
			break;
		}else{
			valid=0;
			presentNode = presentNode->next;
		}
	}
	if (valid == 0){
		fprintf(stderr, "Input not validd\n");
		returnHead = *head;
        	return returnHead;
	}

	presentNode = *head;
	//If first node is equal to letterAfter, add letterBefore before letterAfter
    	if (presentNode->data == letterAfter){
        	insertNode->next = *head;
    		*head = insertNode;
    	}else{
    	//Loop till letterAfter is found
        	while (presentNode->next->data != letterAfter){
           		presentNode = presentNode->next;
        	}
        //If letterAfter is found, add letterBefore before letterAfter
        	insertNode->next= presentNode->next;
        	presentNode->next = insertNode;
    	}

    	returnHead = *head;
    	return returnHead;
}

/*
----------------------------------------------------------
-                          Push                          -
----------------------------------------------------------
Discription:
	1. If the parameter letter is A.
	2. Push a node with value A to the front of the
	   list.
	3. Return head node.
Input: head node, char letter
Output: head node
Caveats: None
----------------------------------------------------------
*/

struct node* Push(struct node** head, char letter){
    	struct node* presentNode = malloc(sizeof(struct node));
	struct node* returnHead = malloc(sizeof(struct node));
	
	//Push letter onto the list and make it the first node
    	presentNode->data = letter;
    	presentNode->next = *head;
    	*head = presentNode;

    	returnHead = *head;
    	return returnHead;
}

/*
----------------------------------------------------------
-                        Remove                          -
----------------------------------------------------------
Discription:
	1. If the parameter letter is A.
	2. Search the list for the first instance of A.
	3. Remove the node containing A.
	4. If A is not in the list, print "Input not
	   valid" to stderr.
	5. Return head node.
Input: head node, char letter
Output: head node, Input not valid
Caveats: Print "Input not valid" if letter not in list
----------------------------------------------------------
*/

struct node* Remove(struct node** head, char letter){
    	struct node* presentNode = *head;
	struct node* previousNode;
	struct node* returnHead = malloc(sizeof(struct node));
	
	//Error handling, if letter is not in list, print "Input not valid"
	int valid = 0;
	while (presentNode != NULL){
		if (presentNode->data == letter){
			valid=1;
			break;
		}else{
			valid=0;
			presentNode = presentNode->next;
		}
	}

	if (valid == 0){
		fprintf(stderr, "Input not valid\n");
		returnHead = *head;
        return returnHead;
	}

	presentNode = *head;
	//Remove the first node if the data inside the node is equal to letter
	if (presentNode != NULL && presentNode->data == letter){
        	*head = presentNode->next;
        	free(presentNode);
        	returnHead = *head;
        	return returnHead;
    	}
    	//Search for the node containing letter
	while (presentNode != NULL && presentNode->data != letter){
        	previousNode = presentNode;
        	presentNode = presentNode->next;
	}
	//Remove the node after searched for it
	previousNode->next = presentNode->next;
	free(presentNode);

	returnHead = *head;
	return returnHead;
}

/*
----------------------------------------------------------
-                         Head                           -
----------------------------------------------------------
Discription:
	1. Display the first node of the list.
	2. If there is no head, print "Input not valid"
	   to stderr.
	3. Return head node.
Input: head node
Output: head node, Input not valid
Caveats: Print "Input not valid" if there is no first
         node
----------------------------------------------------------
*/

struct node* Head(struct node** head){
    	struct node* presentNode = *head;
	struct node* returnHead = malloc(sizeof(struct node));
    	if (*head != NULL){
    	//If the head is not null, print the head node
        	printf("%c\n", presentNode->data);
    	}else{
    	//If the head is null, print "Input not valid"
        	fprintf(stderr, "Input not valid\n");
    	}
    	returnHead = *head;
    	return returnHead;
}

/*
----------------------------------------------------------
-                         Tail                           -
----------------------------------------------------------
Discription:
	1. Iterate to the last node in the list.
	2. Display the last node of the list.
	3. If there is no tail, print "Input not valid"
	   to stderr.
	4. Return head node.
Input: head node
Output: head node, Input not valid
Caveats: Print "Input not valid" if there is no node
         in the list
----------------------------------------------------------
*/

struct node* Tail(struct node** head){
    	struct node* presentNode = *head;
	struct node* returnHead = malloc(sizeof(struct node));
    	if (*head != NULL){
    	    	//Iterate to find the end of the list
        	while (presentNode->next != NULL){
            		presentNode = presentNode->next;
        	}
        	//Print last node if end of list is reached
        	printf("%c\n", presentNode->data);
    	}else{
        	fprintf(stderr, "Input not valid\n");
    	}
    	returnHead = *head;
    	return returnHead;
}

/*
----------------------------------------------------------
-                         Length                         -
----------------------------------------------------------
Discription:
	1. Initialize a counter.
	2. Loop through linked list while incriminting 
	   counter.
	3. Print out the counter.
	4. Return head node.
Input: head node
Output: head node, length
Caveats: None
----------------------------------------------------------
*/

struct node* Length(struct node** head){
	struct node* presentNode = *head;
	struct node* returnHead = malloc(sizeof(struct node));
    	int counter = 0;
    	//Print zero if list is empty
    	if (presentNode == NULL){
		printf("%d\n", counter);
    	}else{
    	//Iterate through list till end and incriment counter
		while (presentNode != NULL){
			presentNode = presentNode->next;
         		counter++;
        	}
       	//Print list length
        printf("%d\n", counter);
    	}
    	returnHead = *head;
    	return returnHead;
}

/*
----------------------------------------------------------
-                       PrintList                        -
----------------------------------------------------------
Discription:
	1. Iterate through the list with a while loop.
	2. Print every character with hyphens between
	   the data values.
	3. If the list is empty, it just prints a
	   hyphen.
	4. Return head node.
Input: head node
Output: head node, linked list
Caveats: None
----------------------------------------------------------
*/

struct node* PrintList(struct node** head){
    	struct node* presentNode = *head;
	struct node* returnHead = malloc(sizeof(struct node));
	//Print "-" if list is empty
	if (presentNode == NULL){
		printf("-");
	}else{
		//Iterate through list and print nodes
		while (presentNode != NULL){
			printf("%c",presentNode->data);
			presentNode = presentNode->next;
			if(presentNode!=NULL){
				printf("-");
			}
		}
	}
	printf("\n");
    	returnHead = *head;
    	return returnHead;
}

/*
----------------------------------------------------------
-                    getFunctionNum                      -
----------------------------------------------------------
Discription:
	1. Function is read in at the main method and 
	   stored inside parameter function.
	2. Compare the function to strings initialized.
	3. Return the appropriate number for the function.
Input: function
Output: appropriate function number
Caveats: None
----------------------------------------------------------
*/

int getFunctionNumber(char* function){
	//Define appropriate strings
    	char* Append = "Append";
    	char* InsertAfter = "InsertAfter";
    	char* InsertBefore = "InsertBefore";
    	char* Push = "Push";
    	char* Remove = "Remove";
    	char* Head = "Head";
    	char* Tail = "Tail";
    	char* Length = "Length";
    	char* PrintList = "PrintList";
    	//Compare function to strings
    	//Return appropriate number of function
    	if (strcmp(function,Append) == 0){
        	return 1;
    	}else if (strcmp(function,InsertAfter) == 0){
        	return 2;
    	}else if (strcmp(function,InsertBefore) == 0){
        	return 3;
    	}else if (strcmp(function,Push) == 0){
        	return 4;
    	}else if (strcmp(function,Remove) == 0){
        	return 5;
    	}else if (strcmp(function,Head) == 0){
        	return 6;
    	}else if (strcmp(function,Tail) == 0){
        	return 7;
    	}else if (strcmp(function,Length) == 0){
        	return 8;
    	}else if (strcmp(function,PrintList) == 0){
        	return 9;
    	}
    	return 0;
}

/*
----------------------------------------------------------
-                    executeFunction                     -
----------------------------------------------------------
Discription:
	1. Execute appropriate function by comparing it
	   to the return value of function getFunctionNum
	2. Store inside the head node inside variable
	   head after function is executed.
	3. Return head node.
Input: head node, int function (function number),
       char letter, char letterTwo
Output: head node
Caveats: -If function is invalid, print "Input not valid"
         -If letter is not between A and Z for functions
          1-5, print "Input not valid"
----------------------------------------------------------
*/

struct node* executeFunction(struct node* head, int function, char letter, char letterTwo){
	//See which function needs to be executed with if statements
	//Functions 1-5 letters has to be between A and Z
    	if (function == 1 && (letter >= 'A' && letter <= 'Z')){
        	head = Append(&head, letter);
        	return head;
    	}else if (function == 2 && (letter >= 'A' && letter <= 'Z') && (letterTwo >= 'A' && letterTwo <= 'Z')){
        	head = InsertAfter(&head, letter, letterTwo);
        	return head;
    	}else if (function == 3 && (letter >= 'A' && letter <= 'Z') && (letterTwo >= 'A' && letterTwo <= 'Z')){
        	head = InsertBefore(&head, letter, letterTwo);
        	return head;
    	}else if (function == 4 && (letter >= 'A' && letter <= 'Z')){
        	head = Push(&head, letter);
        	return head;
    	}else if (function == 5 && (letter >= 'A' && letter <= 'Z')){
        	head = Remove(&head, letter);
        	return head;
    	}else if (function == 6){
        	head = Head(&head);
        	return head;
    	}else if (function == 7){
        	head = Tail(&head);
        	return head;
    	}else if (function == 8){
        	head = Length(&head);
        	return head;
    	}else if (function == 9){
        	head = PrintList(&head);
        	return head;
    	}else{
    		//Print "Input not valid" if function is 0
        	fprintf(stderr, "Input not valid\n");
        	return head;
    	}
}

/*
----------------------------------------------------------
-                         main                           -
----------------------------------------------------------
Discription:
	1. Read each line in testfiles.
	2. Get appropriate function number with function
	   getFunctionNum
	3. Execute the function with function
	   executeFunction
	4. Print "Input not valid" if line or file is
	   equal to NULL
Input: argc (not used), argv[] (File)
Output: 0
Caveats: Print "Input not valid" if line or file is
	 equal to NULL
----------------------------------------------------------
*/

int main(int argc, char* argv[]){

    	struct node* head = NULL;
	
	//Read in the file
    	const char* file = argv[1];
    	FILE* functionFile = fopen(file, "r");
    	
    	//Define appropriate variables
    	const char* space = " ";
    	const char* spacesTwo = " \n";
    	char functionLine[100];
    	//If file is not null, continue
    	if (functionFile != NULL){
    		//Loop through every line
        	while(fgets(functionLine, 100, functionFile)){
        		//Read function into variable function
            		char* function = strtok(functionLine, spacesTwo);
            		if (function == NULL){
                		fprintf(stderr, "Input not valid\n");
                		continue;
            		}
            		//Get appropriate function number
            		int functionNum = getFunctionNumber(function);
            		//Read in first letter
            		char* letter = strtok(NULL, space);

            		char charLetter;
            		char charLetterTwo;

            		char* letterTwo;
            		//If first and second letter not equal NULL
            		if (letter != NULL){
                		charLetter = *letter;
                		//Read in second letter
                		letterTwo = strtok(NULL, space);
                		if (letterTwo != NULL){
                    			charLetterTwo = *letterTwo;
                		}
            		}else{
            			//Prepare letters for executeFunction
                		letter = "";
                		letterTwo = "";
                		charLetter = *letter;
                		charLetterTwo = *letterTwo;
            		}
            		head = executeFunction(head, functionNum, charLetter, charLetterTwo);
        	}
        fclose(functionFile);
    }else{
        fprintf(stderr, "Input not valid\n");
    }
    return 0;
}
