int coin[] = {1, 2, 5, 10, 20, 50, 100, 500};
int dp[10][1000];
int money;
int coinchange(int i, int amount)
{
    if(i >= 8){
        if(amount == money) return 1;
        else return 0;
    }
    if(dp[i][amount] != -1) return dp[i][amount];

    int ret1=0, ret2=0;
    if(amount + coin[i] <= money) ret1 = coinchange(i, amount + coin[i]);
    ret2 = coinchange(i+1, amount);

    return dp[i][amount] = ret1|ret2;
}

main()
{
    memset(dp,-1,sizeof dp);
    while(cin >> money)
    {
        cout << coinchange(0, 0) << endl;
    }

    return 0;
}
