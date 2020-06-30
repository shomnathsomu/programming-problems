#include <stdio.h>
#include <string.h>
int grid[52][52];
char O, dir[101];

int main()
{
    int a, b, flag;
    scanf("%d %d", &a, &b);

    int posx, posy;
    int len, i, x, y;

    while(scanf("%d %d %c", &posx, &posy, &O)!=EOF)
    {
        scanf("%s", dir);
        len = strlen(dir);
        flag = 0;
        for(i = 0; i < len; i++){
            if(dir[i] == 'R'){
                if(O == 'N') O = 'E';
                else if(O == 'E') O = 'S';
                else if(O == 'S') O = 'W';
                else if(O == 'W') O = 'N';
            }
            else if(dir[i] == 'L'){
                if(O == 'N') O = 'W';
                else if(O == 'E') O = 'N';
                else if(O == 'S') O = 'E';
                else if(O == 'W') O = 'S';
            }
            else if(dir[i] == 'F'){
                if(O == 'N') x = posx, y = posy + 1;
                else if(O == 'E') x = posx + 1, y = posy;
                else if(O == 'S') x = posx, y = posy - 1;
                else if(O == 'W') x = posx - 1, y = posy;

                if(x >= 0 && x <= a && y >= 0 && y <= b) posx = x, posy = y;
                else if(grid[posx][posy] == 0){
                    grid[posx][posy] = 1;
                    flag = 1;
                    break;
                }
            }
        }
        if(flag) printf("%d %d %c LOST\n", posx, posy, O);
        else printf("%d %d %c\n", posx, posy, O);
    }

    return 0;
}
