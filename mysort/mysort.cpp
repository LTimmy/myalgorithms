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
		sort.insertsort(array);
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
