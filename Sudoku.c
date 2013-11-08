//
//  Sudoku.c
//
//
//  Created by Paul Adeyemi on 08.11.13.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <Sudoku.h>


int main()
{
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
    
    return EXIT_SUCCESS;
}