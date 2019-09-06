#include<bits/stdc++.h>
using namespace std;

int main()
{
    int pos=0, len=0, lineSize;
    string s, w, ans="";
    vector<string> v, res;

    getline(cin, s);
    cin>> lineSize;

    istringstream word(s);

    while(word>>w)
    {
        v.push_back(w);
    }

    while(pos<v.size())
    {
        if(len == 0){
            if(v[pos].size() <= lineSize){
                len = v[pos].size();
                ans = v[pos++];
            }
            else{
                res.push_back(v[pos++]);
                len = 0;
                ans = "";
            }
        }
        else{
            if(len+v[pos].size()<lineSize){
                ans += " ";
                len += v[pos].size()+1;
                ans += v[pos++];
            }
            else{
                res.push_back(ans);
                len = 0;
                ans = "";
            }
        }
    }
    if(len>0) res.push_back(ans);

    for(int i = 0; i < res.size(); i++){
        int L = res[i].size();
        cout<<res[i];
        for(int j = 0; j < lineSize-L; j++){
            printf(".");
        }
        printf("\n");
    }

    return 0;
}

/*
This is the first time that i am gonna code of right to left alignment.
16

This is the
first time that
i am gonna code
of right to left
alignment

*/
