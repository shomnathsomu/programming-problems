/**____________________________________________________ |
|                                                       |
|            email:shomnathcse22@gmail.com              |
|    Codeforces == L1nK1n_ && Topcoder == L1nK1n        |
|_____________________________________________________**/

/**
Square Root Decomposition
**/

int segment[10000];
int input[100007], segment_size;

int preprocessing(int input[], int n) {
    int current_segment=-1;
    segment_size=sqrt(n);

    for(int i=0; i<n; i++) {
        if(i%segment_size == 0) current_segment++;
        segment[current_segment] += input[i];
    }

    return segment_size;
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
}
