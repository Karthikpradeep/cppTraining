#include <twoHeader.h>

TwoPointer::TwoPointer(){
	left = 0;
	right = 0;
	maxWater = 0;
}
TwoPointer::~TwoPointer(){
}

void TwoPointer::addHeight(int val){
	height.push_back(val);
}


int TwoPointer::mostWater(){
	right = height.size() - 1;
	while(left<right){
		minHeight = min(height[left],height[right]);
		maxWater = max(maxWater,(right - left) * minHeight);
		if(height[left]<height[right]){
			left++;
		}
		else{
			right--;
		}

	}
	return maxWater;
}
