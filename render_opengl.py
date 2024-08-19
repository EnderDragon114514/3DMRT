import pygame
from pygame.locals import *
from OpenGL.GL import *
from OpenGL.GLU import *
import sys

filename = sys.argv[1]
with open(filename, 'r',encoding="utf-8") as file:
    file_content = file.read()

exec(file_content)

def draw_pyramid():
    glBegin(GL_TRIANGLES)
    for i, face in enumerate(faces):
        glColor3fv(colors[i])
        for vertex in face:
            glVertex3fv(vertices[vertex])
    glEnd()

def main():
    pygame.init()
    display = (1024, 768)
    pygame.display.set_mode(display, DOUBLEBUF | OPENGL)
    gluPerspective(45, (display[0] / display[1]), 0.1, 50.0)
    glTranslatef(0.0, 0.0, -5)
    glEnable(GL_DEPTH_TEST)
    glDepthFunc(GL_LESS)
    last_x, last_y = pygame.mouse.get_pos()
    while True:
        for event in pygame.event.get():
            if event.type == QUIT:
                pygame.quit()
                quit()
        x, y = pygame.mouse.get_pos()
        delta_x = x - last_x
        delta_y = y - last_y
        glRotatef(delta_x, 0, 1, 0)
        glRotatef(delta_y, 1, 0, 0)
        last_x, last_y = x, y
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
        draw_pyramid()
        pygame.display.flip()
        pygame.time.wait(1)

if __name__ == "__main__":
    main()