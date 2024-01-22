#include <stdio.h>
#define DSIZE 7
#define PSIZE 3
#define IPSIZE 4

int main()
{
    int data[DSIZE], ip[IPSIZE], d_error[DSIZE], e_pos, c1, c2, c3, i, count;
    printf("Hamming Code for Odd Parity\n");
    printf("===========================\n\n");
    printf("Enter data bits:\n");
    for (i = 0; i < IPSIZE; i++)
    {
        scanf("%d", &ip[i]);
    }
    data[6] = ip[0];
    data[5] = ip[1];
    data[4] = ip[2];
    data[2] = ip[3];
    // p4
    count = 0;
    for (i = 4; i <= 6; i++)
    {
        if (data[i] == 1)
        {
            count++;
        }
    }
    if (count % 2 == 0)
    {
        data[3] = 1;
    }
    else
    {
        data[3] = 0;
    }
    // p2
    count = 0;
    for (i = 2; i <= 6; i++)
    {
        if (i == 3 || i == 4)
        {
            continue;
        }
        else
        {
            if (data[i] == 1)
            {
                count++;
            }
        }
    }
    if (count % 2 == 0)
    {
        data[1] = 1;
    }
    else
    {
        data[1] = 0;
    }
    // p1
    count = 0;
    for (i = 2; i <= 6; i++)
    {
        if (i == 3 || i == 5)
        {
            continue;
        }
        else
        {
            if (data[i] == 1)
            {
                count++;
            }
        }
    }
    if (count % 2 == 0)
    {
        data[0] = 1;
    }
    else
    {
        data[0] = 0;
    }
    printf("\nParity bits are:\n");
    printf("P4 = %d\n", data[3]);
    printf("P2 = %d\n", data[1]);
    printf("P1 = %d\n", data[0]);
    printf("\nThe encoded data is:\n");
    for (i = DSIZE - 1; i >= 0; i--)
    {
        printf("%d", data[i]);
    }
    printf("\n\nEnter the hamming code with 1 bit error:\n");
    for (i = DSIZE - 1; i >= 0; i--)
    {
        scanf("%d", &d_error[i]);
    }
    // RECEIVER
    printf("\nRECEIVER:\n\n");
    // c1
    count = 0;
    for (i = 0; i < DSIZE; i++)
    {
        if (i % 2 != 0)
        {
            continue;
        }
        else
        {
            if (d_error[i] == 1)
            {
                count++;
            }
        }
    }
    if (count % 2 == 0)
    {
        c1 = 1;
    }
    else
    {
        c1 = 0;
    }
    // c2
    count = 0;
    for (i = 0; i < DSIZE; i++)
    {
        if (i == 0 || i == 3 || i == 4)
        {
            continue;
        }
        else
        {
            if (d_error[i] == 1)
            {
                count++;
            }
        }
    }
    if (count % 2 == 0)
    {
        c2 = 1;
    }
    else
    {
        c2 = 0;
    }
    // c3
    count = 0;
    for (i = 3; i < DSIZE; i++)
    {
        if (d_error[i] == 1)
        {
            count++;
        }
    }
    if (count % 2 == 0)
    {
        c3 = 1;
    }
    else
    {
        c3 = 0;
    }
    if (c3 == 1)
    {
        e_pos += 4;
    }
    if (c2 == 1)
    {
        e_pos += 2;
    }
    if (c1 == 1)
    {
        e_pos += 1;
    }
    printf("Error is detected at position %d at the receiving end!\n", e_pos);
    printf("Correcting the error...\n\n");
    if (d_error[e_pos - 1] == 0)
    {
        d_error[e_pos - 1] = 1;
    }
    else
    {
        d_error[e_pos - 1] = 0;
    }
    printf("The corrected code is:\n");
    for (i = DSIZE - 1; i >= 0; i--)
    {
        printf("%d", d_error[i]);
    }
    printf("\nThe decoded data is:\n");
    for (i = DSIZE - 1; i >= 2; i--)
    {
        if (i == 3)
        {
            continue;
        }
        printf("%d", d_error[i]);
    }
    printf("\n");
    return 0;
}