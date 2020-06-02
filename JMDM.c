#include<GL/glut.h>

void draw();
void resize(int, int);
void init ();
void idle(void);
void alterColor(void);
void controllerPhase(void);
void _keys(unsigned char key, int x, int y);
float personX = -0.5;
float persony = -9.5;
float personComp = 1;
float personAlt = 1;

int col,n = 0;
int phase = 1;
int state = 1;
GLfloat r = 255,g = 255,b = 255;

typedef struct{float enemyX; float enemyY;} FilaC;
typedef struct{float enemyX; float enemyY;} FilaB;

FilaC filac[6];
FilaB filab[6];

void main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("FASE 02");
	glutKeyboardFunc(_keys);

    glutDisplayFunc(draw);
    glutReshapeFunc(resize);
	
	if(phase == 1){
    	rowp1();
	}else{
		rowp2();		
	}
	
    glutIdleFunc(idle);
    
    init();

    glutMainLoop();
}

void rowp1(){
		filac[0].enemyX = 0;
		filac[0].enemyY = 8;
		
		filac[1].enemyX = 0;
		filac[1].enemyY = 5;
		
		filac[2].enemyX = 0;
		filac[2].enemyY = 2;
		
		filac[3].enemyX = 0;
		filac[3].enemyY = -1;
		
		filac[4].enemyX = 0;
		filac[4].enemyY = -4;
		
		filac[5].enemyX = 0;
		filac[5].enemyY = -7;
		
		filab[0].enemyX = 0;
		filab[0].enemyY = 6.5;
		
		filab[1].enemyX = 0;
		filab[1].enemyY = 3.5;
		
		filab[2].enemyX = 0;
		filab[2].enemyY = 0.5;
		
		filab[3].enemyX = 0;
		filab[3].enemyY = -2.5;
		
		filab[4].enemyX = 0;
		filab[4].enemyY = -5.5;
		
		filab[5].enemyX = 0;
		filab[5].enemyY = -5.5;
}

void rowp2(){
		filac[0].enemyX = 2.5;
		filac[0].enemyY = 0;
		
		filac[1].enemyX = 5.5;
		filac[1].enemyY = 0;
		
		filac[2].enemyX = -0.5;
		filac[2].enemyY = 0;
		
		filac[3].enemyX = -3.5;
		filac[3].enemyY = 0;
		
		filac[4].enemyX = -6.5;
		filac[4].enemyY = 0;
		
		filac[5].enemyX = -6.5;
		filac[5].enemyY = 0;
		
		filab[0].enemyX = -5;
		filab[0].enemyY = 0;
		
		filab[1].enemyX = -2;
		filab[1].enemyY = 0;
		
		filab[2].enemyX = 1;
		filab[2].enemyY = 0;
		
		filab[3].enemyX = 4;
		filab[3].enemyY = 0;
		
		filab[4].enemyX = 4;
		filab[4].enemyY = 0;
		
		filab[5].enemyX = 4;
		filab[5].enemyY = 0;
}

