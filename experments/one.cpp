#include <iostream>

using namespace std;

void swap(int *a, int *b);
void childSets(char *aSet, bool *fgs, int n, int len) ;
void allSort(int *nums, int n, int len) ;

void testAllSort() {
    int n = 0;
    while (true) {
        cout << "请输入您想要得到全排列的序列的长度(正整数) ： ";
        cin >> n;

        if (n <= 0)
            cout << "长度应该为大于零的整数，您输入的是 ： " << n << "，请重新输入！" << endl;
        else
            break;
    }

    int nums[n];
    for (int i = 0; i < n; ++i) {
        cout << "请输入第" << i+1 << "个整数 ： ";
        cin >> nums[i];
    }

    cout << "结果是 ： " << endl;
    allSort(nums, 0, n);
}

void testChild() {
    int n = 0;
    while (true) {
        cout << "请输入您想要得到全部子集的序列的长度(正整数) ： ";
        cin >> n;

        if (n <= 0)
            cout << "长度应该为大于零的整数，您输入的是 ： " << n << "，请重新输入！" << endl;
        else
            break;
    }

    char arr[n];
    for (int i = 0; i < n; ++i) {
        cout << "请输入第" << i+1 << "个字符 ： ";
        cin >> arr[i];
    }

    cout << "结果是(空集用空行表示,注意！结果最后有一空行,并非集合的空子集) ： " << endl;
    childSets(arr, new bool[n], 0, n);
}

void allSort(int *nums, int n, int len) {
    if (n == len) {
        for (int i = 0; i < len-1; ++i) {
            cout << nums[i] << ",";
        }
        cout << nums[len-1] << endl;
    }

    for (int i = n; i < len; ++i) {
        swap(&nums[i], &nums[n]);
        allSort(nums, n+1, len);
        swap(&nums[i], &nums[n]);
    }
}

void childSets(char *aSet, bool *fgs, int n, int len) {
    if (n+1 == len) {
        fgs[len-1] = false;
        for (int i = 0; i<len-1; i++)
            if(fgs[i]) 
                cout << aSet[i] << " ";
        cout << endl;
        
        fgs[len-1] = true;
        for (int i = 0; i<len-1; i++) 
            if (fgs[i])
                cout << aSet[i] << " ";
        cout << aSet[len-1] << endl;
        
        return;
    }
    
    fgs[n] = true;
    childSets(aSet, fgs, n+1, len);
    fgs[n] = false;
    childSets(aSet, fgs, n+1, len);
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}