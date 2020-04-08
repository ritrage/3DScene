#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<string>
#include<cstring>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include<GL/gl.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
//#include "Model.h"

//std::vector< glm::vec3 > vertices;
//std::vector< glm::vec2 > uvs;
//std::vector< glm::vec3 > normals;

void drawingRoom();
/*
bool loadOBJ(
	const char* path,
	std::vector<glm::vec3>& out_vertices,
	std::vector<glm::vec2>& out_uvs,
	std::vector<glm::vec3>& out_normals
) {
	printf("Loading OBJ file %s...\n", path);

	std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
	std::vector<glm::vec3> temp_vertices;
	std::vector<glm::vec2> temp_uvs;
	std::vector<glm::vec3> temp_normals;

	FILE* file = fopen(path, "r");
	if (file == NULL) {
		printf("Impossible to open the file ! Are you in the right path ? See Tutorial 1 for details\n");
		getchar();
		return false;
	}

	while (1) {

		char lineHeader[128];
		// read the first word of the line
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
			break; // EOF = End Of File. Quit the loop.

		// else : parse lineHeader

		if (strcmp(lineHeader, "v") == 0) {
			glm::vec3 vertex;
			fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
			temp_vertices.push_back(vertex);
		}
		else if (strcmp(lineHeader, "vt") == 0) {
			glm::vec2 uv;
			fscanf(file, "%f %f\n", &uv.x, &uv.y);
			uv.y = -uv.y; // Invert V coordinate since we will only use DDS texture, which are inverted. Remove if you want to use TGA or BMP loaders.
			temp_uvs.push_back(uv);
		}
		else if (strcmp(lineHeader, "vn") == 0) {
			glm::vec3 normal;
			fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
			temp_normals.push_back(normal);
		}
		else if (strcmp(lineHeader, "f") == 0) {
			std::string vertex1, vertex2, vertex3;
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
			int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
			if (matches != 9) {
				printf("File can't be read by our simple parser :-( Try exporting with other options\n");
				fclose(file);
				return false;
			}
			vertexIndices.push_back(vertexIndex[0]);
			vertexIndices.push_back(vertexIndex[1]);
			vertexIndices.push_back(vertexIndex[2]);
			uvIndices.push_back(uvIndex[0]);
			uvIndices.push_back(uvIndex[1]);
			uvIndices.push_back(uvIndex[2]);
			normalIndices.push_back(normalIndex[0]);
			normalIndices.push_back(normalIndex[1]);
			normalIndices.push_back(normalIndex[2]);
		}
		else {
			// Probably a comment, eat up the rest of the line
			char stupidBuffer[1000];
			fgets(stupidBuffer, 1000, file);
		}

	}

	// For each vertex of each triangle
	for (unsigned int i = 0; i < vertexIndices.size(); i++) {

		// Get the indices of its attributes
		unsigned int vertexIndex = vertexIndices[i];
		unsigned int uvIndex = uvIndices[i];
		unsigned int normalIndex = normalIndices[i];

		// Get the attributes thanks to the index
		glm::vec3 vertex = temp_vertices[vertexIndex - 1];
		glm::vec2 uv = temp_uvs[uvIndex - 1];
		glm::vec3 normal = temp_normals[normalIndex - 1];

		// Put the attributes in buffers
		out_vertices.push_back(vertex);
		out_uvs.push_back(uv);
		out_normals.push_back(normal);

	}
	fclose(file);
	return true;
}
*/

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("3DScene");
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(drawingRoom);
	glClearColor(0,0,0,0);
	glViewport(0, 0, 640, 480);
	glutMainLoop();
	return 0;
}

