class Solution {
public:

void merge(vector<int>& nums, int s, int e) {
	int mid = (s+e)/2;

	int lenLeft = mid - s + 1;
	int lenRight = e - mid;

	//create left and right array
	int *left = new int[lenLeft];
	int *right = new int[lenRight];

	//copy values from original array to left array
	int k = s;
	//k -> starting index of left array values in original arrya
	for(int i=0; i<lenLeft; i++) {
		left[i] = nums[k];
		k++;
	}

	//copy values from original array to right array
	k = mid+1;
	for(int i=0; i<lenRight; i++) {
		right[i] = nums[k];
		k++;
	}

	//actual merge logic here

	//left array is already sorted
	//right array is already sorted
	int leftIndex = 0;
	int rightIndex = 0;

	//key point
	int mainArrayIndex = s;

	while(leftIndex < lenLeft &&  rightIndex < lenRight) {
		
		if(left[leftIndex] < right[rightIndex] ) {
			nums[mainArrayIndex] =  left[leftIndex];
			mainArrayIndex++;
			leftIndex++;
		}
		else {
			nums[mainArrayIndex] =  right[rightIndex];
			mainArrayIndex++;
			rightIndex++;
		}
	}


	//2 more cases

	//1 case -> left array exhaust but right array me element abhi bhi bache hai
	while(rightIndex < lenRight) {
		nums[mainArrayIndex] =  right[rightIndex];
		mainArrayIndex++;
		rightIndex++;
	}
	//2nd case -> rigght array exhaust but left array me element abhi bhi bache hai
	while(leftIndex < lenLeft) {
		nums[mainArrayIndex] =  left[leftIndex];
		mainArrayIndex++;
		leftIndex++;
	}
	//1 more step pending
	delete[] left;
	delete[] right;
}

int countPairs(vector<int> &nums, int low, int mid, int high) {
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++) {
        while (right <= high &&(long long)nums[i] > 2 * (long long)nums[right]) right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}

int mergeSort(vector<int>& nums, int s, int e) {
        int cnt = 0;
    // Base case
    if (s >= e) {
        return cnt;
    }

    // Break
    int mid = (s + e) / 2;
    // Recursive call for left vector
        cnt += mergeSort(nums, s, mid);
    // Recursive call for right vector
        cnt += mergeSort(nums, mid + 1, e);
// for counting pair , inversion count technique
    cnt += countPairs(nums, s, mid,e); //Modification
    // Merge 2 sorted vectors
    merge(nums, s, e);
        return cnt;
}

    int reversePairs(vector<int>& nums) {
            int size = nums.size();
    int s = 0;
    int e = size - 1;
        return  mergeSort(nums, s, e);  
    }
};