#include<ctype.h>
#include<stdlib.h>
#include<dos.h>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<iostream.h>
#include<constrea.h>
#include <fstream.h>
#include<string.h>
#include<time.h>

char o1,o2,o3,o4,o5,out6='a';
int l1,l2,l3=1,l4,i=0,j=0;
char question_subpart[6][250];
int val = 0;
float cheque_val = 0.00;

class mainf{
  public:
  	void playSound(){
		int a = 1;
		for(;a<20;a++) {
			sound(a*500);
			delay(500);
		}
		nosound();
	}
	void cheque(float rupees){
		char dateStr [9];
		_strdate( dateStr);
		char date_part[2];
		date_part[1]=' ';
		
		setbkcolor(1);
		setcolor(11);
		int vertices[] = {40,40,600,40,600,280,40,280,40,40};
		setfillstyle(11,2);
		rectangle(40,40,600,280);
		fillpoly(5,vertices);
		setcolor(YELLOW);
		outtextxy(50,50,"ICICI Bank");
		outtextxy(50,60,"New Delhi Branch");
		outtextxy(50,70,"9A, Phelps Building,");
		outtextxy(50,80,"Connaught Place, New Delhi");
		outtextxy(50,90,"RTGS / NEFT IFSC Code : ICIC00007");
		outtextxy(380,50,"Valid For Three Months only");
		rectangle(380,70,400,90);
		date_part[0]=dateStr[3];
		date_part[1]='\0';
		outtextxy(383,76,date_part);
		rectangle(400,70,420,90);
		date_part[0]=dateStr[4];
		outtextxy(403,76,date_part);
		rectangle(420,70,440,90);
		date_part[0]=dateStr[0];
		outtextxy(423,76,date_part);
		rectangle(440,70,460,90);
		date_part[0]=dateStr[1];
		outtextxy(443,76,date_part);
		rectangle(460,70,480,90);
		outtextxy(463,76,"2");
		rectangle(480,70,500,90);
		outtextxy(483,76,"0");
		rectangle(500,70,520,90);
		date_part[0]=dateStr[6];
		outtextxy(503,76,date_part);
		rectangle(520,70,540,90);
		date_part[0]=dateStr[7];
		outtextxy(523,76,date_part);
		outtextxy(390,100,"D D  M M  Y Y Y Y");
		outtextxy(50,125,"Pay");
		line(110,135,400,135);
		outtextxy(110,125,"Arnav Mahajan");
		outtextxy(50,140,"Rupees");
		//converting char in string
		char rup_buf[12] ;
		sprintf(rup_buf,"%.0f",rupees) ;
		outtextxy(110,140,rup_buf);
		line(110,150,400,150);
		outtextxy(70,170,"A/c no: 0007657976");
		outtextxy(350,230,"Authorised Signature");
		delay(10000);
		exit(0);
	}

  void primary(){
	for (int i=0;i<10;i++) {
		clrscr();
		cleardevice();
		question(i);
		callfun();
		delay(1000);
		l3++;
		for(int j=0;j<6;j++){
			for(int k=0;k<250;k++){
				question_subpart[j][k]=' ';
			}
		}
	}
  }
};

	mainf obj;

void getQuestion(int question_no) {
	//for debigging purposes only
	int debug = 0;

	//making file object
	ifstream f;
	f.open("kbc.txt");


	//defining question array
	char question_array[10][250]; // array to hold multiple questions
	//char question_subpart[6][250]; //array to hold question,options and right answer

	//making questions array
	while(!f.eof()) {
		for(int i=0;i<10;i++){
			f.getline(question_array[i], 250);
		}
	} //File reading end

	//printing question array for debug purposes
	if(debug)
		cout << question_array[1]<<"\n";

	//closing file objecct
	f.close();

	int i=0,j=0,k=0;
	int r_cnt = 0;

	if(debug)
		cout<<"\n";

	for(j=0;j<250;j++){

	  if(question_array[question_no][j]=='$') {
		r_cnt++; //to move to subpart array next element
		k=0;     //resetting from start for next element
	  } else {
		question_subpart[r_cnt][k] = question_array[question_no][j];
		k++;
	  }
	  //exiting the loop as no further option left
	  if(r_cnt>5)
		j=250;
	}

	//debug purposes
	if(debug){
		for(int m=0; m<6; m++)
			cout<<"\Subpart["<<m<<"]:"<<question_subpart[m]<<"\n";
	}


}

void questionboxes(){
	//OPTION SCRREN
	setcolor(BLUE);
	line(00,350,20,360);
	line(00,350,20,340);
	line(20,340,100,340);
	line(20,360,100,360);
	line(100,340,120,350);
	line(100,360,120,350);
	line(120,350,140,360);
	line(140,360,220,360);
	line(120,350,100,340);
	line(140,340,220,340);
	line(120,350,140,340);
	line(220,360,240,350);
	line(220,340,240,350);
	line(100,360,120,370);
	line(120,370,100,380);
	line(100,380,20,380);
	line(20,380,00,370);
	line(00,370,20,360);
	line(120,370,140,360);
	line(120,370,140,380);
	line(140,380,220,380);
	line(220,380,240,370);
	line(240,370,220,360);
}

