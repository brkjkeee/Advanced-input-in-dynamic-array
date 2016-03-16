/*
This prog introduces an advanced input in dynamic array.
The array is pretty clever. Its reallocates itself memory
as same as its need. The another pretty thing: very
comfortable input.

Dont be disapeared if you'll see, the same output on screen.
Prog created in used only for concept idea, how its good
can to be to use this input.

To example: input a row of numbers 1 2 3 4 5
then press Enter, to continue input 5 4 3 2 1
press Enter again. For another way - break -
press ESC. Pressing ESC again will terminate the
prog, but pressing any key will free array and let
to continue input the new array.
Be careful, amount of numbers in string must
equial with another string. Else prog will 
terminate with the error code.
*/

#include <iostream>
#include <conio.h>

#define ESC 27
#define EOS '\n'

using namespace std;

int main() {
	do {
		system("CLS");
		//creating the dynamic array[0][0] with only one free space
		float **a = (float**)malloc(sizeof(float*));
		a[0] = (float*)malloc(sizeof(float));
		
		int volume = 0, i = 0;	//volume contains used space(bytes) in array, 'i' need for counting below

		do {
			cout << "Enter " << i + 1 << " string: ";
			do {
				cin >> a[i][_msize(a[i]) / sizeof(float) - 1];													//the 'j' is memory of *p divided by 4, for first one 4/4 = 1, next 8/4 and etc
				if (cin.rdbuf()->in_avail() != 1) a[i] = (float*)realloc(a[i], _msize(a[i]) + sizeof(float));	//realocates memory only if buffer contains more then 1 number in stack
			} while (cin.get() != EOS);		//while not in the end of buffer 'cin'

			volume += _msize(a[i]);			//increases volume 4/8/16 and etc
			
			a = (float**)realloc(a, _msize(a) * sizeof(float*));	//reallocates new pointer
			a[i+1] = (float*)malloc(sizeof(float));					//allocates memory for new p[]
			i++;
		} while (_getch() != ESC);			//while you dont press ESC

		cout << endl << "Result achived:" << endl << endl;

		volume /= _msize(a[0]);				//strings in array calc
		//output on screen
		for (int i = 0; i < volume; i++) {
			for (int j = _msize(a[i]) / sizeof(float); j > 0; j--) {		//'j' is a amount of numbers in string, 1 1 1 1 all size is 16, divided by 4 = 4
				cout << a[i][_msize(a[i]) / sizeof(float) - j] << " ";
			}
			cout << endl;
			free(a[i]);			//frees memory in *p
		}
		free(a);				//frees memory in **p
		
	} while (_getch() != ESC);	//while you dont press ESC
	return 0;
}