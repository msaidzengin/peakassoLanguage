#include <stdio.h>
#include <stdlib.h>

void findend(int i, int j, char** canvas, int output[100][4], int counter) {
    int x = sizeof(canvas)/sizeof(canvas[0]);
    int y = sizeof(canvas[i])/sizeof(canvas[i][0]);

    int flagc = 0;
    int flagr = 0;
    int m, n;
    for (m = i; m < x; m++) {
        if (canvas[m][j] == ' ') {
            flagr = 1;
            break;
        }
        if (canvas[m][j] == 5) {
            continue;
        }

        for (n = j; n < y; n++) {
            if (canvas[m][n] == '*') {
                flagc = 1;
                break;
            }
            canvas[m][n] = 5;
        }
    }
    if (flagr == 1) {
        output[counter][2] = (m-1);
    } else {
        output[counter][2] = (m);
    }

    if (flagc == 1) {
        output[counter][3] = (n-1);
    } else {
        output[counter][3] = (n);
    }
}


void get_rectangle_coordinates(int x, int y, char** canvas) {

    int output[100][4];
    int counter = 0;

    for( int i = 0; i < sizeof(canvas)/sizeof(canvas[0]); i++) {
        for (int j = 0; j < sizeof(canvas[i])/sizeof(canvas[i][0]); j++) {
            if (canvas[i][j] == '*') {
                output[counter][0] = i;
                output[counter][1] = j;
                findend(i, j, canvas, output, counter);
                counter++;
            }
        }
    }
    for (int i = 0; i < counter; i++)
        printf("%d %d %d %d \n", output[i][0], output[i][1], output[i][2], output[i][3]);
}

int main() {
    int x, y;
    scanf("%d %d\n", &x, &y);
    char** canvas = (char**)malloc(sizeof(char) * y);
    for (int i = 0; i < y; i++) {
        canvas[i] = (char*)malloc(sizeof(char) * x);
    }
    char dump1, dump2;

    for( int i = 0; i < sizeof(canvas)/sizeof(canvas[0]); i++) {
        for (int j = 0; j < sizeof(canvas[i])/sizeof(canvas[i][0]); j++) {
            scanf("%c", &canvas[i][j]);
        }
        scanf("%c%c", &dump1, &dump2);
    }
    get_rectangle_coordinates(x, y, canvas);
}