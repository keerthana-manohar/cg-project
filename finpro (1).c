#include<string.h>
#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
GLint shoulder1=0,shoulder2=0,leg11=0,leg12=0,leg21=0,leg22=0;GLint turn=0,turn1=0;
GLfloat angle=0.0,r=0,l=0;int scaleflag=1;int then=0;
//to draw a robot
void robo()
{
//head
   glPushMatrix(); 
   glColor3f(1.0,1.0,0.5);
   glTranslatef (0.0+r,2.0, 0.0); 
   glRotatef(angle,0.0,1.0,0.0);
   glutSolidCube(1.2);
   
   glPushMatrix(); //left eye
   glColor3f(0.5,0.5,0.5);
   glTranslatef(-0.25,-0.08,0.5);
   glutSolidSphere(0.1,15,15);
   glPopMatrix();

   glPushMatrix(); // right eye
   glColor3f(0.5,0.5,0.5);
   glTranslatef(0.25,-0.08,0.5);
   glutSolidSphere(0.1,15,15);
   glPopMatrix();
  glPopMatrix(); 
 
glPushMatrix();
  //neck
  glPushMatrix();   
  glColor3f(0.5,0.5,0.5);
  glTranslatef (0.0+r, 1.0, 0.0);
  glutSolidSphere(0.3,10,10);
glPopMatrix(); 
  //chest
glPushMatrix();
  glColor3f(1,0,0);
  glTranslatef (0.0+r, 0.0, 0.0);
  glutSolidCube (1.5);
glPopMatrix(); 
  //left hand
glPushMatrix();
  glColor3f(0.5,0.5,0.5);
  glTranslatef (-1.0+r, 0.5, 0.0);
  glutSolidSphere (0.3, 15, 15); 
  glRotatef ((GLfloat) shoulder1, 0.0, 0.0, 1.0);
  glRotated(-300,0.0,0.0,1.0);
  glTranslatef (-0.8, 0.0, 0.0);
  glPushMatrix();
  glColor3f(0.1,0.0,0.5);
  glScalef (0.8*scaleflag, 0.5, 1.0);
  glutSolidCube (1.0);			//shoulder1
  glPopMatrix();
glPopMatrix();
  // right hand
glPushMatrix();
  glColor3f(0.5,0.5,0.5);   
  glTranslatef (1.0+r, 0.5, 0.0);
  glutSolidSphere (0.3, 15, 15); 
  glRotatef ((GLfloat) shoulder2, 0.0, 0.0, 1.0);
  glRotated(-60,0.0,0.0,1.0);
  glTranslatef (0.8, 0.0, 0.0);
   
glPushMatrix();
  glColor3f(0.1,0,0.5);
  glScalef (0.8*scaleflag, 0.5, 1.0);
  glutSolidCube (1.0);				//shoulder2
glPopMatrix();
glPopMatrix();
 // leg1
glPushMatrix();
  glColor3f(0.5,0.5,0.5);
  glTranslatef (-0.5+r, -1.0, 0.0);
  glutSolidSphere (0.4, 15, 15);
  glRotatef ((GLfloat) leg11, 0.0, 0.0, 1.0);
  glRotated(80,0.0,0.0,1.0);
  glTranslatef (-1.0, 0.0, 0.0);
   
glPushMatrix();
  glColor3f(.31,1,1);
  glScalef (1.0, 0.5, 0.2);
  glutSolidCube (1.0);			//leg11
glPopMatrix();
  glColor3f(0.5,0.5,0.5);	
  glTranslatef (-1.0, 0.0, 0.0);
  glutSolidSphere (0.4, 15, 15);
  glRotatef ((GLfloat) leg12, 0.0, 0.0, 1.0);
  glTranslatef (-1.0, 0.0, 0.0);
       
glPushMatrix();
  glColor3f(0.0,0.5,1.0);
  glScalef (1.0, 0.5, 0.2);
  glutSolidCube (1.0);			//leg12
glPopMatrix();
  
glPushMatrix();
  glColor3f(1,0.0,1);
  glTranslatef (-1.0, 0.0,0.6);  //foot
  glScalef (0.5, 0.5, 1.5);
  glutSolidCube (1.0);
glPopMatrix();
glPopMatrix();
 // right leg 
glPushMatrix();
  glColor3f(0.5,0.5,0.5);
  glTranslatef (0.5+r, -1.0, 0.0);
  glutSolidSphere (0.4, 15, 15);
  glRotatef ((GLfloat) leg21, 0.0, 0.0, 1.0);		
  glRotated(-80,0.0,0.0,1.0);
  glTranslatef (1.0, 0.0, 0.0);
    
glPushMatrix();
  glColor3f(0.31,1,1);
  glScalef (1.0, 0.5, 0.2);
  glutSolidCube (1.0);			//leg21
glPopMatrix();
  glColor3f(0.5,0.5,0.5);
  glTranslatef (1.0, 0.0, 0.0);
  glutSolidSphere (0.4, 15, 15);
  glRotatef ((GLfloat) leg22, 0.0, 0.0, 1.0);
  glTranslatef (1.0, 0.0, 0.0);
    
glPushMatrix();
  glColor3f(0.0,0.5,1);
  glScalef (1.0, 0.5, 0.2);
  glutSolidCube (1.0);			//leg22
glPopMatrix();

glPushMatrix();
  glColor3f(1,0.5,1);
  glTranslatef (1.0,0.0,0.6);
  glScalef (0.5, 0.5,1.5);
  glutSolidCube (1.0);			//foot
glPopMatrix();
glPopMatrix();
glPopMatrix();
glPopMatrix();
}
void update1(int val)
{
angle+=0.5;
if(angle>360) angle-=360;
glutPostRedisplay();
glutTimerFunc(25,update1,0);
}

