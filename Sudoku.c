//
//  Sudoku.c
//
//
//  Created by Paul Adeyemi on 08.11.13.
//
//

#include <stdio.h>
#include <stdlib.h>
#include "Sudoku.h"


int main()
{
    int check=0;
    char c;
    char *filepath=NULL;
    int i, j;
    int sudoku;
    
    
    do {
        //Menü
        printf("Auswahl:\n(a)Sudoku\n(b)X-Sudoku\n(e)Beenden\n");
        scanf("%s",&c);
        fflush(stdin);
        
        switch (c) {
            case 'a':
                printf("Auswahl:\n(a)Test Raetzel 1\n(b)Test Raetzes 2\n(c)Filename Eingeben\n(d)Eigens Raetzel eingeben\n(e)Zureuck\n");
                scanf("%s",&c);
                switch (c) {
                    case 'a' :
                        printf("Raetzel 1:\n");
                        printf("Loesung:\n");
                        break;
                    case 'b' :
                        printf("Raetzel 2:\n");
                        printf("Loesung:\n");
                        break;
                    case 'c' :
                        printf("File Raetzel:\n");
                        scanf("%s",&filepath);
                        
                        sudoku=filetoarray(filepath);
                        
                        printf("Loesung:\n");
                        break;
                    case 'd' :
                        printf("Eigenes Raetzel:\n");
                        printf("Loesung:\n");
                        break;
                    case 'e':
                        break;
                    default:
                        printf("\nFalsche Eingabe\n\n");
                        break;
                }
                break;
            case 'b':
                printf("Auswahl:\n(a)Test Raetzel 1\n(b)Test Raetzes 2\n(c)Filename Eingeben\n(d)Eigens Raetzel eingeben\n(e)Zureuck\n");
                scanf("%s",&c);
                switch (c) {
                    case 'a' :
                        printf("Raetzel 1:\n");
                        printf("Loesung:");
                        break;
                    case 'b' :
                        printf("Raetzel 2:\n");
                        printf("Loesung:");
                        break;
                    case 'c' :
                        printf("File Raetzel:\n");
                        printf("Loesung:\n");
                        break;
                    case 'd' :
                        printf("Eigenes Raetzel:\n");
                        printf("Loesung:\n");
                        break;
                    case 'e':
                        break;
                    default:
                        printf("\nFalsche Eingabe\n\n");
                        break;
                }
                break;
            case 'e':
                check=1;
                break;
            default:
                printf("\nFalsche Eingabe\n\n");
                break;
        }
        fflush(stdin);
    } while (check==0);

    /*
    if( fillsudoku(sudoku, 0, 0) )
    {
        
        for(i=0; i<9; ++i)
        {
            for(j=0; j<9; ++j)
                printf("%d ", sudoku[i][j]);
            printf("\n");
        }
    }
    else
    {
        printf("\n\nNO SOLUTION\n\n");
    }*/

    return EXIT_SUCCESS;
}

int filetoarray(char *fpath){
    FILE *fp;
    int sudoku[9][9];
    int i,j;
    
    fp=fopen(fpath,"r");
    
    for(i=0 ; i<9 ; i++)
        for(j=0 ; j<9 ; j++){
            sudoku[i][j] = fgetc(fp) - '0';
            fgetc(fp);
        }
    return sudoku;
}