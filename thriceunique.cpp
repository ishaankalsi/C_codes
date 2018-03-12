//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
using namespace std;
const int BITS = 32;

int cvtToDec(int bitArr[]){
    int decNum = 0;
    for(int i = 0; i < BITS; ++i){
        decNum += bitArr[i] * (1 << i);
    }
    return decNum;
}


void setArr(int bitArr[], int num){
    //updates bitArr as per binary code of num
    int i = 0;
    while(num){
        if (num & 1){
            bitArr[i]++;
        }
        num >>= 1;
        i++;
    }
}


int findUnique(int arr[], int n){
    int bitArr[BITS] = {};  //initailly all zero

    for(int i = 0; i < n; ++i){
        setArr(bitArr, arr[i]);
    }

    for(int i = 0; i < BITS; ++i){
        bitArr[i] %= 3;
    }

    int ans = cvtToDec(bitArr);
    return ans;
}

int main() {
    int arr[100];
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) cin >> arr[i];

    int x = findUnique(arr, n);
    cout << x;
}