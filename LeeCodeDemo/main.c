//
//  main.c
//  LeeCodeDemo
//
//  Created by Laibu tech_2 on 2020/5/12.
//  Copyright © 2020 Laibu tech_2. All rights reserved.
//

#include <stdio.h>

//#include <vector>
#define max(a, b)    (((a) > (b)) ? (a) : (b))
#define min(a, b)    (((a) < (b)) ? (a) : (b))

#define INT_MIN (-2147483647 - 1)

#define INT_MAX 2147483647

double findMedianSortedArrays(int nums1[], int nums2[], int nums1Size, int nums2Size) {
    if (nums1Size > nums2Size) {
        // 始终保证nums1为短的那个
        return findMedianSortedArrays(nums2, nums1, nums2Size, nums1Size);
    }
    
    int n = nums1Size;
    int m = nums2Size;
    
    // ci为第 i个数组的割.
    // LMaxi 为第i个数字割后的左元素。
    // RMini 为第i个数组割后的右元素。
    int LMax1, LMax2, RMin1, RMin2, c1, c2, lo = 0, hi = 2 * n;
    
    while (lo <= hi) { // 二分法
        c1 = (lo + hi) / 2;
        c2 = m + n - c1;
        LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
        RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
        LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
        RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];
        if (LMax1 <= RMin2 && LMax2 <= RMin1) {
            break;
        }
        
        if (LMax1 > RMin2) { // c1 向左割
            hi = c1 - 1;
        } else if (LMax2 > RMin1) { // c1 向右割
            lo = c1 + 1;
        }
    }
    float result = (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
    printf("%f", result);
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int nums1[] = {1, 2, 3, 4, 7, 8, 9};
    int nums2[] = {1, 2, 3, 4, 7};
    
    int m = sizeof(nums1) / sizeof(int);
    int n = sizeof(nums2) / sizeof(int);
//    printf("%d ___ %d", m, n);
    double result = findMedianSortedArrays(nums1, nums2, m, n);
    
    printf("\n");
    printf("%f", result);
    printf("\n");
    return 0;
}
