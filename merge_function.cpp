void merge(int a[], int n, int b[], int m, pair<int, int> p[]) {
    
    int i=0, j=0, k=0;
    while(i < n && j < m) {
        if(a[i] < b[j]) {
            p[k].first = a[i];
            p[k].second = 1;
            ++i; 
        } else {
            p[k].first = b[j];
            p[k].second = 2;
            ++j; 
        }
        ++k;
    }

    while(i < n) {
        p[k].first = a[i];
        p[k].second = 1;
        ++i; ++k;
    }
    while(j < m) {
        p[k].first = b[j];
        p[k].second = 2;
        ++j; ++k;
    }
}