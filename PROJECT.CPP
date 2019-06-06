//Welcome To The Study Zone
#include<iostream>
#include<string>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<cstring>

using namespace std;

class pl   							  //creating class pl
{
  public :

  char name[20];		                                          //name of user
  int age;					                    //age of user
  char id[10],pass[10];									//user
  void enter();
  void display()				       //to display details of user
    {
	  cout<<"\nI.D. \t";
	  cout<<id;
	  cout<<"\nName  \t";
	  cout<<name;
	  cout<<"\nAge  \t";
	  cout<<age;
  }
}po;
class study:public pl{
	public:
		void choose();
		void heading();
		void face1();
		void face2();
		void face3();
		void sure();
		void create_notes();
		void display_notes();
		void modify_notes();
		void modifyphynts();
		void modifymathnts();
		void modifychemnts();

		void delete_notes();
		void problem_solving();
		void crtid();
		void delid();
		void entidt();
		void chemistry();
		void log_out();
		void maths();
		void physics();
		void display();
		void idt();
		void final();

}ob;


void pl::enter()
{
    long *pas;
    cout<<"Select Pass\n";
    gets(pass);
    cout<<"ENTER Pass Again(not visible now)\n";
    pas=getpass(" ");
    if(strcmp(pas,pass))
    {
	cout<<"DOES NOT Match ";
	getch();
	ob.idt();
    }

    ll:
    cout<<"Enter Name\n";
    gets(name);
    if(strlen(name)==0)
    {
	cout<<"Name field can not be left blank\n";
	goto ll;
    }
    cout<<"Enter Age\n";
    cin>>age;
    ofstream file;
    file.open("log.txt",ios::app);
    file<<"\nCreated User ";
    file<<name<<"\t";
    file<<id;
    file.close();
}


