all: sudoku.o give_question.cpp solve.cpp
	g++ -o give_question give_question.cpp sudoku.o
	g++ -o solve solve.cpp sudoku.o
sudoku.o: sudoku.o Sudoku.cpp Sudoku.h
	g++ -c Sudoku.cpp -o sudoku.o
