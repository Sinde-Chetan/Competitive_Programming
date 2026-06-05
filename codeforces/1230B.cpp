int n, k;
cin >> n >> k;

string s;
cin >> s;

if(n == 1 && k >= 1){
    cout << 0 << "\n";
    return 0;
}

int oper = 0;

if(s[0] != '1' && oper < k){
    s[0] = '1';
    oper++;
}

for(int i = 1; i < n && oper < k; i++){
    if(s[i] != '0'){
        s[i] = '0';
        oper++;
    }
}

cout << s << "\n";
