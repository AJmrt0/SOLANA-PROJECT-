#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<dos.h>
#include<fstream.h>
int gkey=0;
int keyt=0;
int keyd=0;
char pk[15];
int skey=0;
int keyl=0;
int mout=0;

class login{

    public:
    char user[25];
    char pwd[20];
    char rpw[15];
    char mno[10];
    char ban[15];

    int bal;
    int wd;
    int dep;
    void getregester();
    void signin();
    void withdraw(int);
    void deposit(int);
    void transfer();
    void changeprofile();
    void accontsummary();
    }up1,up2,up4;


    void login::getregester()

    {

    textcolor(BLUE);
    textbackground(YELLOW);
    clrscr();
    ofstream out1;
    out1.open("record.dat",ios::app|ios::binary);
    cout<<"USERNAME:   \t";
    gets(user);
    int passflag=0;
    do
    {
    if(passflag)cout<<"Passwords do not match\n";
    passflag=1;
    cout<<"\nPASSWORD:    \t";
    gets(pwd);
    cout<<"\nCONFIRM PASSWORD:   \t";
    gets(rpw);
    }


    while(strcmp(pwd,rpw) !=0;
    int numflag=0;
    do


    {
    if(numflag)cout<<"\nNOT A VALID NUMBER\n";
    numflag=1;
    cout<<"\nMOBILE NUMBER:    \t";
    gets(mno);
    }
    while(strlen(mno)!=10);
    fstream in2;
    in2.open("record.dat",ios::in|ios::binary);


    while(in2)
    {
    in2.read((char*)&up2,sizeof(up2));
    if((strcmpi(mno,up2.mno)==0))
    {
    skey++;
    break;
    }
  }


  cout<<"\nBANK ACCOUNT NUMBER:\t";
  gets(ban);

  cout<<"\nSTART YOUR ACCOUNT WITH A MINIMUM BALANCE:\t";
  cin>>bal;
  cout<<"\nPRESS ANY KEY"<<endl;

  getch();
  if(skey==0){
  out1.write((char*)&up1,size of(up1));
  textcolor(WHITE);
  textbackground(BLACK);
  clrscr();
  gotoxy(40,15);
  cprintf("ACCOUNT CREATED:)");
  out1.close();
  getch();
  }

  else
  cout<<"SORRY,MOBILE NUMBER ALREADY REGISTERED."<<endl;

  }

   void login::signin()
   {
   char un2[11];
   char pw2[20];
   textbackground(BLACK);
   textcolor(WHITE);
   clrscr();
   gotoxy(30,12);
   cout<<"MOBILE NO.:\t";
   gets(un2);
   gotoxy(30,13);
   cout<<"PASSWORD:\t";
   gets(pw2);
   ifstream in2;
   in2.open("record.dat",ios::in|ios::binary);
   keyl=0;
   while(in2)
   {
    in2.red((char*)&up1,size(up1));
     if((strcmpi(un2,up1.mno)==0)&&(strcmpi(pw2,up2.pwd)==0))
     {
     textcolor(RED);
     textbackground(WHITE);
     clrscr();
     gotoxy(25,11);
     cout<<"Welcome to your account\n";delay(300);
     gotoxy(25,12);
     cout<<"User name":<<upl.user<<endl;delay(300);
     gotoxy(25,13);
     cout<<"mobile number:":<<upl.mno<<endl;delay(300);
     gotoxy(25,14);
     cout<<"Bank account number :":<<upl.ban<<endl;delay(300);
     gotoxy(25,15);
     cout<<"Current balance :":<<upl.bal<<en dl;delay(300);
     keyl++;
     break;

     }
     else
     {
     continue;
     }
    }

    if(keyl==0)
    {
    textcolor(Black);
    textbackground(WHITE);
    clrscr();
    cout<<"\nEither the Mobile number or the password you entered is incorrect .";
    }
    in2.close();
    getch():
    }

    void login::withdraw(intwa)
    { int amt=wa,key=0;login upt;
    fstream in3("record.dat",ios::in|ios::out|ios::binary);

    if((amt<=up1.bal)&&(amt>0))
    {
    key=1;
    }

    else if(amt>up1.bal)
    {
    cout<<"\nNot enough balance.";
    gkey=1;
    return;
    }
    if(key)
    { bal=bal-amt;
      wd++;
      long pos;
      //fstream in4("record.dat",ios::in|ios::out|ios::binary);
      while(in3)
      {
      pos=in3.tellg();
	in3.read((char*)&upt,sizeof(upt));
	if(in3.eof())break;

	if(strcmpi(upt.user,user)==0)
	{
	  upt.bal=upt.bal-amt;

	  in3.seekp(pos);
	  upt.wd++;
	  in3.write((char*)&upt,sizeof(upt));


	  break;

	  }

       }


       }
       in3.close();
       }

       void login::deposit(int da)
       {int amt=da,key=0;login upt;
       if(amt>0)

       {
       key=1;


       }
       else if(amt<=0)
       {gotoxy(25,12);
       cout<<"\nNegative amount can't be added.";

       keyd=1;
       getch();
       }
       if(key)
       {
       bal=bal+amt;
       dep++;
       fstream in4("record.dat",ios::in|ios::out|ios::binary);
       long pos;
       while(!in4.eof())
       {
       pos=in4.tellg();
       in4.read((char*)&upt,sizeof(upt));
       if(strcmpi(upt.user,user)==0)
       {
       upt.bal=upt.bal+amt;

	   in4.seekg(pos);
	   upt.dep++;
	   in4.write((char*)&upt,sizeof(upt));


	   getch();
	   break;
	   }
       }
       in4.close();
       }
      }
      void login::transfer()
      {
      injt amt;char ut[20];login upt;
      textcolor( BLACK);
      textbackground(WHITE);
      clrscr();
      gotoxy(25,12);
      cout<<"Enter the amount you want to transfer:";
      gotoxy(25,13);
      cin>>amt;
      gotoxy(17,14);
      cout<<"Enter the mobile number you want to send the money to:";
      gotoxy(25,15);
      gets(ut);
      gotoxy(25,16);
      withdraw(amt);



      ifstream in5("record.dat",ios::in|ios::binary);
      while(!in5.eof())
      {
      in5.read((char*)&upt,sizeof(upt));

      if(strcmpi(upt.mno,ut)==0)
      {
      if(gkey==0)
      {
      upt.deposit(amt);
      keyt=1;
      break;

      }
      else
       keyt=0;
       }
       }
       if(keyt==1)
       {
	 textcolor(BLACK);
	 textbackground(WHITE);
	 clrscr();
	 gotoxy(25,12);
	 cout<<"Rs"<<amt<<"tranfered from";
	 gotoxy(25,13);
	 puts(up1.user);
	 gotoxy(25,14);
	 cout<<"to";
	 gotoxy(25,15);
	 puts(upt.user);
	 getch();
	 }
	 else if(keyt==0)
	 {
	 gotoxy(25,17);
	 cout<<"Transaction Failed.";
	 }
	 in5.close();
	 getch();

	 }
	 voidlogin::changeprofile()
	 {
	 clrscr();
	 cout<<"\nEnter new user details"<<endl;


	 textcolor(BLACK);
	 textbackground(WHITE);
	 clrscr();
	 ofstream out1;
	 out1.open("record.dat",iosw::app|ios::binary);
	 cout<<"USERNAME:    \t";
	 gets(user);
	 int passflag=0;
	 do
	 {
	 if(passflag) cout<<"Passwords do not match\n";
	 passflag=1;
	 cout<<"\nPASSWORD:    \t";
	 gets(pwd);
	 cout<<"\Confirm password:  \t";
	 gets(rpw);
	 }
	 while(strcp(pwd,rpw)!=0);

	 int numflag=0;
	 do
	 {
	 if(numflag)cout<<"Not a valid number\n";
	 numflag=1;
	 cout<<"\n Mobile Number:     \t";
	 gets(mno);
	 }
	 while(stlen(mno)!=10);


	 cout<<"\n Bank Account Number:\t";
	 gets(ban);
	 cout<<"\n press any key";
	 getch();

	 out.write((char*)&up1,sizeof(up1));
	 clrscr();
	 textcolor(BLACK);
	 textbackground(WHITE);
	 out1.close();
	 ifstream in3("record.dat",ios::in);
	 ofstream out3("temp.dat",ios::out)l
	 while(!in3.eof())
	 {
	 in3.read((char*)&up2,sizeof(up2));
	 if(strcmpi(up2.user,up1.user)==0)
	 {
	 continue;
	 }
	 else
	 out3.write((char*)&up2,sizeof(up2));
	 }
	 remove("record.dat");
	 rename("temp.dat","record.dat");
	 cprintf("\n  Account Updated:)");
	 getch();
	 }
	 void login::accontsummary()
	 {
	 login upt;
	 textcolor(GREEN);
	 textbackground(BLACK);
	 clrscr();
	 gotoxy(25,12);
	 cout<<"Number of deposits:"<<dep<<endl;
	 gotoxy(25,13);
	 cout<<"Number of withdrawls:"<<wd<<endl;

	 ifstream in3;
	 in3.read((char*)&upt,sizeof(upt));
	 if(strcmpi(upt.user,user)==0)
	 {gotoxy(25,14);
	 cout<<"Current balance"<<upt.bal<<endl;
	 }
	 getch();
	 }
	 void cinema()
	 {
	 textcolor(BLACK);
	 textbackground(WHITE);
	 clrscr();
	 cout<<"\nCurrent balance:"<<up1.bal;
	 char cinema[40];
	cout<<"\nenter the name of the movie you want to watch:";
	gets(cinema);
	char film[20];
	cout<<"\nIn which theatre do you want to watch the cinema?:";
	gets(film);
	int seat;
	cout<<"\n 1.Platinum";	cout<<"\nChoose your seat:";
	cout<<"\n 1.Platinum";
	cout<<"\n 1.Gold";
	cout<<"\n 1.Silver"<<endl<<" ";
	cin>>sseat;
	int nseat;
	cout<<"\n Enter the number of seats:";
	cin>>nseat;

	switch(seat)
	{ case1
	   up1.withdraw(nseat*300);
	   if(gkey==0){
	   textcolor(GREEN);
	   textbackground(BLACK);
	   clrscr();
	   gotoxy(25,9);
	   cout<<nseat<<"tickets for"<<endl;
	   gotoxy(25,10);
	   puts(cinema);
	   gotoxy(25,11);
	   cout<<"at"<<endl;
	   gotoxy(25,12);
	   puts(film);
	   gotoxy(25,13);
	   cout<<"booked in platinum section for Rs."<<nseat*300<<endl;}
	   break;

	   case2
	   up1.withdraw(nseat*200);
	   if(gkey==0){
	   textcolor(GREEN);
	   textbackground(BLACK);
	   clracr();
	   gotoxy(25,9);
	   cout<<nseat<<"tickets for"<<endl;
	   gotoxy(25,10);
	   puts(cinema);
	   gotoxy(25,11);
	   cout<<"at"<<endl;
	   gotoxy(25,12);
	   puts(film);
	   gotoxy(25,13);
	   cout<<"booked in Gold section for Rs."<<nseat*200<<endl;
	   }
	   break;
	   case3
	   up1.withdraw(nseat*180);
	   if(gkey==0)
	   {
	   textcolor(GREEN);
	   textbackground(BLACK);
	   clrscr();
	   gotoxy(25,9);
	   cout<<nseat<<"tickets for";
	   gotoxy(25,10);
	   puts(cinema);
	   gotoxy(25,11);
	   cout<<"at";
	   gotoxy(25,12);
	   puts(film);
	   gotoxy(25,13);
	   cout<<"booked in silver section for Rs."<<nseat*180<<endl;}
	   break;

	   default:gotoxy(25,9);
	    cout<<"\n Valid option not chosen";
	    gotoxy(25,10);
	     cout<<"\n Transaction Cancelled";

	   }
	   getch();
	   }
	   void showflix()
	   {
	   textbackground(WHITE);
	   textcolor(BLACK);
	   clrscr();
	    cout<<"\n Current balance"<<up1.bal;
	    char flix[20];
	     cout<<"\n Enter your Showflix ID:\t";
	     gets(flix);
	     int months;
	     cout<<"\n Enter the number of months you want to recharge for:\t";
	     cin>>months;
	     up1.withdraw(months*500);


	     if(gkey==0)
	     {
	     textbackground(BLACK);
	     textcolor(GREEN);
	     clrscr();
	     gotoxy(25,12);
	       cout<<"\nShowflix for"<<endl;
	     gotoxy(25,13);
	      puts(flix);
	      gotoxy(25,14);
	      cout<<"recharged for"<<months<<"months";
	      gotoxy(25,15);
	      cout<<"\ncost:"<<months*500<<endl;
	      }
	      else
	      {
	      cout<<"\nTransaction failed.";
	      }
	      getch();
	      }
	      void mobile()
	       {
	      textcolor(BLACK);
	      textbackground(WHITE);
	      clrscr();
	      gotoxy(25,12);
		cout<<"\Current balance:"<<up1.bal;
		char mobile[15];
		int numflag1=0;
		do
		{
		if(numflag1)
		{
		gotoxy(25,15);
		  cout<<"\Not a valid number" ;
		 numflag1=0;
		 getch();
		 }
		 gotoxy(15,14);
		 cout<<"Enter the number you wish to recharge:\t";
		 gets(mobile);
		 if(strlen(mobile)!=10 )
		 numflag1=1;
		 }
		 while(strlen(mobile)!=10);
		 gotoxy(25,15);
		 cout<<"      ";
		 int recharge;
		 gotoxy(25,16);
		 cout<<"Enter recharge amount:\t";
		 cin>>recharge;
		 up1.withdraw(recharge);
		 if(gkey==0)
		 {
		 textcolor(GREEN);
		 textbackground(BLACK);
		 clrscr():
		gotoxy (20,12);
	       cout<<mobile<<"succesfully recharged with Rs"<<recharge;
	       }
	       else
	       {
	       gotoxy(25,17);
	       cout<<"Transaction failed";
	       }
	       getch();
	       }

	       void quit()
	       {
	       int rev=0;
	       while(!rev)
	       {
	       rev=0;
	       textcolor(BLACK);
	       textbackground(WHITE);
	       clrscr();
	      gotoxy(25,8);
	      cout<<"THANKS FOR USING C-WALLET";
	      int feed;
	      gotoxy(25,9);
	      cout<<"PLEASE LEAVE YOUR FEEDBACK:";
	      gotoxy(25,10);
	      cout<<"1.POOR";
	      gotoxy(25,11);
	       cout<<"2.SATISFACTORY";
	       gotoxy(25,11);
		cout<<"3.GOOD";
		gotoxy(25,13);
		cin>>feed;
		gotoxy(25,14);
		switch(feed)
		{
		case1:cout<<"WE ARE EXTREMELY SORRY FOR THE INCONVINIENCE.";
		gotoxy(25,15);
		cout<<"WE WILL TRY TO SOLVE ALL THE ISSUE.";
		rev++;
		getch():
		break;
		case2:cout<<"WE ARE HAPPY YOU LIKED IT.";
		gotoxy(25,15);
		cout<<"WE WILL TRY TO SOLVE ALL THE ISSUE.";
		rev++;
		getch():
		break;
		case3:cout<<"THANK YOU FOR YOUR SUPPORT.";
		gotoxy(25,15);
		cout<<"WE HOPE YOU'LL RETURN IN FUTURE.";
		rev++;
		getch():
		break;
		default:cout<<"PLEASE CHOOSE AVALID REVIEW.";
		getch();
		 }
	       }
	      }
	      void main()
	      {
	      textcolor(GREEN);
	      textbackground(BLACK);
	      clrscr();



	    gotoxy(25,10);
	    cout<<"     *******":gotoxy(25,11); delay(50);
	    cout<<"     *** ***":gotoxy(25,12); delay(50);
	    cout<<"     ***":gotoxy(25,13); delay(50);
	    cout<<"     ***":gotoxy(25,14); delay(50);
	    cout<<"     *** ***":gotoxy(25,15); delay(50);
	    cout<<"     *** ***":gotoxy(25,16); delay(50);
	    cout<<"     ********":gotoxy(25,17); delay(500);


	    clrscr();
	    gotoxy(25,10);
	    cout<<"     ***    ***":gotoxy(25,11); delay(50);
	    cout<<"     ***  ***":gotoxy(25,12); delay(50);
	    cout<<"     *******":gotoxy(25,13); delay(50);
	    cout<<"     *** ** ***":gotoxy(25,14); delay(50);
	    cout<<"     *** ** ***":gotoxy(25,15); delay(50);
	    cout<<"     *** **** ***":gotoxy(25,16); delay(500);


	    clrscr();
	    gotoxy(25,10);
	    cout<<"     ******":gotoxy(25,11); delay(50);
	    cout<<"     ***  ***":gotoxy(25,12); delay(50);
	    cout<<"     *** ** ***":gotoxy(25,13); delay(50);
	    cout<<"     *** ** ***":gotoxy(25,14); delay(50);
	    cout<<"     ***  ***":gotoxy(25,15); delay(50);
	    cout<<"     ***  ***":gotoxy(25,16); delay(500);



	    clrscr();

	    gotoxy(25,10);
	     cout<<"     ***":gotoxy(25,11); delay(50);
	    cout<<"     ***  ":gotoxy(25,12); delay(50);
	    cout<<"     *** ":gotoxy(25,13); delay(50);
	    cout<<"     *** ":gotoxy(25,14); delay(50);
	    cout<<"     ***":gotoxy(25,15); delay(50);
	    cout<<"     ********":gotoxy(25,16); delay(50);
	    cout<<"     ********":gotoxy(25,17); delay(500);


	    clrscr();

	    gotoxy(25,10);
	     cout<<"     ***":gotoxy(25,11); delay(50);
	    cout<<"     ***  ":gotoxy(25,12); delay(50);
	    cout<<"     *** ":gotoxy(25,13); delay(50);
	    cout<<"     *** ":gotoxy(25,14); delay(50);
	    cout<<"     ***":gotoxy(25,15); delay(50);
	    cout<<"     ********":gotoxy(25,16); delay(50);
	    cout<<"     ********":gotoxy(25,17); delay(500);

	    clrscr();

	    gotoxy(25,10);
	     cout<<"     ********":gotoxy(25,11); delay(50);
	    cout<<"     ********  ":gotoxy(25,12); delay(50);
	    cout<<"     *** ":gotoxy(25,13); delay(50);
	    cout<<"     ***** ":gotoxy(25,14); delay(50);
	    cout<<"     ***":gotoxy(25,15); delay(50);
	    cout<<"     ********":gotoxy(25,16); delay(50);
	    cout<<"     ********":gotoxy(25,17); delay(500);

	    clrscr();

	    gotoxy(25,10);
	     cout<<"     ********":gotoxy(25,11); delay(50);
	    cout<<"     ********  ":gotoxy(25,12); delay(50);
	    cout<<"     *** ":gotoxy(25,13); delay(50);
	    cout<<"     ***** ":gotoxy(25,14); delay(50);
	    cout<<"     ***":gotoxy(25,15); delay(50);
	    cout<<"     ********":gotoxy(25,16); delay(50);
	    cout<<"     ********":gotoxy(25,17); delay(500);
	    textbackground(WHITE);
	    textcolor(BLACK);
	    clrscr();
	   textbackground(25,10);
	   textcolor(RED);
	   cprintf("***WELCOME TO C-WALLET***");
	   getch();
	   int n,gotoxy(25,11);
	   cout<<"Please chose an option:";
	   delay(800);
	   gotoxy(25,12);
	   cout<<"1:Log In";
	   gotoxy(25,13);
	   delay(800);
	   gotoxy(25,14);
	   cout<<"3:Exit";
	   delay(800);
	   gotoxy(25,15);
	   cin>>n;
	   int out=0;
	   switch(n)
	   {
	     case1: up1.signin();
	     do
	     {
	     out=0,keyd=0;gkey=0,keyt=0;
	     if(keyl!=0)
	     {
	     textcolor(BLACK);
	     textbackground(White);
	     clrscr();
	     gotoxy(25,7);
	     cout<<"Current balance:"<<up1.bal;
	     gotoxy(25,8);
	     delay(500;
	     cout<<"What do you want to do with your money?";
	     gotoxy(25,9);
	     delay(500);
	     cout<"1.Pay for a service.";
	     gotoxy(25,10);
	     delay(500);
	     cout<<"2.Recharge.";
	     gotoxy(25,11);
	     delay(500);
	     cout<<"3.Transfer."<<endl;
	     gotoxy(25,13);
	     delay(500);
	     cout<<"Press 4 to edit profile."<<endl;
	     gotoxy(25,15);
	     delay(500);
	     cout<<"Press 5 to view account summary."<<endl;
	     gotoxy(25,17);
	     delay(500);
	     cout<<"Press 6 to sign out."<<endl;
	     gotoxy(25,18);
	     int mon;
	     cin>>mon;
	     switch(mon)
	     {
	     case1:b textcolor(BLACK);
	     textbackground(WHITE );
	     clrscr();
	     gotoxy(25,11);
	       cout<<"Current balance:Rs."<<up1.bal;
	       gotoxy(25,12);
	       cout<<"What do you want to pay for?";
		gotoxy(25,13);
	       cout<<"1.Mobile recharge.";
		gotoxy(25,14);
		cout<<"2.Cinema tickets.";
		gotoxy(25,15);
		cout<<"3.Showflix Subscription"<<end;
		gotocy(25,16);
		int with;
		cin>>with;


		switch(with)
		{
		case1:mobile();
		getch();
		break;

		case2:cinema();
		getch();
		break;

		case3:showflix();
		getch();
		break;
		default:gotoxy(25,16);
		cout<<"PLEASE RECONSIDER YOUR CHOICE AS IT IS WRONG."<<endl;
		getch():

		}
		break;

		case2:textcolor(BLACK);
		textbackground(WHITE);
		clrscr();
		gotoxy(10,10);
		cout<<"Enter the amount you want to recharge the wallet with:";
		in dep;
		cin>>dep;
		up1.deposit(dep);
		if(!keyd)
		{
		textcolor(GREEN);
		textbackground(BLACK);
		clrscr();
		gotoxy(25,13);
		cout<<"Rs"<<dep<<"successfully added to":
		puts(up1.user);
		{
		gotoxy(25,13);
		cout<<"\n Transaction Failed.";
		}
		getch();
		break;

		case3:up1.transfer();
		getch();
		break;

		case4:up1.changeprofile();
		getch();
		break;

		case5:up1.accountsummary();
		getch();
		break;
		case6:out++;
		break;
		default:cout<<"\nPlease choose a valid option";
		getch();


		}
	     }
	     else if(keyl==0)
	     {
	     out=1;
	     continue;
	     }
	     }
	     while(!out);
	     getch():
	     break;
	     case2:up1.getregister();
	     getch();
	     break;

	     case3:quit();
	     getch();
	     mout=1;
	     break;
	     default:cout<<"\n you did not choose a valid opyion"<<endl;
	     getch():
	     break;
	     }
	     }
	     while(mout==0):
	     textbackground(BLACK);
	     clrscr();
	     getch();
