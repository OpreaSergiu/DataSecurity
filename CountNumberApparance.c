#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str[100];

    int counts[26] = { 0 };

    int i;

    printf("\nEnter the text: ");
    scanf(" %s", str);

    size_t len = strlen(str);

    for (i = 0; i < len; i++) {
        char c = str[i];
        if (!isalpha(c)) continue;

        counts[(int)(tolower(c) - 'a')]++;
    }

    for (i = 0; i < 26; i++) {
        printf("'%c' has %2d occurrences.\n", i + 'a', counts[i]);
    }

 return 0;
}
