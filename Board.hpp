#pragma once
#include "Square.hpp"

class Board{
    std::vector<Square> arr;
    std::vector<usint> solution={1,2,3,4,5,6,7,8,0}; //9th elem is the hole=0
    std::vector<usint> currentSituation={0,0,0,0,0,0,0,0,0};

    usint N=3;
    usint size=N*N;

    public:

        bool checkifDone(){
            for(usint i=0;i<size;i++){
                if(currentSituation[i]!=solution[i]){
                    return 0;
                }
            }
            return 1;
        }
        void generateBoard(){
            for(usint i=0;i<size;i++){
                usint current=getRandom(0,8);
                bool repeatflag=false;
                do{
                    repeatflag=false;
                    for(usint j=0;j<i;j++){
                        if(currentSituation[j]==current){
                            repeatflag=true;
                            current=getRandom(0,8);
                        }
                    }

                }while(repeatflag==true);
                
                currentSituation[i]=current;
            }
        }

        void printBoard(){
            for(usint i=0;i<size;i++){
                std::cout<<currentSituation[i]<<' ';
                if((i+1)%N==0){
                    std::cout<<std::endl;
                }
                
            }
        }

        void makeSwitch(){

            usint positionMatrix[N][N];

            for(usint i=0;i<N;i++){
                for(usint j=0;j<N;j++){
                    positionMatrix[i][j]=currentSituation[i*3+j];
                }
            }

            usint input;
            std::cin>>input;
            input--;

            if(input<0 || input>N*N-1){
                std::cout<<"Invalid choice!"<<std::endl;
                return;
            }

            usint i=input/N; //lineChoice
            usint j=input%N; //columnChoice
            std::cout<<"i="<<i<<" j="<<j<<std::endl;

            ///complete input rules!

            //i==0 ->upper line; i==N-1 ->lower line; j==0 ->left border; j==N-1 ->right border
            if(i==0){
                if(j==0){
                    if(positionMatrix[i][j+1]==0){
                        std::swap(positionMatrix[i][j],positionMatrix[i][j+1]);
                    }
                    else if(positionMatrix[i+1][j]==0){
                        std::swap(positionMatrix[i][j],positionMatrix[i+1][j]);
                    }
                }
                else if(j==N-1){
                    if(positionMatrix[i][j-1]==0){
                        std::swap(positionMatrix[i][j],positionMatrix[i][j-1]);
                    }
                    else if(positionMatrix[i+1][j]==0){
                        std::swap(positionMatrix[i][j],positionMatrix[i+1][j]);
                    }
                }
                else if(positionMatrix[i+1][j]==0){
                    std::swap(positionMatrix[i][j],positionMatrix[i+1][j]);
                }
                else if(positionMatrix[i][j+1]==0){
                    std::swap(positionMatrix[i][j],positionMatrix[i][j+1]);
                }
                else if(positionMatrix[i][j-1]==0){
                    std::swap(positionMatrix[i][j],positionMatrix[i][j-1]);
                }
            }
            else if(i==(N-1)){
                if(j==0){
                    if(positionMatrix[i][j+1]==0){
                        std::swap(positionMatrix[i][j],positionMatrix[i][j+1]);
                    }
                    else if(positionMatrix[i-1][j]==0){
                        std::swap(positionMatrix[i][j],positionMatrix[i-1][j]);
                    }
                }
                else if(j==N-1){
                    if(positionMatrix[i][j-1]==0){
                        std::swap(positionMatrix[i][j],positionMatrix[i][j-1]);
                    }
                    else if(positionMatrix[i-1][j]==0){
                        std::swap(positionMatrix[i][j],positionMatrix[i-1][j]);
                    }
                }
                else if(positionMatrix[i-1][j]==0){
                    std::swap(positionMatrix[i][j],positionMatrix[i-1][j]);
                }
                else if(positionMatrix[i][j+1]==0){
                    std::swap(positionMatrix[i][j],positionMatrix[i][j+1]);
                }
                else if(positionMatrix[i][j-1]==0){
                    std::swap(positionMatrix[i][j],positionMatrix[i][j-1]);
                }
            }
            else{
                if(j==0){
                    if(positionMatrix[i-1][j]==0){
                        std::swap(positionMatrix[i][j],positionMatrix[i-1][j]);
                    }
                    else if(positionMatrix[i+1][j]==0){
                        std::swap(positionMatrix[i][j],positionMatrix[i+1][j]);
                    }
                    else if(positionMatrix[i][j+1]==0){
                        std::swap(positionMatrix[i][j],positionMatrix[i][j+1]);
                    }
                }
                else if(j==N-1){
                    if(positionMatrix[i-1][j]==0){
                        std::swap(positionMatrix[i][j],positionMatrix[i-1][j]);
                    }
                    else if(positionMatrix[i+1][j]==0){
                        std::swap(positionMatrix[i][j],positionMatrix[i+1][j]);
                    }
                    else if(positionMatrix[i][j-1]==0){
                        std::swap(positionMatrix[i][j],positionMatrix[i][j-1]);
                    }
                }
                else{
                    if(positionMatrix[i-1][j]==0){
                        std::swap(positionMatrix[i][j],positionMatrix[i-1][j]);
                    }
                    else if(positionMatrix[i+1][j]==0){
                        std::swap(positionMatrix[i][j],positionMatrix[i+1][j]);
                    }
                    else if(positionMatrix[i][j-1]==0){
                        std::swap(positionMatrix[i][j],positionMatrix[i][j-1]);
                    }
                    else if(positionMatrix[i][j+1]==0){
                        std::swap(positionMatrix[i][j],positionMatrix[i][j+1]);
                    }
                }
            }

            usint k=0;
            for(usint i=0;i<N;i++){
                for(usint j=0;j<N;j++){
                    currentSituation[k++]=positionMatrix[i][j];
                }
            }


        }
        

};