void lifelinesboxes(){
	//lifelines
	setcolor(RED);
	rectangle(500,50,580,70);
	rectangle(480,50,400,70);
	rectangle(480,90,400,110);
	rectangle(500,90,580,110);
}

void lifelineoptiontext(){
	//lifelines option
	 outtextxy(517,58,"50:50");
	 outtextxy(404,58,"AUDIENCE");
	 outtextxy(410,98,"PHONE");
	 outtextxy(517,98,"EXPERT");
}

void question(int i){
	//setting question
	getQuestion(i);
	setcolor(WHITE);
	outtextxy(0,100,question_subpart[0]);
}

void multipleanswers(){
	//setting question option
	setcolor(WHITE);
	outtextxy(14,347,question_subpart[1]);
	outtextxy(14,367,question_subpart[2]);
	outtextxy(137,347,question_subpart[3]);
	outtextxy(137,367,question_subpart[4]);
}

void currentquestionposition(){
	int i;
	val = 50;
	char buf[12];
	int y_pos = 450;

	//painting vertical divider line
	setcolor(WHITE);
	line( 370,10,370,490);

	for (i = 1; i <11; i++) {
		//seeting colors as per question number
		//Any question which i sless than current is red, current question blue
		// Any question greater than current is yellow
		if(i<l3)
			setcolor(RED);
		else if(i==l3){
			setcolor(BLUE);
			cheque_val = val;
		}
		else
			setcolor(YELLOW);

		//concatinating the strings in variable buf
		sprintf(buf, "Q-%d: %d", i, val); // puts string into buffer

		//painting the question number
		outtextxy(400,y_pos,buf);

		//increasing question value for next question
		val = val*2;

		//setting Y position for next question
		y_pos = y_pos - 20;
	}
}

void useroption(){
	//painting additional option at bottom
	setcolor(RED);
	outtextxy(0,400,"Your Option(PRESS e FOR LIFELINES): ");
	outtextxy(0,410,"Need Any Help??");
	outtextxy(0,420,"1. 50:50       2. EXPERT");
	outtextxy(0,430,"3. PHONE       4. AUIDENCE");
}

void answerbox(){
	setcolor(RED);
	cout<<"\nAnswer Box: ";
	setcolor(RED);
	rectangle(90,15,130,30);
}


