#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DELIMETER ","

struct Person {
    char name[30];
    char surname[30];
    char number[30];
	char email[30];
    struct Person *next;
};

struct Person* create_node(char *name, char *surname, char *number, char *email);
struct Person* create_address_node(char *address_line);
void add_to_list(struct Person **list, struct Person *node);
void print_list(struct Person *list);
void delete_list(struct Person **list);
void load_addresses(FILE *file, struct Person **list);
void print_start(struct Person *list);
void add_to_list_position(struct Person **list, struct Person *person, int position);
void findByPosition(struct Person *list, int position);
void findByText(struct Person *list, char text[30]);
void deleteByPosition(struct Person **list, int position);

void load_addresses(FILE *file, struct Person **list)
{
    char line[128];
    while (fgets(line, sizeof(line), file)) {
		strtok(line, "\r");
        struct Person *person = NULL;
        if(strcmp(line, "\n") == 0) {
			break;
        }
        person = create_address_node(line);
        if (person != NULL) {
            add_to_list(list, person);
        }
    }
}

struct Person* create_address_node(char *address_line)
{
    struct Person *person = NULL;
    char *name;
    char *surname;
    char *number;
	char *email;

    name = strtok(address_line, DELIMETER);
    surname = strtok(NULL, DELIMETER);
    number = strtok(NULL, DELIMETER);
	email = strtok(NULL, DELIMETER);

    person = create_node(name, surname, number, email);
    
    return person;
}

struct Person* create_node(char *name, char *surname, char *number, char *email)
{
    struct Person *person = NULL;
    person = (struct Person*) malloc(sizeof(struct Person));
    if (person == NULL) {
        return NULL;
    }
    strcpy(person->name, name);
    strcpy(person->surname, surname);
    strcpy(person->number, number);
	strcpy(person->email, email);
    person->next = NULL;
    return person;
}

void add_to_list(struct Person **list, struct Person *person)
{
    struct Person* temp = *list;
    if (temp == NULL) {
        *list = person;
        return; 
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = person;
}
void add_to_list_position(struct Person **list, struct Person *person, int position)
{
	
	int i = 0;
    struct Person *previous;
	struct Person *current;
	struct Person *new;
	
	
    new= person;
	
	previous = NULL;
	
	if (position < 0) {
    printf("ERROR - position number is too low");
    return;
    }
	
	for (current = *list;  current != NULL;  current = current->next, i += 1) {
        if (i >= position)
            break;
        previous = current;
    }
	
	new->next = current;
	
	if (previous != NULL)
        previous->next = new;
    else
        *list = new;
	if (position >= i) {
    printf("Added to end of list");
    }
}


void print_list(struct Person *list)
{
	int i = 0;
    struct Person *temp = list;
    while (temp != NULL) {
        printf("%s %s %s %s \n", temp->name, temp->surname, temp->number, temp->email);
        temp = temp->next;
		i++;
    }
	if (i>0)
	{
		printf("Successfully printed list");
	}
	else
	{
		printf("List is empty");
	}
}

void print_start(struct Person *list)
{
	int i = 0;
    struct Person *temp = list;
    while (temp != NULL && i < 10) {
        printf("%s %s %s %s \n", temp->name, temp->surname, temp->number, temp->email);
        temp = temp->next;
		i++;
    }
}

void delete_list(struct Person **list) 
{
	struct Person *to_delete = *list;
    while (*list != NULL) 
	{
        *list = (*list)->next;
        free(to_delete);
        to_delete = *list;
    }
	if (*list == NULL)
	{
		printf("Successfully deleted all persons from list");
	}
}

void findByPosition(struct Person *list, int position)
{
	int found = -1;
	int i = 0;
    struct Person *temp = list;
	if (position < 0) {
    printf("ERROR - position number is too low");
    return;
    }
    while (temp != NULL) {
		if(i == position)
        {
			printf("%s %s %s %s \n", temp->name, temp->surname, temp->number, temp->email);
			found = 1;
			break;
		}
        temp = temp->next;
		i++;
    }
	if (found == -1)
	{
		printf("ERROR - position number is too high");
	}	
}

void findByText(struct Person *list, char text[30])
{
	int found = -1;
	int i = 0;
    struct Person *temp = list;
    while (temp != NULL) {
		if(strcmp(temp->name,text) == 0 || strcmp(temp->surname,text) == 0|| strcmp(temp->number,text)== 0|| strcmp(temp->email,text)== 0)
        {
			printf("%s %s %s %s \n", temp->name, temp->surname, temp->number, temp->email);
			found = 1;
		}
        temp = temp->next;
		i++;
    }
	if (found == -1)
	{
		printf("Search didn't find anything");
	}
		
}

void deleteByPosition(struct Person **list, int position) 
{
	int i = 0;
	struct Person *to_delete = *list;
	
	if (position < 0) {
    printf("ERROR - position number is too low");
    return;
    }
	
	if (position == 0) {
    *list = to_delete->next; 
    free(to_delete);
    return;
    }
	for (int i = 0; to_delete != NULL && i < position - 1; i++)
        to_delete = to_delete->next;
	
	if (to_delete == NULL || to_delete->next == NULL)
	{
		printf("ERROR - position number is too high");
		return;
	}
        
	struct Person *next = to_delete->next->next;
    free(to_delete->next); 
    to_delete->next = next; 
}
