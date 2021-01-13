#include <iostream>
using namespace std;


void location(int  x, int  y, char grid[][10])
{
    grid[x][y] = 'o';
}

void mapDisplay(int x, int y, char grid[][10])
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if (grid[i][j] == 'o')
            {
                if(i != x || j != y)
                    grid[i][j] = 'x'; 
            }        
            cout << grid[i][j];
        }
        cout << endl;
    }

}

void coordinates(int & x, int & y, char input, char grid[][10])
{
    if(toupper(input) == 'W')
        ((x - 1) < 0 || grid[x-1][y] == 'X') ? x : x-- ;
    else if (toupper(input) == 'S')
        ((x + 1) >= 10 || grid[x+1][y] == 'X') ? x : x++ ;
    else if (toupper(input) == 'D')
        ((y + 1) >= 10 || grid[x][y+1] == 'X') ? y : y++ ;
    else
        ((y - 1) < 0 || grid[x][y-1] == 'X') ? y : y-- ;
}



int main()
{
    //Initialize the first location of the bug
    int x = 0, y = 0;
    //Initialize the trace of the bug
    int prev = 0;
    //Player's input
    char input;


    //Create 10x10 array of characters and fill it with '.'
    char grid[10][10];
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
            grid[i][j] = '.';
    }

    //Initialize final point
    grid[9][9] = 'f';

    //Initialize barriers X
    grid[1][4] = 'X';
    grid[6][1] = 'X';
    grid[9][8] = 'X';
    grid[3][4] = 'X';
    grid[5][3] = 'X';

    //Create repeating menu
    do
    {  
        
        location(x,y,grid);
        mapDisplay(x, y, grid);
        cout << "W. Up\n";
        cout << "A. Left\n";
        cout << "S. Down\n";
        cout << "D. Right\n";
        cout << "Q. Quit\n";
        cin >> input;
        while (toupper(input) != 'W' && toupper(input) != 'A' && toupper(input) != 'S' && toupper(input) != 'D')
        {
            cin.ignore();
            if(toupper(input) == 'Q')
                exit(1);
            cout << "Invalid Input! Please choose again: ";
            cin >> input;
        }
            
        coordinates(x,y,input,grid);
        
    } while (grid[x][y] != 'f');
    
    return 0;
}