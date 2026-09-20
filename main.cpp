#include <iostream>
#include <vector>
using namespace std;

/*Required implementation
Implement bool isSorted(const std::vector<int>& values). 1/1
Implement bubble sort, selection sort, insertion sort, and quicksort from scratch. 4/4
Verify each algorithm with isSorted after sorting. 1/1
Benchmark all four algorithms on random, already sorted, and reverse-sorted input. 0/3
Use at least three input sizes. Choose sizes large enough to show a meaningful trend without causing unreasonable run time. 0/3
Report a small timing table and explain the observed best, average, and worst behavior. 0/1*/

bool isSorted(const std::vector<int>& values){
	for(int i = 0; i < static_cast<int>(values.size() - 1); i++){
		if(values[i] > values[i + 1]){
			return false;
		}
	}
	return true;
}

//bubble sort
void bubbleSort(vector<int>& nums){
	int temp;
	for(int i = 0; i < static_cast<int>(nums.size() - 1); i++){
		bool swapped = false;
		for(int j = 0; j < static_cast<int>(nums.size() - 1); j++){
			if(nums[j] > nums[j + 1]){
				swapped = true;
				temp = nums[j];
			 nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
		}
		if(!swapped){
			break;
		}
	}
}

//selection sort
void selectionSort(vector<int>& nums){
	int temp;
	for(int i = 0; i < static_cast<int>(nums.size() - 1); i++){
		int smalli = i;
		for(int j = i + 1; j < static_cast<int>(nums.size()); j++){
			if(nums[j] < nums[smalli]){
				smalli = j;
			}
		}
		temp = nums[i];
		nums[i] = nums[smalli];
		nums[smalli] = temp;
	}
}

//insertion sort
void insertionSort(vector<int>& nums){
	for(int i = 1; i < static_cast<int>(nums.size()); i++){
		int temp = nums[i];
		int j = i - 1;
		while(j >= 0 && nums[j] > temp){
			nums[j + 1] = nums[j];
			j--;
		}
		nums[j + 1] = temp;
	}
}

//quicksort
void quickSort(vector<int>& nums, int low, int high){

	if(nums.empty()){
		return;
	}
	if(low >= high){
		return;
	}
	int piv = nums[high];
	int j = low;
	int temp;
	for(int i = low; i < high; i++){
		if(nums[i] < piv){
			temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
			j++;
		}
	}
	nums[high] = nums[j];
	nums[j] = piv;
	quickSort(nums, low, j - 1);
	quickSort(nums, j + 1, high);
}

void printEverything(const vector<int>& nums){
	cout<< " {";
	if(nums.empty()){
		cout<< "}\n";
	}
	else{
		for(int i = 0; i < static_cast<int>(nums.size() - 1); i++){
			cout<< nums[i] << ", ";
		}
		cout<< nums[nums.size() - 1] << "}\n";
	}

	if(isSorted(nums) == 1){
		cout<< "  sorted\n";
	}
	else{
		cout<< "  not sorted\n";
	}
}

int main(){
	vector<vector<int>> nums = {{1,6,2,3,9,8,5,0,4,7},
	{},
	{0},
	{1,2,3,4},
	{5,4,3,2,1}};

	for(int i = 0; i < static_cast<int>(nums.size()); i++){
		vector<int> temp = nums[i];
		cout<< "test case " << i + 1 << endl;
		printEverything(nums[i]);
		cout<< "bubble sorted:\n";
		bubbleSort(temp);
		printEverything(temp);
		temp = nums[i];
		cout<< "selection sorted:\n";
		selectionSort(temp);
		printEverything(temp);
		temp = nums[i];
		cout<< "insertion sorted:\n";
		insertionSort(temp);
		printEverything(temp);
		temp = nums[i];
		cout<< "quick sorted:\n";
		quickSort(temp, 0, temp.size() - 1);
		printEverything(temp);
		cout<< endl;
	}
}