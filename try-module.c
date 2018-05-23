// DEVELOPED by wil.tor

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// gcc -m32 -fno-stack-protector -no-pie -no-relro -z noexecstack -o trymodule trymodule.c
#define BUFF_SIZE 25


// User struct type 
typedef struct user {
	int total;
	int identifiant;
	double phone_nomber;
	char *name;
};
struct user user_t;


int try_action(char *input);
void welcome_message();
void welcome_message()
{
	system("clear");
	printf("+------------------------------+\n");
	printf("|                              |\n");
	printf("|   NORDEA BANK | try module   |\n");
	printf("|                              |\n");
	printf("+------------------------------+\n");
	printf("                   Board: v0.01\n");
	puts("This program is in developement\n\n");
}

int try_action(char *input)
{
	user_t.name = (char*)malloc(sizeof(BUFF_SIZE)*1);
	user_t.name = "william";
	user_t.identifiant = 66;
	user_t.phone_nomber = 118;

	while(1)
	{
		if(strcmp(input, user_t.name) == 0)
	    {
	    	return 0;
	    } else 
	    {  
	    	return -1;
	    }
	}
}

int main(int argc, char **argv)
{
	welcome_message();

	if(argc != 2)
	{
		puts("Format: ./try-module <str>\n");
		exit(1);
	}
	char buffer[32];
	strcpy(buffer, argv[1]);

	printf("[~] Searching %s in our database ...\n", buffer); 
	sleep(2);

	if(try_action(buffer) == 0)
	{
		printf("[+] We found a %s in our database\n", buffer);
		printf("\nInformations: \n");
		printf("Name: %s\n", user_t.name);
		printf("Phone: %d\n", user_t.phone_nomber);
		printf("Identifiant: %d\n\n", user_t.identifiant);
	} else 
	{
		printf("[-] We not found a %s in our database\n", buffer);
	}

	return 0;
}
