#include <iostream>
#include "Display.h"
#include "shader.h"
#include "mesh.h"

#undef main
int main(int argc, char** argv) 
{
	Display display(800, 600, "Hello World!");

	Shader shader(".\\res\\basicShader");
	Vertex vertices[] = { Vertex(vec3(-0.5, -0.5, 0)),
							Vertex(vec3(0, 0.5, 0)),
							Vertex(vec3(0.5, -0.5, 0)) };
	Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));

	while (!display.IsClosed()) 
	{
		display.Clear(0.0f, 0.15f, 0.3f, 1.0f);
		
		shader.Bind();
		mesh.Draw();

		display.Update();
	}

	return 0;
}