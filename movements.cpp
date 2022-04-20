#include<iostream>
using namespace std;
/*0     1      2    3     4     5      6     7    */
int board [8][8]=
{ 
{ 'R',  ' ',  'B',  'Q',  'K',  'B',  ' ',  'K' },//white 0
{ ' ',  'k',  'P',  'P',  ' ',  'p',  ' ',  ' ' },//white 1
{ ' ',  ' ',  ' ' ,  ' ',  'P',  ' ',  ' ',  ' ' },//space//32 2
{ ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  'K' },// 3
{ 'k',  ' ',  'K',  ' ',  'q',  ' ',  'Q',  ' ' },//4
{ ' ',  ' ',  'b',  ' ',  'p',  ' ',  ' ',  ' ' },//5
{ ' ',  ' ',  'p',  'p',  ' ',  'p',  'p',  'p' },//black 6
{ ' ',  'K',  'b',  'q',  'k',  'b',  'n',  'K' },//black 7
};
//7,4
int iswhite(int row,int col)
{
    char c=board[row][col];
    if(c>=65 && c<=90)  return 1;
    else return 0;
}

int is_enemy(int crow,int ccol,int drow,int dcol)
{   
    if(drow>7||dcol>7||dcol<0||drow<0) return 0;
    if(iswhite(crow,ccol))
        {   if(iswhite(crow,ccol) && iswhite(drow,dcol)&&board[drow][dcol]!=32)    return 2;//friends
            else if(board[drow][dcol]==32 ) return 0;//space
            else return 1;//it enemy because one is enemy
        }
    else if(!iswhite(crow,ccol))
        {   
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
    int indication=is_enemy(row,col,row-1,col);
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
            cout<<"bottomleft ="<<bottomleft(row,col)<<row+1<<col-1<<(indication==1 ?" <=kill " :"")<<endl;
}

void horizontal(int row,int col)
{   int  move=1;
    while(1)//horizontal left
    {
        int indication=is_enemy(row,col,row,abs(col-move));
        if(indication==2)   break;
        if(col-move >-1)
        cout<<"left ="<<left(row,(abs(col-move)))<<" "<<row<<abs(col-move);
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
        cout<<"right ="<<right(row,move+col)<<" "<<row<<col+move;//<<(is_enemy(row,col,row,col+move)?" <=kill " :" ");
        //if kill break the loop
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
        if(row-move>-1)
        cout<<"top ="<<top(abs((row-move)),col)<<" "<<abs((row-move))<<col;//<<(is_enemy(row,col,abs(row-move),col)?" <=kill " :" ");

        if (indication==1)
            { std::cout<<" <=kill "; break;}
             
            
        move++;
        if (move>7) break;
    }
    move=1;
    while(1)//verticalbottom
    {   int indication=is_enemy(row,col,row+move,col);
            if(indication==2) break;
        if(row+move<8)
            cout<<"bottom ="<<bottom(row+move,col)<<" "<<row+move<<col;//<<(is_enemy(row,col,row+move,col)?" <=kill " :" ");
        
        if (indication==1)
            { std::cout<<" <=kill "; break;}
             
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
    {   int indication=is_enemy(row,col,abs(row-move),abs(col-move));
        if(indication==2) break;
       
    if(col-move >=0 && row-move>=0)
        cout<<"bottomleft ="<<bottomleft(abs(row-move),(abs(col-move)))<<" "<<abs(row-move)<<(abs(col-move))<<(is_enemy(row,col,abs(row-move),abs(col-move))?" <=kill " :" ");
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
        cout<<"topright ="<<topright(row+move,move+col)<<" "<<row+move<<col+move<<(is_enemy(row,col,row+move,col+move)?" <=kill " :" ");
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
        cout<<"bottomright ="<<bottomright(abs(row-move),(abs(col+move)))<<" "<<abs(row-move)<<(abs(col+move))<<(is_enemy(row,col,abs(row-move),abs(col+move))?" <=kill " :" ");
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
        cout<<"topleft ="<<topleft(row+move,abs(move-col))<<" "<<row+move<<abs(col-move)<<(is_enemy(row,col,row+move,abs(col-move))?" <=kill " :" ");
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
int main()
{
    //  queen(4,4);
    // bishop(3,4);
     king(0,7);
    // king(7,1);
    // rook(4,4);
}

// /*
// #include<iostream>
// using namespace std;
// /*0     1      2    3     4     5      6     7    
// int board [8][8]=
// { 
// { 'b',  ' ',  'B',  'Q',  'K',  'B',  ' ',  'K' },//white 0
// { ' ',  'k',  'P',  'P',  ' ',  'p',  ' ',  ' ' },//white 1
// { ' ',  ' ',  ' ',  ' ',  'P',  ' ',  ' ',  ' ' },//space//32 2
// { ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  'K' },// 3
// { 'k',  ' ',  'K',  ' ',  'q',  ' ',  'Q',  ' ' },//4
// { ' ',  ' ',  'b',  ' ',  'p',  ' ',  ' ',  ' ' },//5
// { ' ',  ' ',  'p',  'p',  ' ',  'p',  'p',  'p' },//black 6
// { ' ',  'K',  'b',  'q',  'k',  'b',  'n',  'K' },//black 7
// };

// int iswhite(int row,int col)
// {
//     char c=board[row][col];
//     if(c>=65 && c<=90)  return 1;
//     else return 0;
// }

// int is_enemy(int crow,int ccol,int drow,int dcol)
// {   
//     if(drow>7||dcol>7||dcol<0||drow<0) return 0;
//     if(iswhite(crow,ccol))
//         {   if(iswhite(crow,ccol) && iswhite(drow,dcol)&&board[drow][dcol]!=32)    return 2;//friends
//             else if(board[drow][dcol]==32 ) return 0;//space
//             else return 1;//it enemy because one is enemy
//         }
//     else if(!iswhite(crow,ccol))
//         {   
//             if(! iswhite(crow,ccol) && ! iswhite(drow,dcol) && board[drow][dcol]!=32)    return 2;//friends
//             else if(board[drow][dcol]==32 ) return 0;//space
//             else return 1;//it enemy because one is enemy
//         }
//     return 0;
// }   
// int top(int r,int c)//-- decrease
// {   
//     if(((r-1)>=0)&&(c>=0 && c<=7)) return 1;
//     else return 0;

// }
// int bottom(int r,int c)
// {
//     if(((r+1)<=7)&&(c>=0 && c<=7)) return 1;
//     else return 0;
// }
// int left(int r,int c)
// {
//     if((c-1)>=0 &&(r>=0 )) return 1;
//     else return 0;
// }
// int right(int r,int c)
// {
//     if((c+1)<=7 && r<=7) return 1;
//     else return 0;
// }
// int topright(int r,int c)
// {
//     if((r-1)>=0 && (c+1)<=7) return 1;
//     else return 0;
// }
// int topleft(int r,int c)
// {
//     if( (r-1)>=0 && (c-1>=0)) return 1;
//     else return 0;
// }

// int bottomright(int r,int c)
// {
//     if((r+1)<=7&&(c+1)<=7) return 1;
//     else return 0;
// }
// int bottomleft(int r,int c)
// {
//     if((r+1)<=7&&(c-1)>=0) return 1;
//     else return 0;
// }

// void king(int row ,int col)//check king movemensts
// { //make logic for friend and possibe move with if else
//     int indication=is_enemy(row,col,row-1,col);
//         if (indication!=2)
//             cout<<"top ="<<top(row,col)<<(indication==1 ?" <=kill " :"")<<endl;
//     indication=is_enemy(row,col,row+1,col);
//         if (indication!=2)
//                 cout<<"bottom ="<<bottom(row,col)<<(indication==1 ?" <=kill " :"")<<endl;
//     indication=is_enemy(row,col,row,col-1);
//         if (indication!=2)
//             cout<<"left ="<<left(row,col)<<(indication==1 ?" <=kill " :"")<<endl;
//     indication=is_enemy(row,col,row,col+1);
//         if (indication!=2)
//             cout<<"right ="<<right(row,col)<<(indication==1 ?" <=kill " :"")<<endl;
//     indication=is_enemy(row,col,row+1,col+1);
//         if (indication!=2)
//             cout<<"topright ="<<topright(row,col)<<(indication==1 ?" <=kill " :"")<<endl;
//     indication=is_enemy(row,col,row+1,col-1);
//         if (indication!=2)
//             cout<<"topleft ="<<topleft(row,col)<<(indication==1 ?" <=kill " :"")<<endl;
//     indication=is_enemy(row,col,row-1,col+1);
//         if (indication!=2)
//             cout<<"bottomright ="<<bottomright(row,col)<<(indication==1 ?" <=kill " :"")<<endl;
//      indication=is_enemy(row,col,row-1,col-1);
//         if (indication!=2)
//             cout<<"bottomleft ="<<bottomleft(row,col)<<(indication==1 ?" <=kill " :"")<<endl;
// }

// void horizontal(int row,int col)
// {   int  move=1;
//     while(1)//horizontal left
//     {
//         int indication=is_enemy(row,col,row,abs(col-move));
//         if(indication==2)   break;
//         if(col-move >-1)
//         cout<<"left ="<<left(row,(abs(col-move)))<<" "<<row<<abs(col-move);
//             if (indication==1)
//                 { std::cout<<" <=kill "; break;}
             
//         move++;
//         if (move>7) break;
//     }
//     move=1;
//     while(1)//horizontal right
//     {
//         int indication=is_enemy(row,col,row,col+move);
//         if(indication==2) break;
        
//         if(col+move<8)
//         cout<<"right ="<<right(row,move+col)<<" "<<row<<col+move;//<<(is_enemy(row,col,row,col+move)?" <=kill " :" ");
//         //if kill break the loop
//         if (indication==1)
//                 { std::cout<<" <=kill "; break;}
            
//         move++;
//         if (move>7) break;
//     }
// }
// void vertical(int row,int col)
// {   int  move=1;
//     while(1)//verticaltop
//     {   int indication=is_enemy(row,col,abs(row-move),col);
//         if(indication==2) break;
//         if(row-move>-1)
//         cout<<"top ="<<top(abs((row-move)),col)<<" "<<abs((row-move))<<col;//<<(is_enemy(row,col,abs(row-move),col)?" <=kill " :" ");

//         if (indication==1)
//             { std::cout<<" <=kill "; break;}
             
            
//         move++;
//         if (move>7) break;
//     }
//     move=1;
//     while(1)//verticalbottom
//     {   int indication=is_enemy(row,col,row+move,col);
//             if(indication==2) break;
//         if(row+move<8)
//             cout<<"bottom ="<<bottom(row+move,col)<<" "<<row+move<<col;//<<(is_enemy(row,col,row+move,col)?" <=kill " :" ");
        
//         if (indication==1)
//             { std::cout<<" <=kill "; break;}
             
//         move++;
//         if (move>7) break;
//     }
// }


// void rook(int row , int col)//rookie
// {   /*
//     int move=1;
//     while(1)//vertical
//     {
//         if(row-move>-1)
//         cout<<"top ="<<top(abs((row-move)),col)<<" "<<abs((row-move))<<col<<(is_enemy(row,col,abs(row-move),col)?" <=kill " :" ");
//         if(row+move<8)
//             cout<<"bottom ="<<bottom(row+move,col)<<" "<<row+move<<col<<(is_enemy(row,col,row+move,col)?" <=kill " :" ");
//         move++;
//         if (move>7) break;
//     }*/
    
//     horizontal(row,col);
//     cout<<endl;
//     vertical(row,col);
//     /*
//     move=1;
//     while(1)//horizontal
//     {
       
//         if(col-move >-1)
//         cout<<"left ="<<left(row,(abs(col-move)))<<" "<<row<<abs(col-move)<<(is_enemy(row,col,row,abs(col-move))?" <=kill " :" ");
//         if(col+move<8)
//         cout<<"right ="<<right(row,move+col)<<" "<<row<<col+move<<(is_enemy(row,col,row,col+move)?" <=kill " :" ");
//         move++;
//         if (move>7) break;
//     }
//     */
// }

// void rightdiag(int row,int col)//"\"
// {
//     int  move=1;
//     while(1)//horizontal bl <-+^
//     {   int indication=is_enemy(row,col,abs(row-move),abs(col-move));
//         if(indication==2) break;
       
//     if(col-move >=0 && row-move>=0)
//         cout<<"bottomleft ="<<bottomleft(abs(row-move),(abs(col-move)))<<" "<<abs(row-move)<<(abs(col-move))<<(is_enemy(row,col,abs(row-move),abs(col-move))?" <=kill " :" ");
//         if (indication==1)
//             { std::cout<<" <=kill "; break;}
//         move++;
//         if (move>7) break;
//      }
//     move=1;
//     while(1)//horizontal v->
//     {
//         int indication=is_enemy(row,col,row+move,col+move);
//         if(indication==2) break;
//     if(col+move<=7 && row+move<=7) 
//         cout<<"topright ="<<topright(row+move,move+col)<<" "<<row+move<<col+move<<(is_enemy(row,col,row+move,col+move)?" <=kill " :" ");
//        if (indication==1)
//             { std::cout<<" <=kill "; break;}
//         move++;
//         if (move>7) break;
//     }
// }
// void leftdiag(int row,int col)//"/"
// {
//     int  move=1;
//     while(1)//^->
//     {   int indication=is_enemy(row,col,abs(row-move),abs(col+move));
//         if(indication==2) break;
       
//     if(col+move <=7 && row-move>=0)
//         cout<<"bottomright ="<<bottomright(abs(row-move),(abs(col+move)))<<" "<<abs(row-move)<<(abs(col+move))<<(is_enemy(row,col,abs(row-move),abs(col+move))?" <=kill " :" ");
//         if (indication==1)
//             { std::cout<<" <=kill "; break;}
//         move++;
//         if (move>7) break;
//     }
//     move=1;
//     while(1)//horizontal<-v
//     {
//         int indication=is_enemy(row,col,row+move,abs(col-move));
//         if(indication==2) break;
//     if(col-move>=0 && row+move<=7) 
//         cout<<"topleft ="<<topleft(row+move,abs(move-col))<<" "<<row+move<<abs(col-move)<<(is_enemy(row,col,row+move,abs(col-move))?" <=kill " :" ");
//         if (indication==1)
//             { std::cout<<" <=kill "; break;}
//         move++;
//         if (move>7) break;
//     }
// }

// void bishop(int row,int col)
// {
//     rightdiag(row, col);
//     std::cout<<std::endl;
//     leftdiag(row,col);
// }
// void queen(int row,int col)
// {
//     horizontal(row,col);
//     std::cout<<"\n";
//     vertical(row,col);
//     std::cout<<"\n";
//     rightdiag(row,col);
//     std::cout<<"\n";
//     leftdiag(row,col);
//     std::cout<<"\n";
// }
// int main()
// {
//     //  queen(4,4);
//     // bishop(3,4);
//      king(7,4);
//     // king(7,1);
//     // rook(4,4);
// }