void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void phase1(){
	//PAREDE CIMA
    glColor3ub(255,0,0);
    glBegin(GL_POLYGON);
        glVertex2f(-10, 8);
        glVertex2f(-10, 10);
        glVertex2f(10, 10);
        glVertex2f(10, 8);
    glEnd();

    //PAREDE BAIXO
    glColor3ub(255,0,0);
    glBegin(GL_POLYGON);
        glVertex2f(-10, -8);
        glVertex2f(-10, -10);
        glVertex2f(10, -10);
        glVertex2f(10, -8);
    glEnd();

    //ENTRADA
    glColor3ub(0,255,0);
    glBegin(GL_POLYGON);
        glVertex2f(-1, -8);
        glVertex2f(-1, -10);
        glVertex2f(1, -10);
        glVertex2f(1, -8);
    glEnd();

    //CHEGADA
    glColor3ub(0,255,0);
    glBegin(GL_POLYGON);
        glVertex2f(-1, 8);
        glVertex2f(-1, 10);
        glVertex2f(1, 10);
        glVertex2f(1, 8);
    glEnd();

    glColor3ub(r,g,b);
	//OBSTACULOS
    for(n = 0; n < 6; n++){
	  	glBegin(GL_POLYGON);
	    	glVertex2f(filac[n].enemyX, filac[n].enemyY);
	    	glVertex2f(filac[n].enemyX, filac[n].enemyY - 1);
	    	glVertex2f(filac[n].enemyX + 1, filac[n].enemyY - 1);
	    	glVertex2f(filac[n].enemyX + 1, filac[n].enemyY);		
		glEnd();
		
		glBegin(GL_POLYGON);
	    	glVertex2f(filab[n].enemyX, filab[n].enemyY);
	    	glVertex2f(filab[n].enemyX, filab[n].enemyY - 1);
	    	glVertex2f(filab[n].enemyX - 1, filab[n].enemyY - 1);
	    	glVertex2f(filab[n].enemyX - 1, filab[n].enemyY);		
		glEnd();
		    	
		if(filac[n].enemyY + 1 < persony){col = 0;}
		else if(filac[n].enemyY > persony + personAlt){col = 0;}
		else if(filac[n].enemyX + 1 < personX){col = 0;}
		else if(filac[n].enemyX > personX + personComp){col = 0;}
		else{personX = -0.5; persony = -9.5;}
		
		if(filab[n].enemyY + 1 < persony){col = 0;}
		else if(filab[n].enemyY > persony + personAlt){col = 0;}
		else if(filab[n].enemyX + 1 < personX){col = 0;}
		else if(filab[n].enemyX > personX + personComp){col = 0;}
		else{personX = -0.5; persony = -9.5;}
	}
    
	
}

void phase2(){
	
	//ENTRADA
    glColor3ub(0,255,0);
    glBegin(GL_POLYGON);
        glVertex2f(7, -10);
        glVertex2f(7, -7);
        glVertex2f(10, -7);
        glVertex2f(10, -10);
    glEnd();

    //CHEGADA
    glColor3ub(0,255,0);
    glBegin(GL_POLYGON);
        glVertex2f(-10, 7);
        glVertex2f(-10, 10);
        glVertex2f(-7, 10);
        glVertex2f(-7, 7);
    glEnd();

    //PAREDE DIREITA
    glColor3ub(255,0,0);
    glBegin(GL_POLYGON);
        glVertex2f(10, -7);
        glVertex2f(10, 10);
        glVertex2f(7, 10);
        glVertex2f(7, -7);
    glEnd();

    //PAREDE ESQUERDA
    glColor3ub(255,0,0);
    glBegin(GL_POLYGON);
        glVertex2f(-10, -10);
        glVertex2f(-10, 7);
        glVertex2f(-7, 7);
        glVertex2f(-7, -10);
    glEnd();

    glColor3ub(r,g,b);
    	
	//OBSTACULOS
    for(n = 0; n < 6; n++){
	  	glBegin(GL_POLYGON);
	    	glVertex2f(filac[n].enemyX, filac[n].enemyY);
	    	glVertex2f(filac[n].enemyX + 1, filac[n].enemyY);
	    	glVertex2f(filac[n].enemyX + 1, filac[n].enemyY + 1);
	    	glVertex2f(filac[n].enemyX, filac[n].enemyY + 1);		
		glEnd();
		
		glBegin(GL_POLYGON);
	    	glVertex2f(filab[n].enemyX, filab[n].enemyY);
	    	glVertex2f(filab[n].enemyX + 1, filab[n].enemyY);
	    	glVertex2f(filab[n].enemyX + 1, filab[n].enemyY - 1);
	    	glVertex2f(filab[n].enemyX, filab[n].enemyY - 1);		
		glEnd();
		    	
		if(filac[n].enemyY + 1 < persony){col = 0;}
		else if(filac[n].enemyY > persony + personAlt){col = 0;}
		else if(filac[n].enemyX + 1 < personX){col = 0;}
		else if(filac[n].enemyX > personX + personComp){col = 0;}
		else{personX = 8; persony = -9;}
		
		if(filab[n].enemyY + 1 < persony){col = 0;}
		else if(filab[n].enemyY > persony + personAlt){col = 0;}
		else if(filab[n].enemyX + 1 < personX){col = 0;}
		else if(filab[n].enemyX > personX + personComp){col = 0;}
		else{personX = 8; persony = -9;}
	}
}

