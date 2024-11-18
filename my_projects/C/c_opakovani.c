#include <stdio.h>

int main() {
    int height = 11;
    int width = 7;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if ((i == 0 && j == 3) || 
                (i == 1 && (j == 2 || j == 4)) || 
                (i == 2 && (j == 1 || j == 5)) || 
                (i == 3) || 
                (i >= 4 && i <= 9 && (j == 0 || j == 6)) || 
                (i == 10)) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
