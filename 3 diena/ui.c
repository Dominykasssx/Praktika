#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "program.h"


void print_usage()
{
	printf("\nAvailable commands:\n");
	printf("v is for view all persons\n");
	printf("a is for add person in the end of list\n");
	printf("p is for add person in specific position\n");
	printf("e is for delete one person from list in position\n");
	printf("d is for delete all persons from list\n");
	printf("f is for find person from position in list\n");
	printf("g is for find person from list by name, surname, email or phone number\n");
	printf("c for commands\n");
	printf("q for exit\n");
}

void actions(char operator, struct Person **list)
{
	char a[30], b[30], c[30], d[30], e[30];
	struct Person *person = NULL;
	switch(operator) {
			case 'v':
				print_list(*list);
				break;
			case 'a':
				printf("Enter name: ");
				scanf("%s", &a);
				printf("Enter surname: ");
				scanf("%s", &b);
				printf("Enter phone number: ");
				scanf("%s", &c);
				printf("Enter email: ");
				scanf("%s", &d);
				printf("%s %s %s %s\n", a,b,c,d);
				
				person = create_node(a,b,c,d);
				if (person != NULL) {
				   add_to_list(list, person);
				}
				break;
			case 'd':
				delete_list(list);
				
				break;
			case 'p':
				printf("Enter name: ");
				scanf("%s", &a);
				printf("Enter surname: ");
				scanf("%s", &b);
				printf("Enter phone number: ");
				scanf("%s", &c);
				printf("Enter email: ");
				scanf("%s", &d);
				printf("Enter postition: ");
				scanf("%s", &e);
				printf("%s %s %s %s %s\n", a,b,c,d,e);
			
				person = create_node(a,b,c,d);
				if (person != NULL) {
				add_to_list_position(list, person, atoi(e));
				}
				break;
			case 'e':
				printf("Enter position: ");
				scanf("%s", &a);
				deleteByPosition(list,atoi(a));
				break;
			case 'f':
				printf("Enter position: ");
				scanf("%s", &a);
				findByPosition(*list,atoi(a));
				break;
			case 'g':
				printf("Search by text: ");
				scanf("%s", &a);
				findByText(*list,a);
				break;
			case 'c':
				print_usage();
				break;
			case '\n':
				break;
			default:
				printf("Command not found\n");
		}
}



int main(void)
{
char address_file_path[30] = "addresses.csv";
    struct Person *list = NULL;
    FILE *address_file = NULL;
    address_file = fopen(address_file_path, "r");
    if( address_file == NULL) {
        printf("Unable to open file\n");
        exit(1);
    }

    load_addresses(address_file, &list);
	print_start(list);
	print_usage();
	
	char operator;
	printf("Enter command: ");
	while((operator = getchar()) != '0') {
		if (operator == 'q')
		{
			delete_list(&list);
			break;
		}
		if (operator != '\n') {
			actions(operator, &list);
			printf("\nEnter command: ");
		}
	}
    return 0;
}