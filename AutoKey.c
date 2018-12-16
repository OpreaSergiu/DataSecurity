#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <conio.h>
#include <math.h>

#define VAL(PTR) (*PTR)

typedef char* STRING;
typedef char** STRING_REF;

void autokey_encrypt_decrypt(STRING_REF str, char key, int encrypt){
	int str_length, itr_str, next_key,current_key, remainder;
	str_length = strlen(VAL(str));
	for(itr_str = 0 ; itr_str < str_length ; ++itr_str){
		if(isalpha(VAL(str)[itr_str])){
			VAL(str)[itr_str] = toupper(VAL(str)[itr_str]);
		}
	}
	next_key = toupper(key)-'A';
	for(itr_str = 0 ; itr_str < str_length ; ++itr_str){
		if(isalpha(VAL(str)[itr_str])){
			current_key = next_key;
			if(encrypt){
				next_key = VAL(str)[itr_str]-'A';
				VAL(str)[itr_str] = (VAL(str)[itr_str]-'A'+current_key)%26+'A';
			}
			else{
				remainder = (VAL(str)[itr_str]-'A'-current_key)%26+'A';
				VAL(str)[itr_str] = remainder < 'A' ? remainder + 26 : remainder ;
				next_key = VAL(str)[itr_str]-'A';
			}
		}
	}
}

void flush_stdin()
{
	while(fgetc(stdin) != '\n');
}

int main()
{
    int i, j, lenText, lenKey;
    char str[100], key[100], finalKey[100], intitial_str[100], type;
    char *str1;

    printf("Chose an option: \n");
    printf("0 - Encrypt \n");
    printf("1 - Decrypt \n");
    scanf(" %d", &type);

    while((type < 0) || (type > 1))
    {
        printf("Wrong option! %d \n",type);
        printf("Chose an option: \n");
        printf("0 - Encrypt \n");
        printf("1 - Decrypt \n");
        scanf("%d", &type);
    }

    if(type==0)
    {
        loop_text:
        printf("\nEnter the text to encrypt: ");
        scanf(" %s", str);
        lenText = strlen(str);
        for(i = 0; i < lenText; ++i)
        {
            if(isalpha(str[i]) == false)
            {
                printf("Please enter only alphabet letters.\n");
                goto loop_text;
            }
        }

        loop_key:
        printf("\nEnter the encryption key: ");
        scanf(" %s", key);
        lenKey = strlen(key);
        for(j = 0; j < lenKey; ++j)
        {
            if(isalpha(key[j]) == false)
            {
                printf("Please enter only alphabet letters.\n");
                goto loop_key;
            }
        }

        for(i = 0; i < lenText; ++i)
            intitial_str[i] = str[i];

        str1 = (char*)malloc((lenText+1)*sizeof(char));
        str1 = str;


        autokey_encrypt_decrypt(&str1,key,1);

        printf("\nThe plain text was: %s\n", intitial_str);
        printf("The encryption key was: %s\n", key);
        printf("The encrypted  text is: %s\n", str1);
    }
    else if(type==1)
    {
        loop_text1:
        printf("\nEnter the text to decrypt: ");
        scanf(" %s", str);
        lenText = strlen(str);
        for(i = 0; i < lenText; ++i)
        {
            if(isalpha(str[i]) == false)
            {
                printf("Please enter only alphabet letters.\n");
                goto loop_text1;
            }
        }
        loop_key1:
         printf("\nEnter the decryption key: ");
        scanf(" %s", key);
        lenKey = strlen(key);
        for(j = 0; j < lenKey; ++j)
        {
            if(isalpha(key[j]) == false)
            {
                printf("Please enter only alphabet letters.\n");
                goto loop_key1;
            }
        }

        for(i = 0; i < lenText; ++i)
            intitial_str[i] = str[i];


        str1 = (char*)malloc((lenText+1)*sizeof(char));
        str1 = str;

        autokey_encrypt_decrypt(&str1,key,0);

        printf("\nThe encrypted  text was: %s\n", intitial_str);
        printf("The decryption key was: %s\n", key);
        printf("The decrypted text is: %s\n", str1);
    }
}