// keyboard function
void keyboard(unsigned char key, int x, int y)
{

   switch (key) {
      case 'r':
          r=r+0.5; 
          glutPostRedisplay();
          break;
      case 'l':
      	  r=r-0.5;
      	  glutPostRedisplay();
      	  break;
      case 's':
         shoulder1 = (shoulder1+5)%360;
         glutPostRedisplay();
         break;
      case 'S':
         shoulder1 = (shoulder1 - 5) % 360;
         glutPostRedisplay();
         break;
      case 'w':
         shoulder2 = (shoulder2 + 5) % 360;
         glutPostRedisplay();
         break;
      case 'W':
         shoulder2 = (shoulder2 - 5) % 360;
         glutPostRedisplay();
         break;
       case 'a':
         leg11 = (leg11 + 5) % 360;
         glutPostRedisplay();
         break;
      case 'A':
         leg11 = (leg11 - 5) % 360;
         glutPostRedisplay();
         break;
      case 'b':
         leg12 = (leg12 + 5) % 360;
         glutPostRedisplay();
         break;
      case 'B':
         leg12 = (leg12 - 5) % 360;
         glutPostRedisplay();
         break;
      case 'c':
         leg21 = (leg21 + 5) % 360;
         glutPostRedisplay();
         break;
      case 'C':
         leg21 = (leg21 - 5) % 360;
         glutPostRedisplay();
         break;
      case 'd':
         leg22 = (leg22 + 5) % 360;
         glutPostRedisplay();
         break;
      case 'D':
         leg22 = (leg22 - 5) % 360;
         glutPostRedisplay();
         break;	  
        default:
         break;
       }
}
/*background color menu*/
void bgcolour_menu(int i) 		
{
	switch(i)
	{
	     case 0: glClearColor(0.0,0.0,0.0,1.0);
		    break;
		case 1: glClearColor(1.0,1.0,0.0,1.0);
			break;
		case 2: glClearColor(0.0,1.0,0.0,1.0);
			break;
		case 3: glClearColor(0.0,0.0,1.0,1.0);
			break;
		case 4: glClearColor(0.0,1.0,1.0,1.0);
			break;
		case 5: glClearColor(0.75,0.75,0.75,1.0);
			break;
		case 6: glClearColor(1.0,0.84,0.0,1.0);
			break;
        }
}
//to display text
void print_text(char *s, GLint i,GLint j,int k)
{
	int n=strlen(s);
	glRasterPos3f(i,j,k);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glScalef(0.1,0.1,0.1);
	for(i=0;i<n;i++)
         glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,(int)s[i]);
        glPopMatrix();
    
}
//front page
void welcomepage()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);                     
	glColor3f(0.0,0.0,1.0);
	print_text("Bangalore Institute Of Technology",-2,2.0,-5);
	print_text("Department of Computer Science and Engineering",-3,1.0,-5);
	print_text("OpenGL Mini Project",-1,0,-5);
	print_text("Robot",-0,-1,-5);
	print_text("by- KEERTHANA S",-3,-2,-5);
	print_text("Press left button to display the robot",-3.0,-3,-5);
	glFlush();
        
}
//Display Function
void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT );
   glMatrixMode(GL_MODELVIEW);
   if(then==0)
   {
   welcomepage();
   glutPostRedisplay();
   }
   else if(then ==1)
    {
     	  glPushMatrix();
          glTranslatef(0.0, 0.0, -5.0);

          glPushMatrix();
          glPushMatrix();
            glColor3f(1,0.0,0.9);
               glutWireCube(18.0);       //wire frame
          glPopMatrix();

	  glPushMatrix();			//robo function
               robo();
          glPopMatrix(); 
          glPopMatrix();
      glFlush();
    }
      glutSwapBuffers();
}
//mouse function
void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
	then=1;
        glutPostRedisplay();
    }
}
void menu_select(int mode)
{
 switch (mode) {
  case 5:
    exit(EXIT_SUCCESS);
  case 4:
     glutTimerFunc(25, update1, 0);
     break;
  }
}
void scale_menu(int i)
{
switch(i)
{
case 0:
       scaleflag=scaleflag*2;
       break;
case 1:scaleflag=1/scaleflag*(1/2);
	break;
}
}
void
null_select(int mode)
{
}
void glutmenu(void)
{

	int glut_menu[11];

  glut_menu[1] = glutCreateMenu(null_select);
  glutAddMenuEntry("AT THE  SHOULDERS : s,S", 0);

  glut_menu[2] = glutCreateMenu(null_select);
  glutAddMenuEntry("AT THE  SHOULDERS : w,W", 0);
  
  glut_menu[4] = glutCreateMenu(null_select);
  glutAddMenuEntry("AT THE  HIP : a,A", 0);
  glutAddMenuEntry("AT THE KNEES : b,B", 0);

  glut_menu[5] = glutCreateMenu(null_select);
  glutAddMenuEntry("AT THE  HIP : c,C", 0);
  glutAddMenuEntry("AT THE KNEES : d,D", 0);
  
  glut_menu[7]=glutCreateMenu(bgcolour_menu);
	glutAddMenuEntry("black",0);
	glutAddMenuEntry("Yellow",1);
	glutAddMenuEntry("Green",2);
	glutAddMenuEntry("Blue",3);
	glutAddMenuEntry("Cyan",4);
	glutAddMenuEntry("Silver",5);
	glutAddMenuEntry("Gold",6);
  glut_menu[8]=glutCreateMenu(NULL);
  glutAddMenuEntry("MOVE LEFT->press l",0);
  glutAddMenuEntry("MOVE RIGHT->press r",0);
  
  glut_menu[3] = glutCreateMenu(NULL);
  glutAddSubMenu("LEG 1", glut_menu[4]);
  glutAddSubMenu("LEG 2", glut_menu[5]);

  glut_menu[0] = glutCreateMenu(null_select);
  glutAddSubMenu("HAND 1", glut_menu[1]);
  glutAddSubMenu("HAND 2", glut_menu[2]);
  
  glut_menu[6]=glutCreateMenu(scale_menu);
  glutAddMenuEntry("INCREASE ARM LENGTH BY 2:*2",0);
  glutAddMenuEntry("DECREASE ARM LENGTH BY 2:*0.5",1);
   
  glutCreateMenu(menu_select);
  glutAddSubMenu("CHANGE OF BACKGROUND COLOR",glut_menu[7]);
  glutAddSubMenu("MOVE THE ROBOT",glut_menu[8]);
  glutAddSubMenu("HAND ROTATION", glut_menu[0]);
  glutAddSubMenu("LEG ROTATION", glut_menu[3]);
  glutAddMenuEntry("ROTATE HEAD",4);
  glutAddSubMenu("SCALE",glut_menu[6]);

  glutAddMenuEntry("QUIT", 5);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
}
//Reshape function
 void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(65.0,(GLfloat)w/(GLfloat)h,1.0,30.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef (0.0, 0.0, -5.0);
} 

// main function
int main(int argc, char** argv)
{
   glViewport(0,0,200,300);
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (600, 600); 
   glutInitWindowPosition (0,0);
   glutCreateWindow ("robo");
   glEnable(GL_DEPTH_TEST);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutDisplayFunc(display);
   glutMouseFunc(mouse);
   glutmenu();
   glutMainLoop();                   
}

