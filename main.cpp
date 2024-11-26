#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Grid{
    vector<vector<int>> grid;
    public:
        Grid(vector<vector<int>> g) : grid(g){};
        int AliveNeighbors(int x,int y){
            int number=0;
            for (int i=x-1;i<=x+1;i++){
                for (int j=y-1;j<=y+1;j++){
                    if (0<=i && i<=grid.size()-1 && 0<=j && j<=grid[0].size()-1){
                        if(grid[i][j]==1){
                            number++;
                        }
                    }
                }
            }
            return number-grid[x][y];
        }
        void run(){
            vector<vector<int>> newGrid(grid.size(), vector<int>(grid[0].size()));
            for (int i=0;i<grid.size();i++){
                for (int j=0;j<grid[0].size();j++){
                    if (grid[i][j]==1){
                        (this->AliveNeighbors(i,j)==2 || this->AliveNeighbors(i,j)==3) ? newGrid[i][j]=1 : newGrid[i][j]=0;
                    }
                    if (grid[i][j]==0){
                        this->AliveNeighbors(i,j)==3 ? newGrid[i][j]=1 : newGrid[i][j]=0;
                    }
                }
            }
            this->grid=newGrid;
        }
        void print(){
            for (int i=0;i<grid.size();i++){
                for (int j=0;j<grid[0].size();j++){
                    cout<<grid[i][j]<<" ";
                }
                cout<<endl;
            }
        }
};

int main(){

vector<vector<int>> matrice={{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{1,1,1,0,0,0},{0,0,1,0,0,0},{0,1,0,0,0,0}};
Grid grille{matrice};
grille.print();
grille.run();
cout<<"---"<<endl;
grille.print();
grille.run();
cout<<"---"<<endl;
grille.print();
grille.run();
cout<<"---"<<endl;
grille.print();
grille.run();
cout<<"---"<<endl;
grille.print();
grille.run();
cout<<"---"<<endl;
grille.print();
grille.run();
cout<<"---"<<endl;
grille.print();
grille.run();
cout<<"---"<<endl;
grille.print();
grille.run();
cout<<"---"<<endl;
grille.print();
grille.run();
cout<<"---"<<endl;
grille.print();
grille.run();
cout<<"---"<<endl;
grille.print();
grille.run();
cout<<"---"<<endl;
grille.print();

}