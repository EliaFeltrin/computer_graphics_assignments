void Assignment14::createCubeMesh(std::vector<Vertex> &vDef, std::vector<uint32_t> &vIdx) {
	// The procedure fills array vPos with the positions of the vertices and of the normal vectors of the mesh
/*	vDef.push_back({{0.0f, 0.0f, 0.1f}, {0.5f, 0.0f, 0.866f}});	// vertex 0 - Position and Normal
	vDef.push_back({{1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}});	// vertex 1 - Position and Normal
	vDef.push_back({{0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}});	// vertex 2 - Position and Normal
	vDef.push_back({{1.0f, 1.0f, 0.1f}, {-0.5f, 0.0f, 0.866f}});// vertex 3 - Position and Normal

	// The procedures also fill the array vIdx with the indices of the vertices of the triangles
	vIdx.push_back(0); vIdx.push_back(1); vIdx.push_back(2);	// First triangle
	vIdx.push_back(1); vIdx.push_back(2); vIdx.push_back(3);	// Second triangle
	
	// The primitive built here is a cube centered in the origin, whose edge lenght is 2.
*/	

	int tmp = 0;

	vDef.push_back({{-1.0f, +1.0f, +1.0f}, {-1.0f, 0.0f, 0.0f}});	// vertex 0 - Position and Normal
	vDef.push_back({{-1.0f, +1.0f, -1.0f}, {-1.0f, 0.0f, 0.0f}});	// vertex 1 - Position and Normal
	vDef.push_back({{-1.0f, -1.0f, +1.0f}, {-1.0f, 0.0f, 0.0f}});	// vertex 2 - Position and Normal
	vDef.push_back({{-1.0f, -1.0f, -1.0f}, {-1.0f, 0.0f, 0.0f}});	// vertex 3 - Position and Normal
	vIdx.push_back(tmp); vIdx.push_back(tmp+1); vIdx.push_back(tmp+2);		// First triangle
	vIdx.push_back(tmp+1); vIdx.push_back(tmp+2); vIdx.push_back(tmp+3);	// Second triangle
	tmp += 4;

	vDef.push_back({{+1.0, +1.0f, +1.0f}, {+1, 0.0f, 0.0f}});	// vertex 0 - Position and Normal
	vDef.push_back({{+1.0, +1.0f, -1.0f}, {+1, 0.0f, 0.0f}});	// vertex 1 - Position and Normal
	vDef.push_back({{+1.0, -1.0f, +1.0f}, {+1, 0.0f, 0.0f}});	// vertex 2 - Position and Normal
	vDef.push_back({{+1.0, -1.0f, -1.0f}, {+1, 0.0f, 0.0f}});	// vertex 3 - Position and Normal
	vIdx.push_back(tmp); vIdx.push_back(tmp+1); vIdx.push_back(tmp+2);		// First triangle
	vIdx.push_back(tmp+1); vIdx.push_back(tmp+2); vIdx.push_back(tmp+3);	// Second triangle
	tmp += 4;

	vDef.push_back({{+1.0f, -1.0f, +1.0f}, {0.0f, -1.0f, 0.0f}});	// vertex 0 - Position and Normal
	vDef.push_back({{+1.0f, -1.0f, -1.0f}, {0.0f, -1.0f, 0.0f}});	// vertex 1 - Position and Normal
	vDef.push_back({{-1.0f, -1.0f, +1.0f}, {0.0f, -1.0f, 0.0f}});	// vertex 2 - Position and Normal
	vDef.push_back({{-1.0f, -1.0f, -1.0f}, {0.0f, -1.0f, 0.0f}});	// vertex 3 - Position and Normal
	vIdx.push_back(tmp); vIdx.push_back(tmp+1); vIdx.push_back(tmp+2);		// First triangle
	vIdx.push_back(tmp+1); vIdx.push_back(tmp+2); vIdx.push_back(tmp+3);	// Second triangle
	tmp += 4;

	vDef.push_back({{+1.0f, +1.0f, +1.0f}, {0.0f, +1.0f, 0.0f}});	// vertex 0 - Position and Normal
	vDef.push_back({{+1.0f, +1.0f, -1.0f}, {0.0f, +1.0f, 0.0f}});	// vertex 1 - Position and Normal
	vDef.push_back({{-1.0f, +1.0f, +1.0f}, {0.0f, +1.0f, 0.0f}});	// vertex 2 - Position and Normal
	vDef.push_back({{-1.0f, +1.0f, -1.0f}, {0.0f, +1.0f, 0.0f}});	// vertex 3 - Position and Normal
	vIdx.push_back(tmp); vIdx.push_back(tmp+1); vIdx.push_back(tmp+2);		// First triangle
	vIdx.push_back(tmp+1); vIdx.push_back(tmp+2); vIdx.push_back(tmp+3);	// Second triangle
	tmp += 4;

	vDef.push_back({{+1.0f, +1.0f, -1.0f}, {0.0f, 0.0f, -1.0f}});	// vertex 0 - Position and Normal
	vDef.push_back({{+1.0f, -1.0f, -1.0f}, {0.0f, 0.0f, -1.0f}});	// vertex 1 - Position and Normal
	vDef.push_back({{-1.0f, +1.0f, -1.0f}, {0.0f, 0.0f, -1.0f}});	// vertex 2 - Position and Normal
	vDef.push_back({{-1.0f, -1.0f, -1.0f}, {0.0f, 0.0f, -1.0f}});	// vertex 3 - Position and Normal
	vIdx.push_back(tmp); vIdx.push_back(tmp+1); vIdx.push_back(tmp+2);		// First triangle
	vIdx.push_back(tmp+1); vIdx.push_back(tmp+2); vIdx.push_back(tmp+3);	// Second triangle
	tmp += 4;

	vDef.push_back({{+1.0f, +1.0f, +1.0f}, {0.0f, 0.0f, +1.0f}});	// vertex 0 - Position and Normal
	vDef.push_back({{+1.0f, -1.0f, +1.0f}, {0.0f, 0.0f, +1.0f}});	// vertex 1 - Position and Normal
	vDef.push_back({{-1.0f, +1.0f, +1.0f}, {0.0f, 0.0f, +1.0f}});	// vertex 2 - Position and Normal
	vDef.push_back({{-1.0f, -1.0f, +1.0f}, {0.0f, 0.0f, +1.0f}});	// vertex 3 - Position and Normal
	vIdx.push_back(tmp); vIdx.push_back(tmp+1); vIdx.push_back(tmp+2);		// First triangle
	vIdx.push_back(tmp+1); vIdx.push_back(tmp+2); vIdx.push_back(tmp+3);	// Second triangle
}