void drawingRoom() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();


	///front side of back wall
	glBegin(GL_POLYGON);
	glColor3f(.67, 0.48, 0.16);     
	glVertex3f(0.5, -0.35, .5);      
	glVertex3f(0.5, 0.35, .5);      
	glVertex3f(-0.5, 0.35, .5);
	glVertex3f(-0.5, -0.35, .5);    
	glEnd();

	///back side of back wall
	glBegin(GL_POLYGON);
	glColor3f(.67, 0.48, .16);
	glVertex3f(0.5, -0.35, .65);
	glVertex3f(0.5, 0.35, .65);
	glVertex3f(-0.5, 0.35, .65);
	glVertex3f(-0.5, -0.35, .65);
	glEnd();

	///right side of back wall
	glBegin(GL_POLYGON);
	glColor3f(1, 0.99, .73);
	glVertex3f(0.5, -0.35, .65);
	glVertex3f(0.5, -0.35, .5);
	glVertex3f(0.5, 0.35, .5);
	glVertex3f(0.5, 0.35, .65);
	glEnd();

	///left side of back wall
	glBegin(GL_POLYGON);
	glColor3f(1,.99,.73);
	glVertex3f(-0.5, -0.35, .65);
	glVertex3f(-0.5, -0.35, .5);
	glVertex3f(-0.5, 0.35, .5);
	glVertex3f(-0.5, 0.35, .65);
	
	glEnd();

	///top side of back wall
	glBegin(GL_POLYGON);
	glColor3f(1, .99, .73);
	glVertex3f(-0.5, 0.35, .65);
	glVertex3f(-0.5, 0.35, .5);
	glVertex3f(0.5, 0.35, .5);
	glVertex3f(0.5, 0.35, .65);
	
	glEnd();

	///bottom side of back wall
	glBegin(GL_POLYGON);
	glColor3f(1, .99, .73);
	glVertex3f(-0.5, -0.35, .65);
	glVertex3f(-0.5, -0.35, .5);
	glVertex3f(0.5, -0.35, .5);
	glVertex3f(0.5, -0.35, .65);
	
	glEnd();

	///front side of left wall
	glBegin(GL_POLYGON);
	glColor3f(.67, 0.48, 0.16);
	glVertex3f(-1, 1, -.5);
	glVertex3f(-1.15, 1, -.5);
	glVertex3f(-1.15, -1, -.5);
	glVertex3f(-1, -1, -.5);

	glEnd();

	///back side of left wall
	glBegin(GL_POLYGON);
	glColor3f(1, .99, .73);
	glVertex3f(-.5,.35,.5);
	glVertex3f(-.65, .35, .5);
	glVertex3f(-.65, -.35, .5);
	glVertex3f(-.5, -.35, .5);
	glEnd();

	///right side of left wall
	glBegin(GL_POLYGON);
	glColor3f(1, .99, .73);
	glVertex3f(-.5,.35,.5);
	glVertex3f(-.5, -.35, .5);
	glVertex3f(-1, -1, -.5);
	glVertex3f(-1, 1, -.5);
	glEnd();

	///left side of left wall
	glBegin(GL_POLYGON);
	glColor3f(1, .99, .73);
	glVertex3f(-.65, .35, .5);
	glVertex3f(-.65, -.35, .5);
	glVertex3f(-1.15, -1, -.5);
	glVertex3f(-1.15, 1, -.5);
	glEnd();

	///top side of left wall
	glBegin(GL_POLYGON);
	glColor3f(1, .99, .73);
	glVertex3f(-.5, .35, .5);
	glVertex3f(-.65, .35, .5);
	glVertex3f(-1.15, 1, -.5);
	glVertex3f(-1, 1, -.5);
	glEnd();

	///bottom side of left wall
	glBegin(GL_POLYGON);
	glColor3f(1,.99,.73);
	glVertex3f(-.5,-.35, .5);
	glVertex3f(-.65, -.35, .5);
	glVertex3f(-1.15, -1, -.5);
	glVertex3f(-1, -1, -.5);
	glEnd();

	///front side of righßt wall
	glBegin(GL_POLYGON);
	glColor3f(.67, 0.48, 0.16);
	glVertex3f(1, 1, -.5);
	glVertex3f(1.15, 1, -.5);
	glVertex3f(1.15, -1, -.5);
	glVertex3f(1, -1, -.5);

	glEnd();

	///back side of left wall
	glBegin(GL_POLYGON);
	glColor3f(1, .99, .73);
	glVertex3f(.5, .35, .5);
	glVertex3f(.65, .35, .5);
	glVertex3f(.65, -.35, .5);
	glVertex3f(.5, -.35, .5);
	glEnd();

	///left side of left wall
	glBegin(GL_POLYGON);
	glColor3f(1, .99, .73);
	glVertex3f(.5, .35, .5);
	glVertex3f(.5, -.35, .5);
	glVertex3f(1, -1, -.5);
	glVertex3f(1, 1, -.5);
	glEnd();

	///right side of left wall
	glBegin(GL_POLYGON);
	glColor3f(1, .99, .73);
	glVertex3f(.65, .35, .5);
	glVertex3f(.65, -.35, .5);
	glVertex3f(1.15, -1, -.5);
	glVertex3f(1.15, 1, -.5);
	glEnd();

	///top side of left wall
	glBegin(GL_POLYGON);
	glColor3f(1, .99, .73);
	glVertex3f(.5, .35, .5);
	glVertex3f(.65, .35, .5);
	glVertex3f(1.15, 1, -.5);
	glVertex3f(1, 1, -.5);
	glEnd();

	///bottom side of left wall
	glBegin(GL_POLYGON);
	glColor3f(1, .99, .73);
	glVertex3f(.5, -.35, .5);
	glVertex3f(.65, -.35, .5);
	glVertex3f(1.15, -1, -.5);
	glVertex3f(1, -1, -.5);
	glEnd();

	///front side of floor
	glBegin(GL_POLYGON);
	glColor3f(.86, .81, .71);
	glVertex3f(-1,-1,-.5);
	glVertex3f(-1, -1.15, -.5);
	glVertex3f(1, -1.15, -.5);
	glVertex3f(1, -1, -.5);
	glEnd();

	///back side of floor
	glBegin(GL_POLYGON);
	glColor3f(.86, .81, .71);
	glVertex3f(-.5,-.35,.5);
	glVertex3f(-.5, -.5, .5);
	glVertex3f(.5, -.5, .5);
	glVertex3f(.5, -.35, .5);
	glEnd();

	///left side of floor
	glBegin(GL_POLYGON);
	glColor3f(.86, .81, .71);
	glVertex3f(-.5, -.35, .5);
	glVertex3f(-.5, -.5, .5);
	glVertex3f(-1, -1.15, -.5);
	glVertex3f(-1, -1, -.5);
	glEnd();

	///right side of floor
	glBegin(GL_POLYGON);
	glColor3f(.86, .81, .71);
	glVertex3f(.5, -.35, .5);
	glVertex3f(.5, -.5, .5);
	glVertex3f(1, -1.15, -.5);
	glVertex3f(1, -1, -.5);
	glEnd();

	///top side of floor
	glBegin(GL_POLYGON);
	glColor3f(.86, .81, .71);
	glVertex3f(-.5,-.35,.5);
	glVertex3f(.5, -.35, .5);
	glVertex3f(1, -1, -.5);
	glVertex3f(-1, -1, -.5);
	glEnd();

	///bottom side of floor
	glBegin(GL_POLYGON);
	glColor3f(.86, .81, .71);
	glVertex3f(-.5, -.5, .5);
	glVertex3f(.5, -.5, .5);
	glVertex3f(1, -1.15, -.5);
	glVertex3f(-1, -1.15, -.5);
	glEnd();

	///front side of ceiling
	glBegin(GL_POLYGON);
	glColor3f(.86, .81, .71);
	glVertex3f(-1, 1, -.5);
	glVertex3f(-1, 1.15, -.5);
	glVertex3f(1, 1.15, -.5);
	glVertex3f(1, 1, -.5);
	glEnd();

	///back side of floor
	glBegin(GL_POLYGON);
	glColor3f(.86, .81, .71);
	glVertex3f(-.5, .35, .5);
	glVertex3f(-.5, .5, .5);
	glVertex3f(.5, .5, .5);
	glVertex3f(.5, .35, .5);
	glEnd();

	///left side of floor
	glBegin(GL_POLYGON);
	glColor3f(.86, .81, .71);
	glVertex3f(-.5, .35, .5);
	glVertex3f(-.5, .5, .5);
	glVertex3f(-1, 1.15, -.5);
	glVertex3f(-1, 1, -.5);
	glEnd();

	///right side of floor
	glBegin(GL_POLYGON);
	glColor3f(.86, .81, .71);
	glVertex3f(.5, .35, .5);
	glVertex3f(.5, .5, .5);
	glVertex3f(1, 1.15, -.5);
	glVertex3f(1, 1, -.5);
	glEnd();

	///bottom side of floor
	glBegin(GL_POLYGON);
	glColor3f(.86, .81, .71);
	glVertex3f(-.5, .35, .5);
	glVertex3f(.5, .35, .5);
	glVertex3f(1, 1, -.5);
	glVertex3f(-1, 1, -.5);
	glEnd();

	///top side of floor
	glBegin(GL_POLYGON);
	glColor3f(.86, .81, .71);
	glVertex3f(-.5, .5, .5);
	glVertex3f(.5, .5, .5);
	glVertex3f(1, 1.15, -.5);
	glVertex3f(-1, 1.15, -.5);
	glEnd();



/*
	Shader shader("modelLoading.vs", "modelLoading.frag");
	Model ourModel((GLchar*)"blenderObjects/Wood_Table.obj");
	glm::mat4 model;
	model = glm::translate(model, glm::vec3(0.0f, -1.75f, 0.0f));
	model = glm::scale(model, glm::vec3(.2f, .2f, .2f));
	glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
	ourModel.Draw(shader);
	*/
	glFlush();
	glutSwapBuffers();
}