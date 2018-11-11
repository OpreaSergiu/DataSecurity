#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int text_len, key_len, type, i, j;
char text[100], key[100], right_key[100], result[100];

int main()
{
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
        scanf(" %s", text);
        text_len = strlen(text);
        for(i = 0; i < text_len; ++i)
        {
            if(isalpha(text[i]) == false)
            {
                printf("Please enter only alphabet letters.\n");
                goto loop_text;
            }
        }
        loop_key:
        printf("\nEnter the encryption key: ");
        scanf(" %s", key);
        key_len = strlen(key);
        for(j = 0; j < key_len; ++j)
        {
            if(isalpha(key[j]) == false)
            {
                printf("Please enter only alphabet letters.\n");
                goto loop_key;
            }
        }

        for(i = 0, j = 0; i < text_len; ++i, ++j)
        {
            if(j == key_len)
            {
                j = 0;
            }

            right_key[i] = key[j];
        }

        i = 0;
        while(i < text_len)
        {
            result[i] = ((toupper(text[i]) + toupper(right_key[i])) % 26) + 'A';
            i += 1;
        }

        printf("\nThe plain text was: %s\n", text);
        printf("The encryption key was: %s\n", key);
        printf("The encrypted text is: %s\n", result);
    }
    else if(type==1)
    {
        loop_text1:
        printf("\nEnter the text  to decrypt: ");
        scanf(" %s", text);
        text_len = strlen(text);
        for(i = 0; i < text_len; ++i)
        {
            if(isalpha(text[i]) == false)
            {
                printf("Please enter only alphabet letters.\n");
                goto loop_text1;
            }
        }
        loop_key1:
        printf("\nEnter the decryption key: ");
        scanf(" %s", key);
        key_len = strlen(key);
        for(j = 0; j < key_len; ++j)
        {
            if(isalpha(key[j]) == false)
            {
                printf("Please enter only alphabet letters.\n");
                goto loop_key1;
            }
        }

        for(i = 0, j = 0; i < text_len; ++i, ++j)
        {
            if(j == key_len)
            {
                j = 0;
            }

            right_key[i] = key[j];
        }

        i = 0;
        while(i < text_len)
        {
            result[i] = (((toupper(text[i]) - toupper(right_key[i])) + 26) % 26) + 'A';
            i += 1;
        }

        printf("\nThe encrypted text was: %s\n", text);
        printf("The decryption key was: %s\n", key);
        printf("The decrypted text is: %s\n", result);
    }
}
