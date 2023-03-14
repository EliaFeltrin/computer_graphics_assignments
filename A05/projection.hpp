

void SetupProjectionMatrices(Assignment05 *A, float Ar) {
/**************
 Method Matrix(int N, glm::mat4 M) of object A,
 receives in N the number of the matrix that needs to be set, and the matrix in M
***************/

	glm::mat4 S;
	float n = 0.1f, f = 50.0;
	
	// Fov-y = 60 deg
	S = glm::perspective(glm::radians(60.0f), Ar, 0.1f, 50.0f);
	A->Matrix(1, S); // sets the matrix corresponding to piece 1

	// Fov-y = 105 deg
	S = glm::perspective(glm::radians(120.0f), Ar, 0.1f, 50.0f);
	A->Matrix(2, S); // sets the matrix corresponding to piece 2

	// Fov-y = 25 deg
	S = glm::perspective(glm::radians(25.0f), Ar, 0.1f, 50.0f);
	A->Matrix(3, S); // sets the matrix corresponding to piece 3

	// Right View, Fov-x = 45 deg
	float comm = n * tan(glm::radians(45.0f)/2),
		  l = 0,
		  r = Ar*2 * comm,
		  b = -comm,
		  t = comm;

	S = glm::frustum(l, r, b, t, n, f);
	A->Matrix(4, S); // sets the matrix corresponding to piece 4

}
