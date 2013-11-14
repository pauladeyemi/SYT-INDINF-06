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


int grid[9][9];

int main()
{
    int check=0;
    char c;
    char filepath[50];
    int i, j;
    
    int sudoku[9][9]={{3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    
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
                        filetoarray();
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
                        }
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

<<<<<<< HEAD
    
    
=======
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
    }
    */
>>>>>>> 340c091178251f4ca64c5bb3565a7f7148226e0e

    return EXIT_SUCCESS;
}

int filetoarray(){
    FILE *pInput;
    
	//open file
	char name[40];
	printf("Which file do you want to read from? \n ");
	scanf("%s", name);
	pInput = fopen(name, "r");
    
	char puffer[20];
	int colum = 0, row = 0;
	char delimiter[] = ",;";
	char *ptr;
	while (fgets(puffer, 20, pInput)) {
		ptr = strtok(puffer, delimiter);
		while (ptr != NULL) {
			grid[colum][row] = atoi(ptr);
			ptr = strtok(NULL, delimiter);
			row++;
		}
		row = 0;
		colum = colum + 1;
	}
    /*fflush(stdin);
    char filepath[50];
    int sudoku[9][9];
    int buf;
    FILE *fp;
    int i,j;
    
    printf("File Raetzel:\n");
    scanf("%s",filepath);
    printf("%s",filepath);
    fp=fopen(filepath,"r");
    printf("%s",fp);
    for(i=0 ; i<9 ; i++)
        for(j=0 ; j<9 ; j++){
            //fscanf(fp,"%d*%c",buf);
            sudoku[i][j]=buf;
        }
    fclose(fp);
     
    for(i=0; i<9; ++i)
    {
        for(j=0; j<9; ++j)
            printf("%d ", sudoku[i][j]);
        printf("\n");
    }
    */
    return 0;
    
}