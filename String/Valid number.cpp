


    bool isNumber(char *s) {
        int i = 0;
        int n = strlen(s);
        int dotv = 0, var = 0;
        
        if(s[i] == '+' || s[i] == '-') ++i;
        if(i == n) return false;
        
        if(s[i] == '.' && (i + 1 == n || s[i + 1] == 'e' || s[i + 1] == 'E')) return false;

        for(int j = i; j < n; ++j) {
            if(s[j] == '.') {
                if(var || dotv) return false;
                ++dotv;
            }
            else if(s[j] == 'e' || s[j] == 'E') {
                if(var || j == i || j == n - 1) return false;
                ++var;
                if(s[j + 1] == '+' || s[j + 1] == '-') {
                    if(++j == n - 1) return false;
                }
            }
            else if(s[j] < '0' || s[j] > '9') return false;
        }
        return true;
    }

