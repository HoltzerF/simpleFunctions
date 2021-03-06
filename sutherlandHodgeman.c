#include <stdio.h>
#define MAX 9

// basic structs and functions

typedef struct{
	float x, y;
}vec2_t;

typedef struct{
	vec2_t normal;
	float distance;
}plane_t;

float dist(vec2_t *v, plane_t *p){
	return v->x * p->normal.x + v->y * p->normal.y - p->distance;
}

// lerp a vector
vec2_t clip_edge(vec2_t *v0, float dv0, vec2_t *v1, float dv1){
	float s = dv0 / (dv0 - dv1);
	
	// scale vertex and properties
	vec2_t v;
	v.x = v0->x + s * (v1->x - v0->x);
	v.y = v0->y + s * (v1->y - v0->y);
	
	return v;
}

// clipping a polygon with respect to a plane
int clipPolyPlane(vec2_t *verts, int vertCount, plane_t *p){
	
	// start and end point of a line
	vec2_t *start;
	vec2_t *end;
	
	// memory for saving clipped polygon vertices
	int stack_pos = 0;
	vec2_t stack[MAX];
	
	start = &verts[vertCount - 1];
	end = &verts[0];
	
	// seperate polygon into edges
	int i;
	for(i = 0; i < vertCount; ++i){
		
		// get distances to determine position relative to plane
		// distance >= 0		-> inside / on the plane
		// distance < 0		-> outside the plane
		float dstart = dist(start, p);
		float dend = dist(end, p);
		
		if(dstart >= 0){	// start inside
			stack[stack_pos++] = *start;
			if(dend < 0)
				stack[stack_pos++] = clip_edge(start, dstart, end, dend);
		}else if(dend > 0)
			stack[stack_pos++] = clip_edge(start, dstart, end, dend);
		
		// next edge
		start = &verts[i];
		end = &verts[i + 1];
	}
	
	// stack_pos now contains number of vertices
	
	// write clipped verts from stack back into input array
	for(i = 0; i < stack_pos; ++i)
		verts[i] = stack[i];
	
	return stack_pos;
}

int suHo(vec2_t *verts, int vertCount, plane_t *planes, int planeCount){
	
	// clipping a polygon to a number of planes
	int i;
	for(i = 0; i < planeCount; ++i)
		vertCount = clipPolyPlane(verts, vertCount, &planes[i]);
	
	return vertCount;
}

int main(){
	
	plane_t planes[3] = {
		{{0, 1}, -2},
		{{-1, 0}, -1},
		{{0, -1}, -1}
	};
	
	vec2_t poly[MAX] = {
		{0, 2},
		{2, -2},
		{-2, -2}
	};
	
	int vertCount = suHo(poly, 3, planes, 3);
	
	int i;
	for(i = 0; i < vertCount; ++i)
		printf("%f %f\n", poly[i].x, poly[i].y);
	
	return 0;
}
