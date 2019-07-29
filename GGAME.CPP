#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<dos.h>
void home();
void submit(int);
void win(int);
void winnerlist();
static p=0;

void copying(){
  ofstream o("sampleans.dat");
  ifstream ob("sanswer.dat");
  char ch;
  while(!ob.eof()){
  ob.get(ch);
  o.put(ch);
  }
  o.close();
  ob.close();

  }


  void sourcecall(){
  clrscr();
  ifstream myfile;
  char a;
  myfile.open ("source.dat");
  while(!myfile.eof()){
  myfile.get(a);
  cout<<a;  }
  cout<<"\n**********************"<<endl;
myfile.close();
}


void answer()
{


char a[12];
char b[12];
char c[12];
char d[12]="EXIT";
int flag1,flag2;
ofstream clr("scompare.dat",ios::trunc);
clr.close();
REENTRY:
clrscr();
sourcecall();
cout<<"WORDS YOU INSERTED"<<endl;
ifstream wtry("scompare.dat") ;
while(!wtry.eof()){
wtry.getline(c,12);
cout<<c<<"-";
}
cout<<"\n\nYOUR SCORE--"<<p<<" POINTS"<<endl;
cout<<"WHAT YOU FOUND?-- "<<endl;
cin>>b  ;
strupr(b);
if(strcmp(b,d)==0){
win(p);}
//
ifstream q("scompare.dat");
while(!q.eof())
{
q.getline(c,12);
if(strcmp(c,b)==0)
  {   q.close();
      win(p);
  }
}
q.close();
ofstream o("scompare.dat",ios::app);
o<<b<<endl;
o.close();
//
ifstream file;
file.open("sampleans.dat");
 while(!file.eof())
    {
     file.getline(a,12);

     if(strcmp(a,b)==0)
       {
	 p=p+10 ;
    if(p==100){
    win(p);
    }


	  }


}
file.close();
goto REENTRY;



}

void home(){

clrscr();
gotoxy(34,2);
cout<<"W0RD1ES";
gotoxy(34,3);
cout<<"G A M E"<<endl;
gotoxy(32,5);
cout<<"INSTRUCTIONS.";
gotoxy(8,6);
cout<<"1.FIND THE WORD IN THE BOX AND TYPE IT CORRECTLY TO GAIN 10 POINTS.";
gotoxy(8,7);
cout<<"2.IF YOU REWRITE ANY WORD ,YOU WILL BE OUT WITH PRESENT SCORE.";
gotoxy(8,8);
cout<<"3.WRITE 'EXIT'TO EXIT THE GAME WITH PRESENT SCORE.";
gotoxy(36,10);
cout<<"ENTER ";
gotoxy(30,11);
cout<<"1.-to- START THE GAME. ";
gotoxy(30,12);
cout<<"2.-to- SEE SCORE LIST. ";
gotoxy(30,13);
cout<<"3.-to- EXIT.";
gotoxy(32,15);
cout<<"YOUR OPTION ";
int opt;
p=0;
cin>>opt;
if(opt==1){
answer();
}
if(opt==2){
winnerlist();
}


if(opt==3){
exit(0);
}
}

void win(int p)
{
clrscr();
int w1;
if(p==100){
cout<<"WOW! YOU WIN............"<<endl;}
else{
cout<<"MUST TRY AGAIN TO BE WINNER"<<endl;
}
cout<<"\n\nENTER\n1-TO KEEP THE RECORD\n2-GO HOME/EXIT"<<endl;
cout<<"YOUR OPTION  ";
cin>>w1;
if(w1==1){
submit(p);
}
else{
home();}
}

void submit(int p)
{
char name[40];
char  sub1;
int pos;
cout<<"\nSAVE THE RECORD ON THE NAME ?----  ";
cin>>name;
 ofstream sub("winners.dat",ios::ate);


 sub<<name<<"  "<<p<<endl;
 sub.close();
 home();
}
void winnerlist(){
clrscr();

char w2[20];
int w3;
ifstream win("winners.dat");
while(!win.eof()){
win.getline(w2,20);
cout<<w2<<endl;
}
cout<<"\n\n PRESS 3 TO GO BACK TO HOME.";
cin>>w3;
if(w3==3){
home(); }
}



 void main(){

		 clrscr();
		 copying();
		 home();

		 getch();      }





