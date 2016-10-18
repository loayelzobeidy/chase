
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include <string>
#include <sstream>
#include <cstring>
int passXd =0;
int passY=0;
#define PI 3.14159265
// using namespace std ; 
int timer = 300 ;
double mex = 0;
double mey = 0;
double angleme = 0.0;


double victimx = 500 ; 
double victimy = 300 ;
double anglevictim = 0 ; 

double victim2x = 400 ; 
double victim2y = 200 ;
double anglevictim2 = 0 ; 

double chaserx  = 200 ; 
double chasery  = 100 ; 
double anglechase = 0 ;

double chaser2x  = 200 ; 
double chaser2y  = 400 ; 
double anglechase2 = 0 ;

int score = 0;


bool h= false ;
bool g =false ;

bool superscore = false ; 
bool superstop  = false ; 
int duration = 0 ;
bool displaysuper = false;
bool superpressed = false ; 

void Display(void);
void translalevictim(void);
void passM(int,int);
void translalechaser(void);
void drawText(std::string,float,float);
void DisplayFirstBar(void);
void key(unsigned char, int,int );
void stopGame(void);

//if it takes int wiil be (int,int) without names
//c++ executed from top to buttom thus if the function that will be called after the main then it's signature should be on the top like this with ; at the end
void Animate(void);
void time(int);
int main(int argc,char** argr)
{
	glutInit(&argc,argr); //used to initialze the glut library
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	 //using The RGBA model and using a signle buffer 
	glutInitWindowSize(1000,600);
	glutInitWindowPosition(500,300);// initial position from screen left top corner
	glutCreateWindow("assignment1");
    glutKeyboardFunc(key);	
	//the name of the window
    glutTimerFunc(0,time,0);
    if(!h&&!g)
	glutDisplayFunc(DisplayFirstBar);
    else
	glutDisplayFunc(Display);
	 glutIdleFunc(Animate);
	 glutFullScreen();  
	//the fuction that calls anthing will be displayed , don't write parameters
	glClearColor(0.0f,0.0f,0.0f,0.0f);
    

    glutPassiveMotionFunc(passM);	//call the passive motion function
	gluOrtho2D(0.0,1000.0,0.0,600.0);//type of viewing here its orthographic prespective (left , right , top , bottom)* to be checked
	glutMainLoop();
	return 0 ;//this will let the screen behave as glut and not to be closed as normal c++ if it's commented then the program will open and clode automatically
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);//clear buffer/ memory if it's not cleared then expect anything to appear


    if(timer==0&&g)
    	stopGame();
    if(victimx>1000||victimx<0)
    	victimx = 500;
    if(victimy>600||victimy<0)
    	victimy = 300;

     if(victim2x>1000||victim2x<0)
    	victim2x = 400;
    if(victim2y>600||victim2y<0)
    	victim2y = 200;

       
      for(int i = 0;i<15000;i++);


	glPushMatrix();//anything you want to draw it must be between push and pop matrix will be discused later	
    glTranslated(mex,600-mey,0.0);
    glRotated(angleme,0,0,1.0);
      	 // printf("%f\n  %i %i",angle ,mainx1,mainy1);
	glBegin(GL_QUADS);
	 glColor3f(0.0f,0.2f,0.4f); //GL_QUAD_STRIP
	glVertex3f(-20, -15, 0.0f);
	glVertex3f(-20, 15, 0.0f);
	glVertex3f(0, 15, 0.0f);
	glVertex3f(0, -15, 0.0f);
    // printf("%f \n",angleme );
	// std::cout <<angle <<"";
     glEnd();
    
    glBegin(GL_TRIANGLES); 
   glColor3f(0.4f,0.5f,0.5f);//GL_TRIANGLE_STRIP GL_TRIANGLE_FAN
	glVertex3f(0,-15, 0.0f);
	glVertex3f(0,15, 0.0f);
	glVertex3f(20,0, 0.0f);
	glEnd();
	glPopMatrix();
    
	



	glPushMatrix();
	glTranslated(victimx,600-victimy,0);
	glRotated(anglevictim,0,0,1);
	glBegin(GL_QUADS); //GL_QUAD_STRIP
	glColor3f(0.0f,1.0f,0.5f);
	glVertex3f(-20, -15, 0.0f);
	glVertex3f(-20, 15, 0.0f);
	glVertex3f(0, 15, 0.0f);
	glVertex3f(0, -15, 0.0f);
    // printf("%f \n",angleme );
	// std::cout <<angle <<"";
     glEnd();
    
    glBegin(GL_TRIANGLES); 
    glColor3f(0.0f,0.5f,0.5f);//GL_TRIANGLE_STRIP GL_TRIANGLE_FAN
	glVertex3f(0,-15, 0.0f);
	glVertex3f(0,15, 0.0f);
	glVertex3f(20,0, 0.0f);

	glEnd();
    
	glPopMatrix();

    glPushMatrix();
	glTranslated(victim2x,600-victim2y,0);
	glRotated(anglevictim2,0,0,1);
	glBegin(GL_QUADS); //GL_QUAD_STRIP
	glColor3f(0.0f,1.0f,0.5f);
	glVertex3f(-20, -15, 0.0f);
	glVertex3f(-20, 15, 0.0f);
	glVertex3f(0, 15, 0.0f);
	glVertex3f(0, -15, 0.0f);
    // printf("%f \n",angleme );
	// std::cout <<angle <<"";
     glEnd();
    
    glBegin(GL_TRIANGLES);
     glColor3f(0.0f,0.5f,0.5f); //GL_TRIANGLE_STRIP GL_TRIANGLE_FAN
	glVertex3f(0,-15, 0.0f);
	glVertex3f(0,15, 0.0f);
	glVertex3f(20,0, 0.0f);
	glEnd();
	glPopMatrix();




	glPushMatrix();
	glTranslated(chaser2x,600-chaser2y,0.0);
	glRotated(anglechase2,0,0,1);
	glBegin(GL_QUADS); //GL_QUAD_STRIP
	glColor3f(1.0f,0.5f,0.5f);
	glVertex3f(-20, -15, 0.0f);
	glVertex3f(-20, 15, 0.0f);
	glVertex3f(0, 15, 0.0f);
	glVertex3f(0, -15, 0.0f);
    // printf("%f \n",angleme );
	// std::cout <<angle <<"";
     glEnd();
    
    glBegin(GL_TRIANGLES);
       glColor3f(0.4f,0.5f,0.5f); //GL_TRIANGLE_STRIP GL_TRIANGLE_FAN
	glVertex3f(0,-15, 0.0f);
	glVertex3f(0,15, 0.0f);
	glVertex3f(20,0, 0.0f);
	glEnd();
     
	glPopMatrix();


	glPushMatrix();
	glTranslated(chaserx,600-chasery,0.0);
	glRotated(anglechase,0,0,1);
	glBegin(GL_QUADS); //GL_QUAD_STRIP
	glColor3f(1.0f,0.5f,0.5f);
	glVertex3f(-20, -15, 0.0f);
	glVertex3f(-20, 15, 0.0f);
	glVertex3f(0, 15, 0.0f);
	glVertex3f(0, -15, 0.0f);
    // printf("%f \n",angleme );
	// std::cout <<angle <<"";
     glEnd();
    
    glBegin(GL_TRIANGLES);
       glColor3f(0.4f,0.5f,0.5f); //GL_TRIANGLE_STRIP GL_TRIANGLE_FAN
	glVertex3f(0,-15, 0.0f);
	glVertex3f(0,15, 0.0f);
	glVertex3f(20,0, 0.0f);
	glEnd();
    glPopMatrix();
	 
       std::string scoreFirst = "score : ";
        std::string Score = std::to_string(score);
        drawText(scoreFirst,10,580);
        drawText(Score,60,580);
         std::string timerView = std::to_string(timer);
        drawText(timerView,800,580);
        drawText(".sec",820,580);
         if(displaysuper){
         	std::string text= "press s for stopping chasers or p for double score";
         	drawText(text,100,580);
         }
         if(duration>0&&duration<30)
         {
         	 std::string durationView = std::to_string(duration);
             drawText(durationView,400,500);
         }
         
  
  
      
	glFlush();//to display everything on the screen
}
void passM(int x,int y)//passive motion function takes 2 parameters the x and y positions of the mouse
						//it allows the user to make use of the mouse motion without clicking on the mouse buttons
{  
     	// if(!x||!y)
	x=x*(1000)/glutGet(GLUT_WINDOW_WIDTH);
	y=  y* (600)/glutGet(GLUT_WINDOW_HEIGHT);  // 	return ;
	double diffy = -y+mey ; 
	double diffx = x-mex ; 
    angleme = atan2(diffy,diffx) *180/PI ;
    
     mex = x ; 
     mey =y ;
	glutPostRedisplay();

}

