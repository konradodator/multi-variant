//Konrad Matusewicz//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include <GL/glew.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include <glm/ext/vector_float3.hpp>
#include <string> 




using namespace std;
int i;
int refreshMills = 10;
int pointsNumber;
float angle;
float ct = 0;
float ct2 = 0;
float ct3 = 0;
float ct4 = 0;
float x, y, z;
int counts = 0;
int counts2 = 0;
vector<vector<double>>curveVertex;
//glm::vec3 bezierPoints(float t, vector<vector<double>> points);
//glm::vec3 bezierPoints2(float t, vector<vector<double>> points);
//glm::vec3 bezierPoints3(float t, vector<vector<double>> points);
//glm::vec3 bezierPoints4(float t, vector<vector<double>> points);

glm::vec3 bezierPointspanitik(float t, GLfloat ctrlpoints10[4][3]);
glm::vec3 bt;

glm::vec3 bezierPointspanitik2(float t, GLfloat ctrlpoints10[4][3]);
glm::vec3 bt2;

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
}




void draw(GLfloat ctrlpoints[4][3])
{
    glShadeModel(GL_FLAT);
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4,
        &ctrlpoints[0][0]);

    glEnable(GL_MAP1_VERTEX_3);

    // Fill the color
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_STRIP);


    // Find the coordinates
    for (i = 0; i <= 30; i++)
        glEvalCoord1f((GLfloat)i / 30.0);

    glEnd();
}


void drawHaupt(GLfloat ctrlpoints[4][3])
{

    glShadeModel(GL_FLAT);
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4,
        &ctrlpoints[0][0]);

    glEnable(GL_MAP1_VERTEX_3);

    // Fill the color
    glColor3f(0, 1.0, 0);
    glBegin(GL_LINE_STRIP);


    // Find the coordinates
    for (i = 0; i <= 30; i++)
        glEvalCoord1f((GLfloat)i / 30.0);

    glEnd();

}


void timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(refreshMills, timer, 0);
}


/*
vector<vector<double>> initValues() {
    while (pointsNumber < 2 || pointsNumber > 4)
    {
        cout << "Geben Sie die anzahlder punkte ein 2-4 " << endl;
    cin >> pointsNumber;
}


vector<vector<double>> points(pointsNumber, vector<double>(3));

for (int i = 0; i < pointsNumber; i++) {

    cout << "koordinaten eingeben x,y,z" << i + 1 << "mit Enter trennen" << endl;
    cin >> points[i][0] >> points[i][1] >> points[i][2];
}
return points;
}*/
bool start = false;
float speed = 0;

bool start2 = false;
float speed2 = 0;

void SpecialKeyFunc(int Key, int x, int y)
{
    switch (Key) {
    case GLUT_KEY_UP:

        // ct += 0.02;
        start = true;
        speed += 0.001;
        glutPostRedisplay();

        break;
    case GLUT_KEY_DOWN:

        // ct += 0.02;
        if (speed >= 0)
            speed -= 0.001;

        if (speed < 0.0001)
            start = false;

        glutPostRedisplay();

        break;
    case GLUT_KEY_F1:

        speed = 0;
        ct = 0;
        start = false;

        glutPostRedisplay();

        break;

    case GLUT_KEY_RIGHT:

        // ct += 0.02;
        start2 = true;
        speed2 += 0.001;
        glutPostRedisplay();

        break;
    case GLUT_KEY_LEFT:

        // ct += 0.02;
        if (speed2 >= 0)
            speed2 -= 0.001;

        if (speed2 < 0.0001)
            start2 = false;

        glutPostRedisplay();

        break;

    case GLUT_KEY_F2:

        speed2 = 0;
        ct2 = 0;
        start2 = false;

        glutPostRedisplay();

        break;
    }


}

