//Emily Haller
#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
        int q[8]; //initialize 1D array to 0 so no queens on board to start
	int c=0; //begin at column 0
	int r; //no row value since its 1D
        int solutions=0; //initialize counter to 0 to keep track of solution number
        q[0]=0;//place queen in upper left square to start
NC:
        c++; //go to next column
        if(c==8) goto print; //reach column 8 you found a solution so print solution
        q[c]=-1; //
NR:
	q[c]++; //q[c] is the row number in 1D array so increment row by 1 to get to next row
        if(q[c]==8) goto backtrack; //out of rows bc none worked so backtrack
        for(int i=0; i<c; i++){ //row test
		if(q[i]==q[c]) goto NR; //if has queen in row already goes to next row
        }
        for(int i=0; i<c ;i++){ //up diagonal test 
		if((c-i)==q[c]-q[i]) goto NR; //if there is a queen in up diagonal(difference in rows equals difference in columns) go to next row
        }
        for(int i=0; i<c; i++) // down diagonal test
                if ((c-i)==abs(q[c]-q[i])) goto NR; //if there is a queen in down diagonal then go to next row
	goto NC; // then go to next column
backtrack:
        c--; // go back a column
        if(c==-1) return 0; //off board, done with all solutions so terminate program
	goto NR; //go to next row since solutions still need to be found
print:
       	solutions++; //increment number of solution counter to keep track of amount of solutions
       	cout<< "Solution " << solutions << endl;
	for(int col=0; col<8; col++){ //prints 1D array of each possible solution by iterating through array q
        	cout << q[col] << " ";
	}
	cout << endl;
 	for (int row=0; row<8; row++){ //prints a 2D array of each possible solution by looping through columns and rows        
 		for (int col=0; col<8; col++){
                        if(row==q[col]) cout << "1 "; //if row number is equal to the value in the array then print 1
                        else cout << "0 ";
                }
		cout << endl;
	}
 	goto backtrack; //continues looping to find next solution
        return 0;
}
