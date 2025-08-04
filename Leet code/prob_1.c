#include <stdio.h>
#include <string.h>

void shift_char(char *word){
    int len = strlen(word);
    char shift[1000000];
    for (int i = 0; i < len; i++)
    {
        shift[i] = (word[i] - 'a' + 1) % 26 + 'a';
    }
    shift[len] = '\0';
    strcat(word, shift);
}

char kthCharacter(int k) {
    static char word[1000000] = "a";
    int len = strlen(word);
    if (k > len) {
        shift_char(word);
        return kthCharacter(k);
    }
    else {
        return word[k - 1];
    }
    
}

int main() {
    int k ;
    scanf("%d", &k);
    if(1 <= k && k <= 500){
        char result = kthCharacter(k);
        printf("%c\n", result);
        return 0;
    }
    else {
        printf("Invalid input. k must be between 1 and 500.\n");
        return 1;
    }
}