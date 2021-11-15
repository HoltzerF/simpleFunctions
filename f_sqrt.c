
//square root using newton method
float f_sqrt(float a){
	
	if(a < 0.0){
		return -1.0;
	}
	
	float start = a;
	float x = 0;
	
	while(a){
		x = start - (start * start - a) / (2.0 * start);
		
		//deviation very small
		if(start <= x)
			break;
		
		start = x;
	}
	
	return x;
}