//Konrad Matusewicz + Steven Klocke ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void display() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    //------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------
    //rechts unten
    GLfloat ctrlpoints[4][3]
        = { { 95, 45, 0.0 },
            { 95, 35, 0.0 },
            { 85, 25, 0.0 },
            { 75, 25, 0.0 } };
    draw(ctrlpoints);


    //unten
    GLfloat ctrlpoints2[4][3]
        = { { 75, 25, 0.0 },
            { 65, 25, 0.0 },
            { 55, 25, 0.0 },
            { 45, 25, 0.0 } };

    draw(ctrlpoints2);

    //links unten
    GLfloat ctrlpoints3[4][3]
        = { { 45, 25, 0.0 },
            { 35, 25, 0.0 },
            { 25, 35, 0.0 },
            { 25, 45, 0.0 } };

    draw(ctrlpoints3);

    //links oben
    GLfloat ctrlpoints4[4][3]
        = { { 25, 45, 0.0 },
            { 25, 55, 0.0 },
            { 35, 65, 0.0 },
            { 45, 65, 0.0 } };
    draw(ctrlpoints4);

    //oben
    GLfloat ctrlpoints41[4][3]
        = { { 45, 65, 0.0 },
            { 55, 65, 0.0 },
            { 65, 65, 0.0 },
            { 75, 65, 0.0 } };
    draw(ctrlpoints41);

    //rechts oben
    GLfloat ctrlpoints42[4][3]
        = { { 75, 65, 0.0 },
            { 85, 65, 0.0 },
            { 95, 55, 0.0 },
            { 95, 45, 0.0 } };
    draw(ctrlpoints42);
    //------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------
    //Außenlinie

    GLfloat ctrlpoints5[4][3]
        = { { 115, 45, 0.0 },
            { 115, 25, 0.0 },
            {  95,  5, 0.0 },
            {  75,  5, 0.0 } };
    draw(ctrlpoints5);

    GLfloat ctrlpoints6[4][3]
        = { { 75,  5, 0.0 },
            { 65,  5, 0.0 },
            { 55,  5, 0.0 },
            { 45,  5, 0.0 } };
    draw(ctrlpoints6);

    GLfloat ctrlpoints7[4][3]
        = { { 45,  5, 0.0 },
            { 25,  5, 0.0 },
            {  5, 25, 0.0 },
            {  5, 45, 0.0 } };
    draw(ctrlpoints7);

    GLfloat ctrlpoints8[4][3]
        = { {  5, 45, 0.0 },
            {  5, 65, 0.0 },
            { 25, 85, 0.0 },
            { 45, 85, 0.0 } };
    draw(ctrlpoints8);

    GLfloat ctrlpoints81[4][3]
        = { { 45, 85, 0.0 },
            { 55, 85, 0.0 },
            { 65, 85, 0.0 },
            { 75, 85, 0.0 } };
    draw(ctrlpoints81);

    GLfloat ctrlpoints82[4][3]
        = { { 75, 85, 0.0 },
            { 95, 85, 0.0 },
            {115, 65, 0.0 },
            {115, 45, 0.0 } };
    draw(ctrlpoints82);
    //------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------
    //Hauptlinie

    GLfloat ctrlpoints9[4][3]
        = { { 105, 45, 0.0 },
            { 105, 30, 0.0 },
            {  90, 15, 0.0 },
            {  75, 15, 0.0 } };

    drawHaupt(ctrlpoints9);


    GLfloat ctrlpoints10[4][3]
        = { { 75, 15, 0.0 },
            { 60, 15, 0.0 },
            { 50, 15, 0.0 },
            { 40, 15, 0.0 } };
    drawHaupt(ctrlpoints10);

    GLfloat ctrlpoints11[4][3]
        = { { 40, 15, 0.0 },
            { 25, 15, 0.0 },
            { 15, 30, 0.0 },
            { 15, 45, 0.0 } };
    drawHaupt(ctrlpoints11);

    GLfloat ctrlpoints12[4][3]
        = { { 15, 45, 0.0 },
            { 15, 60, 0.0 },
            { 30, 75, 0.0 },
            { 40, 75, 0.0 } };
    drawHaupt(ctrlpoints12);

    GLfloat ctrlpoints121[4][3]
        = { { 40, 75, 0.0 },
            { 50, 75, 0.0 },
            { 60, 75, 0.0 },
            { 75, 75, 0.0 } };
    drawHaupt(ctrlpoints121);

    GLfloat ctrlpoints122[4][3]
        = { { 75, 75, 0.0 },
            { 90, 75, 0.0 },
            {105, 60, 0.0 },
            {105, 45, 0.0 } };
    drawHaupt(ctrlpoints122);

    GLfloat ctrlpoints123[4][3]
        = { { 75, 75, 0.0 },
            { 90, 75, 0.0 },
            {100, 65, 0.0 },
            {100, 40, 0.0 } };



    //glFlush();


