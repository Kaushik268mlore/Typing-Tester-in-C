#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>


int T=30,c=0;

char name[15];
static int X=1;
#define p x_y(33,X++) 
#define dline  printf("................................");

 COORD cord={0,0};
 void rect(int a,int b,int c,int d)
{
    int k,t;
    x_y(a,b); printf("%c",201);
    for(k=a+1;k<c-1;k++){
        x_y(k,b);
        printf("%c",205);
    }
    x_y(k,b); printf("%c",187);

    for (t=b+1;t<d;t++){
        x_y(X,t);
        for(k=a;k<c;k++){
            if(k==a||k==c-1)
            
                x_y(k,t);
				printf("%c",186);
            }}

    x_y(a,t);
	 printf("%c",200);
    for(k=a+1;k<c-1;k++){
        x_y(k,t);
        printf("%c",205);}
x_y(k,t);
printf("%c",188);
}

void x_y(int x,int y){
    cord.X=x;
    cord.Y=y;
	SetcursorPos(GetStdHandle(STD_OUTPUT_HANDLE),cord);}
void gm_beg(){       
	int sc=0,ll=1,mode=100,count=0;
	clock_t begin;int time_spent,speed;

	int r,letter,ch;
    rect(5,5,60,20);
	late(499);

	srand(time(NULL)) ; 
	x=2;
	      p;
	set_color(12);
	printf("SELECT THE LEVEL");p;
	dline
	      p;
	printf("1) EASY");
	      p;
	printf("2)NORMAL");
	      p;
	printf("3)HARD");
	      p;
	printf("4)MAIN MENU");
	   p;
	scanf("%d",&ll);
	if(ll==4)
	       main();

	else

	{     if(ll==1)   
	       mode=65;
	     if(ll==2)    
		mode=97;
	     if(ll==3)    
		mode=120;
		begin=clock();
		while(1)
		{      
			time_spent=(int)(clock()-begin)/CLOCKS_PER_SEC;

			if(time_spent>=t)
			break;
			r=rand()%1000;
			r=r%26+mode;
			x_y(20,8);
			printf("....TYPE THE CHARACTERS SHOWN BELOW....");
			x_y(36,11) ;
			printf(" %c",r); 
			letter=getch();

			if(letter!=r)
			break;
			else
			{       count++;
				sc+=10;
				x_y(28,9);
				printf("sc=%d",sc);
				x_y(37,9);
				printf("time_spent=%d sec",time_spent);

				if(ll==1)
				late(399);
				if(ll==2)
				late(199);
				if(ll==3)
				late(399);

			} 
		}
		x_y(26,x);

		late(633);

		set_color(5);
		x++;
		p;
		speed=(count*60)/time_spent ;
	       
		if(time_spent<t-1)
		printf("GAME OVER");
		else
		{       set_color(11);
			printf("Times up !Game over!");
			p;
			set_color(5);
			if((speed>=40)&&(speed<=50))
			{	printf("GREAT JOB");p;

				printf("U EARNED A SILVER MEDAL");
			}
			else
			if(speed>50)
			{
				printf("U EARNED A GOLD MEDAL");
			}
			else
			printf("SORRY U NEED MORE PRACTICE TO EARN A MEDAL");
		}
		p;
		printf("Your score will be ::%d",sc);
		p;

		printf("Your total speed is equal to=%d letter per minute",speed);

		get_score(sc,speed,ll);
		++x;
		p;
		printf("1. PLAY AGAIN \n");
		p;

		printf("2.GO To MAIN MENU");p;
		printf("3.EXIT"); p;
		printf("ENTER YOUR CHOICE::\n");
		scanf("%d",&ch);
		switch(ch)
		{
		      case 1:gm_beg();break;
		      case 2:main();break;
		      case 3:x_y(17,10);printf("This Game is created by Kaushik Kumar");late(1555);exit(1);
		      default:p;
			      printf("wrong choice!");
			      p;
				  main();}}}


void time_setter()  
{
	int ch;
	set_color(11);
	x=5;
	p;
	printf("Set the time limit for game in minute::");
	p;
	dline
	p;
	printf("press 0 for half minute") ;p;
	printf("press 1 for 1 minute"); p;
	printf("press 2 for 2 minute");p;
	scanf("%d",&ch);
	switch(ch)
	{
		case 0:t=30;break;
		case 1:t=60;break;
		case 2:t=120;break;
		default:main();
	}
}


void game_rules()
{
	system("cls");
	x_y(7,5);
	set_color(6);

	printf("#......Rules of the Game......#");x_y(7,6);
	printf("=>Enter your name as player name");x_y(7,7);
	printf("=>Set the time limit under option 3 in main menu(default limit is 30 sec)");x_y(7,8);
	printf("=>select the level and get started :");x_y(7,9);
	printf("=>Characters are displayed and you have to type them as fast as you can..");x_y(7,10);
	printf("=>Avoid incorrect typing otherwise game will be over..");
	getch();main();
}

void get_score(int sc,int speed,int ll)
{
	FILE *fp;
	fp=fopen("file.txt","a");
	p;
	if(fp==NULL)
	printf("error in opening file");
	fprintf(fp,"\nname=%s   score=%d    speed=%d    level=%d",name,score,speed,ll);
	fclose(fp);
	p;
	printf("scorecard updated");
}
void hall_of_fame()
{       int ch;
	FILE *fp;
	x=3;

	printf("\t\t\t....The scores are...\n");

	fp=fopen("file.txt","r");
	while((ch=fgetc(fp))!=EOF)
	{	printf("%c",ch);
	}
	getch();
	main();
}

void late(unsigned int mseconds)//function that can delay the next flow of control
{
    clock_t goal=mseconds+clock();
    while(goal>clock());
}





//main function
int main()
{       int ch;

	time_t t;
	time(&t);
	x=1;
	system("cls");
	p;
	set_color(12) ;
	printf("WELCOME TO THE TYPING GAME\n");
	set_color(10) ;
	p;
	printf("%s",ctime(&t));
	p;
    dline p;
	if(c==0)
	   {	printf("Enter the  player's name::\n");
		gets(name);
	   }
	   c++;
	    p;dline ;p;
		printf("THE MENU!!!!");p;
		dline
		p;
		printf("1.Start The Game\n");
		p;
		printf("2.Set the time limit::\n");
		p;
		printf("3.Display the scorecard\n");
		p;
		printf("4.Ask Help\n");
		p;
		printf("0.EXIT!!\n");
		p;
		printf("Please Enter your choice::\n");
		scanf("%d",&ch);
		p;
		switch(ch)
		{       case 1:gm_beg();break;
			case 2:hall_of_fame();break;
			case 3:time_setter();main();
			case 4:game_rules();break;
			case 0:system("cls");x_y(19,20);printf("This Game is created by Kaushik Kumar\n");late(1555);exit(1);
			default:main();
		}

getch();
}