void answerafterlifeline(){
	//capturing user answer
	cin>>o2;

	setcolor(YELLOW);

	//If user provids correct answer
	if(o2==question_subpart[5][0]){
		outtextxy(0,440,"Correct Answer");
	}
	else if(tolower(o2)=='e'){
		//user opt for helpline
		outtextxy(0,440,"Which One?? Press Number Acoording To It!!");

		//capturing user input for helpline
		cin>>l1;

		//user opted for 50-50 option
		if(l1==1){
			//Painting cross lines for 50:50 option on right side
			line(500,50,580,70);
			line(580,50,500,70);

			//if right answer is 'a' than cross following options
			if(question_subpart[5][0]=='a') {
				//for second
				line(145,340,220,360);
				line(145,360,220,340);

				//for third
				line(20,360,100,380);
				line(20,380,100,360);

			} else if(question_subpart[5][0]=='b') {
				//for first
				line(20,340,100,360);
				line(20,360,100,340);

				//for fourth
				line(145,360,220,380);
				line(145,380,220,360);

			} else if(question_subpart[5][0]=='c') {
				//for first
				line(20,340,100,360);
				line(20,360,100,340);

				//for second
				line(145,340,220,360);
				line(145,360,220,340);

			} else if(question_subpart[5][0]=='d') {
				//for second
				line(145,340,220,360);
				line(145,360,220,340);

				//for third
				line(20,360,100,380);
				line(20,380,100,360);

			} else {
				//for first
				line(20,340,100,360);
				line(20,360,100,340);

				//for second
				line(145,340,220,360);
				line(145,360,220,340);

				//for third
				line(20,360,100,380);
				line(20,380,100,360);

				//for fourth
				line(145,360,220,380);
				line(145,380,220,360);

			}

			//Now taking user input for queation answer
			cin>>o3;
			if(o3==question_subpart[5][0]){
				outtextxy(0,450,"Correct Answer");
			}
			else {
				outtextxy(0,450,"Wrong Answer...Game over");
				//cheque_val = val;
				obj.cheque(cheque_val);
			}
		}

		//Taking expert opinion helpline
		if(l1==2){
			//painting character at right as an expert
			line(500,90,580,110);
			line(580,90,500,110);
			circle(440,150,15);
			line(440,170,440,225);
			line(440,225,425,240);
			line(440,225,455,240);
			line(440,200,425,215);
			line(440,200,455,215);

			//converting char in string
			char str_ans[2];
			str_ans[0] = question_subpart[5][0];
			str_ans[1]='\0';

			//painting the right answer
			outtextxy(460,150,"Hi! The Correct Ans is:" );
			setcolor(RED);
			outtextxy(530,180,str_ans);
			setcolor(YELLOW);

			//Taking user answer
			cin>>o3;

			if(o3==question_subpart[5][0]){
				outtextxy(0,450,"Correct Answer");
			}
			else {
				outtextxy(0,450,"Wrong Answer...Game Over");
				//cheque_val = val;
				obj.cheque(cheque_val);
			}
		}

		//Taking phone a friend helpline
		if(l1==3){
			//painting friend character
			line(480,90,400,110);
			line(400,90,480,110);
			circle(440,150,15);
			line(440,170,440,225);
			line(440,225,425,240);
			line(440,225,455,240);
			line(440,200,425,215);
			line(440,200,455,215);

			//converting char in string
			char str_ans[2];
			str_ans[0] = question_subpart[5][0];
			str_ans[1]='\0';

			//painting right answer as help
			outtextxy(460,150,"Hey Friend!Correct Ans:" );
			setcolor(RED);
			outtextxy(530,180,str_ans);
			setcolor(YELLOW);

			//taking user answer for question
			cin>>o3;
			if(o3==question_subpart[5][0]){
				outtextxy(0,450,"Correct Answer");
			}
			else {
				outtextxy(0,450,"Wrong Answer...Game Over");
				//cheque_val = val;
				obj.cheque(cheque_val);
			}
		}

		//AUDIENCE Poll helpline
		if(l1==4){
			//crossing AUDIENCE option at top
			line(480,50,400,70);
			line(400,50,480,70);
			//painting outer box
			rectangle(400,130,600,260);

			//painting option A as 60% when right otherwise 20%
			if(question_subpart[5][0]=='a') {
				//painting option A
				rectangle(410,260,435,170);
				outtextxy(410,160,"60%");
				outtextxy(419,180,"A");
			} else {
			   //painting option A
				rectangle(410,260,435,220);
				outtextxy(410,210,"20%");
				outtextxy(419,230,"A");
			}
			//painting option B as 60% when right or 20% when A is right otherwise 10%
			if(question_subpart[5][0]=='b') {
				//Painting option B
				rectangle(457,260,482,170);
				outtextxy(457,160,"60%");
				outtextxy(465,180,"B");
			}
			else {
				if(question_subpart[5][0]=='a'){
					rectangle(457,260,482,220);
					outtextxy(457,210,"20%");
					outtextxy(465,230,"B");

				} else {
					rectangle(457,260,482,230);
					outtextxy(457,220,"10%");
					outtextxy(465,240,"B");
				}
			}
			//painting option C as 60% when right otherwise 20%
			if(question_subpart[5][0]=='c') {
			//painting option C
			rectangle(504,260,529,170);
			outtextxy(504,160,"60%");
			outtextxy(512,180,"C");
			} else{
				//painting option C
				rectangle(504,260,529,230);
				outtextxy(504,220,"10%");
				outtextxy(512,240,"C");
			}
			//painting option D as 60% when right otherwise 20%
			if(question_subpart[5][0]=='d') {
			//painting option D
			rectangle(551,260,576,170);
			outtextxy(551,160,"80%");
			outtextxy(559,180,"D");
			} else {

			rectangle(551,260,576,230);
			outtextxy(551,220,"10%");
			outtextxy(559,240,"D");
			}
			//Taking User answer for question
			cin>>o3;
			if(o3==question_subpart[5][0]){
				outtextxy(0,450,"Correct Answer");
			}
			else {
				outtextxy(0,450,"Wrong Answer...Game Over");
				//cheque_val = val;
				obj.cheque(cheque_val);
			}
		}
	}
	else {
		outtextxy(0,440,"Wrong Answer...Game Over!!");
		obj.cheque(cheque_val);
	}
}

//Calling various function for whole quiz
void callfun() {
	questionboxes();
	lifelinesboxes();
	lifelineoptiontext();
	multipleanswers();
	currentquestionposition();
	useroption();
	answerbox();
	answerafterlifeline();
}

//main function
void main(){
	//initiate graphics
	int gm=DETECT,gr;
	initgraph(&gm,&gr,"c:\\turboc3\\bgi" );

	//setting up the welcome scren
	settextstyle(1,0,1);
	outtextxy(230,200,"Welcome to KBC Quiz.");
	settextstyle(6,0,1);
	outtextxy(220,220,"You can win upto Rs.25,600.");
	settextstyle(7,0,1);
	setcolor(WHITE);
	outtextxy(240,260,"All the best !! :-)");
	settextstyle(0,0,1);
	//playin sound
	obj.playSound();
	clrscr();
	cleardevice();
	//starting the game
	obj.primary();
	obj.cheque(cheque_val);
	closegraph();
}