#include <cmath>
#include <iostream>

using std::cin; 
using std::cout;                   

typedef enum {wood , stone} material;
typedef struct{
    int x,y;
    bool isWall;
    material type;
}field;

#define n 16
#define m 12
field playground[n][m];
int x_pos=5, y_pos=5;

void play();
void printFinalField();

int main(){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            playground[i][j].x=i;
            playground[i][j].y=j;
            playground[i][j].isWall=(i==0||i==(n-1)||(j==0&&i!=3) ||j==(m-1));
            if (playground[i][j].isWall && !(i==3 && j==0)){
                playground[i][j].type=stone;
            }
            else{
                playground[i][j].type=wood;
            }
        }
    }
    play();
    
}

void printFinalField(){
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if(playground[j][i].isWall){
                cout << '*';
            } else {
                if(j == x_pos && i == y_pos){
                    cout << 'O';
                }
                else{
                    cout << ' ';
                }
            } 
        }
        cout << '\n';
    }
}

void play(){
    char input;
    do {
     //   cout << "Curr y_pos: " << y_pos << " x_pos: "  << x_pos << " isWall: " << !playground[y_pos-1][x_pos].isWall << std::endl; 
        printFinalField();
        cin >> input;
        switch (input)
        {
        case 'l':
            if(x_pos > 1 )// && !playground[y_pos][x_pos-1].isWall  ) 
                x_pos--;
            break;
        case 'r':
            if(x_pos < n-2 ) //&& !playground[y_pos][x_pos+1].isWall)
                x_pos++;
            break;
        case 'u':
        //    cout << "Curr y_pos: " << y_pos << " x_pos: "  << x_pos << " isWall: " << !playground[y_pos-1][x_pos].isWall; //  playground[y_pos-1][x_pos].type;   // !((playground[y_pos-1][x_pos].type == stone);  // playground[y_pos-1][x_pos].isWall; 
            if( y_pos>0 && !playground[x_pos][y_pos-1].isWall)//  ||  (y_pos == 1 && x_pos == 3)) // && !playground[y_pos-1][x_pos].isWall) // (y_pos == 1 && x_pos == 3)) //  &&!(playground[y_pos-1][x_pos].type == stone))
                y_pos--;
            break;
        case 'd':
            if(y_pos<m-2) // && !playground[y_pos+1][x_pos].isWall)
                y_pos++;
            break;
        }
    } while(input != 'q');
}
