
#include <chrono>

void GameLogic(Assignment07 *A, float Ar, glm::mat4 &ViewPrj, glm::mat4 &World) {
	// The procedure must implement the game logic  to move the character in third person.
	// Input:
	// <Assignment07 *A> Pointer to the current assignment code. Required to read the input from the user
	// <float Ar> Aspect ratio of the current window (for the Projection Matrix)
	// Output:
	// <glm::mat4 &ViewPrj> the view-projection matrix of the camera
	// <glm::mat4 &World> the world matrix of the object
	// Parameters
	// Camera FOV-y, Near Plane and Far Plane
	const float FOVy = glm::radians(45.0f);
	const float nearPlane = 0.1f;
	const float farPlane = 100.f;
	
	// Player starting point
	const glm::vec3 StartingPosition = glm::vec3(-41.50, 0.0, -19.5);
	
	// Camera target height and distance
	const float camHeight = 0.25;
	const float camDist = 1.5;
	// Camera Pitch limits
	const float minPitch = glm::radians(-8.75f);
	const float maxPitch = glm::radians(60.0f);
	// Rotation and motion speed
	const float ROT_SPEED = glm::radians(120.0f);
	const float MOVE_SPEED = 2.0f;

	const float dampFac = 10;
	// Integration with the timers and the controllers
	// returns:
	// <float deltaT> the time passed since the last frame
	// <glm::vec3 m> the state of the motion axes of the controllers (-1 <= m.x, m.y, m.z <= 1)
	// <glm::vec3 r> the state of the rotation axes of the controstatic glm::quat Rot =llers (-1 <= r.x, r.y, r.z <= 1)
	// <bool fire> if the user has pressed a fire button (not required in this assginment)
	float deltaT;
	glm::vec3 m = glm::vec3(0.0f), r = glm::vec3(0.0f);
	bool fire = false;
	A->getSixAxis(deltaT, m, r, fire);

	// Game Logic implementation
	// Current Player Position - statc variables make sure that the value remain unchanged in subsequent calls to the procedure
	static glm::vec3 Pos = StartingPosition;
	static float objYaw = 0, camPitch = 0, camYaw = 0; 
	

	// The Walk model update procedure
	
	//computing world matrix
	glm::mat4 Mw;

	// camera rotation (around the character)
	camYaw = camYaw + ROT_SPEED * r.y * deltaT ;
	//limit rotation between -360 and 360 to prevent overflow
	if(camYaw > glm::radians(360.0f))
		camYaw -= glm::radians(360.0f);
	else if(camYaw < glm::radians(-360.0f))
		camYaw += glm::radians(360.0f);

	// character rotation
	objYaw -= ROT_SPEED * m.x * deltaT; 
	//limit rotation between -360 and 360 to prevent overflow
	if(objYaw > glm::radians(360.0f))
		objYaw -= glm::radians(360.0f);
	else if(objYaw < glm::radians(-360.0f))
		objYaw += glm::radians(360.0f);
	

	// camera pitch (up and down)
	camPitch -= ROT_SPEED * r.x * deltaT;
	//limit pitch between minPitch and maxPitch
	if(camPitch < minPitch)
		camPitch = minPitch;
	else if(camPitch > maxPitch)
		camPitch = maxPitch;
	
	// character movement
	glm::vec3 ux = glm::vec3(glm::rotate(glm::mat4(1), objYaw, glm::vec3(0,1,0)) *glm::vec4(1,0,0,1));
	//no up or down movement are supported
	glm::vec3 uy = glm::vec3(0,1,0); 
	glm::vec3 uz = glm::vec3(glm::rotate(glm::mat4(1), objYaw, glm::vec3(0,1,0)) * glm::vec4(0,0,-1,1));
	 
	Pos -= ux * MOVE_SPEED * r.z * deltaT; //character translate left and right with "Q" and "E"
	Pos += uy * MOVE_SPEED * m.y * deltaT; //character moving up and down with "R" and "F"
	Pos.y = Pos.y * (Pos.y >= 0);		   //character cannot go below the ground
	Pos += uz * MOVE_SPEED * m.z * deltaT; //character moving forward and backward with "W" and "S"

	
	Mw = glm::translate(glm::mat4(1), Pos) *  
		glm::rotate(glm::mat4(1), objYaw, glm::vec3(0,1,0));
		//no other rotation or scaling of the character can be performed


	//computing the view matrix
	static glm::vec3 oldC = glm::vec3(Mw * glm::vec4(
														camDist * cos(camPitch) * sin(camYaw), 
														camHeight + camDist * sin(camPitch),
														camDist * cos(camPitch) * cos(camYaw),
														1)
													);

	glm::vec3 newC =  glm::vec3(Mw * glm::vec4(
												camDist * cos(camPitch) * sin(camYaw), 
												camHeight + camDist * sin(camPitch),
												camDist * cos(camPitch) * cos(camYaw),
												1)
											);

	//computing projection matrixA
	glm::mat4 P = glm::perspective(FOVy, Ar, nearPlane, farPlane);
	P[1][1] *= -1;
	
	//damping the camera movement
	glm::vec3 C = oldC * exp(-dampFac*deltaT) + newC * (1-exp(-dampFac*deltaT));
	oldC = C;

	glm::vec3 to = glm::vec3(Mw*glm::vec4(0,0,0,1)) + glm::vec3(0,camHeight, 0);
	glm::mat4 Mv = glm::lookAt(C, to, glm::vec3(0,1,0));

	ViewPrj = P*Mv;
	World = Mw;	
}