#include "main.h"

int print_integer(va_list args, int count)
{
    int num = va_arg(args, int);
    int digits = 0;
    int temp = num;

    if (num < 0) {
        putchar('-');
        count++;
        temp = -temp;
    }

    if (temp == 0) {
        putchar('0');
        count++;
        return count;
    }

    // Determine the number of digits in the number
    while (temp != 0) {
        digits++;
        temp /= 10;
    }

    // Print the digits of the number from left to right
    temp = num;
    while (digits > 0) {
        int divisor = 1;
        for (int i = 1; i < digits; i++) {
            divisor *= 10;
        }
        int digit = temp / divisor;
        temp %= divisor;
        putchar('0' + digit);
        count++;
        digits--;
    }

    return count;
}