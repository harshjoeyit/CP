

// counting the subarrays, all of whose subarray have sum != 0
int main() {
      int n;
	cin >> n;
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

      int st = 0, sum = 0, ans = 0;
      unordered_map<int, int> ump;
      ump[0] = 1;

      for (int i = 1; i <= n; i++) {
            sum += a[i];

            st = max(st, ump[sum]);
            cout << st << " " << i << " " << (i - st) << endl;
            ans += (i - st);
            ump[sum] = i + 1;
      }
      cout << ans << endl;
}