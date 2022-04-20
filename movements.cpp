#include<iostream>
using namespace std;
/*0     1      2    3     4     5      6     7    */
int board [8][8]=
{ 
{ 'b',  ' ',  'B',  'Q',  ' ',  'B',  ' ',  'K' },//white 0
{ ' ',  'k',  'P',  'P',  ' ',  'P',  ' ',  ' ' },//white 1
{ ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ' },//space//32 2
{ ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  'K' },// 3
{ ' ',  ' ',  ' ',  ' ',  'q',  ' ',  ' ',  ' ' },//4
{ ' ',  ' ',  'b',  ' ',  ' ',  ' ',  ' ',  ' ' },//5
{ ' ',  ' ',  'p',  'p',  ' ',  'p',  'p',  'p' },//black 6
{ ' ',  'K',  'b',  'q',  ' ',  'b',  'n',  'K' },//black 7
};

int iswhite(int row,int col)
{
    char c=board[row][col];
    if(c>=65 && c<=90)  return 1;
    else return 0;
}

int is_enemy(int crow,int ccol,int drow,int dcol)
{   if(iswhite(crow,ccol))
        {   if(iswhite(crow,ccol) && iswhite(drow,dcol))    return 0;//friends
            else if(board[drow][dcol]==32 ) return 0;//space
            else return 1;//it enemy because one is enemy
        }
    else if(!iswhite(crow,ccol))
        {  // std::cout<<"c black";
            if(! iswhite(crow,ccol) && ! iswhite(drow,dcol))    return 0;//friends
            else if(board[drow][dcol]==32 ) return 0;//space
            else return 1;//it enemy because one is enemy
        }
    return 0;
}   
int top(int r,int c)//-- decrease
{   
    if(((r-1)>=0)&&(c>=0 && c<=7)) return 1;
    else return 0;

}
int bottom(int r,int c)
{
    if(((r+1)<=7)&&(c>=0 && c<=7)) return 1;
    else return 0;
}
int left(int r,int c)
{
    if((c-1)>=0 &&(r>=0 )) return 1;
    else return 0;
}
int right(int r,int c)
{
    if((c+1)<=7 && r<=7) return 1;
    else return 0;
}
int topright(int r,int c)
{
    if((r-1)>=0 && (c+1)<=7) return 1;
    else return 0;
}
int topleft(int r,int c)
{
    if( (r-1)>=0 && (c-1>=0)) return 1;
    else return 0;
}

int bottomright(int r,int c)
{
    if((r+1)<=7&&(c+1)<=7) return 1;
    else return 0;
}
int bottomleft(int r,int c)
{
    if((r+1)<=7&&(c-1)>=0) return 1;
    else return 0;
}

void king(int row ,int col)
{ //make logic for friend and possibe move with if else
    cout<<"top ="<<top(row,col)<<(is_enemy(row,col,row-1,col)?" <=kill " :"")<<endl;
    cout<<"bottom ="<<bottom(row,col)<<(is_enemy(row,col,row+1,col)?" <=kill " :" ")<<endl;
    cout<<"left ="<<left(row,col)<<(is_enemy(row,col,row,col-1)?" <=kill " :"")<<endl;
    cout<<"right ="<<right(row,col)<<(is_enemy(row,col,row,col+1)?" <=kill " :"")<<endl;
    cout<<"topright ="<<topright(row,col)<<(is_enemy(row,col,row+1,col+1)?" <=kill " :"")<<endl;
    cout<<"topleft ="<<topleft(row,col)<<(is_enemy(row,col,row+1,col-1)?" <=kill " :"")<<endl;
    cout<<"bottomright ="<<bottomright(row,col)<<(is_enemy(row,col,row-1,col+1)?" <=kill " :"")<<endl;
    cout<<"bottomleft ="<<bottomleft(row,col)<<(is_enemy(row,col,row-1,col-1)?" <=kill " :"")<<endl;    
}

void horizontal(int row,int col)
{   int  move=1;
    while(1)//horizontal left
    {
       
        if(col-move >-1)
        cout<<"left ="<<left(row,(abs(col-move)))<<" "<<row<<abs(col-move)<<(is_enemy(row,col,row,abs(col-move))?" <=kill " :" ");
        // if(col+move<8)
        // cout<<"right ="<<right(row,move+col)<<" "<<row<<col+move<<(is_enemy(row,col,row,col+move)?" <=kill " :" ");
        move++;
        if (move>7) break;
    }
    move=1;
    while(1)//horizontal right
    {
       
        // if(col-move >-1)
        // cout<<"left ="<<left(row,(abs(col-move)))<<" "<<row<<abs(col-move)<<(is_enemy(row,col,row,abs(col-move))?" <=kill " :" ");
        if(col+move<8)
        cout<<"right ="<<right(row,move+col)<<" "<<row<<col+move<<(is_enemy(row,col,row,col+move)?" <=kill " :" ");
        //if kill break the loop
        move++;
        if (move>7) break;
    }
}
void vertical(int row,int col)
{   int  move=1;
    while(1)//verticaltop
    {
        if(row-move>-1)
        cout<<"top ="<<top(abs((row-move)),col)<<" "<<abs((row-move))<<col<<(is_enemy(row,col,abs(row-move),col)?" <=kill " :" ");
        // if(row+move<8)
        //     cout<<"bottom ="<<bottom(row+move,col)<<" "<<row+move<<col<<(is_enemy(row,col,row+move,col)?" <=kill " :" ");
        move++;
        if (move>7) break;
    }
    move=1;
    while(1)//verticalbottom
    {
        // if(row-move>-1)
        // cout<<"top ="<<top(abs((row-move)),col)<<" "<<abs((row-move))<<col<<(is_enemy(row,col,abs(row-move),col)?" <=kill " :" ");
        if(row+move<8)
            cout<<"bottom ="<<bottom(row+move,col)<<" "<<row+move<<col<<(is_enemy(row,col,row+move,col)?" <=kill " :" ");
        move++;
        if (move>7) break;
    }
}


void rook(int row , int col)//rookie
{   /*
    int move=1;
    while(1)//vertical
    {
        if(row-move>-1)
        cout<<"top ="<<top(abs((row-move)),col)<<" "<<abs((row-move))<<col<<(is_enemy(row,col,abs(row-move),col)?" <=kill " :" ");
        if(row+move<8)
            cout<<"bottom ="<<bottom(row+move,col)<<" "<<row+move<<col<<(is_enemy(row,col,row+move,col)?" <=kill " :" ");
        move++;
        if (move>7) break;
    }*/
    
    horizontal(row,col);
    cout<<endl;
    vertical(row,col);
    /*
    move=1;
    while(1)//horizontal
    {
       
        if(col-move >-1)
        cout<<"left ="<<left(row,(abs(col-move)))<<" "<<row<<abs(col-move)<<(is_enemy(row,col,row,abs(col-move))?" <=kill " :" ");
        if(col+move<8)
        cout<<"right ="<<right(row,move+col)<<" "<<row<<col+move<<(is_enemy(row,col,row,col+move)?" <=kill " :" ");
        move++;
        if (move>7) break;
    }
    */
}

void rightdiag(int row,int col)//"\"
{
    int  move=1;
    while(1)//horizontal bl <-+^
    {
       
    if(col-move >=0 && row-move>=0)
        cout<<"bottomleft ="<<bottomleft(abs(row-move),(abs(col-move)))<<" "<<abs(row-move)<<(abs(col-move))<<(is_enemy(row,col,abs(row-move),abs(col-move))?" <=kill " :" ");
    // if(col+move<=7 && row+move<=7) 
    //     cout<<"topright ="<<topright(row+move,move+col)<<" "<<row+move<<col+move<<(is_enemy(row,col,row+move,col+move)?" <=kill " :" ");
        move++;
        if (move>7) break;
     }
    move=1;
    while(1)//horizontal v->
    {
       
    // if(col-move >=0 && row-move>=0)
    //     cout<<"bottomleft ="<<bottomleft(abs(row-move),(abs(col-move)))<<" "<<abs(row-move)<<(abs(col-move))<<(is_enemy(row,col,abs(row-move),abs(col-move))?" <=kill " :" ");
    if(col+move<=7 && row+move<=7) 
        cout<<"topright ="<<topright(row+move,move+col)<<" "<<row+move<<col+move<<(is_enemy(row,col,row+move,col+move)?" <=kill " :" ");
        move++;
        if (move>7) break;
    }
}
void leftdiag(int row,int col)//"/"
{
    int  move=1;
    while(1)//^->
    {
       
    if(col+move <=7 && row-move>=0)
        cout<<"bottomright ="<<bottomright(abs(row-move),(abs(col+move)))<<" "<<abs(row-move)<<(abs(col+move))<<(is_enemy(row,col,abs(row-move),abs(col+move))?" <=kill " :" ");
    // if(col-move>=0 && row+move<=7) 
    //     cout<<"topleft ="<<topleft(row+move,abs(move-col))<<" "<<row+move<<abs(col-move)<<(is_enemy(row,col,row+move,abs(col-move))?" <=kill " :" ");
        move++;
        if (move>7) break;
    }
    move=1;
    while(1)//horizontal<-v
    {
       
    // if(col+move <=7 && row-move>=0)
    //     cout<<"bottomright ="<<bottomright(abs(row-move),(abs(col+move)))<<" "<<abs(row-move)<<(abs(col+move))<<(is_enemy(row,col,abs(row-move),abs(col+move))?" <=kill " :" ");
    if(col-move>=0 && row+move<=7) 
        cout<<"topleft ="<<topleft(row+move,abs(move-col))<<" "<<row+move<<abs(col-move)<<(is_enemy(row,col,row+move,abs(col-move))?" <=kill " :" ");
        move++;
        if (move>7) break;
    }
}

void bishop(int row,int col)
{
    rightdiag(row, col);
    std::cout<<std::endl;
    leftdiag(row,col);
}
void queen(int row,int col)
{
    horizontal(row,col);
    std::cout<<"\n";
    vertical(row,col);
    std::cout<<"\n";
    rightdiag(row,col);
    std::cout<<"\n";
    leftdiag(row,col);
    std::cout<<"\n";
}
int main()
{
    queen(4,4);
    // bishop(3,7);
    // king(4,4);
    // king(7,1);
    // rook(4,4);
}