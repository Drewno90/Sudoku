#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

static int F[9][9] ={  {1, 0, 0, 3, 0, 8, 6, 0, 0},
                        {4, 0, 9, 0, 0, 0, 0, 0, 0},
                        {0, 2, 0, 9, 0, 0, 0, 7, 0},
                        {3, 6, 0, 0, 0, 0, 2, 0, 4},
                        {5, 0, 8, 2, 0, 0, 0, 9, 3},
                        {0, 0, 0, 8, 0, 7, 5, 0, 0},
                        {0, 3, 0, 7, 1, 0, 0, 0, 5},
                        {7, 0, 0, 0, 6, 0, 0, 0, 0},
                        {2, 0, 6, 0, 0, 9, 0, 0, 0} };

                        /*{{1, 6, 4, 0, 0, 0, 0, 0, 2},
                        {2, 0, 0, 4, 0, 3, 9, 1, 0},
                        {0, 0, 5, 0, 8, 0, 4, 0, 7},
                        {0, 9, 0, 0, 0, 6, 5, 0, 0},
                        {5, 0, 0, 1, 0, 2, 0, 0, 8},
                        {0, 0, 8, 9, 0, 0, 0, 3, 0},
                        {8, 0, 9, 0, 4, 0, 2, 0, 0},
                        {0, 7, 3, 5, 0, 9, 6, 6, 1},
                        {4, 0, 0, 0, 0, 0, 6, 7, 9}}; 
                          
                        
                        {{0, 0, 9, 0, 0, 8, 0, 1, 0},
                        {0, 0, 4, 0, 0, 0, 0, 8, 5},
                        {5, 0, 0, 1, 3, 0, 6, 0, 0},
                        {0, 0, 1, 0, 5, 4, 0, 0, 0},
                        {0, 7, 8, 0, 2, 3, 5, 0, 0},
                        {0, 0, 0, 0, 0, 0, 2, 4, 0},
                        {6, 0, 0, 2, 0, 1, 0, 5, 0},
                        {0, 0, 0, 3, 8, 0, 0, 0, 6},
                        {0, 1, 0, 4, 6, 5, 0, 3, 0} }; */ 
                        
static bool znajdz (int a, int b)
{
    int u = (a/3)*3;
    int v = (b/3)*3;
    int m = F[a][b];
    F[a][b] = 0;
    
    for (int t = m+1; t <= 9; t++)
    {
        for (int i = 0; i < 9; i++)
        {
            div_t q = div(i,3);
            if ((F[i][b] == t) || (F[a][i] == t) || F[u+q.quot][v+q.rem] == t)
                break;
                      
      if(i==8)
      {
            F[a][b] = t;
            return true;
            } 
        }
    }
    return false;
}
    

bool sudoku (void)
{
    bool Ffixed[9][9];
    int r = 1;


    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            Ffixed[i][j] = (F[i][j] != 0);

    int i = 0;
    while ( (i >= 0) && (i < 81) )
    {
        div_t q = div(i,9);
        int a = q.quot;
        int b = q.rem;

        if ( ! Ffixed[a][b])
        {
            if ( !znajdz(a,b))
                r = -1;
            else
                r = 1;
        }
        i += r;
    }
    if ( i < 0)
    {
        return false;  
    }
    return true;
}


int main()  
{
        int a=9,b=9;
        cout<<"Pierwotnie :\n";
        for (int i=0; i<9;i++)
          {
          cout<<"\t\t";
                for (int j=0; j<9;j++){
                    
                     if(j%3==0)
                     cout<<" ";
                      cout<<F[i][j];
}
                cout <<"\n";
                if((i+1)%3==0)
                cout <<"\n";
                }
        cout<<"Po wypelnieniu:\n";        
        getchar();
        sudoku ();
        
        for (int i=0; i<9;i++)
          {
          cout<<"\t\t";
                for (int j=0; j<9;j++){
                    
                     if(j%3==0)
                     cout<<" ";
                      cout<<F[i][j];
}
                cout <<"\n";
                if((i+1)%3==0)
                cout <<"\n";
}
        system("PAUSE");
        return 0;
}
