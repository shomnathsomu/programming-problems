/**____________________________________________________ |
|                                                       |
|            Email:shomnathcse22@gmail.com              |
|    Codeforces == L1nK1n_ && Topcoder == L1nK1n        |
|_____________________________________________________**/
//#pragma warning (disable: 4786)
//#pragma comment (linker, "/STACK:16777216")

/**
Square Root Decomposition
**/

#include <bits/stdc++.h>
using namespace std;

int segment[10000];

void preprocessing(int input[], int n, int segment_size) {
    int current_segment=-1;

    for(int i=0; i<n; i++) {
        if(i%segment_size == 0) current_segment++;
        segment[current_segment] += input[i];
    }
    return;
}

int query(int input[], int segment_size, int l, int r) {
    int sum=0;

    while(l<r && l%segment_size != 0){
        sum += input[l];
        l++;
    }

    while(l+segment_size<=r) {
        sum += segment[l/segment_size];
        l += segment_size;
    }

    while(l<=r) {
        sum += input[l];
        l++;
    }

    return sum;
}

void update(int input[], int segment_size, int i, int val) {
    int segment_no = i/segment_size;

    segment[segment_no] -= input[i];
    segment[segment_no] += val;

    input[i] = val;
    return;
}

int main(int argc, const char *argv[]) {

    int cs, n, input[100000];
    scanf("%d", &cs);

    for(int ii=1; ii<cs+1; ii++){

        scanf("%d", &n);
        int segment_size = sqrt(n);
        memset(input, 0, sizeof(input));

        for(int j=0; j<n; j++) scanf("%d", &input[j]);
        preprocessing(input, n, segment_size);

        cout << query(input, segment_size, 0, 9) << endl;
        update(input, segment_size, 9, 0);
        cout << query(input, segment_size, 0, 9) << endl;
    }

}


/*

Output:
55
45

*/