void translalevictim(){
    double diffx = victimx-mex ; 
    double diffy = victimy-mey ;

    double diff2x = victim2x-mex ; 
    double diff2y = victim2y-mey ;
    // printf("%f\n",diffx );
    // printf("%f\n",diffy );

      if(abs(diffx)<=20&&abs(diffy)<=20){
    	score+=2;
    	if(superscore)
    		score+=2;
    	victimx = 500 ; 
        victimy = 300;
         

    }

    if(abs(diff2x)<=20&&abs(diff2y)<=20){
    	score+=2;
    	if(superscore)
    		score+=2;
    	victim2x = 400 ; 
        victim2y = 200  ;
        
    }

    double magnitude = sqrt(pow(diffx,2)+pow(diffy,2));
     anglevictim = atan2(600-(victimy+mey),diffx)*180/PI ;
    victimx+=1.3*(diffx/magnitude);
    victimy+=1.3*(diffy/magnitude);  

    double magnitude2 = sqrt(pow(diff2x,2)+pow(diff2y,2));
     anglevictim2 = atan2(600-(victim2y+mey),diff2x)*180/PI ;
    victim2x+=1.7*(diff2x/magnitude2);
    victim2y+=1.7*(diff2y/magnitude2);  
}
void translalechaser(){
    double diffx = chaserx-mex ; 
    double diffy = chasery-mey ;

    double diffx2 = chaser2x-mex;
    double diffy2 = chaser2y-mey;


   if(abs(diffx)<=20&&abs(diffy)<=20){
    	score-=2;
    	if(superscore)
    		score-=2;
	    	if(h)
	    		stopGame();
    	chaserx = 200 ; 
        chasery = 100 ;
   }

    if(abs(diffx2)<=20&&abs(diffy2)<=20)
    	{  
    		if(h)
    		stopGame();
    	
    	if(superscore)
    		score-=2;
    	chaser2x = 200;
    	chaser2y = 400;
    	score-=2;
    }

    double magnitude = sqrt(pow(diffx,2)+pow(diffy,2));
    anglechase = -atan2(600-(chasery+mey),diffx)*180/PI +180;
    chaserx -=0.9*(diffx/magnitude);
    chasery -=0.9*(diffy/magnitude);  

    double magnitude2 = sqrt(pow(diffx2,2)+pow(diffy2,2));
    anglechase2 = -atan2(600-(chaser2y+mey),diffx2)*180/PI +180;
    chaser2x -=0.4*(diffx2/magnitude2);
    chaser2y -=0.4*(diffy2/magnitude2);  
}
void Animate(){
	translalevictim();
	for(int i = 0;i<150000;i++);
		if(!superstop)
		translalechaser();

	glutPostRedisplay();
}
 void drawText(std::string text,float x,float y)
 {
	glRasterPos2i(x, y);

glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
    for (int i = 0; i < text.size(); i++){
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
 }
}
void DisplayFirstBar(){
	glClear(GL_COLOR_BUFFER_BIT);
    std::string hello = "Click on H for game mode 1 and click on G for game mode 2 ";
	drawText(hello,300,200);
}
void key(unsigned char k, int x,int y)//keyboard function, takes 3 parameters
									// k is the key pressed from the keyboard
									// x and y are mouse postion when the key was pressed.
{
	if(k=='h'){//if the letter d is pressed, then the object will be translated in the x axis by 10 (moving to the right).
		h = true;
		drawText("h is pressed",20,380);
        //glutDisplayFunc(Display);
        
	 	
        //type of viewing here its orthographic prespective (left , right , top , bottom)* to be checked
	   
	
	}
	if(k=='g')//if the letter a is pressed, then the object will be translated in the x axis by -10 (moving to the left).
	{    drawText("g is pressed",20,380);
         g = true;
	 }   //glutDisplayFunc(Display2);
	
	if(k==27)
	{
		glutDestroyWindow (0);
      exit (0);
	}

	if(k=='s'&&!superscore&&displaysuper)
	{
		superstop = true;
		displaysuper = false;
		superpressed = true;
		duration++;
	}
	if(k=='p'&&!superstop&&displaysuper)
	{
		superscore = true;
		score*=2;
        duration++;
		displaysuper = false; 
	    superpressed = true;
	}
	glutDisplayFunc(Display);
	//redisplay to update the screen with the changes
}
void stopGame()
{
timer = 300 ;

 mex = 0;
 mey = 0;
 angleme = 0.0;

 victimx = 500 ; 
 victimy = 300 ;
 anglevictim = 0 ; 

 victim2x = 400 ; 
 victim2y = 200 ;
 anglevictim2 = 0 ; 

 chaserx  = 200 ;
 chasery  = 100 ; 
 anglechase = 0 ;

 chaser2x  = 200 ; 
 chaser2y  = 400 ; 
 anglechase2 = 0 ;

 score = 0;


 h= false ;
 g =false ;

 superscore = false ; 
 superstop  = false ; 
 duration = 0 ;
 displaysuper = false;
 superpressed = false ; 


	glutDisplayFunc(DisplayFirstBar);
}

void time (int x){
	timer--;
	if(superstop||superscore)
		duration++;
    if(timer<270&&!superpressed)
    {
    	displaysuper = true;
    }
	if(duration==30)
	{
		duration = 0 ; 
		superstop = false ; 
		superscore = false;
	}
	glutTimerFunc(1000,time,0);	

}

