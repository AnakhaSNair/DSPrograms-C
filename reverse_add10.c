#include <stdio.h>

int main() {
    int num, reversed = 0, remainder, result;

    printf("Enter an integer: ");
    scanf("%d", &num);

    // Find the reverse of the number
    while (num != 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }

    // Add 10 to the reversed number
    result = reversed + 10;

    printf("Result after adding 10 to reversed number: %d\n", result);

    return 0;
}