#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

class Sudoku{
	public:
		void GiveQuestion();
		void ReadIn();
		void Solve();

	private:
		int sudoku[12][12];
};