void study::sure(){
	int i;
	char ch[10],c[10];
  for(i=0;i<1;i++)
  ch[i]=97+random(26);
  ch[1]='\0';
  cout<<"\n\n Are You Sure. \n\n To Continue Press: ";
  cout<<ch;
  cout<<"\n\n ";
  cin>>c;
  if(strcmp(c,ch))
  {
  cout<<"Abort !! Could NOT Proceed Further ";
  idt();
  }

}



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void study::face1()
{
  clrscr();
  char id[10],*pass;
  cout<<"\n\nEnter your I.D.: ";
  cin>>id;
  strcat(id,".txt");
  ifstream user(id);
  user.read((char*) &po,sizeof(po));
  cout<<"\n\nEnter PassCode...\n";
  pass=getpass("");
  if(strcmp(pass,po.pass)!=0||user==NULL){

   cout<<"\nWrong PassCode OR I.D.";
   cout<<"\nPlease Try Again";
   getch();
   idt();

   }
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void study::face2()
{
	 clrscr();
	 pl p1;
	 cout<<"\n\nSet I.D.";
	 gets(p1.id);
	 char ch[10];
	 strcpy(ch,p1.id);
	 strcat(ch,".txt");

	 ifstream user(ch);
	 if(!user){
		 user.close();
		 p1.enter();
		 ofstream nuser(ch);
		 nuser.write((char*)&p1,sizeof(p1));
		 nuser.close();
		 idt();
	 }
	  else
	  {
		 user.close();
		  cout<<"\nI.D. already exist \nabort!!!!";
		  getch();
		  idt();
	  }
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void study::face3()
{
	 char id[10];
	 strcpy(id,po.id);
	 strcat(id,".txt");
	 remove(id);
	 cout<<"\nUser I.D. Removed";
	 ofstream file;
		  file.open("log.txt",ios::app);
		  file<<"\nDeleted User ";
		  file<<po.id;
		  file.close();
	 getch();
	 idt();
}

void study::idt(){                               //ID FN
	_setcursortype(_NORMALCURSOR);
	sv:
	textcolor(WHITE);
	clrscr();
	char stu;
	gotoxy(25,5);
	cout<<"ENTER YOUR CHOICE\n";
	cout<<"1. LOGIN IDENTITY\n";
	cout<<"2. NEW IDENTITY\n";
	cout<<"3. DELETE IDENTITY\n";
	cout<<"4. EXIT\n\n\n ";
	textcolor(1+random(14));
	cprintf("PLEASE ENTER:");
	cin>>stu;
	textcolor(WHITE);
	switch(stu){
	case '1': face1();
		  display();
		  break;
	case '2': sure();
		  face2();
		  break;
	case '3': sure();
		  face1();
		  face3();
		  break;
	case '4': final();
		  break;
	default: goto sv;

	}
}

//***************************************************************************
 void study::display()                                 //DISPLAY FN
{   int co;
    clrscr();
    gotoxy(20,10);
   cout<<" ENTER SERIAL NUMBER OF YOUR CHOICE : "<<endl;
    gotoxy(20,12);
   cout<<" 1. CREATE NEW NOTES ";
    gotoxy(20,13);
   cout<<" 2. DISPLAY NOTES ";
    gotoxy(20,14);
   cout<<" 3. MODIFY NOTES ";
    gotoxy(20,15);
   cout<<" 4. DELETE NOTES ";
    gotoxy(20,16);
   cout<<" 5. LOG OUT ";
    gotoxy(20,17);
   cout<<" 6. EXIT ";
    gotoxy(16,19);
   cout<<" Enter: ";
   cin>>co;


   switch(co){

   case 1: create_notes();
	   break;
   case 2: display_notes();
	   break;
   case 3: modify_notes();
	   break;
   case 4: delete_notes();
	   break;
   case 5: log_out();
	   break;
   case 6: final();
	   break;
   default:{ gotoxy(16,19);
	   cout<<" You have entered wrong number ";
	   display();
	   }
   }
}

//+++++++++++++++++++++++++++++++++NOTES FUNTION ++++++++++++++++++++++++++++++
void study::create_notes(){                                  //CREAT NOTES FN
	clrscr();
	int a;
	cout<<"Choose a serial number whose notes you want to write:\n";
	cout<<"1. PHYSICS \n";
	cout<<"2. MATHS \n";
	cout<<"3. CHEMISTRY \n";
	cout<<"4. BACK\n";
	cout<<" Enter here :";
	cin>>a;
	switch (a){

		case 1: physics();
			break;
		case 2: maths();
			break;
		case 3: chemistry();
			break;
		case 4: display();
	       default: cout<<"You enter a wrong choice";
			create_notes();
			break;
		}


}
//+++++++++++++++++++++++++++++++ SUBJECT FUNCTION ++++++++++++++++++++++++++++
void study::physics(){                               //PHYSICS

	cout<<"\n\n write esc to discontinue\n";
	cout<<"Write notes here :";
	char ch[10];
	strcpy(ch,po.name);
	strcat(ch,"p.txt");
	ofstream fio(ch);
	char b[100];
	ll:
	gets(b);
	if(strcmp(b,"esc")!=0){
		fio<<b;
		fio<<"  ";
		goto ll;
	}
	else{
		fio.close();
		create_notes();
		getch();
	}

}
	//************************************************//
void study::chemistry(){                              //CHEMISTRY

	cout<<"\n\n write esc to discontinue\n";
	char ch[10];
	cout<<"Write notes here :";
	strcpy(ch,po.name);
	strcat(ch,"c.txt");
	ofstream fio(ch);
	char b[100];
	ll:
	gets(b);
	if(strcmp(b,"esc")!=0){
		fio<<b;
		fio<<"  ";
		goto ll;
	}
	else{
		fio.close();
		create_notes();
		getch();
	}
}
	//***************************************************//
void study::maths(){                            //MATHS

	cout<<"\n\n write esc to discontinue\n";
	char ch[10];
	cout<<"Write notes here :";
	strcpy(ch,po.name);
	strcat(ch,"m.txt");
	ofstream fio(ch);
	char b[100];
	ll:
	gets(b);
	if(strcmp(b,"esc")!=0){
		fio<<b;
		fio<<"  ";
		goto ll;
	}
	else{
		fio.close();
		create_notes();
		getch();
	}
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void study::display_notes(){                              //DISPLAY FN
	 clrscr();
	 char sub;
	 int a;
	 fstream fio;
	 cout<<"Which subject notes u want to see:\n";
	 cout<<"1.Enter p for physics\n";
	 cout<<"2.Enter m for maths\n";
	 cout<<"3.Enter c for chemistry\n";
	 cout<<"4.Press esc to go back\n";
	 cout<<"Enter:";
	 cin>>sub;
	 a=sub;
	 char ch[50];
	 if(sub=='p'){
		 strcpy(ch,po.name);
		 strcat(ch,"p.txt");
		 ifstream read(ch);
		 char r[100];
	 if(read){
		cout<<"Physics notes::\t";
		 while(!read.eof()){
			 read.getline(r,100);
			 puts(r);
		 }
		 fio.close();
		 getch();
	 }
	 else{
		cout<<"file doesn't exist/n";
		getch();
	 }
	 }
	 if(sub=='m'){
		 strcpy(ch,po.name);
		 strcat(ch,"m.txt");
		 ifstream read(ch);
		 char r[100];
	  if(read){
		cout<<"Maths notes::\t";
		 while(!read.eof()){
			 read.getline(r,100);
			 puts(r);
		 }
		 fio.close();
		 getch();
	 }
	 else{
		cout<<"file doesn't exist/n";
		getch();
	 }
	}
	 if(sub=='c'){
		 strcpy(ch,po.name);
		 strcat(ch,"c.txt");
		 ifstream read(ch);
		 char r[100];
	 if(read){
		 cout<<"chemistry notes::\t";
		 while(!read.eof()){
			 read.getline(r,100);
			 puts(r);
		 }
		 fio.close();
		 getch();
	 }
	 else{
		cout<<"file doesn't exist/n";
		getch();
	}
	}
	 else{
		if(a==27)
			display();
	 }
display_notes();
}

//***********************************************************************

void study::modify_notes(){                             //MODIFY NOTES
	clrscr();
	int a;
	cout<<"Choose a serial number whose notes you want to write:\n";
	cout<<"1. PHYSICS \n";
	cout<<"2. MATHS \n";
	cout<<"3. CHEMISTRY \n";
	cout<<"4. BACK\n";
	cout<<" Enter here :";
	cin>>a;
	switch (a){

		case 1: modifyphynts();
			break;
		case 2: modifymathnts();
			break;
		case 3: modifychemnts();
			break;
		case 4: display();

	       default: cout<<"You enter a wrong choice";
			modify_notes();
			break;
		}
}
void study::modifyphynts(){                               //PHYSICS
	cout<<"\n\n write esc to discontinue\n";
	char ch[10];
	strcpy(ch,po.name);
	strcat(ch,"p.txt");
	fstream fio;
	fio.open(ch,ios::in|ios::out|ios::app);
	char b[100];
	ll:
	gets(b);
	if(strcmp(b,"esc")!=0){
		fio<<b;
		fio<<"  ";
		goto ll;
	}
	else{
		fio.close();
		create_notes();
		getch();
	}
}//************************************************//
void study::modifychemnts(){                              //CHEMISTRY
	cout<<"\n\n write esc to discontinue\n";
	char ch[10];
	strcpy(ch,po.name);
	strcat(ch,"c.txt");
	fstream fio;
	fio.open(ch,ios::in|ios::out|ios::app);
	char b[100];
	ll:
	gets(b);
	if(strcmp(b,"esc")!=0){
		fio<<b;
		fio<<"  ";
		goto ll;
	}
	else{
		fio.close();
		create_notes();
		getch();
	}
}
	//***************************************************//
void study::modifymathnts(){                            //MATHS
	cout<<"\n\n write esc to discontinue\n";
	char ch[10];
	strcpy(ch,po.name);
	strcat(ch,"m.txt");
	fstream fio;
	fio.open(ch,ios::in|ios::out|ios::app);
	char b[100];
	ll:
	gets(b);
	if(strcmp(b,"esc")!=0){
		fio<<b;
		fio<<"  ";
		goto ll;
	}
	else{
		fio.close();
		create_notes();
		getch();
	}
}


void study::delete_notes(){
	clrscr();
	int a;			    //DELETE NOTES
	cout<<"which sub file you want to delete";
	cout<<"1. PHYSICS\n2. CHEMISTRY\n3. MATHS\n";
	cin>>a;
	fstream fin;
	char ch[10];
	if(a==1){
		strcpy(ch,po.name);
		strcat(ch,"p.txt");
		fin.open(ch,ios::in|ios::out|ios::app);
		remove(ch);
		cout<<"file deleted";
		getch();
		display();
	}
	if(a==2){
		strcpy(ch,po.name);
		strcat(ch,"c.txt");
		fin.open(ch,ios::in|ios::out|ios::app);
		remove(ch);
		cout<<"file deleted";
		getch();
		display();

	}
	if(a==3){
		strcpy(ch,po.name);
		strcat(ch,"m.txt");
		fin.open(ch,ios::in|ios::out|ios::app);
		remove(ch);
		cout<<"file deleted";
		getch();
		display();

	}
	else{
	cout<<"Wrong value entered";
	delay(350);
	delete_notes();
	}


}
void study::log_out(){                            //PROBLEM SOLVING
	clrscr();
	char ch;
	cout<<"\n\nARE YOU SURE!!!\n";
	cout<<"YOU WANT TO LOG OUT OR NOT(if yes then press(y or Y))\n";
	cin>>ch;
	if(ch=='y'||ch=='Y'){
	 idt();
	 }
	else
	 display();
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void main(){                                       //MAIN FUNCTION

clrscr();
ob.heading();
getch ();

}

//***************************************************************************
void study::heading()                                      //HEADING FN
{  clrscr();
   randomize();
   while(!kbhit()){
   textbackground(0);
   textcolor(1+random(14));
    gotoxy(1,7);
   cprintf("******** ******* *      * ********** *     *    ********* ******** *     * ****");
    gotoxy(1,8);
   cprintf("******** ******* *      * ********** *     *    ********* ******** *     * ****");
    gotoxy(1,9);
   cprintf("*           *    *      *   *      * *     *            * *      * **    * *    ");
    gotoxy(1,10);
   cprintf("*           *    *      *   *      * *     *           *  *      * * *   * *    ");
    gotoxy(1,11);
   cprintf("********    *    *      *   *      * *******          *   *      * *  *  * ****");
    gotoxy(1,12);
   cprintf("********    *    *      *   *      * *******        *     *      * *  *  * ****");
    gotoxy(1,13);
   cprintf("       *    *    *      *   *      *    *         *       *      * *   * * *    ");
    gotoxy(1,14);
   cprintf("       *    *    *      *   *      *    *       *         *      * *    ** *   ");
    gotoxy(1,15);
   cprintf("********    *    ******** **********    *       ********* ******** *     * ****");
    gotoxy(1,16);
   cprintf("********    *    ******** **********    *       ********* ******** *     * ****");
    _setcursortype(_NOCURSOR);
    delay(450);
    }
   getch();
   idt();

 }
 void study::final()
{

    clrscr();
    randomize();
    _setcursortype(_NOCURSOR);
    gotoxy(0,0);
    while(!kbhit())
    {       clrscr();

	textcolor(1+random(14));
	cprintf(" ");
	cout<<"\n\n\n";
	cout<<" ******************                     *   *	                 *   * "
	<<"\n ******************      	          *   *	               *   * "
	<<"\n   	*  *          		            *   *            *   * "
	<<"\n      	*  *            	              *   *       *   * "
	<<"\n      	*  *    	        	        *    *  *   * "
	<<"\n      	*  *    		        	  *       * "
	<<"\n      	*  *   		 		  	   *     * "
	<<"\n      	*  *   		    	 	   	    *   * "
	<<"\n      	*  *                                        *   * "
	<<"\n      	*  *				    	    *   * "
	<<"\n      	*  *    *   *   *****  *    *  *    *       *   *   *****  *    *"
	<<"\n      	*  *    *   *   *   *  **   *  *  *	    *   *   *   *  *    *"
	<<"\n      	*  *    *****   *   *  * *  *  * *	    *   *   *   *  *    *"
	<<"\n      	*  *    *   *   *****  *  * *  * * 	    *   *   *   *  *    *"
	<<"\n      	*  *    *   *   *   *  *   **  *  *  	    *   *   *   *  *    *"
	<<"\n      	*  *    *   *   *   *  *    *  *   * 	    *   *   *****  ******";
			delay(320);
}
 textcolor(WHITE);
  exit(0);
}


