#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int type, i, j, k, numstr[100], apparitionVector[100], numericText[100], lenText ,keyTable[5][5], row1, row2, col1, col2;
char str[100], key[100];

void insertelementat(int position, int a[], int size)
{
    int i, insitem=23, aux[size+1];
    for(i=0; i<=size; ++i)
    {
        if(i<position)
        {
            aux[i] = a[i];
        }
        else if(i>position)
        {
            aux[i] = a[i-1];
        }
        else if(i==position)
        {
            aux[i] = insitem;
        }
    }

    for(i=0; i<=size; ++i)
    {
        a[i] = aux[i];
    }
}

int main(void)
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
        scanf(" %s", str);
        for(i=0, j=0; i<strlen(str); ++i)
        {
            if(isalpha(str[i])==false)
            {
                printf("Please enter only alphabet letters.\n");
                goto loop_text;
            }

            if(str[i]!=' ')
            {
                str[j]=toupper(str[i]);
                j += 1;
            }
        }

        str[j]='\0';
        for(i=0; i<strlen(str); ++i)
        {
            if(str[i]!=' ')
            {
                numstr[i]=str[i]-'A';
            }
        }

        lenText=i;
        loop_key:
        printf("\nEnter the encryption key: ");
        scanf(" %s", key);
        for(i=0, j=0; i<strlen(key); ++i)
        {
            if(isalpha(key[i])==false)
            {
                printf("Please enter only alphabet letters.\n");
                goto loop_key;
            }

            if(key[i]!=' ')
            {
                key[j]=toupper(key[i]);
                j += 1;
            }
        }

        key[j]='\0';

        for(i=0; i<100; ++i)
            apparitionVector[i] = 0;

        k = 1;
        for(i=0; i<strlen(key); ++i)
        {
            if ((key[i] == 'J') && (apparitionVector[key[i]] == 0)&&(key[i] >= 65)&&(key[i] <= 90))
            {
                apparitionVector['I'] = k;
                k++;
            }
            else if((apparitionVector[key[i]] == 0)&&(key[i] >= 65)&&(key[i] <= 90))
            {
                apparitionVector[key[i]] = k;
                k++;
            }
        }

        for(i=65; i<=90; ++i)
        {
            if((apparitionVector[i] == 0)&&(i != 74))
            {
                apparitionVector[i] = k;
                k++;
            }
        }

        for(i=0; i<5; ++i)
        {
            for(j=0; j<5; ++j)
            {
                for(k=65; k<=90; ++k)
                    if(apparitionVector[k]==i*5 + j + 1)
                        keyTable[i][j] = k - 'A';
            }
        }

        for(i=0; i<lenText; i+=2)
        {
            if(numstr[i]==numstr[i+1])
            {
                insertelementat(i+1,numstr,lenText);
                lenText += 1;
            }
        }

        if(lenText%2!=0)
        {
            insertelementat(lenText,numstr,lenText);
            lenText += 1;
        }

        for(k=0; k<lenText; k+=2)
        {
            for(i=0; i<5; ++i)
            {
                for(j=0; j<5; ++j)
                {
                    if(numstr[k]==keyTable[i][j])
                    {
                        row1 = i;
                        col1 = j;
                    }
                    else if(numstr[k+1]==keyTable[i][j])
                    {
                        row2 = i;
                        col2 = j;
                    }
                }
            }

            if(row1==row2)
            {
                col1= (col1+1) % 5;
                col2= (col2+1) % 5;
                numericText[k] = keyTable[row1][col1];
                numericText[k+1] = keyTable[row2][col2];
            }
            else if(col1==col2)
            {
                row1= (row1+1) % 5;
                row2= (row2+1) % 5;
                numericText[k] = keyTable[row1][col1];
                numericText[k+1] = keyTable[row2][col2];
            }
            else if(row1!=row2&&col1!=col2)
            {
                numericText[k] = keyTable[row1][col2];
                numericText[k+1] = keyTable[row2][col1];
            }
        }

        printf("\nThe plain text was: %s\n", str);
        printf("The encryption key was: %s\n", key);
        printf("The encrypted text is: ");
        for(i=0; i<lenText; ++i)
        {
            printf("%c",numericText[i]+'A');
        }
    }
    else if(type==1)
    {
        loop_text1:
        printf("\nEnter the text to decrypt: ");
        scanf(" %s", str);
        for(i=0, j=0; i<strlen(str); ++i)
        {
            if(isalpha(str[i])==false)
            {
                printf("Please enter only alphabet letters.\n");
                goto loop_text1;
            }

            if(str[i]!=' ')
            {
                str[j]=toupper(str[i]);
                j += 1;
            }
        }

        str[j]='\0';
        for(i=0; i<strlen(str); ++i)
        {
            if(str[i]!=' ')
            {
                numstr[i]=str[i]-'A';
            }
        }

        lenText=i;
        loop_key1:
        printf("\nEnter the decryption key: ");
        scanf(" %s", key);
        for(i=0, j=0; i<strlen(key); ++i)
        {
            if(isalpha(key[i])==false)
            {
                printf("Please enter only alphabet letters.\n");
                goto loop_key1;
            }

            if(key[i]!=' ')
            {
                key[j]=toupper(key[i]);
                j += 1;
            }
        }

        key[j]='\0';

        for(i=0; i<100; ++i)
            apparitionVector[i] = 0;

        k = 1;
        for(i=0; i<strlen(key); ++i)
        {
            if ((key[i] == 'J') && (apparitionVector[key[i]] == 0)&&(key[i] >= 65)&&(key[i] <= 90))
            {
                apparitionVector['I'] = k;
                k++;
            }
            else if((apparitionVector[key[i]] == 0)&&(key[i] >= 65)&&(key[i] <= 90))
            {
                apparitionVector[key[i]] = k;
                k++;
            }
        }

        for(i=65; i<=90; ++i)
        {
            if((apparitionVector[i] == 0)&&(i != 74))
            {
                apparitionVector[i] = k;
                k++;
            }
        }

        for(i=0; i<5; ++i)
        {
            for(j=0; j<5; ++j)
            {
                for(k=65; k<=90; ++k)
                    if(apparitionVector[k]==i*5 + j + 1)
                        keyTable[i][j] = k - 'A';
            }
        }

        for(i=0; i<lenText; i+=2)
        {
            if(numstr[i]==numstr[i+1])
            {
                insertelementat(i+1,numstr,lenText);
                lenText += 1;
            }
        }

        if(lenText%2!=0)
        {
            insertelementat(lenText,numstr,lenText);
            lenText += 1;
        }

        for(k=0; k<lenText; k+=2)
        {
            for(i=0; i<5; ++i)
            {
                for(j=0; j<5; ++j)
                {
                    if(numstr[k]==keyTable[i][j])
                    {
                        row1 = i;
                        col1 = j;
                    }
                    else if(numstr[k+1]==keyTable[i][j])
                    {
                        row2 = i;
                        col2 = j;
                    }
                }
            }

            if(row1==row2)
            {
                col1= (col1-1) % 5;
                col2= (col2-1) % 5;
                if(col1<0)
                {
                    col1= 5 + col1;
                }
                else if(col2<0)
                {
                    col2 = 5 + col2;
                }

                numericText[k] = keyTable[row1][col1];
                numericText[k+1] = keyTable[row2][col2];
            }
            else if(col1==col2)
            {
                row1= (row1-1) % 5;
                row2= (row2-1) % 5;
                if(row1<0)
                {
                    row1 = 5 + row1;
                }
                else if(row2<0)
                {
                    row2 = 5 + row2;
                }

                numericText[k] = keyTable[row1][col1];
                numericText[k+1] = keyTable[row2][col2];
            }
            else if(row1!=row2&&col1!=col2)
            {
                numericText[k] = keyTable[row1][col2];
                numericText[k+1] = keyTable[row2][col1];
            }
        }

        printf("\nThe encrypted text was: %s\n", str);
        printf("The decryption key was: %s\n", key);
        printf("The decrypted text is: ");
        for(i=0; i<lenText; ++i)
        {
            if((numericText[i]+'A')!='X')
            {
                printf(" %c",numericText[i]+'A');
            }
        }
    }

    return 0;
}
