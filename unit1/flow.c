#include <stdio.h>

int main(void)
{
    // 1
    int x = 0;
    if (x = 5)
        printf("A\n");// = is assigning hence everything is printed 
    else
        printf("B\n");

    // 2
    int i = 10;
    while (i < 5) {
        printf("while %d\n", i);
        i++;
        /* nothing gets printed here since condition is not met*/
    }
    do {
        printf("do %d\n", i);
        i++;
    } while (i < 5);// i is printed once before checking the condition

    // 3
    for (int k = 0; k < 10; k++) {
        if (k % 2 == 0) continue;
        if (k > 6) break;
        printf("%d ", k);// 0 1 3 5 
    }
    printf("\n");

    // 4
    int day = 2;
    switch (day) {
        case 1: printf("Mon ");
        case 2: printf("Tue ");
        case 3: printf("Wed ");// Tue Wed - there is fall through 
            break;
        case 4: printf("Thu ");
    }
    printf("\n");

    return 0;
}



/*
 * Notes from this exercise (mistakes I made):
 *
 * 1. if (x = 5) -> I predicted both branches print. Wrong: only "A" printed.
 *    - if/else runs at most ONE branch.
 *    - x = 5 assigns, and its value is 5. Non-zero = true, so "A".
 *    - Side effect: x is now 5. That's the hidden damage of this bug.
 *    - gcc warned: "suggest parentheses around assignment".
 *      Meant to compare? Use ==. Really meant to assign? Write if ((x = 5)).
 *
 * 3. I predicted "0 1 3 5". Wrong: real output "1 3 5".
 *    - k = 0: 0 % 2 == 0 is true -> continue, so 0 is skipped.
 *    - Lesson: trace the first pass through the loop instead of guessing.
 *
 * Rules to remember:
 *    - In C, 0 = false, anything else = true.
 *    - break = leave the loop. continue = skip to the next pass.
 *    - for loop: continue still runs k++. while loop: continue can skip
 *      my own i++ -> infinite loop.
 *    - switch without break falls through. If intentional, put a
 *      /* fall through * / comment before the next case (gcc reads it).
 *    - A warning is the compiler asking "did you mean this?"
 */