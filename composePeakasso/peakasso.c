#include <stdio.h>
#include <stdlib.h>
#define MAX_RECTANGLES 100

// an array to keep rectangles' coordinates in the given input
int rectangles[MAX_RECTANGLES][4];

// size of array rectangles
int rectSize = 0;

int* endPoints(char** arr, int start_x, int start_y, int x, int y) {
    /* function that finds end point pair(x,y) of given star('*') symbol in array arr */
    int* endpoints = malloc(sizeof(int)*2), i, j;
    int right = 0, down = 0;

    for(i = start_x; i < y; i++) {
        /* if rectangle does not continue in the right way make the loop stopped */
        if(arr[i][start_y] != '*') {
            right = 1;
            break;
        }

        /* dummy symbol to making controls easy */
        if(arr[i][start_y] == 'X') {
            continue;
        }

        /* if rectangle does not continue in the bottom way make the loop stopped */
        for(j = start_y; j < x; j++) {
            if(arr[i][j] != '*') {
                down = 1;
                break;
            }
        }
    }
    /* special case for 1-height 1-width */
    if (i == y) i = i - 1;
    if (j == x) j = j - 1;
    endpoints[0] = right ? i-1 : i;
    endpoints[1] = down ? j-1 : j;


    for (int k = start_x; k <= endpoints[0]; k++) {
        for (int l = start_y; l <= endpoints[1]; l++) {
            arr[k][l] = 'X';
        }
    }
    return endpoints;
}

void countOfRectangle(char** arr, int x, int y) {
    int* end;
    for(int i = 0; i < y; i++) {
        for(int j = 0; j < x; j++) {
            /* if a rectangle is being drawn */
            if(arr[i][j] == '*') {
                end = endPoints(arr, i, j, x, y);
                rectangles[rectSize][0] = j+1;
                rectangles[rectSize][1] = i+1;
                rectangles[rectSize][2] = end[1]-j+1;
                rectangles[rectSize++][3] = end[0]-i+1;
            }
        }
    }
}


int main() {

    int x, y;
    scanf("%d %d\n", &x, &y);
    char** canvas = (char**)malloc(sizeof(char) * y);
    for (int i = 0; i < y; i++) {
        canvas[i] = (char*)malloc(sizeof(char) * x);
    }

    char c; int j = 0;
    for(int i = 0; i < y; i++) {
            c = (char)getchar();
            while(c != '\n') {
                canvas[i][j++] = c;
                scanf("%c",&c);
            }
            j = 0;
    }

    countOfRectangle(canvas, x, y);

    printf("PROGRAM mypeakasso; !! The number of PAINT-CANVAS statements is %d\n", rectSize);
    printf("CANVAS-INIT-SECTION :\n");
    printf("CONST CanvasX = %d ; CONST CanvasY = %d ; CursorX = %d ; CursorY = %d ;\n", x, y, rectangles[0][0], rectangles[0][1]);
    printf("BRUSH-DECLARATION-SECTION : !! Declare brushes\n");
    printf("BRUSH ");
    for(int i = 0; i < rectSize; i++) {
        if (i == rectSize - 1) printf("b%d = %d %d; \n\n", (i+1), rectangles[i][2], rectangles[i][3]);
        else printf("b%d = %d %d, ", (i+1), rectangles[i][2], rectangles[i][3]);
    }
    printf("DRAWING-SECTION : !! Start drawing\n");
    printf("PAINT-CANVAS b1;\n");
    for(int i = 1; i < rectSize; i++) {
        printf("MOVE CursorX TO %d ;\n", rectangles[i][0]);
        printf("MOVE CursorY TO %d ;\n", rectangles[i][1]);
        printf("PAINT-CANVAS b%d;\n", (i+1));
    }
    printf("EXHIBIT-CANVAS;");

    return 0;
}