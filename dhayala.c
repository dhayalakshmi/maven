#include <stdio.h>
#include <string.h>

void caesarCipher(char text[], int shift) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A' + shift) % 26) + 'A';
        }
    }
    printf("Encrypted Text: %s\n", text);
}

int main() {
    char text[100];
    int shift;

    printf("Enter UPPERCASE text: ");
    scanf("%s", text);
    printf("Enter shift (0-25): ");
    scanf("%d", &shift);

    caesarCipher(text, shift);

    return 0;
}
