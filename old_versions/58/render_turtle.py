import turtle
import math
import sys

filename = sys.argv[1]
with open(filename, 'r',encoding="utf-8") as file:
    file_content = file.read()

exec(file_content)
# 投影矩阵参数
def project(x, y, z):
    scale = 500 / (z + 5)  # 投影缩放因子
    x_proj = x * scale
    y_proj = y * scale
    return x_proj, y_proj

def rotate_x(x, y, z, angle):
    rad = math.radians(angle)
    y_rot = y * math.cos(rad) - z * math.sin(rad)
    z_rot = y * math.sin(rad) + z * math.cos(rad)
    return x, y_rot, z_rot

def rotate_y(x, y, z, angle):
    rad = math.radians(angle)
    x_rot = x * math.cos(rad) + z * math.sin(rad)
    z_rot = -x * math.sin(rad) + z * math.cos(rad)
    return x_rot, y, z_rot

def rotate_z(x, y, z, angle):
    rad = math.radians(angle)
    x_rot = x * math.cos(rad) - y * math.sin(rad)
    y_rot = x * math.sin(rad) + y * math.cos(rad)
    return x_rot, y_rot, z

def draw_tetrahedron(vertices, faces, colors, rotation_angle_x, rotation_angle_y, rotation_angle_z):
    turtle.clear()
    turtle.penup()
    
    for i, face in enumerate(faces):
        turtle.begin_fill()
        turtle.color(colors[i % len(colors)])
        for idx in face:
            x, y, z = vertices[idx]
            x, y, z = rotate_x(x, y, z, rotation_angle_x)
            x, y, z = rotate_y(x, y, z, rotation_angle_y)
            x, y, z = rotate_z(x, y, z, rotation_angle_z)
            x_proj, y_proj = project(x, y, z)
            turtle.goto(x_proj, y_proj)
            turtle.pendown()
        turtle.goto(project(vertices[face[0]][0], vertices[face[0]][1], vertices[face[0]][2])[0],
                    project(vertices[face[0]][0], vertices[face[0]][1], vertices[face[0]][2])[1])
        turtle.end_fill()
    
    turtle.penup()

# 初始化旋转角度和鼠标事件的起始点
rotation_angle_x = 0
rotation_angle_y = 0
rotation_angle_z = 0
last_x = 0
last_y = 0

def on_drag(x, y):
    global last_x, last_y, rotation_angle_x, rotation_angle_y

    if last_x != 0 and last_y != 0:
        dx = x - last_x
        dy = y - last_y
        
        # 根据鼠标拖动方向更新旋转角度
        rotation_angle_x += dy * 0.1
        rotation_angle_y -= dx * 0.1

    last_x = x
    last_y = y

def on_release(x, y):
    global last_x, last_y
    last_x = 0
    last_y = 0

def main():
    turtle.setup(1024, 768)
    turtle.speed(0)  # Fastest drawing speed

    turtle.onscreenclick(on_drag, 1)  # 鼠标左键拖动事件
    turtle.onscreenclick(on_release, 3)  # 鼠标右键释放事件（可选）

    while True:
        draw_tetrahedron(vertices, faces, colors, rotation_angle_x, rotation_angle_y, rotation_angle_z)
        turtle.update()

if __name__ == "__main__":
    main()