void Assignment14::createFunctionMesh(std::vector<Vertex> &vDef, std::vector<uint32_t> &vIdx) {
	// The procedure fills array vPos with the positions of the vertices and of the normal vectors of the mesh
	// The procedures also fill the array vIdx with the indices of the vertices of the triangles
	// The primitive built here is the surface y = sin(x) * cos(z) with -3 <= x <= 3 and -3 <= z <= 3.
	

	// Fill array vPos with the positions of the vertices of the mesh
	float norm_x, norm_y = 1.0f, norm_z, norm_len;
	for(float x=-3.0f; x<=3.0f; x+=0.1f) {
		for(float z=-3.0f; z<=3.0f; z+=0.1f) {
			norm_x = cos(x)*cos(z);
			norm_z = -sin(x)*sin(z);
			norm_len = sqrt(norm_x*norm_x + norm_y+ norm_z*norm_z);
			norm_x /= norm_len;
			norm_y /= norm_len;
			norm_z /= norm_len;
			vDef.push_back({{x, sin(x)*cos(z), z}, {norm_x, norm_y, norm_z}});	
		}
	}

	std::vector<float> sas;
	// Fill the array vIdx with the indices of the vertices of the triangles
	for(int i=0; i<3600; i+=61){
		for(int j=0; j<60; j++){
			vIdx.push_back(i+j);
			vIdx.push_back(i+j+1);
			vIdx.push_back(i+j+61);

			vIdx.push_back(i+j+1);
			vIdx.push_back(i+j+61);
			vIdx.push_back(i+j+62);
		}
	}

}

void Assignment14::createCylinderMesh(std::vector<Vertex> &vDef, std::vector<uint32_t> &vIdx) {
	// The procedure fills array vPos with the positions of the vertices and of the normal vectors of the mesh
	// The procedures also fill the array vIdx with the indices of the vertices of the triangles
	// The primitive built here is a cylinder, with radius 1, and height 2, centered in the origin.
	
	const int steps = 50;

	// Fill array vPos with the positions of the vertices of the mesh of the top
	vDef.push_back({{0.0f, 1.0f, 0.0f}, {0.0f, 1.0f, 0.0f}});		

	for(float i=0; i<2*glm::pi<float>(); i+=2*glm::pi<float>()/steps){
		vDef.push_back({{cos(i), 1.0f, sin(i)}, 
						{0.0f, 1.0f, 0.0f}});	
	}

	// Fill the array vIdx with the indices of the vertices of the triangles of the top
	for(int i=0; i<steps; i++){
		vIdx.push_back(0);
		vIdx.push_back(i+1);
		vIdx.push_back(i+2);
	}
	vIdx.push_back(0);
	vIdx.push_back(steps);
	vIdx.push_back(1);


	//same for the bottom
	int offset = vDef.size();

	vDef.push_back({{0.0f, -1.0f, 0.0f}, {0.0f, -1.0f, 0.0f}});		

	for(float i=0; i<2*glm::pi<float>(); i+=2*glm::pi<float>()/steps){
		vDef.push_back({{cos(i), -1.0f, sin(i)}, 
						{0.0f, -1.0f, 0.0f}});	
	}

	for(int i=0; i<steps; i++){
		vIdx.push_back(offset);
		vIdx.push_back(i+1+offset);
		vIdx.push_back(i+2+offset);
	}
	vIdx.push_back(offset);
	vIdx.push_back(offset+steps);
	vIdx.push_back(offset+1);

	//you cannot use the same vertex of the top and the bottom for the side, 'cause they have different normals

	offset = vDef.size();
	for(float i=0; i<2*glm::pi<float>(); i+=2*glm::pi<float>()/steps){
		vDef.push_back({{cos(i), 1.0f, sin(i)}, 
						{cos(i), 0.0f, sin(i)}});	

		vDef.push_back({{cos(i), -1.0f, sin(i)}, 
						{cos(i), 0.0f, sin(i)}});	
	}

	for(int i=0; i<steps-1; i++){
		vIdx.push_back(2*i+offset);
		vIdx.push_back(2*i+1+offset);
		vIdx.push_back(2*i+2+offset);

		vIdx.push_back(2*i+1+offset);
		vIdx.push_back(2*i+2+offset);
		vIdx.push_back(2*i+3+offset);
	}
	vIdx.push_back(vDef.size()-2);
	vIdx.push_back(vDef.size()-1);
	vIdx.push_back(offset);

	vIdx.push_back(vDef.size()-1);
	vIdx.push_back(offset);
	vIdx.push_back(offset+1);
}

