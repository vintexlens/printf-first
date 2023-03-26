#include "main.h"

int printf_integer(va_list args, int printed)
{
    int num = va_arg(args, int);
    int digits = 0;
    int temp = num;

    if (num < 0) {
        _putchar('-');
        printed++;
        temp = -temp;
    }

    if (temp == 0) {
        _putchar('0');
        printed++;
        return printed;
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
        _putchar('0' + digit);
        printed++;
        digits--;
    }

    return printed;
}