//Konrad Matusewicz///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    

    if (start)
    {
        if (ct < 1)
            ct += 0.002 + speed;
    }
    //if (ct < 1)
       // ct += 0.002;

    if (ct >= 1)
    {
        ct = 0;
        counts++;
    }

    if (counts > 5)
        counts = 0;


    //glLoadIdentity();
    if (counts == 0)
    {
        bt = bezierPointspanitik(ct, ctrlpoints9);
        if (ct > 0)
            angle -= 0.7;

        if (speed > 0.025)
        {
            bt.x = bt.x + 5;
            bt.y = bt.y - 5;
            start = false;

        }
    }



    if (counts == 1)
        bt = bezierPointspanitik(ct, ctrlpoints10);


    if (counts == 2)
    {
        bt = bezierPointspanitik(ct, ctrlpoints11);

        if (speed > 0.025)
        {
            bt.x = bt.x - 12;
            //bt.y = bt.y + 5;
            start = false;
        }

    }



    if (counts == 3)
    {
        bt = bezierPointspanitik(ct, ctrlpoints12);
   
        if (speed > 0.025)
        {
            //bt.x = bt.x - 12;
            bt.y = bt.y + 5;
            start = false;
        }

    }

    if (counts == 4)
        bt = bezierPointspanitik(ct, ctrlpoints121);

    if (counts == 5)
    {
        bt = bezierPointspanitik(ct, ctrlpoints122);
        if (speed > 0.025)
        {
            bt.x = bt.x + 12;
            //bt.y = bt.y + 5;
            start = false;
           
        }
    }

   


    x = bt.x;
    y = bt.y;
    z = bt.z;
    cout << bt.x << "," << bt.y << "," << bt.z << endl;
    glTranslatef(x, y, z);
    glRotatef(angle, 0, 0, 1);
    glColor3f(0.0, 1.0, 0.0);


    //Auto
    glBegin(GL_QUADS);
    //Rumpf
    glVertex2f(-1.5,  -2);
    glVertex2f(-1.5, 2.3);
    glVertex2f( 1.5, 2.3);
    glVertex2f( 1.5,  -2);
    //Rad 1
    glVertex2f(-2.5, -2);
    glVertex2f(-2.5, -1);
    glVertex2f(-1.5, -1);
    glVertex2f(-1.5, -2);
    //Rad2
    glVertex2f(-2.5, 1);
    glVertex2f(-2.5, 2);
    glVertex2f(-1.5, 2);
    glVertex2f(-1.5, 1);
    //Rad3
    glVertex2f(1.5, 1);
    glVertex2f(1.5, 2);
    glVertex2f(2.5, 2);
    glVertex2f(2.5, 1);
    //Rad4
    glVertex2f(1.5, -2);
    glVertex2f(1.5, -1);
    glVertex2f(2.5, -1);
    glVertex2f(2.5, -2);
    glEnd();
    //Spitze
    glBegin(GL_TRIANGLES);
    glVertex2f(-1.5, -2);
    glVertex2f(0,  -3.5);
    glVertex2f(1.5,  -2);
    glEnd();
    //glutSolidSphere(2, 20, 10);



    /*glLoadIdentity();
    glm::vec3 bt2 = bezierPoints2(ct2, curveVertex);
    x = bt2.x;
    y = bt2.y;
    z = bt2.z;
    cout << bt2.x << "," << bt2.y << "," << bt2.z << endl;
    glTranslatef(x, y, z);
    glColor3f(0.0, 1.0, 0.0);
    glutSolidSphere(1, 10, 10);


    glLoadIdentity();
    glm::vec3 bt3 = bezierPoints3(ct3, curveVertex);
    x = bt3.x;
    y = bt3.y;
    z = bt3.z;
    cout << bt3.x << "," << bt3.y << "," << bt3.z << endl;
    glTranslatef(x, y, z);
    glColor3f(0.0, 1.0, 0.0);
    glutSolidSphere(1, 10, 10);

    glLoadIdentity();
    glm::vec3 bt4 = bezierPoints4(ct4, curveVertex);
    x = bt4.x;
    y = bt4.y;
    z = bt4.z;
    cout << bt4.x << "," << bt4.y << "," << bt4.z << endl;
    glTranslatef(x, y, z);
    glColor3f(0.0, 1.0, 0.0);
    glutSolidSphere(1, 10, 10);*/
    glLoadIdentity();
    if (start2)
    {
        if (ct2 < 1)
            ct2 += 0.002 + speed2;
    }
    //if (ct < 1)
       // ct += 0.002;

    if (ct2 >= 1)
    {
        ct2 = 0;
        counts2++;
    }

    if (counts2 > 5)
        counts2 = 0;


    //glLoadIdentity();
    if (counts2 == 0)
    {
        bt2 = bezierPointspanitik2(ct2, ctrlpoints9);
        if (ct2 > 0)
            angle -= 0.7;

        if (speed2 > 0.025)
        {
            bt2.x = bt2.x + 5;
            bt2.y = bt2.y - 5;
            start2 = false;

        }
    }



    if (counts2 == 1)
        bt2 = bezierPointspanitik2(ct2, ctrlpoints10);


    if (counts2 == 2)
    {
        bt2 = bezierPointspanitik2(ct2, ctrlpoints11);

        if (speed2 > 0.025)
        {
            bt2.x = bt2.x - 12;
            //bt.y = bt.y + 5;
            start2 = false;
        }

    }



    if (counts2 == 3)
    {
        bt2 = bezierPointspanitik2(ct2, ctrlpoints12);

        if (speed2 > 0.025)
        {
            //bt.x = bt.x - 12;
            bt2.y = bt2.y + 5;
            start2 = false;
        }

    }

    if (counts2 == 4)
        bt2 = bezierPointspanitik2(ct2, ctrlpoints121);

    if (counts2 == 5)
    {
        bt2 = bezierPointspanitik2(ct2, ctrlpoints122);
        if (speed2 > 0.025)
        {
            bt2.x = bt2.x + 12;
            //bt.y = bt.y + 5;
            start2 = false;

        }
    }




    x = bt2.x;
    y = bt2.y;
    z = bt2.z;
    cout << bt2.x << "," << bt2.y << "," << bt2.z << endl;
    glTranslatef(x, y, z);
    glRotatef(angle, 0, 0, 1);
    glColor3f(0.0, 1.0, 1.0);


    //Auto
    glBegin(GL_QUADS);
    //Rumpf
    glVertex2f(-1.5, -2);
    glVertex2f(-1.5, 2.3);
    glVertex2f(1.5, 2.3);
    glVertex2f(1.5, -2);
    //Rad 1
    glVertex2f(-2.5, -2);
    glVertex2f(-2.5, -1);
    glVertex2f(-1.5, -1);
    glVertex2f(-1.5, -2);
    //Rad2
    glVertex2f(-2.5, 1);
    glVertex2f(-2.5, 2);
    glVertex2f(-1.5, 2);
    glVertex2f(-1.5, 1);
    //Rad3
    glVertex2f(1.5, 1);
    glVertex2f(1.5, 2);
    glVertex2f(2.5, 2);
    glVertex2f(2.5, 1);
    //Rad4
    glVertex2f(1.5, -2);
    glVertex2f(1.5, -1);
    glVertex2f(2.5, -1);
    glVertex2f(2.5, -2);
    glEnd();
    //Spitze
    glBegin(GL_TRIANGLES);
    glVertex2f(-1.5, -2);
    glVertex2f(0, -3.5);
    glVertex2f(1.5, -2);
    glEnd();




    glutSwapBuffers();

  
   

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w,
        (GLsizei)h);

    // Matrix mode
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (w <= h)
        glOrtho(0, 100, 0 * (GLfloat)h / (GLfloat)w, 100 * (GLfloat)h / (GLfloat)w, 0, 100);


    else
        glOrtho(0 * (GLfloat)w / (GLfloat)h, 100 * (GLfloat)w / (GLfloat)h, 0, 100, 0, 100);




    glMatrixMode(GL_MODELVIEW);

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


