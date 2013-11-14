all: a.out

a.out: Sudoku_alg.o Sudoku.o
	gcc Sudoku_alg.o Sudoku.o -o a.out

Sudoku_alg.o: Sudoku_alg.c
	gcc -c Sudoku_alg.c -ISudoku_alg.h

Sudoku.o: Sudoku.c
        gcc -c Sudoku.c -ISudoku.h 

clean:
	 rm Sudoku_alg.o Sudoku.o a.out

