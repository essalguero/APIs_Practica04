#ifdef _MSC_VER
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif


#include <fstream>
#include <iostream>
#include <sstream>

#include <vector>

#include <memory>


#include "../lib/glew/glew.h"
#include "../lib/glfw3/glfw3.h"
#include "common.h"
#include "Shader.h"
#include "Vertex.h"
#include "Buffer.h"
#include "Mesh.h"
#include "Entity.h"
#include "Model.h"
#include "Camera.h"
#include "World.h"
#include "Texture.h"

#include "State.h"


#define FULLSCREEN false

const float ROTATION_SPEED = 64.0f;
const float MOVING_SPEED = 0.01f;
//const float ROTATION_SPEED_RADS = glm::radians(ROTATION_SPEED);

std::string readString(const char* filename) {
	std::ifstream f(filename, std::ios_base::binary);
	std::stringstream ss;
	ss << f.rdbuf();
	return ss.str();
}


int init() {
	
	// init glew
	if (glewInit()) {
		std::cout << "could not initialize glew" << std::endl;
		return -1;
	}

	// enable gl states
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_SCISSOR_TEST);
	return 0;

}


// This method creates all the models and add them to the world
int createModelsInWorld(World & world)
{
	/*// Crear los Buffers que contiene los datos del cubo. El cubo lo forman dos buffers distintos (se usan una textura distinta en cada Buffer)
	// 1.- Caras laterales
	// 2.- Caras superior e inferion
	vector<Vertex> verticesLaterales;
	vector<uint16_t> indicesLaterales;
	vector<Vertex> verticesTapas;
	vector<uint16_t> indicesTapas;




	Vertex v0{ glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0, 0) };
	Vertex v1{ glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(1, 0) };
	Vertex v2{ glm::vec3(0.5f, 0.5f, -0.5f), glm::vec2(1, 1) };
	Vertex v3{ glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(0, 1) };

	verticesLaterales.push_back(v0);
	verticesLaterales.push_back(v1);
	verticesLaterales.push_back(v2);
	verticesLaterales.push_back(v3);

	indicesLaterales.push_back(0);
	indicesLaterales.push_back(1);
	indicesLaterales.push_back(2);
	indicesLaterales.push_back(2);
	indicesLaterales.push_back(3);
	indicesLaterales.push_back(0);



	Vertex v4{ glm::vec3(0.5f, -0.5f, -0.5f),  glm::vec2(0, 0) };
	Vertex v5{ glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(1, 0) };
	Vertex v6{ glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(1, 1) };
	Vertex v7{ glm::vec3(0.5f, 0.5f, -0.5f), glm::vec2(0, 1) };

	verticesLaterales.push_back(v4);
	verticesLaterales.push_back(v5);
	verticesLaterales.push_back(v6);
	verticesLaterales.push_back(v7);


	indicesLaterales.push_back(4);
	indicesLaterales.push_back(5);
	indicesLaterales.push_back(6);
	indicesLaterales.push_back(6);
	indicesLaterales.push_back(7);
	indicesLaterales.push_back(4);


	Vertex v8{ glm::vec3(0.5f, -0.5f, 0.5f),  glm::vec2(0, 0) };
	Vertex v9{ glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(1, 0) };
	Vertex v10{ glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(1, 1) };
	Vertex v11{ glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(0, 1) };

	verticesLaterales.push_back(v8);
	verticesLaterales.push_back(v9);
	verticesLaterales.push_back(v10);
	verticesLaterales.push_back(v11);

	indicesLaterales.push_back(8);
	indicesLaterales.push_back(9);
	indicesLaterales.push_back(10);
	indicesLaterales.push_back(10);
	indicesLaterales.push_back(11);
	indicesLaterales.push_back(8);


	
	Vertex v12{ glm::vec3(-0.5f, -0.5f, 0.5f),  glm::vec2(0, 0) };
	Vertex v13{ glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(1, 0) };
	Vertex v14{ glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(1, 1) };
	Vertex v15{ glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(0, 1) };

	verticesLaterales.push_back(v12);
	verticesLaterales.push_back(v13);
	verticesLaterales.push_back(v14);
	verticesLaterales.push_back(v15);

	indicesLaterales.push_back(12);
	indicesLaterales.push_back(13);
	indicesLaterales.push_back(14);
	indicesLaterales.push_back(14);
	indicesLaterales.push_back(15);
	indicesLaterales.push_back(12);

	//Insert indexes for the top and bottom sides of the cube
	Vertex v20{ glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(0, 0) };
	Vertex v21{ glm::vec3(0.5f, 0.5f, -0.5f), glm::vec2(1, 0) };
	Vertex v22{ glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(1, 1) };
	Vertex v23{ glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(0, 1) };

	verticesTapas.push_back(v20);
	verticesTapas.push_back(v21);
	verticesTapas.push_back(v22);
	verticesTapas.push_back(v23);

	indicesTapas.push_back(0);
	indicesTapas.push_back(1);
	indicesTapas.push_back(2);
	indicesTapas.push_back(2);
	indicesTapas.push_back(3);
	indicesTapas.push_back(0);

	Vertex v24{ glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0, 0) };
	Vertex v25{ glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(1, 0) };
	Vertex v26{ glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(1, 1) };
	Vertex v27{ glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0, 1) };

	verticesTapas.push_back(v24);
	verticesTapas.push_back(v25);
	verticesTapas.push_back(v26);
	verticesTapas.push_back(v27);

	indicesTapas.push_back(4);
	indicesTapas.push_back(5);
	indicesTapas.push_back(6);
	indicesTapas.push_back(6);
	indicesTapas.push_back(7);
	indicesTapas.push_back(4);

	// Creacion de los Buffers
	shared_ptr<Buffer> bufferDatosLaterales = Buffer::create(verticesLaterales, indicesLaterales);
	if (strcmp(bufferDatosLaterales->getError(), "") != 0)
	{
		cout << bufferDatosLaterales->getError() << endl;
		return 0;
	}

	shared_ptr<Buffer> bufferDatosTapas = Buffer::create(verticesTapas, indicesTapas);
	if (strcmp(bufferDatosTapas->getError(), "") != 0)
	{
		cout << bufferDatosTapas->getError() << endl;
		return 0;
	}

	// Carga Material para caras laterales
	Material materialFront = Material::Material(Texture::load("../data/front.png"), nullptr);
	// Carga Material para caras Superior e Inferior
	Material materialTop = Material::Material(Texture::load("../data/top.png"), nullptr);

	// Crear un Mesh para el cubo
	shared_ptr<Mesh> cubeMesh = make_shared<Mesh>();

	// Crear un Model para el cubo
	shared_ptr<Model> cube = make_shared<Model>(cubeMesh);

	// Añadir el Buffer que contiene los datos de las caras laterales al Mesh del cubo
	cubeMesh->addBuffer(bufferDatosLaterales, materialFront);
	// Añadir el Buffer que contiene los datos de las caras laterales al Mesh del cubo
	cubeMesh->addBuffer(bufferDatosTapas, materialTop);

	glm::vec3 scaleVector(1.0f, 1.0f, 1.0f);
	glm::vec3 rotationVector(0.0f, 0.0f, 0.0f);


	cube->setScale(scaleVector);
	cube->setRotation(rotationVector);
	cube->setPosition(glm::vec3(0.0f, 0.0f, 0.0f));

	//Add the cube to the world object
	world.addEntity(cube);*/


	std::shared_ptr<Mesh> worldMesh = Mesh::load("../data/asian_town.msh.xml");
	shared_ptr<Model> worldModel = make_shared<Model>(worldMesh);
	worldModel->setScale(vec3(10.0f, 10.0f, 10.0f));

	world.addEntity(worldModel);

	return 1;
}


