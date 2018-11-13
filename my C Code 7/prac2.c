#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char data;
    struct node* next;
};

struct node* Push(struct node* head, char letter){
    struct node* currentNode = malloc(sizeof(struct node));

    currentNode->data = letter;
    currentNode->next = head;
    head = currentNode;
    return head;
}

struct node* Remove(struct node* head, char letter){
    struct node* presentNode = head;
	struct node* previousNode;
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
        	return head;
	}
	presentNode = head;
	if (presentNode != NULL && presentNode->data == letter){
        	head = presentNode->next;
        	free(presentNode);
        	return head;
    	}
	while (presentNode != NULL && presentNode->data != letter){
        	previousNode = presentNode;
        	presentNode = presentNode->next;

	}
	previousNode->next = presentNode->next;
	free(previousNode);
	free(presentNode);
	return head;
}

struct node* Head(struct node* head){
    struct node* currentNode = head;
    if (head != NULL){
        printf("%c\n", currentNode->data);
    }else{
        fprintf(stderr, "Input not valid\n");
    }
    return head;
}

struct node* Tail(struct node* head){
    struct node* currentNode = head;
    if (head != NULL){
        while (currentNode->next != NULL){
            currentNode = currentNode->next;
        }
        printf("%c\n", currentNode->data);
    }else{
        fprintf(stderr, "Input not valid\n");
    }
    return head;
}

struct node* Length(struct node* head){
    struct node* currentNode = head;
    int counter = 0;
    if (currentNode == NULL){
        printf("%d\n", counter);
    }else{
        while (currentNode != NULL){
            currentNode = currentNode->next;
            counter++;
        }
        printf("%d\n", counter);
    }
    return head;
}

struct node* PrintList(struct node* head){
    struct node* presentNode = head;

	if (presentNode == NULL){
		printf("-");
	}else{
		while (presentNode != NULL){
			printf("%c",presentNode->data);
			presentNode = presentNode->next;
			if(presentNode!=NULL){
				printf("-");
			}
		}
	}
	printf("\n");
	return head;
}

int getFunctionNumber(char* function){
    char* Push = "Push";
    char* Remove = "Remove";
    char* Head = "Head";
    char* Tail = "Tail";
    char* Length = "Length";
    char* PrintList = "PrintList";
    if (strcmp(function,Push) == 0){
        return 1;
    }else if (strcmp(function,Remove) == 0){
        return 2;
    }else if (strcmp(function,Head) == 0){
        return 3;
    }else if (strcmp(function,Tail) == 0){
        return 4;
    }else if (strcmp(function,Length) == 0){
        return 5;
    }else if (strcmp(function,PrintList) == 0){
        return 6;
    }
    return 0;
}

struct node* executeFunction(struct node* head, int function, char letter){
    if (function == 1 && (letter >= 'A' && letter <= 'Z')){
        head = Push(head, letter);
        return head;
    }else if (function == 2 && (letter >= 'A' && letter <= 'Z')){
        head = Remove(head, letter);
        return head;
    }else if (function == 3){
        head = Head(head);
        return head;
    }else if (function == 4){
        head = Tail(head);
        return head;
    }else if (function == 5){
        head = Length(head);
        return head;
    }else if (function == 6){
        head = PrintList(head);
        return head;
    }else{
        fprintf(stderr, "Input not valid\n");
        return head;
    }
}

int main(int argc, char* argv[]){

    struct node* head = NULL;

    const char* file = argv[1];
    const char* space = " ";
    const char* spaces2 = " \n";
            FILE* functionFile = fopen(file, "r");
            char functionLine[100];
              if (functionFile != NULL){
                while(fgets(functionLine, 100, functionFile)){
                    char* function = strtok(functionLine, spaces2);
                    char* letter = strtok (NULL, space);
                    if (letter == NULL){
                        letter = ""; 
                    }
                    if (function == NULL){
                        fprintf(stderr, "Input not valid\n");
                        continue;
                    }
                    char charLetter = *letter;
                    int functionNum = getFunctionNumber(function);
                    head = executeFunction(head, functionNum, charLetter);
                }
        fclose(functionFile);
    }else{
        fprintf(stderr, "Input not valid\n");
    }
    return 0;
}
