#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Mysort {
	public:
	void swap(vector<int> &arr, int a, int b) {
		arr[a] = arr[a]+arr[b];
		arr[b] = arr[a]-arr[b];
		arr[a] = arr[a]-arr[b];
	}
	void selectsort(vector<int> &arr) {
		for (int i = 0; i < arr.size()-1; i++) {
			int min = i;
			int j = i+1;
			for (;j < arr.size(); j++) {
				if (arr[j] < arr[min]) {
					min = j;
				}
			}
			if (min != i)
				swap(arr, i, min);
		}
	}
	void bubblesort(vector<int> &arr) {
		for (int i = arr.size(); i > 0; i--) {
			bool flag = false;
			for (int j = 0; j < i-1; j++) {
				if (arr[j] > arr[j+1]) {
					flag = true;
					swap(arr,j,j+1);
				}
			}
			if (!flag) {
				break;
			}
		}
	}
	void insertsort(vector<int> &arr) {
		for (int i = 1; i < arr.size(); i++) {
			int j = i;
			while (j > 0 && arr[j] < arr[j-1]) {
				swap(arr, j, j-1);
				j--;
			}
		}
	}
	// 插入排序与玩扑克牌时整理手中的牌有异曲同工之处
	void insertsort2(vector<int> &arr) {
		for (int i = 1; i < arr.size(); i++) {
			int key = arr[i];  // 记录当前要插入的数
			int j = i-1;
			while (j >= 0 && arr[j] > key) { // 整个循环为了将当前要插入的数插入到正确的位置
				arr[j+1] = arr[j];  // 每当当前要插入的数比前面已经排序好的数小时，将与之比较的数向后移动一位
				j--;
			}
			arr[j+1] = key;  // 找到当前要插入的数的正确位置，将其放入
		}
	}
	void shellsort(vector<int> &arr) {
		for (int gap = arr.size()/2; gap > 0; gap/=2) {
			for (int i = gap; i < arr.size(); i++) {
				int j = i;
				while (j-gap >= 0 && arr[j] < arr[j-gap]) {
					swap(arr, j, j-gap);
					j = j-gap;
				}
			}
		}
	}

	/*  heapsort */
	void adjustheap(vector<int>&arr, int i, int length) {
		int temp = arr[i];  // current value
		for (int k = 2*i+1; k < length; k = k*2+1) {
			if (k+1 < length && arr[k] < arr[k+1]) {
				k++;   // find the bigger number between left son and right son
			}
			if (temp < arr[k]) {
				arr[i] = arr[k];
				i = k;
			} else {
				break;
			}
			arr[i] = temp;
		}
	}

	void heapsort(vector<int>& arr) {
		// construct big heap
		for (int i = arr.size()/2-1; i >= 0; i--) {
			// begin with the first not leaf node
			adjustheap(arr, i, arr.size());
		}

		// find the bigest number and then swap it and the adjust the heap
		for (int i = arr.size()-1; i > 0; i--) {
			swap(arr, 0, i); // swap the biggest number and the end of the heap
			adjustheap(arr, 0, i); // adjust the heap and now the size of the heap is i
		}
	}
	/*mergesort*/
	void mergesort(vector<int> &arr) {
		// gap是要进行归并的数组的大小，刚开始大小为1，接着为2，直到刚好比要排序的数组小
		for (int gap =1; gap < arr.size(); gap = gap*2) {
			mergepass(arr, gap, arr.size());
		}
	}
	void mergepass(vector<int> &arr, int gap, int length) {
		int i = 0;
		// 两两进行排序并归并
		for (int i = 0; i+2*gap-1 < length; i = i+2*gap) {
			merge(arr, i, i+gap-1, i+2*gap-1);
		}
		// 余下的两个数组大小不相同
		if (i+gap-1 < length) {
			merge(arr, i, i+gap-1, length-1);
		}
	}
	void merge(vector<int> &arr, int low, int mid, int high) {
		int i = low;
		int j = mid+1;
		vector<int> merge_arr;
		while (i <= mid && j <=high) {
			if (arr[i] <= arr[j]) {
				merge_arr.push_back(arr[i]);
				i++;
			} else {
				merge_arr.push_back(arr[j]);
				j++;
			}
		}
		while (i <= mid) {
			merge_arr.push_back(arr[i]);
			i++;
		}
		while (j <= high) {
			merge_arr.push_back(arr[j]);
			j++;
		}
		int k = 0;
		for (int i = low; i <= high; i++) {
			arr[i] = merge_arr[k];
			k++;
		}
	}

};

int main() {
	int n;
	cout << "please input the number of the array" << endl;
	Mysort sort;
	while (cin >> n) {
		vector<int> array;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			array.push_back(num);
		}
		cout << "this is your array!" << endl;
		for (int i = 0; i < n; i++) {
			cout << array[i] << " ";
		}
		cout << endl;
		//sort.heapsort(array);
		//sort.shellsort(array);
		//sort.insertsort2(array);
		//sort.bubblesort(array);
		//sort.selectsort(array);
		sort.mergesort(array);
		cout << "this is your sorted array !" << endl;
		for (int i = 0; i < n; i++) {
			cout << array[i] << " ";
		}
		cout << endl;
		cout << "please input the number of the array" << endl;
	}
}
