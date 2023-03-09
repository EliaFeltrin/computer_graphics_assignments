//#include <glm/gtx/transform2.hpp>
#include <math.h>

void SetupProjectionMatrices(Assignment04 *A, float Ar) {
/**************
 Method Matrix(int N, glm::mat4 M) of object A,
 receives in N the number of the matrix that needs to be set, and the matrix in M
***************/
	const float PI = 3.14159265359;
	float l = -10, r = -l, t = (r-l)/(2*Ar), b = -t, n = -50, f = 50;
	
	glm::mat4 S,
			  I = glm::mat4(1.0),
			  Port = glm::scale(I, glm::vec3(1, -1, 1)) * glm::ortho(l, r, b, t, n, f);
	
	
	// Isometric projection
	S = Port * glm::rotate(I, glm::radians(36.26f), glm::vec3(1,0,0)) * glm::rotate(I, glm::radians(-45.0f), glm::vec3(0,1,0));
	A->Matrix(1, S); // sets the matrix corresponding to piece 1

	// Dimetric
	S = Port * glm::rotate(I, glm::radians(20.0f), glm::vec3(1,0,0)) * glm::rotate(I, glm::radians(-45.0f), glm::vec3(0,1,0));
	A->Matrix(2, S); // sets the matrix corresponding to piece 2

	// Trimetric
	S = Port * glm::rotate(I, glm::radians(20.0f), glm::vec3(1,0,0)) * glm::rotate(I, glm::radians(-20.0f), glm::vec3(0,1,0));
	A->Matrix(3, S); // sets the matrix corresponding to piece 3

	// Cabinet
	S = Port * shearZ3D(I, (float)(-0.5*cos(PI/4)), (float)(-0.5*sin(PI/4)));
	A->Matrix(4, S); // sets the matrix corresponding to piece 4

}
