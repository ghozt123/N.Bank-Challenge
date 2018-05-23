// DEVELOPED by wil.tor

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

// Compilation: gcc -fstack-protector-all -D_FORTIFY_SOURCE=2 -Wl,-z,now -Wl,-z,relro,-z,noexecstack -o program program.c


#define BUFF_SIZE 25 // Size for any buffer


// Colors ...
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"
#define BOLD    "\033[1m"


// Account struct type
typedef struct account {
	unsigned int balance;
	char * user_id;
	char *first_name;
	char *last_name;
};

struct account account_t; 


void program();
void welcome_message();
void welcome_message()
{
	system("clear");
	printf("+--------------------------------------+\n");
	printf("|                                      |\n");
	printf("|   NORDEA BANK | management program   |\n");
	printf("|                                      |\n");
	printf("+--------------------------------------+\n");
	puts("                          Board: v0.1\n\n");
}

void create_action()
{
	welcome_message();

	account_t.last_name = (char*)malloc(sizeof(BUFF_SIZE)*1);
	account_t.first_name = (char*)malloc(sizeof(BUFF_SIZE)*1);
	account_t.user_id = (char*)malloc(sizeof(BUFF_SIZE)*1);
	account_t.balance = 0;

	printf("[~] Last name: ");
	scanf("%s", account_t.last_name);

	printf("[~] First name: ");
	scanf("%s", account_t.first_name);

	// Generate id

	static char generate_key_charset[] = "893642510"; 
	size_t len = 10;

	if (len) {

		account_t.user_id = malloc(len +1);
		if (account_t.user_id) {
        int l = (int) (sizeof(generate_key_charset) -1);
        int key;  
        for (int n = 0;n < len;n++) {        
            key = rand() % l;  
            account_t.user_id[n] = generate_key_charset[key];
        }

        account_t.user_id[len] = '\0';
    }
   // End of generate id 

    if(account_t.user_id == "") 
    {
    	puts("[SIG_ERR0R] : Problem 8|");
    }
}

     printf("\n[~] Your account was created !\n######## Identifiant: %s", account_t.user_id);
     puts("\n\nPlease wait ...");
     sleep(2);

     program();
}

void display_action()
{
	welcome_message();

	if(account_t.user_id == 0 || account_t.first_name == 0 || account_t.last_name == 0) 
	{
		puts("[SIG_ERR0R] : No account found\n");
		exit(1);
	}

	printf("######## Account num.: %s ########\n\n", account_t.user_id);
	printf("[+] Last name: %s\n", account_t.last_name);
	printf("[+] First name: %s", account_t.first_name);
	printf("\n[+] Total : %d$", account_t.balance);
	puts("\n\nPlease wait ...");
	sleep(3);

	program();
}

void login_action()
{
	welcome_message();

	if(account_t.user_id == 0 || account_t.first_name == 0 || account_t.last_name == 0) 
	{
		puts("[SIG_ERR0R] : No account found\n");
		exit(1);
	}
	char buffer[BUFF_SIZE+1];

	printf(RED"[~] Developer identifiant: "RESET BOLD);
	scanf("%s", &buffer);

	// Generate id

	char *random_key = (char*)malloc(sizeof(BUFF_SIZE)*1);
	char charset[] = "2413867095"; 
	size_t strlen = 25;

	if (strlen) {

		random_key = malloc(strlen +1);
		if (random_key) {
        int l = (int) (sizeof(charset) -1);
        int strkey;  
        for (int n = 0;n < strlen;n++) {        
            strkey = rand() % l;  
            random_key[n] = charset[strkey];
        }

        random_key[strlen] = '\0';
    }
}
    // End of generate id 

    if (ptrace(PTRACE_TRACEME,0,1,0) == -1)
	{
		puts("Don't debug me !");
		exit(1);
	}
	
    if(strcmp(buffer, random_key) == 0)
    {
    	puts("\n[+] Welcome back developer c:\n");
    	exit(1);
    } else 
    {
    	puts("\n[-] Sorry no similary identifiant found\n");
    }
    sleep(2);

    program();
}

void deposit_action()
{
	welcome_message();

	if(account_t.user_id == 0 || account_t.first_name == 0 || account_t.last_name == 0) 
	{
		puts("[SIG_ERR0R] : No account found\n");
		exit(1);
	}

	printf("[~] Amount to deposit: \t");
	scanf("%d", &account_t.balance);

	if(account_t.balance > 100 || account_t.balance <= 0) 
	{
		puts("\n[SIG_ERR0R] : Value is too high or too low\n");
		exit(1);
	}
	printf("\n[+] You have just deposited %d$ in your account", account_t.balance);
	puts("\nPlease wait ...");
	sleep(2);
	
	program();
}

void remove_action()
{
	welcome_message();

	if(account_t.user_id == 0 || account_t.first_name == 0 || account_t.last_name == 0) 
	{
		puts("[SIG_ERR0R] : No account found\n");
		exit(1);
	}
	int remove_buffer;

	printf("[~] Amount to remove: \t");
	scanf("%d", &remove_buffer);

	account_t.balance -= remove_buffer;
	if(remove_buffer < 0 || remove_buffer > 100 || remove_buffer <= 0)
	{
		puts("\n[SIG_ERR0R] : Value is too high or too low\n");
		exit(1);
	}
	printf("You have just removed %d$ in your account", remove_buffer);
	puts("\nPlease wait ...");
	sleep(2);

	program();
}

void program()
{
	welcome_message();

	int buf;
	printf("1. Create account\n");
	printf("2. Display account\n");
	printf("3. Developer account\n"); // Developer(s) account
	printf("4. - Deposit\n");
	printf("5. - Remove\n\n");

	printf("Give me the operation number : \t");
	scanf("%s", &buf);

	switch(buf) 
	{
		case '1':
		create_action();
		break;

		case '2':
		display_action();
		break;

		case '3':
		login_action();
		break;

		case '4':
		deposit_action();
		break;

		case '5':
		remove_action();
		break;

		default:
		puts("\n\n[SIG_ERR0R] : Please give me a valid operation number.\n");
		exit(1);
	}
}

int main()
{
	program();

	return 0;
}
