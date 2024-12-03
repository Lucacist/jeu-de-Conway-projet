#include "Grille.h"
#include <iostream>
using namespace std;

Grille::Grille()
{
    this->grille={{}};
}

Grille::Grille(vector<vector<int>> g) : grille(g) {}
int Grille::getValue(int h, int l)
{
    return this->grille[h][l];
}
int Grille::AliveNeighbors(int x, int y)
{
    int number=0;
            for (int i=x-1;i<=x+1;i++){
                for (int j=y-1;j<=y+1;j++){
                    if (0<=i && i<=grille.size()-1 && 0<=j && j<=grille[0].size()-1){
                        if(this->getValue(i,j)==1){
                            number++;
                        }
                    }
                }
            }
            return number-grille[x][y];
    }
    
void Grille::run() {
    vector<vector<int>> nGrille(grille.size(), vector<int>(grille[0].size()));
            for (int i=0;i<grille.size();i++){
                for (int j=0;j<grille[0].size();j++){
                    if (this->getValue(i,j)==1){
                        (this->AliveNeighbors(i,j)==2 || this->AliveNeighbors(i,j)==3) ? nGrille[i][j]=1 : nGrille[i][j]=0;
                    }
                    if (this->getValue(i,j)==0){
                        this->AliveNeighbors(i,j)==3 ? nGrille[i][j]=1 : nGrille[i][j]=0;
                    }
                }
            }
            this->grille=nGrille;
    }
    void Grille::print() {
        for (int i=0;i<grille.size();i++){
            for (int j=0;j<grille[0].size();j++){
                if (this->getValue(i,j) > 1) {
                    cout << this->getValue(i,j) << endl;
                }
                grille [i][j]==1 ? cout<<"■"<<" ": cout<<"□"<<" ";
            }
            cout<<endl;
        }
    };