void draw(){
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
	
    if(phase == 1){
    	phase1();
	}else{
		phase2();		
	}
	
	//PERSONAGEM
    glColor3ub(0,0,255);
    glBegin(GL_POLYGON);
        glVertex2f(personX, persony);
        glVertex2f(personX + personComp, persony);
        glVertex2f(personX + personComp, persony + personAlt);
        glVertex2f(personX, persony + personAlt);
    glEnd();
    
	
	if(personX == -0.5 && persony == 8.5){
		phase = 2;
		personX = 8;
		persony = -9;
		rowp2();
	}
	    
    glutSwapBuffers();

}

void resize(int w, int h){
    glViewport(0,0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
}

void alterColor(void){
	r=rand()%255;
	g=rand()%255;
	b=rand()%255;
}

void controllerState(void){
	if(state == 2){
		state = 1;
		alterColor();
	}else{
		state = state + 1;
		alterColor();
	}
}

void idle(void){
    draw(); 
    switch(state){
        case 1:
        	if(phase == 1){
        		for(n = 0; n < 8; n++){
		            if (filac[n].enemyX > -11){	
		                if(filac[n].enemyX >= 9){
		                    controllerState();    
		                }else{
		                		filac[n].enemyX += 0.22;
			                	filab[n].enemyX -= 0.22;
		                }
					}
				}
			}else{
				for(n = 0; n < 7; n++){
		            if (filac[n].enemyY > -11){	
		                if(filac[n].enemyY >= 9){
		                    controllerState();    
		                }else{
			                	filac[n].enemyY += 0.22;
			                	filab[n].enemyY -= 0.22;
		                }
					}
				}
			}	
            break;
		case 2:
			if(phase == 1){
				for(n = 0; n < 8; n++){
		            if(filac[n].enemyX < 11){ 		
		                if(filac[n].enemyX <= -10){
		                    controllerState();    
		                }else{
		                    	filac[n].enemyX -= 0.22;
		                    	filab[n].enemyX += 0.22;
		                }
					}
				}
			}else{
				for(n = 0; n < 7; n++){
		            if(filac[n].enemyY < 11){ 		
		                if(filac[n].enemyY <= -10){
		                    controllerState();    
		                }else{
		                    	filac[n].enemyY -= 0.22;
		                    	filab[n].enemyY += 0.22;
		                }
					}
				}
			}
            
	}
}

void _keys(unsigned char key,int x, int y){
	switch(key){
		case 'a':
			if(phase == 2){
				if(persony < 7 && personX == -7){
					personX += 0;
				}else{				
					personX -= 0.5;
					glutPostRedisplay();
				}
			}else{
				if(personX < -0.5 && persony < -8 || personX < -0.5 && persony > 7){
					personX += 0;
				}else{				
					personX -= 0.5;
					glutPostRedisplay();
				}
			}
        break;
		case 'd':
			if(phase == 2){
				if(persony > -8 && personX == 6){
					personX += 0;
				}else{				
					personX += 0.5;
					glutPostRedisplay();
				}
			}else{
				if(personX > -0.5 && persony < -8 || personX > -0.5 && persony > 7){
					personX += 0;
				}else{				
					personX += 0.5;
					glutPostRedisplay();
				}
			}
        break;
        case 'w':
        	if(phase == 2){
	        	if(persony == -8 && personX < 10 && personX > 6){
					persony += 0;
				}else{				
					persony += 0.5;
					glutPostRedisplay();
				}
			}else{
				if(persony > 6.5 && personX > 0.5 || persony > 6.5 && personX < -1){
					persony += 0;
				}else{				
					persony += 0.5;
					glutPostRedisplay();
				}
			}
        break;
		case 's':
			if(phase == 2){
				if(persony == 7 && personX < -7 && personX > -11){
					persony += 0;
				}else{				
		        	persony -= 0.5;
					glutPostRedisplay();
				}
			}else{
				if(persony < -7.5 && personX > 0 || persony < -7.5 && personX < -0.5){
					persony -= 0;
				}else{				
					persony -= 0.5;
					glutPostRedisplay();
				}
			}
			
			
        break;
	}
}


