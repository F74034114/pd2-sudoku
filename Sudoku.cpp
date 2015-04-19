#include "Sudoku.h"
using namespace std;
	
	void Sudoku::GiveQuestion(){
		srand((unsigned)time(NULL));
                char a,b,c,d,e,f,g,h,i,o,x;
                int m,j,k,n,t=0;
                char A[12][12]={{'i','g','h','b','c','a','x','x','x','f','e','d'},//宣告一個數獨陣列其中必不重複 只要每一英文字母分別帶入不同數字即是不同題目
                 	        {'b','a','b','e','f','d','x','x','x','i','g','h'},
                  	        {'f','d','e','h','i','g','x','x','x','c','a','b'},
               		        {'g','h','i','a','b','c','d','e','f','x','x','x'},
               	  	        {'a','b','c','d','e','f','g','h','i','x','x','x'},
            		        {'d','e','f','g','h','i','a','b','c','x','x','x'},
               		        {'h','i','g','x','x','x','f','d','e','b','c','a'},
                	        {'b','c','a','x','x','x','i','g','h','e','d','f'},
                  		{'e','f','d','x','x','x','c','a','b','h','i','g'},
                 	 	{'x','x','x','c','a','b','e','f','d','g','h','i'},
                   		{'x','x','x','f','d','e','h','i','g','a','b','c'},
                   		{'x','x','x','i','g','h','b','c','a','d','f','e'}};

                n=rand()%5;//一列挖(1~4)個空格
                while(n==0)n=rand()%5;
                for(m=0;m<12;m++){
                        t=0;
			n=rand()%5;
                	while(n==0)n=rand()%5;
                        while(t<n){
                                j=rand()%12;
                                while(A[m][j]=='o' || A[m][j]=='x'){
                                        j=rand()%12;
                                }
                                A[m][j]='o';
                                t++;
                        }
                }

//                int sudoku[12][12];
                n=rand()%9+1;
                for(m=0;m<12;m++){//把數字填入數獨中
                        for(j=0;j<12;j++){
                                if(A[m][j]=='a')sudoku[m][j]=n;
                                if(A[m][j]=='b')sudoku[m][j]=n+1;
                                if(A[m][j]=='c')sudoku[m][j]=n+2;
                                if(A[m][j]=='d')sudoku[m][j]=n+3;
                                if(A[m][j]=='e')sudoku[m][j]=n+4;
                                if(A[m][j]=='f')sudoku[m][j]=n+5;
                                if(A[m][j]=='g')sudoku[m][j]=n+6;
                                if(A[m][j]=='h')sudoku[m][j]=n+7;
                                if(A[m][j]=='i')sudoku[m][j]=n+8;
                                if(sudoku[m][j]>9)sudoku[m][j]-=9;
                                if(A[m][j]=='x')sudoku[m][j]=-1;
                                if(A[m][j]=='o')sudoku[m][j]=0;
                        }
                }
                for(m=0;m<12;m++){//印出數獨題目
                        for(j=0;j<12;j++){
                                cout<<sudoku[m][j]<<" ";
                                if(j==11)cout<<"\n";
                        }
                }
        }
	void Sudoku::ReadIn(){
		int i,j;
		for(i=0;i<12;i++){
			for(j=0;j<12;j++){
				cin>>sudoku[i][j];
			}
		}
	}
	void Sudoku::Solve(){
		int i,j,m,n,k=0,x,z;
        	int c[10],a[10];

        	for(i=0;i<10;i++){
                	c[i]=0;
                	a[i]=0;
        	}
        	for(x=0;x<10;x++){
        	for(i=0;i<12;i++){
                	for(j=0;j<12;j++){
                        	if(sudoku[i][j]==0){
                                	for(m=0;m<12;m++){
                                        	if(sudoku[i][m]!=-1)
                                                	c[sudoku[i][m]]=1;
                                	}	
                                	for(n=0;n<12;n++){
                                        	if(sudoku[n][j]!=-1)
                                                	c[sudoku[n][j]]=1;
                                	}
                                	if(j==0 || j==3 || j==6 || j==9){
                                        	for(m=j+1;m<=j+2;m++){
                                                	if(i==0 || i==3 || i==6 || i==9){
                                                        	for(n=i+1;n<=i+2;n++){
                                                                	if(sudoku[n][m]!=-1&&sudoku[n][m]!=0)
                                                                        	c[sudoku[n][m]]=1;
                                                        	}
                                                	}
                                                	if(i==1 || i==4 || i==7 || i==10){
                                                        	if(sudoku[i+1][m]!=-1&&sudoku[i+1][m]!=0)
                                                                	c[sudoku[i+1][m]]=1;
                                                        	if(sudoku[i-1][m]!=-1&&sudoku[i-1][m]!=0)
                                                                	c[sudoku[i+1][m]]=1;
                                                	}
                                                	if(i==2 || i==5 || i==8 || i==11){
                                                        	for(n=i-2;n<=i-1;n++){
                                                                	if(sudoku[n][m]!=-1&&sudoku[n][m]!=0)
                                                                        	c[sudoku[n][m]]=1;
                                                        	}
                                                	}
                                        	}
                                	}
                                	if(j==1 || j==4 || j==7 || j==10){
                                        	if(i==0 || i==3 || i==6 || i==9){
                                                	for(n=i+1;n<=i+2;n++){
                                                        	if(sudoku[n][j-1]!=-1&&sudoku[n][j-1]!=0)
                                                                	c[sudoku[n][j-1]]=1;
                                                        	if(sudoku[n][j+1]!=-1&&sudoku[n][j+1]!=0)
                                                                	c[sudoku[n][j+1]]=1;
                                                	}
                                        	}
                                        	if(i==1 || i==4 || i==7 || i==10){
                                                	if(sudoku[i-1][j-1]!=-1&&sudoku[i-1][j-1]!=0)c[sudoku[i-1][j-1]]=1;
                                                	if(sudoku[i-1][j+1]!=-1&&sudoku[i-1][j+1]!=0)c[sudoku[i-1][j+1]]=1;
                                                	if(sudoku[i+1][j-1]!=-1&&sudoku[i+1][j-1]!=0)c[sudoku[i+1][j-1]]=1;
                                                	if(sudoku[i+1][j+1]!=-1&&sudoku[i+1][j+1]!=0)c[sudoku[i+1][j+1]]=1;
                                        	}
                                        	if(i==2 || i==5 || i==8 || i==11){
                                                	for(n=i-2;n<=i-1;n++){
                                                        	if(sudoku[n][j-1]!=-1&&sudoku[n][j-1]!=0)
                                                                	c[sudoku[n][j-1]]=1;
                                                        	if(sudoku[n][j+1]!=-1&&sudoku[n][j+1]!=0)
                                                                	c[sudoku[n][j+1]]=1;

                                                	}
                                        	}
                                	}
                                	if(j==2 || j==5 || j==8 || j==11){
                                        	for(m=j-2;m<=j-1;m++){
                                                	if(i==0 || i==3 || i==6 || i==9){
                                                        	for(n=i+1;n<=i+2;n++){
                                                                	if(sudoku[n][m]!=-1&&sudoku[n][m]!=0)
                                                                        	c[sudoku[n][m]]=1;
                                                        	}
                                                	}
                                                	if(i==1 || i==4 || i==7 || i==10){
                                                        	if(sudoku[i+1][m]!=-1&&sudoku[i+1][m]!=0)
                                                                	c[sudoku[i+1][m]]=1;
                                                        	if(sudoku[i-1][m]&&sudoku[i-1][m]!=0)
                                                                	c[sudoku[i-1][m]]=1;
                                                	}
                                                	if(i==2 || i==5 || i==8 || i==11){
                                                        	for(n=i-2;n<=i-1;n++){
                                                                	if(sudoku[n][m]!=-1&&sudoku[n][m]!=0)
                                                                        	c[sudoku[n][m]]=1;
                                                        	}
                                                	}
                                        	}
                                	}


                                	for(m=0;m<10;m++){
                                        	if(c[m]==0){
                                                	a[k]=m;
                                                	k++;
                                        	}
                                	}
                                	if(a[1]==0)
                                        	sudoku[i][j]=a[0];

                                	for(z=0;z<10;z++){
                                        	c[z]=0;
                                        	a[z]=0;
                                        	k=0;
                                	}
                        	}
                	}
        	}
		
		}
		
		for(n=0;n<12;n++){
                        for(m=0;m<12;m++){
                                if(sudoku[n][m]==0){
                                        cout<<"2"<<"\n";
					k=2;
					return;
				}
                                else k=1;
                        }
                }
		if(k!=2){
			cout<<"1"<<"\n";
			for(n=0;n<12;n++){
                        	for(m=0;m<12;m++){
					cout<<sudoku[n][m]<<" ";
					if(m==11)cout<<"\n";
				}
			}
		}




}
