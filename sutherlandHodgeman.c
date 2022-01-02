#include <stdio.h>

typedef struct{
	float x, y;
}vec2_t;

typedef struct{
	vec2_t normal;
	float distance;
}plane_t;


vec2_t clip_edge(vec2_t *v0, float dv0, vec2_t *v1, float dv1)
{	
	float s = dv0 / (dv0 - dv1);
	
	//scale vertex and properties
	vec2_t v;
	v.x = v0->x + s * (v1->x - v0->x);
	v.y = v0->y + s * (v1->y - v0->y);
	
	return v;
}

#define MAX 10
//sutherland hodgeman like clipping algorithm

int clip_plane(vec2_t *input, int vertCount, plane_t *p)
{
	
	//start and end point of a line
	vec2_t *start;
	vec2_t *end;
	
	//memory for saving clipped polygon vertices
	int stack_pos = 0;
	vec2_t stack[MAX];
	
	start = &input[vertCount - 1];
	end = &input[0];
	
	//seperate polygon into lines
	int i;
	for(i = 0; i < vertCount; ++i)
	{
		
		//get distances to determine position relative to plane
		//distance > 0		-> inside
		//distance = 0		-> on the plane
		//distance < 0		-> outside the plane
		float dstart = start->x * p->normal.x + start->y * p->normal.y - p->distance;
		float dend = end->x * p->normal.x + end->y * p->normal.y - p->distance;
		
		
		if(dstart > 0)	//start inside
		{
			stack[stack_pos++] = *start;
			if(dend < 0)
			{
				stack[stack_pos++] = clip_edge(start, dstart, end, dend);
			}
		}else if(dend > 0)
		{
			stack[stack_pos++] = clip_edge(start, dstart, end, dend);
		}
		
		//next line
		start = &input[i];
		end = &input[i + 1];
	}
	
	//stack_pos now contains number of vertices
	
	//write clipped verts back into input array
	for(i = 0; i < stack_pos; ++i)
	{
		input[i] = stack[i];
	}
	
	return stack_pos;
}

int main(){
	plane_t p = {{0, 1}, 0};
	
	vec2_t triangle[MAX] = {
		{1, 1},
		{0, -1},
		{-1, 1}
	};
	
	int ret = clip_plane(triangle, 3, &p);
	
	printf("verts: %d\n", ret);
	
	int i;
	for(i = 0; i < ret; ++i){
		printf("%f %f\n", triangle[i].x, triangle[i].y);
	}
	
	return 0;
}
