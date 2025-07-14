#include <stdio.h>

/* Apuntadores y arreglos */
int main(void)
{
    int V1[4] = {2, 3, 4, 7}, V2[4] = {6, 0, 0, 0};
    int *AX, *AY;

    AX = &V1[3];  // apunta a V1[3] = 7
    AY = &V2[2];  // apunta a V2[2] = 0 (inicialmente)

    V1[V2[0] - V1[2]] = *AY;
    // V2[0] = 6, V1[2] = 4, índice = 6 - 4 = 2
    // V1[2] = *AY (que es 0), entonces V1[2] = 0

    *AY = *AX - V1[0];
    // *AY = V1[3] - V1[0] = 7 - 2 = 5
    // ahora V2[2] = 5

    printf("\nV1[0]=%d V1[1]=%d V1[2]=%d V1[3]=%d \tV2[0]=%d V2[1]=%d V2[2]=%d V2[3]=%d",
           V1[0], V1[1], V1[2], V1[3], V2[0], V2[1], V2[2], V2[3]);

    V2[1] = ++*AX;
    // ++*AX incrementa V1[3]: 7 -> 8, V2[1] = 8

    V2[3] = (*AY)++;
    // V2[3] = valor actual de *AY (V2[2]) = 5
    // luego incrementa *AY: 5 -> 6

    *AX += 2;
    // V1[3] = 8 + 2 = 10

    printf("\nV1[0]=%d V1[1]=%d V1[2]=%d V1[3]=%d \tV2[0]=%d V2[1]=%d V2[2]=%d V2[3]=%d\n",
           V1[0], V1[1], V1[2], V1[3], V2[0], V2[1], V2[2], V2[3]);

    return 0;
}
