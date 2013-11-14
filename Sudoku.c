//
//  Sudoku.c
//
//
//  Created by Paul Adeyemi on 08.11.13.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sudokuarr[9][9];

int main()
{
    int check=0;
    char c;
    char filepath[50];
    int i, j;
    
    do {
        //Menü
        printf("Auswahl:\n(a)Test Raetzel 1\n(b)Test Raetzes 2\n(c)Filename Eingeben\n(e)Beenden\n");
        
            scanf("%s",&c);
            switch (c) {
                case 'a' :
                    raetsel1();
                    ausgabe();
                    //Wenn Sudoku Lösbar, dann ausgabe von gelöstem Sudoku
                    // sonst ausgabe "NO SOLUTION"
                    if(fillsudoku(sudokuarr, 0, 0)){
                        printf("Loesung:\n\n");
                        ausgabe();
                    }
                    else{
                        printf("NO SOLUTION\n\n");
                    }
                    break;
                    
                case 'b' :
                    raetsel2();
                    ausgabe();
                    //Wenn Sudoku Lösbar, dann ausgabe von gelöstem Sudoku
                    // sonst ausgabe "NO SOLUTION"
                    if(fillsudoku(sudokuarr, 0, 0)){
                        printf("Loesung:\n\n");
                        ausgabe();
                    }else{printf("NO SOLUTION\n\n");}
                    break;
                    
                case 'c' :
                    filetoarray();
                    ausgabe();
                    //Wenn Sudoku Lösbar, dann ausgabe von gelöstem Sudoku
                    // sonst ausgabe "NO SOLUTION"
                    if(fillsudoku(sudokuarr, 0, 0)){
                    printf("Loesung:\n\n");
                    ausgabe();
                    }else{printf("NO SOLUTION\n\n");}
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

    return EXIT_SUCCESS;
}



/**
 * Funktion gibt den Aktuellen Array aus
 */
int ausgabe(){
    int i,j;
        for(i=0; i<9; ++i){
            for(j=0; j<9; ++j)
                printf("%d ", sudokuarr[i][j]);
            printf("\n");
        }
}



/**
 * Funktion liest file ein, und wandelt dessen Inhalt in ein Array um
 *
 *
 */
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
    
    //Algorithmus zum auslesen eines Files in ein Array
	while (fgets(puffer, 20, pInput)) {
		ptr = strtok(puffer, delimiter);
		while (ptr != NULL) {
			sudokuarr[colum][row] = atoi(ptr);
			ptr = strtok(NULL, delimiter);
			row++;
		}
		row = 0;
		colum = colum + 1;
	}
    return 0;
}



/**
 * Funktion wandelt ein vorgefertigtes CSV File "raetsel1.csv" in einen Array um
 */
int raetsel1(){
    FILE *pInput;
    
	//open file
	char *name="./raetsel1.csv";
	pInput = fopen(name, "r");
    
	char puffer[20];
	int colum = 0, row = 0;
	char delimiter[] = ",;";
	char *ptr;
    
    //Algorithmus zum auslesen eines Files in ein Array
	while (fgets(puffer, 20, pInput)) {
		ptr = strtok(puffer, delimiter);
		while (ptr != NULL) {
			sudokuarr[colum][row] = atoi(ptr);
			ptr = strtok(NULL, delimiter);
			row++;
		}
		row = 0;
		colum = colum + 1;
	}
    return 0;
}



/**
 * Funktion wandelt ein vorgefertigtes CSV File "raetsel2.csv" in einen Array um
 */
int raetsel2(){
    FILE *pInput;
    
	//open file
	char *name="./raetsel2.csv";
	pInput = fopen(name, "r");
    
	char puffer[20];
	int colum = 0, row = 0;
	char delimiter[] = ",;";
	char *ptr;
    
    //Algorithmus zum auslesen eines Files in ein Array
	while (fgets(puffer, 20, pInput)) {
		ptr = strtok(puffer, delimiter);
		while (ptr != NULL) {
			sudokuarr[colum][row] = atoi(ptr);
			ptr = strtok(NULL, delimiter);
			row++;
		}
		row = 0;
		colum = colum + 1;
	}
    return 0;
}