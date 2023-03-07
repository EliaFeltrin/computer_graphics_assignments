float sq(float sq) {
	return -1 + 0.1*sq;
}

void SetupTriangles(Assignment01 *A) {
/**************
 Function Triangle(float x1, float y1, float x2, float y2, float x3, float y3, float r, float g, float b)

 draws a triangle connecting points (x1,y1)  (x2, y2) and (x3, y3), colored with the (r,g,b) specified color.
 vertex are expressed in Normalized screen coordinates, (i.e. in range [-1,+1]), following the Vulkan convention.
 The red, green and blue (r,g,b) values are in the range [0,1].
 
 Using function Triangle(...) try to draw a children house, similar to the one below.
 
 First remove the two function below (given only as an example), and replace them with your own.
 Since it is a C program, you can use for loops if you think it can be helpful in your drawing.
 The for() command below that draws a sun like shape in exact center of the screen near the top,
 is an example on how you can use it: please remove it, and replace it with your own code.
 It is not necessery to use a for loop if you do not really need it: it has been put here only as
 an example to help students not familiar with C++.
***************/

	//A->Triangle(-1,-1, 0,0, -1,1,   1,0,0);	// Draws a red triangle pointing right
	//A->Triangle(1,-1, 0,0, 1,1,   0,1,0);	// Draws a green triangle pointing left
	A->Triangle(sq(11), sq(1), sq(11), sq(6), sq(13), sq(3), 1, 0, 0);
	A->Triangle(sq(15), sq(1), sq(15), sq(6), sq(13), sq(3), 0, 1, 0);
	A->Triangle(sq(15), sq(6), sq(13), sq(3), sq(11), sq(6), 0, 0, 1);
	A->Triangle(sq(11), sq(6), sq(15), sq(6), sq(13), sq(9), 0, 0, 1);
	A->Triangle(sq(11), sq(6), sq(11), sq(16), sq(7), sq(11), 1, 1, 0);
	A->Triangle(sq(11), sq(6), sq(11), sq(13), sq(14), sq(10), 0, 1, 1);
	A->Triangle(sq(7), sq(11), sq(7), sq(18), sq(13), sq(18), 0.5, 0.5, 0);
	A->Triangle(sq(7), sq(18), sq(4), sq(18), sq(5.5), sq(16), 0, 0.5, 0.5);
	A->Triangle(sq(4), sq(18), sq(2.5), sq(16), sq(5.5), sq(16), 0, 0.5, 0.5);



}
