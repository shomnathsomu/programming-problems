char s[100];
string s1, s2;
map <string, int> mp;

int main(int argc, const char *argv[]) {

    while(gets(s)){

        int len = strlen(s);
        int cnt = 0;

        for(int i = 0; i < len; i++){
            s1 = "";
            for(int j = i; j < len; j++){

                s1 += s[j];
                s2 = "";
                for(int k = s1.size()-1; k >= 0; k--) s2 += s1[k];
                if(s1 == s2) mp[s1] = 1;

            }
        }

        printf("The string '%s' contains %d palindromes.\n", s, mp.size());
        mp.clear();

    }

}
