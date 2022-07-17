#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //gets card number from user
    long n;
    do
    {
        n = get_long("credit card: ");
    }
    while (n < 1);
    // gets each digit as an individual integer
    int a = n % 10;
    int b = ((n % 100) - a) / 10;
    int c = (((n % 1000) - a) - b) / 100;
    int d = ((((n % 10000) - a) - b) - c) / 1000;
    int e = (((((n % 100000) - a) - b) - c) - d) / 10000;
    int f = ((((((n % 1000000) - a) - b) - c) - d) - e) / 100000;
    int g = (((((((n % 10000000) - a) - b) - c) - d) - e) - f) / 1000000;
    int h = ((((((((n % 100000000) - a) - b) - c) - d) - e) - f) - g) / 10000000;
    int i = (((((((((n % 1000000000) - a) - b) - c) - d) - e) - f) - g) - h) / 100000000;
    int j = ((((((((((n % 10000000000) - a) - b) - c) - d) - e) - f) - g) - h) - i) / 1000000000;
    int k = (((((((((((n % 100000000000) - a) - b) - c) - d) - e) - f) - g) - h) - i) - j) / 10000000000;
    int l = ((((((((((((n % 1000000000000) - a) - b) - c) - d) - e) - f) - g) - h) - i) - j) - k) / 100000000000;
    int m = (((((((((((((n % 10000000000000) - a) - b) - c) - d) - e) - f) - g) - h) - i) - j) - k) - l) / 1000000000000;
    int o = ((((((((((((((n % 100000000000000) - a) - b) - c) - d) - e) - f) - g) - h) - i) - j) - k) - l) - m) / 10000000000000;
    int p = (((((((((((((((n % 1000000000000000) - a) - b) - c) - d) - e) - f) - g) - h) - i) - j) - k) - l) - m) - o) / 100000000000000;
    //first number of 16 total
    int q = ((((((((((((((((n % 10000000000000000) - a) - b) - c) - d) - e) - f) - g) - h) - i) - j) - k) - l) - m) - o) - p) / 1000000000000000;
    //checksum for Luhn’s Algorithm
    int r = ((b * 2) % 10) + (((b * 2) % 100) / 10) + ((d * 2) % 10) + (((d * 2) % 100) / 10) + ((f * 2) % 10) + (((f * 2) % 100) / 10) + ((h * 2) % 10) + (((h * 2) % 100) / 10) + ((j * 2) % 10) + (((j * 2) % 100) / 10) + ((l * 2) % 10) + (((l * 2) % 100) / 10) + ((o * 2) % 10) + (((o * 2) % 100) / 10) + ((q * 2) % 10) + (((q * 2) % 100) / 10);
    int s = (long) r + a + c + e + g + i + k + m + p;
    //checks checksum
    int v = (long) s % 10;
    if (v != 0)
    {
        printf("INVALID\n");
    }
    else if (q == 0 && p == 3)
    {
        if (o == 4 || o == 7)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (q == 5)
    {
        if (p == 1 || p == 2 || p == 3 || p == 4 || p == 5)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (q == 4)
    {
        printf("VISA\n");
    }
    else if (q == 0 && p == 0 && o == 0 && m == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}