glm::vec3 bezierPointspanitik(float t, GLfloat ctrlpoints[4][3]) {

    glm::vec3 result;
    glm::vec3 p0(ctrlpoints[0][0], ctrlpoints[0][1], ctrlpoints[0][2]);
    glm::vec3 p1(ctrlpoints[1][0], ctrlpoints[1][1], ctrlpoints[1][2]);
    glm::vec3 p2(ctrlpoints[2][0], ctrlpoints[2][1], ctrlpoints[2][2]);
    glm::vec3 p3(ctrlpoints[3][0], ctrlpoints[3][1], ctrlpoints[3][2]);


    float u = 1 - t;

    result = u * u * u * p0 + 3 * (u * u) * t * p1 + 3 * u * (t * t) * p2 + (t * t * t) * p3;
    return result;

}

glm::vec3 bezierPointspanitik2(float t, GLfloat ctrlpoints[4][3]) {

    glm::vec3 result1;
    glm::vec3 p00(ctrlpoints[0][0], ctrlpoints[0][1], ctrlpoints[0][2]);
    glm::vec3 p11(ctrlpoints[1][0], ctrlpoints[1][1], ctrlpoints[1][2]);
    glm::vec3 p22(ctrlpoints[2][0], ctrlpoints[2][1], ctrlpoints[2][2]);
    glm::vec3 p33(ctrlpoints[3][0], ctrlpoints[3][1], ctrlpoints[3][2]);


    float u1 = 1 - t;

    result1 = u1 * u1 * u1 * p00 + 3 * (u1 * u1) * t * p11 + 3 * u1 * (t * t) * p22 + (t * t * t) * p33;
    return result1;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

glm::vec3 bezierPoints(float t, vector<vector<double>> points) {
    glm::vec3 p0(62.5, 37.5, 0);
    glm::vec3 p1(69, 30, 0);
    float u = 1 - t;


        glm::vec3 p2(69, 25, 0);
        glm::vec3 p3(62.5, 17.5, 0);
        return u * u * u * p0 + 3 * (u * u) * t * p1 + 3 * u * (t * t) * p2 + (t * t * t) * p3;
}

glm::vec3 bezierPoints2(float t, vector<vector<double>> points) {
    glm::vec3 p02(62.5, 17.5, 0);
    glm::vec3 p12(50, 17.5, 0);
    float u = 1 - t;

    glm::vec3 p22(40, 17.5, 0);
    glm::vec3 p32(27.5, 17.5, 0);
    return u * u * u * p02 + 3 * (u * u) * t * p12 + 3 * u * (t * t) * p22 + (t * t * t) * p32;
}


glm::vec3 bezierPoints3(float t, vector<vector<double>> points) {
    glm::vec3 p03(27.5, 17.5, 0);
    glm::vec3 p13(21, 25, 0);
    float u = 1 - t;

    glm::vec3 p23(21, 30, 0);
    glm::vec3 p33(27.5, 37.5, 0);
    return u * u * u * p03 + 3 * (u * u) * t * p13 + 3 * u * (t * t) * p23 + (t * t * t) * p33;
}


glm::vec3 bezierPoints4(float t, vector<vector<double>> points) {
    glm::vec3 p04(27.5, 37.5, 0);
    glm::vec3 p14(40, 37.5, 0);
    float u = 1 - t;

    glm::vec3 p24(50, 37.5, 0);
    glm::vec3 p34(62.5, 37.5, 0);
    return u * u * u * p04 + 3 * (u * u) * t * p14 + 3 * u * (t * t) * p24 + (t * t * t) * p34;
}

*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Driver Code
int main(int argc, char** argv)
{


    //curveVertex = initValues();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);


    // Specifies the window size
    glutInitWindowSize(1300, 900);
    glutInitWindowPosition(100, 50);

    // Creates the window as
    // specified by the user
    glutCreateWindow(argv[0]);


    // Links display event with the
    // display event handler(display)
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    initGL();



    glutTimerFunc(0, timer, 0);
    glutSpecialFunc(SpecialKeyFunc);
    // Loops the current event
    glutMainLoop();

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

