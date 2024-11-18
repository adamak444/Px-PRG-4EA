#include <stdio.h>

int a;
int b;
int c;
int D;


int main() {
    printf("Zadej koeficient a, b, c");

    printf("\nZadej koeficient a:");
    if (scanf("%d", &a) != 1) {
        printf("chyba: Neplatny vstup\n");
        exit(1);
    }
    
        printf("\nZadej koeficient b:");
    if (scanf("%d", &b) != 1) {
        printf("chyba: Neplatny vstup\n");
        exit(1);
    }

        printf("\nZadej koeficient c:");
    if (scanf("%d", &c) != 1) {
        printf("chyba: Neplatny vstup\n");
        exit(1);
    }
    

    D = b^2-4*a*c;

    if (D < -999 || D > 999){
    printf ("Error: diskriminant mimo rozsah\n" );
    exit(1);
    }
    
    printf("+-------+-------+-------+-------+\n");
    printf("|%5d  |%5d  |%5d  |%5d  |\n", a, b, c, D);
    printf("+-------+-------+-------+-------+\n");

    if (D > 0) {
        printf("|                    Dva  koreny|\n");
    } else if (D == 0) {
        printf("|                       Jeden koren|\n");
    } else {
        printf("|              Imaginarni koren |\n");
    }
    printf("+-------------------------------+\n");

    return 0;
}