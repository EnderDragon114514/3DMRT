#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>
#include <fstream>
using namespace std;
void gotoxy(int y, int x) {
	COORD pos = { x,y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}
int main(int argc,char* argv[]) {
	cout<<"���Եȣ����ڳ�ʼ��OpenGL..."<<endl;
	system("pip install pyopengl pygame numpy");
	string openglCode="import pygame\nfrom pygame.locals import *\nfrom OpenGL.GL import *\nfrom OpenGL.GLU import *\nimport sys\n\nfilename = sys.argv[1]\nwith open(filename, 'r',encoding=\"utf-8\") as file:\n    file_content = file.read()\n\nexec(file_content)\n\ndef draw_pyramid():\n    glBegin(GL_TRIANGLES)\n    for i, face in enumerate(faces):\n        glColor3fv(colors[i])\n        for vertex in face:\n            glVertex3fv(vertices[vertex])\n    glEnd()\n\ndef main():\n    pygame.init()\n    display = (1024, 768)\n    pygame.display.set_mode(display, DOUBLEBUF | OPENGL)\n    gluPerspective(45, (display[0] / display[1]), 0.1, 50.0)\n    glTranslatef(0.0, 0.0, -5)\n    glEnable(GL_DEPTH_TEST)\n    glDepthFunc(GL_LESS)\n    last_x, last_y = pygame.mouse.get_pos()\n    while True:\n        for event in pygame.event.get():\n            if event.type == QUIT:\n                pygame.quit()\n                quit()\n        x, y = pygame.mouse.get_pos()\n        delta_x = x - last_x\n        delta_y = y - last_y\n        glRotatef(delta_x, 0, 1, 0)\n        glRotatef(delta_y, 1, 0, 0)\n        last_x, last_y = x, y\n        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)\n        draw_pyramid()\n        pygame.display.flip()\n        pygame.time.wait(1)\n\nif __name__ == \"__main__\":\n    main()";
	ofstream openGLCodeOutput("render_opengl.py");
	openGLCodeOutput<<openglCode;
	while(1) {
		system("cls");
		system("mode con cols=50 lines=13");
		system("title 3DMRT Launcher For Windows v1.1 Build 62");
		cout<<"3DMRT Launcher For Windows v1.1 Build 62"<<endl;
		cout<<"=================================================="<<endl;
		cout<<"|ѡ��Ҫ�����İ汾:                               |"<<endl;
		cout<<"|   [1]OpenGLӲ����Ⱦ��                          |"<<endl;
		cout<<"|   [2]Turtle�����Ⱦ��(��֧��58����)            |"<<endl;
		cout<<"|ע��:Turtle��Ⱦ�ٶ�С��1fps                     |"<<endl;
		cout<<"|�������ѡ��:                                   |"<<endl;
		cout<<"|                                                |"<<endl;
		cout<<"|                                                |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"|׼������                                        |"<<endl;
		cout<<"=================================================="<<endl;
		int sel=_getch();
		if(sel=='1') {
			gotoxy(0,0);
			system("mode con cols=50 lines=13");
			system("title 3DMRT Launcher For Windows v1.1 Build 62");
			cout<<"3DMRT Launcher For Windows v1.1 Build 62"<<endl;
			cout<<"=================================================="<<endl;
			cout<<"|ѡ��Ҫ�����İ汾:                               |"<<endl;
			cout<<"| ->[1]OpenGLӲ����Ⱦ��                          |"<<endl;
			cout<<"|   [2]Turtle�����Ⱦ��                          |"<<endl;
			cout<<"|ע��:Turtle��Ⱦ�ٶ�С��1fps                     |"<<endl;
			cout<<"|�����ļ���/���ļ���ק���˴�:                    |"<<endl;
			cout<<"| [                                            ] |"<<endl;
			cout<<"|                                                |"<<endl;
			cout<<"|------------------------------------------------|"<<endl;
			cout<<"|��ȡ����(30%)                                   |"<<endl;
			cout<<"=================================================="<<endl;
			gotoxy(7,3);
			string filename;
			getline(cin,filename);
			gotoxy(10,1);
			cout<<"�ϲ�����(75%)"<<endl;
			Sleep(350);
			string cmd="py .\\render_opengl.py ";
			cmd+=filename;
			gotoxy(10,1);
			cout<<"��������(100%)"<<endl;
			Sleep(125);
			gotoxy(0,0);
			system("cls");
			cout<<"[��־���] - 3DMRT Launcher For Win V1.1 Build 62"<<endl;
			cout<<"=================================================="<<endl;
			system(cmd.c_str());
			system("pause");
		} else if(sel=='2') {
			gotoxy(0,0);
			system("mode con cols=50 lines=13");
			system("title 3DMRT Launcher For Windows v1.1 Build 62");
			cout<<"3DMRT Launcher For Windows v1.1 Build 62"<<endl;
			cout<<"=================================================="<<endl;
			cout<<"|ѡ��Ҫ�����İ汾:                               |"<<endl;
			cout<<"|   [1]OpenGLӲ����Ⱦ��                          |"<<endl;
			cout<<"| ->[2]Turtle�����Ⱦ��                          |"<<endl;
			cout<<"|ע��:Turtle��Ⱦ�ٶ�С��1fps                     |"<<endl;
			cout<<"|�����ļ���/���ļ���ק���˴�:                    |"<<endl;
			cout<<"| [                                            ] |"<<endl;
			cout<<"|                                                |"<<endl;
			cout<<"|------------------------------------------------|"<<endl;
			cout<<"|��ȡ����(30%)                                   |"<<endl;
			cout<<"=================================================="<<endl;
			gotoxy(7,3);
			string filename;
			getline(cin,filename);
			gotoxy(10,1);
			cout<<"�ϲ�����(75%)"<<endl;
			Sleep(350);
			string cmd="py .\\render_turtle.py ";
			cmd+=filename;
			gotoxy(10,1);
			cout<<"��������(100%)"<<endl;
			Sleep(125);
			gotoxy(0,0);
			system("cls");
			cout<<"[��־���] - 3DMRT Launcher For Win V1.1 Build 62"<<endl;
			cout<<"=================================================="<<endl;
			cout<<"Unsupported Version:62"<<endl;
			cout<<"At "<<&cmd<<":Unsupported Version"<<endl; 
			system("pause");
		}
	}
}
