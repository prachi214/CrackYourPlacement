bool canJump(int* nums, int numssize)
{
	int maxIndex=0;
	for(int i= 0;i<numssize;i++){
		// when maxIndex ele is 0, means cann't jump ahead
		if(i>maxIndex) return false;
		// can reach till this index
		maxIndex = max(maxIndex, i+arr[i]);
		if(maxIndex >=numssize -1)return true;
	}
	return true;
}