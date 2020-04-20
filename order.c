//
// Created by visionary on 2019-07-31.
//

#include <stdio.h>
void bubble_sort(int arr[], int len) {
    int i, j, temp;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}
//实例
void swap(int *a,int *b) //交換兩個變數w
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
/**
 * 选择排序
 * @param arr
 * @param len
 */
void selection_sort(int arr[], int len)
{
    int i,j;

    for (i = 0 ; i < len - 1 ; i++)
    {
        int min = i;
        for (j = i + 1; j < len; j++)     //走訪未排序的元素
            if (arr[j] < arr[min])    //找到目前最小值
                min = j;    //紀錄最小值
        swap(&arr[min], &arr[i]);    //做交換
    }
}
/**
 * 插入
 * @param arr
 * @param len
 */
void insertion_sort(int arr[], int len){
    int i,j,temp;
    for (i=1;i<len;i++){
        temp = arr[i];
        for (j=i;j>0 && arr[j-1]>temp;j--)
            arr[j] = arr[j-1];
        arr[j] = temp;
    }
}
/**
 * 希尔
 * @param arr
 * @param len
 */
void shell_sort(int arr[], int len) {
    int gap, i, j;
    int temp;
    for (gap = len >> 1; gap > 0; gap = gap >> 1)
        for (i = gap; i < len; i++) {
            temp = arr[i];
            for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
                arr[j + gap] = arr[j];
            arr[j + gap] = temp;
        }
}


// 归并排序
//int min(int x, int y) {
//    return x < y ? x : y;
//}
//void merge_sort(int arr[], int len) {
//    int* a = arr;
//    int* b = (int*) malloc(len * sizeof(int));
//    int seg, start;
//    for (seg = 1; seg < len; seg += seg) {
//        for (start = 0; start < len; start += seg + seg) {
//            int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
//            int k = low;
//            int start1 = low, end1 = mid;
//            int start2 = mid, end2 = high;
//            while (start1 < end1 && start2 < end2)
//                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
//            while (start1 < end1)
//                b[k++] = a[start1++];
//            while (start2 < end2)
//                b[k++] = a[start2++];
//        }
//        int* temp = a;
//        a = b;
//        b = temp;
//    }
//    if (a != arr) {
//        int i;
//        for (i = 0; i < len; i++)
//            b[i] = a[i];
//        b = a;
//    }
//    free(b);
//}


int main() {
    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    int len = (int) sizeof(arr) / sizeof(*arr);
    bubble_sort(arr, len);
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    return 0;
}
