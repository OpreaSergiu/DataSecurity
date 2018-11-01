#include <stdio.h>
#include <string.h>
int main()
{
    char text[100], ch;

    int type, key, i=0, length;

    printf("Enter the text: ");
    gets(text);

    printf("Chose an option: \n");
    printf("0 - Encrypt \n");
    printf("1 - Decrypt \n");
    scanf("%d", &type);

    while((type < 0) || (type > 1))
    {
        printf("Wrong option! %d \n",type);
        printf("Chose an option: \n");
        printf("0 - Encrypt \n");
        printf("1 - Decrypt \n");
        scanf("%d", &type);
    }

    printf("Enter the key: \n");
    scanf("%d", &key);

    if(type == 0)
    {
        length = strlen(text);
        for(i = 0; i<= length; i++)
        {
            if((text[i] >= 65)&&(text[i] <= 90))
            {
                ch = text[i] + key;
                if(ch > 90)
                {
                    ch = ch % 90 + 64;
                }
                printf("%c",ch);
            }
            else if((text[i] >= 97)&&(text[i] <= 122))
            {
                ch = text[i] + key;
                if(ch > 122)
                {
                    ch = ch % 122 + 96;
                }
                printf("%c",ch);
            }
            else
            {
                printf("%c",text[i]);
            }
        }
    }
    else
    {
        length = strlen(text);
        for(i = 0; i<= length; i++)
        {
            if((text[i] >= 65)&&(text[i] <= 90))
            {
                ch = text[i] - key;
                if(ch < 65)
                {
                    ch = 90 - (64 - ch);
                }
                printf("%c",ch);
            }
            else if((text[i] >= 97)&&(text[i] <= 122))
            {
                ch = text[i] - key;
                if(ch < 97)
                {
                    ch = 122 - (96 - ch);
                }
                printf("%c",ch);
            }
            else
            {
                printf("%c",text[i]);
            }
        }
    }

    return 0;
}
