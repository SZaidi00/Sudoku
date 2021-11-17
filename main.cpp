#include <iostream>
#include <algorithm>
#include <ctime>
#include <random>
#include <cstdlib>



using namespace  std;


void shuffler(int a[9]){
    int b[9] = {0,0,0,0,0,0,0,0,0};
    int base[9] ={1,2,3,4,5,6,7,8,9};



    for (int i=0; i <9; i++){
        b[i]= a[i];
    } /// puts inputted array into a new array


    for (int i=0; i < 8; i++){ /// randomises the new array
        int index = rand() % 8 ;
        int temp  = b[i];
        b[i]      = b[index];
        b[index]  = temp;
        }

            for (int j=0; j < 9; j++){ // puts new array back into parameter
                a[j]= b[j];
            }
            //  for (int i=0; i <9; i++){
            //       cout << a[i];
            //   } prints to make sure it is done correctly


}

void printer(int aB[9][9]){
    for (int i = 0; i < 9; i++) { // row
        for (int j = 0; j < 9; j++) { // col

            cout << aB[i][j];

            if (j == 2 || j == 5) {
                cout << " || ";
            }

            if (j == 8) {
                cout << endl;
            }
            if (j == 8 & i == 2 || j == 8 & i == 5) {
                cout << endl;
            }


        }
    }
}


int main() {
    srand(time(0));

    //// BOARD
    int board[9][9] = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };




    /// TOP LEFT BOX
    int topLeft[9] ={1,2,3,4,5,6,7,8,9};
    int c1 = 0;
    shuffler(topLeft);
    for (int i = 0; i < 3; i++){ // Top Left box
        for (int j=0; j<3; j++){
            board[i][j]= topLeft[c1];
            c1++;
        }
    }



    /// TOP MIDDLE BOX
    int topMiddle[9] ={1,2,3,4,5,6,7,8,9};
    shuffler(topMiddle);                    // shuffles the array
    int c2 = 0;                             // used to move through the topMiddle array


    //int tempArray[9] = {0,0,0,0,0,0,0,0,0};


    int condition = 0;

    do{

        int spot = 0;
        int counter = 0;

/// Puts the sorted values into the board
        for (int r = 0; r < 3; r++){
            for (int c = 3; c < 6; c++){

                board[r][c] = topMiddle[c2];
                c2++;
            }
        }



        while (spot < 6)
        {
            /// Look at values that were just added
            for (int r = 0; r < 3; r++)
            {
                for (int c = 3; c < 6; c++)
                {

                    // if any of the values do not equal the previous columns in that row then continue
                    if (board[r][c] != board[r][spot]){
                        counter++;
                        spot++;
                        continue;
                    }
                    // if it does equal a previous spot, then re-shuffle the array and reset the values and break loop to re-enter values
                    else{
                        shuffler (topMiddle);


                        spot = 0;
                        counter = 0;
                        break;

                    }
                }
            }

        }
        // if the counter is equal to 9 then it passed all the values and it doesn't repeat in the row
        // change condition so that it finishes
        if (counter == 9)
        {
            condition = 1;
        }

    }
    while (condition != 1);






    //// PRINT FORMAT
    printer(board);

    cout << endl;



    return 0 ;
}
////











