#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

/*Required implementation
Implement bool isSorted(const std::vector<int>& values). 1/1
Implement bubble sort, selection sort, insertion sort, and quicksort from scratch. 4/4
Verify each algorithm with isSorted after sorting. 1/1
Benchmark all four algorithms on random, already sorted, and reverse-sorted input. 3/3
Use at least three input sizes. Choose sizes large enough to show a meaningful trend without causing unreasonable run time. 3/3
Report a small timing table and explain the observed best, average, and worst behavior. 1/1*/

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
	for(int i = 0; i < static_cast<int>(nums.size() - 1); i++){
		//bool swapped = false;
		for(int j = 0; j < static_cast<int>(nums.size() - 1); j++){
			if(nums[j] > nums[j + 1]){
				//swapped = true;
				int temp = nums[j];
			 nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
		}
		/*if(!swapped){
			break;
		}*/
	}
}

//selection sort
void selectionSort(vector<int>& nums){
	for(int i = 0; i < static_cast<int>(nums.size() - 1); i++){
		int smalli = i;
		for(int j = i + 1; j < static_cast<int>(nums.size()); j++){
			if(nums[j] < nums[smalli]){
				smalli = j;
			}
		}
		int temp = nums[i];
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
	for(int i = low; i < high; i++){
		if(nums[i] < piv){
			int temp = nums[i];
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

//generate random vector
vector<int> randNums(int n){
	vector<int> randNums;
	for(int i = 0; i < n; i++){
		int randN = rand() % n;
		randNums.push_back(randN);
	}
	return randNums;
}

//generate sorted vector
vector<int> sortedNums(int n){
	vector<int> sortedNums;
	for(int i = 0; i < n; i++){
		sortedNums.push_back(i);
	}
	return sortedNums;
}

//generate reverse sorted vector
vector<int> reverseSortedNums(int n){
	vector<int> reverseSortedNums;
	for(int i = 0; i < n; i++) {
		reverseSortedNums.push_back(n - 1 - i);
	}
	return reverseSortedNums;
}

//calculate avg of two bubbleSort runtimes
long long bubbleTime(vector<int> nums){
	vector<int> temp = nums;
	auto start = chrono::high_resolution_clock::now();
	bubbleSort(temp);
	auto time = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start).count();
	temp = nums;
	start = chrono::high_resolution_clock::now();
	bubbleSort(temp);
	auto time2 = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start).count();
	return (time + time2)/2;
}

//calculate avg of two selectionSort runtimes
long long selectionTime(vector<int> nums){
	vector<int> temp = nums;
	auto start = chrono::high_resolution_clock::now();
	selectionSort(temp);
	auto time = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start).count();
	temp = nums;
	start = chrono::high_resolution_clock::now();
	selectionSort(temp);
	auto time2 = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start).count();
	return (time + time2)/2;
}

//calculate avg of two insertionSort runtimes
long long insertionTime(vector<int> nums){
	vector<int> temp = nums;
	auto start = chrono::high_resolution_clock::now();
	insertionSort(temp);
	auto time = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start).count();
	temp = nums;
	start = chrono::high_resolution_clock::now();
	insertionSort(temp);
	auto time2 = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start).count();
	return (time + time2)/2;
}

//calculate avg of two quickSort runtimes
long long quickTime(vector<int> nums){
	vector<int> temp = nums;
	auto start = chrono::high_resolution_clock::now();
	quickSort(temp, 0, temp.size() - 1);
	auto time = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start).count();
	temp = nums;
	start = chrono::high_resolution_clock::now();
	quickSort(temp, 0, temp.size() - 1);
	auto time2 = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start).count();
	return (time + time2)/2;
}

int main() {
	vector<int> nums = randNums(5000);
	vector<int> test = nums;
	bubbleSort(test);
	if(isSorted(test)){
		cout<< "bubble sort(works)\n random vector\n  ";
		for(int i = 5000; i < 20001; i *= 2) {
			cout<< i << " elements: " << bubbleTime(randNums(i)) << " microseconds\n  ";
		}
		cout<< "\bsorted vector\n  ";
		for(int i = 5000; i < 20001; i *= 2) {
			cout<< i << " elements: " << bubbleTime(sortedNums(i)) << " microseconds\n  ";
		}
		cout<< "\breverse sorted vector\n  ";
		for(int i = 5000; i < 20001; i *= 2) {
			cout<< i << " elements: " << bubbleTime(reverseSortedNums(i)) << " microseconds\n  ";
		}
	}

	test = nums;
	selectionSort(test);
	if(isSorted(test)){
		cout<< "\nselection sort(works)\n random vector\n  ";
		for(int i = 5000; i < 20001; i *= 2) {
			cout<< i << " elements: " << selectionTime(randNums(i)) << " microseconds\n  ";
		}
		cout<< "\bsorted vector\n  ";
		for(int i = 5000; i < 20001; i *= 2) {
			cout<< i << " elements: " << selectionTime(sortedNums(i)) << " microseconds\n  ";
		}
		cout<< "\breverse sorted vector\n  ";
		for(int i = 5000; i < 20001; i *= 2) {
			cout<< i << " elements: " << selectionTime(reverseSortedNums(i)) << " microseconds\n  ";
		}
	}

	test = nums;
	insertionSort(test);
	if(isSorted(test)){
		cout<< "\ninsertion sort(works)\n random vector\n  ";
		for(int i = 5000; i < 20001; i *= 2) {
			cout<< i << " elements: " << insertionTime(randNums(i)) << " microseconds\n  ";
		}
		cout<< "\bsorted vector\n  ";
		for(int i = 5000; i < 20001; i *= 2) {
			cout<< i << " elements: " << insertionTime(sortedNums(i)) << " microseconds\n  ";
		}
		cout<< "\breverse sorted vector\n  ";
		for(int i = 5000; i < 20001; i *= 2) {
			cout<< i << " elements: " << insertionTime(reverseSortedNums(i)) << " microseconds\n  ";
		}
	}

	test = nums;
	quickSort(test, 0 , nums.size() - 1);
	if(isSorted(test)){
		cout<< "\nquick sort(works)\n random vector\n  ";
		for(int i = 5000; i < 20001; i *= 2) {
			cout<< i << " elements: " << quickTime(randNums(i)) << " microseconds\n  ";
		}
		cout<< "\bsorted vector\n  ";
		for(int i = 5000; i < 20001; i *= 2) {
			cout<< i << " elements: " << quickTime(sortedNums(i)) << " microseconds\n  ";
		}
		cout<< "\breverse sorted vector\n  ";
		for(int i = 5000; i < 20001; i *= 2) {
			cout<< i << " elements: " << quickTime(reverseSortedNums(i)) << " microseconds\n  ";
		}
	}
}