int main(int, char**) {


	if (glfwInit() != GLFW_TRUE) {
		std::cout << "could not initalize glfw" << std::endl;
		return -1;
	}
	atexit(glfwTerminate);

	// create window
	//glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	GLFWwindow* window = glfwCreateWindow(800, 600, "U-gine", FULLSCREEN ? glfwGetPrimaryMonitor() : nullptr, nullptr);
	if (!window) {
		std::cout << "could not create glfw window" << std::endl;
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (init())
		return -1;


	// Store the Shader in the global object State
	State::defaultShader = Shader::create(readString("../data/shader.vert"), readString("../data/shader.frag"));

	// If there  was any error on the generation of the sharder, raise an error
	if (strcmp(State::defaultShader->getError(), "") != 0)
	{
		cout << State::defaultShader->getError() << endl;
		return -1;
	}

	// Generate the world
	World world;

	// Generate a camera and store it in the world
	shared_ptr<Camera> camera = make_shared<Camera>();
	camera->setPosition(glm::vec3(0.0f, 0.1f, 0.0f));
	camera->setClearColor(glm::vec3(135.0f / 255.0f, 206.0f / 255.0f, 235.0f / 255.0f));
	//glm::vec3 cameraRotation = camera->getRotation();
	//cameraRotation.x = -20.0f;
	//camera->setRotation(cameraRotation);
	world.addEntity(camera);

	// Generate the objects in the world
	if (!createModelsInWorld(world))
	{
		cout << "Error creating the Model objects in the world" << endl;
		return -1;
	}

	// create a cuaternion with the  
	//glm::quat rotationQuat = angleAxis(ROTATION_SPEED,
	//	glm::vec3(0.0f, 1.0f, 0.0f));

	double xPrev = 0;
	double yPrev = 0;

	double xCurrent;
	double yCurrent;

	glfwSetCursorPos(window, xPrev, yPrev);

	// Bucle principal
	float lastTime = static_cast<float>(glfwGetTime());
	while ( !glfwWindowShouldClose(window) && !glfwGetKey(window, GLFW_KEY_ESCAPE) ) {
		
		// Check key status
		if (glfwGetKey(window, GLFW_KEY_W) || glfwGetKey(window, GLFW_KEY_UP))
		{
			camera->move(vec3(0.0f, 0.0f, -MOVING_SPEED));
		}

		if (glfwGetKey(window, GLFW_KEY_S) || glfwGetKey(window, GLFW_KEY_DOWN))
		{
			camera->move(vec3(0.0f, 0.0f, MOVING_SPEED));
		}

		if (glfwGetKey(window, GLFW_KEY_A) || glfwGetKey(window, GLFW_KEY_LEFT))
		{
			camera->move(vec3(-MOVING_SPEED, 0.0f, 0.0f));
		}

		if (glfwGetKey(window, GLFW_KEY_D) || glfwGetKey(window, GLFW_KEY_RIGHT))
		{
			camera->move(vec3(MOVING_SPEED, 0.0f, 0.0f));
		}

		//Check mouse position
		glfwGetCursorPos(window, &xCurrent, &yCurrent);		camera->setRotation(glm::vec3((yPrev - yCurrent) / 2.0, (xPrev - xCurrent) / 2.0, 0.0f));

		// update delta time
		float newTime = static_cast<float>(glfwGetTime());
		float deltaTime = newTime - lastTime;
		lastTime = newTime;

		// get updated screen size
		int screenWidth, screenHeight;
		glfwGetWindowSize(window, &screenWidth, &screenHeight);

		// report screen size
		std::stringstream ss;
		ss << screenWidth << "x" << screenHeight;
		glfwSetWindowTitle(window, ss.str().c_str());

		// Update viewport in case the screen has been resized
		camera->setViewport(glm::ivec4(0, 0, screenWidth, screenHeight));

		// Set projection matrix in case the screen has been resized
		glm::mat4 projectionMatrix = glm::perspective(45.0f, 
			static_cast<float>(screenWidth) / static_cast<float>(screenHeight), 0.1f, 100.0f);
		camera->setProjection(projectionMatrix);

		
		// Update the objects in the world
		for (int i = 0; i < world.getNumEntities(); ++i) {

			std::shared_ptr<Entity> currentEntity = world.getEntity(i);

			//Only Model objects must be displayed
			std::shared_ptr<Model> currentModel = std::dynamic_pointer_cast<Model>(currentEntity);
			if (currentModel != nullptr)
			{
				// get the current quaternion of the object
				//glm::quat rotationQuaternion = currentModel->getRotationQuat();

				// Calculate the new quaternion
				//currentModel->setRotationQuat(glm::slerp(rotationQuaternion, 
				//	rotationQuat * rotationQuaternion, deltaTime));
				
			}
		}

		// Draw the objects
		world.update(deltaTime);
		world.draw();

		// update swap chain & process events
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	return 0;
}