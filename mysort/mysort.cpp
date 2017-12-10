#include <iostream>
#include <vector>
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
		sort.heapsort(array);
		//sort.shellsort(array);
		//sort.insertsort(array);
		//sort.bubblesort(array);
		//sort.selectsort(array);
		cout << "this is your sorted array !" << endl;
		for (int i = 0; i < n; i++) {
			cout << array[i] << " ";
		}
		cout << endl;
		cout << "please input the number of the array" << endl;
	}
}
