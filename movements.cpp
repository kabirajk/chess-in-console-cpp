#include<iostream>
using namespace std;
#include<vector>
std::vector<string>MOVES;
vector<string>CompltedMoves;
// /*0     1      2    3     4     5      6     7    */
// int board [8][8]=
// { 
// { 'R',  ' ',  'B',  'Q',  'h',  'B',  ' ',  'K' },//white 0
// { ' ',  'k',  'P',  'P',  ' ',  'p',  ' ',  ' ' },//white 1
// { ' ',  ' ',  ' ',  'P',  'P',  'P',  ' ',  ' ' },//space//32 2
// { ' ',  ' ',  'K',  ' ',  ' ',  ' ',  'Q',  'h' },// 3
// { 'k',  ' ',  'k',  ' ',  'h',  ' ',  'Q',  ' ' },//4
// { ' ',  ' ',  'K',  ' ',  'p',  ' ',  'Q',  ' ' },//5
// { ' ',  ' ',  'p',  'P',  ' ',  'P',  'p',  'p' },//black 6
// { ' ',  'K',  'b',  'q',  'k',  'b',  'n',  'K' },//black 7
// };
// //7,4
int board [8][8]=
{ 
{ 'R',  'N',  'B',  'Q',  'K',  'B',  'N',  'R' },//white 0
{ 'P',  'P',  'P',  'P',  'P',  'P',  'P',  'P' },//white 1
{ ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ' },//space//32 2
{ ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ' },// 3
{ ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ' },//4
{ ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ' },//5
{ 'p',  'p',  'p',  'p',  'p',  'p',  'p',  'p' },//black 6
{ 'r',  'n',  'b',  'q',  'k',  'b',  'n',  'r' },//black 7
};

string number_to_string(int row,int col)// 11 to "11"
{   string s="";
    return s+((char)(48+row))+(((char)(48+col)));
}
string Alphanumeric_to_numberstring(string alnu)
{   string s="";//b1 to 01 //col row to rwo col
    char row=alnu[1]-1;
    char col=(48+(alnu[0]-97));
    return s+row+col;
}
string numeric_to_Alphanumeric(int row,int col)
{//11 to b1//col row
    string s;
    char r=48+row+1;
    char c=97+col;
    return s+c+r;
}
//for pusing purpose//completed moves
void push_to_completed (string completedmove)
{
    CompltedMoves.push_back(completedmove);
}

int row(string s)//internal 1,1
{ 
    return ((int)s[0]-48);
}
int col(string s)//internal 1,1
{ 
    return ((int)s[1]-48);
}

int iswhite(int row,int col)
{
    char c=board[row][col];
    if(c>=65 && c<=90)  return 1;
    else return 0;
}

int is_enemy(int crow,int ccol,int drow,int dcol)
{//   cout<<"\n"<<drow<<dcol<<"\n";if(drow>7||dcol>7||dcol<0||drow<0) return 0;
    if(iswhite(crow,ccol))
        {   if(iswhite(crow,ccol) && iswhite(drow,dcol)&&board[drow][dcol]!=32)    return 2;//friends
            else if(board[drow][dcol]==32 ) return 0;//space
            else return 1;//it enemy because one is enemy
        }
    else if(!iswhite(crow,ccol))
        {   //std::cout<<crow<<" "<<ccol<<" "<<drow<<" "<<dcol<<"||"<<(board[drow][dcol]==32);
            if(! iswhite(crow,ccol) && ! iswhite(drow,dcol) && board[drow][dcol]!=32)    return 2;//friends
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

void king(int row ,int col)//check king movemensts//check to cordinates
{ //make logic for friend and possibe move with if else
   /* int indication=is_enemy(row,col,row-1,col);
        if (indication!=2)
            cout<<"top ="<<top(row,col)<<row-1<<col<<(indication==1 ?" <=kill " :"")<<endl;
    indication=is_enemy(row,col,row+1,col);
        if (indication!=2)
                cout<<"bottom ="<<bottom(row,col)<<row+1<<col<<(indication==1 ?" <=kill " :"")<<endl;
    indication=is_enemy(row,col,row,col-1);
        if (indication!=2)
            cout<<"left ="<<left(row,col)<<row<<col-1<<(indication==1 ?" <=kill " :"")<<endl;
    indication=is_enemy(row,col,row,col+1);
        if (indication!=2)
            cout<<"right ="<<right(row,col)<<row<<col+1<<(indication==1 ?" <=kill " :"")<<endl;
    indication=is_enemy(row,col,row-1,col+1);
        if (indication!=2)
            cout<<"topright ="<<topright(row,col)<<row-1<<col+1<<(indication==1 ?" <=kill " :"")<<endl;
    indication=is_enemy(row,col,row-1,col-1);
        if (indication!=2)
            cout<<"topleft ="<<topleft(row,col)<<row-1<<col-1<<(indication==1 ?" <=kill " :"")<<endl;
    indication=is_enemy(row,col,row+1,col+1);
        if (indication!=2)
            cout<<"bottomright ="<<bottomright(row,col)<<row+1<<col+1<<(indication==1 ?" <=kill " :"")<<endl;
     indication=is_enemy(row,col,row+1,col-1);
        if (indication!=2)
            cout<<"bottomleft ="<<bottomleft(row,col)<<row+1<<col-1<<(indication==1 ?" <=kill " :"")<<endl;*/
// vecor push
if(top(row,col) == 1 &&is_enemy(row,col,row-1,col)!=2)
        MOVES.push_back(number_to_string(row-1,col));
if(bottom(row,col) == 1&& is_enemy(row,col,row+1,col)!=2)
        MOVES.push_back(number_to_string(row+1,col));
if(left(row,col) == 1&& is_enemy(row,col,row,col-1) !=2)
        MOVES.push_back(number_to_string(row,col-1));
if(right(row,col) == 1&& is_enemy(row,col,row,col+1) !=2)
        MOVES.push_back(number_to_string(row,col+1));
if(topright(row,col) == 1 && is_enemy(row,col,row-1,col+1) !=2)
        MOVES.push_back(number_to_string(row-1,col+1));
if(topleft(row,col) == 1 && is_enemy(row,col,row-1,col-1)!=2)
        MOVES.push_back(number_to_string(row-1,col-1));
if(bottomright(row,col) == 1&& is_enemy(row,col,row+1,col+1)!=2)
        MOVES.push_back(number_to_string(row+1,col+1));
if(bottomleft(row,col) == 1&&is_enemy(row,col,row+1,col-1) !=2)
        MOVES.push_back(number_to_string(row+1,col-1));

}
namespace line
{
int top(int r,int c)//-- decrease
{   
    if(((r)>=0)&&(c>=0 && c<=7)) return 1;
    else return 0;
}
int bottom(int r,int c)
{
    if(((r)<=7)&&(c>=0 && c<=7)) return 1;
    else return 0;
}
int left(int r,int c)
{
    if((c)>=0 &&(r>=0 )) return 1;
    else return 0;
}
int right(int r,int c)
{
    if((c)<=7 && r<=7) return 1;
    else return 0;
}
}

void horizontal(int row,int col)
{   int  move=1;
    while(1)//horizontal left
    {
        int indication=is_enemy(row,col,row,abs(col-move));
        if(indication==2)   break;
        if(col-move >-1)
        {//cout<<"left ="<<line::left(row,(abs(col-move)))<<" "<<row<<abs(col-move);
        if(line::left(row,(abs(col-move))) == 1&& is_enemy(row,col,row,abs(col-move)) !=2)
        MOVES.push_back(number_to_string(row,abs(col-move)));}
            if (indication==1)
                { std::cout<<" <=kill "; break;}
             
        move++;
        if (move>7) break;
    }
    move=1;
    while(1)//horizontal right
    {
        int indication=is_enemy(row,col,row,col+move);
        if(indication==2) break;
        
        if(col+move<8)
        {//cout<<"right ="<<line::right(row,move+col)<<" "<<row<<col+move;//<<(is_enemy(row,col,row,col+move)?" <=kill " :" ");
        //if kill break the loop
        if(line::right(row,move+col) == 1&& is_enemy(row,col,row,col+move) !=2)
        MOVES.push_back(number_to_string(row,move+col));}
        if (indication==1)
                { std::cout<<" <=kill "; break;}
            
        move++;
        if (move>7) break;
    }
}
void vertical(int row,int col)
{   int  move=1;
    while(1)//verticaltop
    {   int indication=is_enemy(row,col,abs(row-move),col);
        if(indication==2) break;
        if(row-move>=0)
        {
        //cout<<line::top(abs(row-move),col)<<" "<<abs((row-move))<<col<<(is_enemy(row,col,abs(row-move),col)?==1" <=kill " :" ");
        if(line::top(abs(row-move),col) == 1 &&is_enemy(row,col,abs(row-move),col)!=2)
            { 
                MOVES.push_back(number_to_string(abs(row-move),col));
            if (is_enemy(row,col,abs(row-move),col)==1) MOVES.push_back("*");
            }
        }
        else break;
        if (indication==1)
            // { std::cout<<" <=kill "; break;}
             
        move++;
        if (move>7) break;
    }
    move=1;
    while(1)//verticalbottom
    {   int indication=is_enemy(row,col,row+move,col);
            if(indication==2) break;
        if(row+move<8)
          {// cout<<"bottom ="<<line::bottom(row+move,col)<<" "<<row+move<<col;//<<(is_enemy(row,col,row+move,col)?==1" <=kill " :" ");
            if(line::bottom(row+move,col) == 1&& is_enemy(row,col,row+move,col)!=2)
               {  MOVES.push_back(number_to_string(row+move,col));
                if (is_enemy(row,col,row+move,col)==1) MOVES.push_back("*");}
            }
        else break;

        if (indication==1)
            { std::cout<<" <=kill "; break;}
             
        move++;
        if (move>7) break;
    }
}


void rook(int row , int col)//rookie
{   
    
    horizontal(row,col);
    cout<<endl;
    vertical(row,col);

}

namespace diag
{
    int topright(int r,int c)
{
    if((r)>=0 && (c)<=7) return 1;
    else return 0;
}
int topleft(int r,int c)
{
    if( (r)>=0 && (c>=0)) return 1;
    else return 0;
}

int bottomright(int r,int c)
{
    if((r)<=7&&(c)<=7) return 1;
    else return 0;
}
int bottomleft(int r,int c)
{

    if((r)<=7&&(c)>=-1) return 1;
    else return 0;
}
} 

void rightdiag(int row,int col)//"\"
{
    int  move=1;
    while(1)//horizontal bl <-+^
    {   int indication=is_enemy(row,col,abs(row-move),abs(col-move));
        if(indication==2) break;
       
    if(col-move >=0 && row-move>=0)
        {//cout<<"bottomleft ="<<diag::bottomleft(abs(row-move)-1,(abs(col-move)))<<" "<<abs(row-move)<<(abs(col-move))<<" ";
        if(diag::bottomleft(abs(row-move),abs(col-move)) == 1&&is_enemy(row,col,abs(row-move),abs(col-move)) !=2)
        MOVES.push_back(number_to_string(abs(row-move),abs(col-move)));
        }
    else break;
        
        if (indication==1)
            { std::cout<<" <=kill "; break;}
        move++;
        if (move>7) break;
     }
    move=1;
    while(1)//horizontal v->
    {
        int indication=is_enemy(row,col,row+move,col+move);
        if(indication==2) break;
    if(col+move<=7 && row+move<=7) 
    {   // cout<<"topright ="<<diag::topright(row+move,move+col)<<" "<<row+move<<col+move<<" ";
        if(diag::topright(row+move,move+col) == 1 && is_enemy(row,col,row+move,col+move) !=2)
        MOVES.push_back(number_to_string(row+move,col+move));
        }
    else break;
       if (indication==1)
            { std::cout<<" <=kill "; break;}
        move++;
        if (move>7) break;
    }
}
void leftdiag(int row,int col)//"/"
{
    int  move=1;
    while(1)//^->
    {   int indication=is_enemy(row,col,abs(row-move),abs(col+move));
        if(indication==2) break;
       
    if(col+move <=7 && row-move>=0)
       { //cout<<"bottomright ="<<diag::bottomright(abs(row-move),(abs(col+move)))<<" "<<abs(row-move)<<(abs(col+move))<<" ";
        if(diag::bottomright(abs(row-move),(abs(col+move))) == 1 && is_enemy(row,col,abs(row-move),abs(col+move))!=2)
        MOVES.push_back(number_to_string(abs(row-move),abs(col+move)));
        }
    else break;
        if (indication==1)
            { std::cout<<" <=kill "; break;}
        move++;
        if (move>7) break;
    }
    move=1;
    while(1)//horizontal<-v
    {
        int indication=is_enemy(row,col,row+move,abs(col-move));
        if(indication==2) break;
    if(col-move>=0 && row+move<=7) 
       { //cout<<"topleft ="<<diag::topleft(row+move,abs(move-col))<<" "<<row+move<<abs(col-move)<<" ";
       if(diag::topleft(row+move,abs(move-col)) == 1 && is_enemy(row,col,row+move,abs(col-move))!=2)
        MOVES.push_back(number_to_string(row+move,abs(col-move)));
       }
    else break;
        if (indication==1)
            { std::cout<<" <=kill "; break;}
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
int upleft(int row,int col)
{
    if ((row-2)<0||(col-1)<0) return 0;
    return 1;
}
int upright(int row,int col)
{
    if ((row-2)<0||(col+1)>7) return 0;
    int indication=is_enemy(row,col,row-2,col+1);
    if (indication==2) return 0;
    return 1;
}
int downleft(int row,int col)
{
    if ((row+2)>7||(col-1)<0) return 0;
    
    int indication=is_enemy(row,col,(row+2),(col-1));
    if (indication==2) return 0;
    return 1;
}
int downright(int row,int col)
{
    if ((row+2)>7||(col+1)>7) return 0;
    int indication=is_enemy(row,col,row+2,col+1);
    if (indication==2) return 0;
    return 1;
}
int leftdown(int row,int col)
{
    if ((row+1)>7||(col-2)<0) return 0;
    int indication=is_enemy(row,col,row+1,col-2);
    if (indication==2) return 0;
    return 1;
}
int leftup(int row,int col)
{
    if ((row-1)<0||(col-2)<0) return 0;
    int indication=is_enemy(row,col,row-1,col-2);
    if (indication==2) return 0;
    return 1;
}
int rightdown(int row,int col)
{
    if((row+1)>7 ||(col+2)>7 ) return 0;
    int indication=is_enemy(row,col,row+1,col+2);
    if (indication==2) return 0;
    return 1;
}
int rightup(int row,int col)
{
    if((row-1)<0 ||(col+2)>7 ) return 0;
    int indication=is_enemy(row,col,row-1,col+2);
    if (indication==2) return 0;
    return 1;
}

void knight(int row,int col)
{  
     /*
    std::cout<<"upleft= "<<upleft(row,col)<<" "<<row-2<<col-1;
        std::cout<<(is_enemy(row,col,row-2,col-1)==1?"<= kill ":" ")<<std::endl;
    std::cout<<"upright= "<<upright(row,col)<<" "<<row-2<<col+1;
        std::cout<<(is_enemy(row,col,row-2,col+1)==1?"<= kill ":" ")<<std::endl;
    std::cout<<"downleft= "<<downleft(row,col)<<" "<<row+2<<col-1;
        std::cout<<(is_enemy(row,col,row+2,col-1)==1?"<= kill ":" ")<<std::endl;
    std::cout<<"downright= "<<downright(row,col)<<" "<<row+2<<col+1;
        std::cout<<(is_enemy(row,col,row+2,col+1)==1?"<= kill ":" ")<<std::endl;
    std::cout<<"leftup= "<<leftup(row,col)<<" "<<row-1<<col-2;
        std::cout<<(is_enemy(row,col,row-1,col-2)==1?"<= kill ":" ")<<std::endl;
    std::cout<<"leftdown= "<<leftdown(row,col)<<" "<<row+1<<col-2;
        std::cout<<(is_enemy(row,col,row+1,col-2)==1?"<= kill ":" ")<<std::endl;
    std::cout<<"rightup = "<<rightup(row,col)<<" "<<row-1<<col+2;
        std::cout<<(is_enemy(row,col,row-1,col+2)==1?"<= kill ":" ")<<std::endl;
    std::cout<<"right down= "<<rightdown(row,col)<<" "<<row+1<<col+2;
        std::cout<<(is_enemy(row,col,row+1,col+2)==1?"<= kill ":" ")<<std::endl;*/
//vector psuh
    if(upleft(row,col) == 1)
        MOVES.push_back(number_to_string(row-2,col-1));
    if(upright(row,col) == 1)
        MOVES.push_back(number_to_string(row-2,col+1));
    if(downleft(row,col) == 1)
        MOVES.push_back(number_to_string(row+2,col-1));
    if(downright(row,col) == 1)
        MOVES.push_back(number_to_string(row+2,col+1));
    if(leftdown(row,col) == 1)
        MOVES.push_back(number_to_string(row+1,col-2));
    if(leftup(row,col) == 1)
        MOVES.push_back(number_to_string(row-1,col-2));
    if(rightup(row,col) == 1)
        MOVES.push_back(number_to_string(row+1,col+2));
    if(rightdown(row,col) == 1)
        MOVES.push_back(number_to_string(row-1,col+2));
}

//#white pawn
namespace white
{
int move(int row,int col)
{  
    if((row+1)>7) return 0;
    if(board[row+1][col]==32)
        return 1;
    else return 0;
}
int twomove(int row,int col)
{   //white
    if ((row+1)>7) return 0;
    if(row==1 &&board[row+1][col]==32 &&board[row+2][col]==32)  return 1;
    return 0;
}
int moveright(int row,int col)
{
    if((row+1)>7 || (col+1)>7) return 0;
    return is_enemy(row,col,row+1,col+1);//check enemey
}
int moveleft(int row,int col)
{
    if((row+1)>7 || (col-1)<0) return 0;
    return is_enemy(row,col,row+1,col-1);//check enemey
}
}
//#black
//pawn{
namespace black
{
int move(int row,int col)
{  
    if((row-1)<0) return 0;
    if(board[row-1][col]==32)
        return 1;
    else return 0;
}
int twomove(int row,int col)
{   //black
    if ((row-1)>7) return 0;
    if(row==6&&board[row-1][col]==32 && board[row-2][col]==32 ) return 1;
    return 0;
}
int moveright(int row,int col)
{
    if((row-1)<0 || (col+1)>7) return 0;
    return is_enemy(row,col,row-1,col+1);//check enemey
}
int moveleft(int row,int col)
{
    if((row-1)<0 || (col-1)<0) return 0;
    return is_enemy(row,col,row-1,col-1);//check enemey
}
}

void pawn(int row,int col)
{
    if (iswhite(row,col))
    {
       /* std::cout<<"twomove"<<white::twomove(row,col)<<" ";
        std::cout<<"move"<<white::move(row,col)<<" ";
        std::cout<<"moveright"<<white::moveright(row,col)<<" ";
        std::cout<<"moveleft"<<white::moveleft(row,col)<<" ";*/
    
        if(white::twomove(row,col)==1)
            MOVES.push_back(number_to_string(row+2,col));
        if(white::move(row,col)==1)
            MOVES.push_back(number_to_string(row+1,col));
        if(white::moveright(row,col)==1)
            MOVES.push_back(number_to_string(row+1,col+1));
        if(white::moveright(row,col)==1)
            MOVES.push_back(number_to_string(row+1,col-1));
    }
    else
    {
       /* std::cout<<"black";
        std::cout<<"twomove"<<black::twomove(row,col)<<" ";
        std::cout<<"move"<<black::move(row,col)<<" ";
        std::cout<<"moveright"<<black::moveright(row,col)<<" ";
        std::cout<<"moveleft"<<black::moveleft(row,col)<<" ";*/

        if(black::twomove(row,col)==1)
            MOVES.push_back(number_to_string(row-2,col));
        if(black::move(row,col)==1)
            MOVES.push_back(number_to_string(row-1,col));
        if(black::moveright(row,col)==1)
            MOVES.push_back(number_to_string(row-1,col+1));
        if(black::moveright(row,col)==1)
            MOVES.push_back(number_to_string(row-1,col-1));
        }
}
void cointype(int row,int col)
{   
    char coin=board[row][col];
    if(coin=='K' || coin =='k')
        king(row,col);
    else if(coin=='Q' || coin =='q')
        queen(row,col);
    else if(coin=='B' || coin =='b')
        bishop(row,col);
    else if(coin=='N' || coin =='n')
        knight(row,col);
    else if(coin=='R' || coin =='r')
        rook(row,col);
    else if(coin=='P' || coin =='p')
        pawn(row,col);
    else
        std::cout<<"invalid input"<<board[row][col];
}

void change_coins(int from_row,int from_col,int to_row,int to_col)
{   //check enemy forend//rechek avilablity
    if(is_enemy(from_row ,from_col ,to_row,to_col))
    {
        board[to_row][to_col]=board[from_row][from_col];
        board[from_row][from_col]=32;
    //point +1
    }
    else if (is_enemy(from_row ,from_col ,to_row,to_col)==2)
    {
        std::cout<<"hey choose a different place";
    }
    else if(is_enemy(from_row ,from_col ,to_row,to_col)==0)
    {
        board[to_row][to_col]=board[from_row][from_col];
        board[from_row][from_col]=32;
    }
}

int is_move_avilable(string Index)
{
    for(int i=0;i<MOVES.size();i++)
    {
        if(MOVES[i]==Index)
            {std::cout<<"matched";
            return 1;}
    }
    std::cout<<"notmatched";return 0;
}

string coin(int row,int col)
{   char coin=board[row][col];
    
    string s;
    if(coin==32)
        return s+"   ";
    if(iswhite(row,col)) s+="W_";
    else s+="B_";
    if(coin=='K' || coin =='k')
        s+="K";
    else if(coin=='Q' || coin =='q')
        s+="Q";
    else if(coin=='B' || coin =='b')
        s+="B";
    else if(coin=='N' || coin =='n')
        s+="N";
    else if(coin=='R' || coin =='r')
        s+="R";
    else if(coin=='P' || coin =='p')
        s+="P";

    return s;
}
void printboard()
{   string s="   ";
    string ss="  ";
    std::cout<<"      ";
    for(int i=0;i<8;i++)
        {
            cout<< s+((char)(97+i))+s;
        }
    std::cout<<"\n\n";
    for(int i=1;i<=8;i++)
    {
       cout<< s+((char)(48+i))+s;
            for(int col=0;col<8;col++)
            {
                cout<< ss+(coin(i-1,col))+ss;
            }
        cout<<"\n\n";
    }
}

void printv()
{
    for(int i=0;i<MOVES.size();i++)
    {
        cout<<MOVES[i]<<" ";
    }
    cout<<"\n\n";
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            cout<<"  "<<i<<j<<"="<<(char)board[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n\n";
}

int main()
{
    printboard();
    while(true)
    {
        string s;
       std::cout<<"chose the coin";
       std::cin>>s;
       s=Alphanumeric_to_numberstring(s);
       int srow=row(s);
       int scol=col(s);
       cointype(srow,scol);
       std::cout<<"chose destionation";
       printv();
       std::cin>>s;
       if(is_move_avilable(s))
       {
           int drow=row(s),dcol=col(s);
           change_coins(srow,scol,drow,dcol);
           printboard();
       }
       MOVES.clear();
    }

}
