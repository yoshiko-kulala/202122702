#include<stdio.h>

int binary_search_r(int data[], int key, int left, int right) 
{
    if (left > right) {
        return -1;
    }

    int mid = (left + right) / 2;
    
    if (data[mid] == key) {
        return mid;
    }
    
    if (data[mid] > key) {
        return binary_search_r(data, key, left, mid-1);
    } else {
        return binary_search_r(data, key, mid+1, right); 
    }

    return 0;
}

int binary_search(int data[], int key, int left, int right) 
{
    while(1){
        if(left > right)return -1;//再帰と同じ条件
        int mid = (left + right) / 2;//再帰と同じ条件
        if(data[mid] == key)return mid;//再帰と同じ条件
        if (data[mid] > key) {//無ければ再帰と同様にleftかrightを一つずつずらす
            right=mid-1;
        } else {
            left=mid+1; 
        }
    }
    return 0;
}

int main()
{
    int data[] = {1, 3, 5, 7, 8, 9, 10, 12, 15};
    int n = sizeof data / sizeof data[0];
    int key;
    int index;

    printf("key: ");
    scanf("%d", &key);


    //index = binary_search_r(data, key, 0, n-1);
    

    index = binary_search(data, key, 0, n-1);

    if(index >= 0) {
        printf("Index = %d\n",index);
    } else {
        printf("Not found\n");
    }

    return 0;
}