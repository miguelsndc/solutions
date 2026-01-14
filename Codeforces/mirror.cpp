#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Interactive problem - ensure we flush output after every query.
void solve() {
    int n;
    cin >> n;
    
    // Using 1-based indexing for convenience to match the problem statement
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    // Iterate from the outermost pair inwards
    for (int l = 1; l <= n / 2; ++l) {
        int r = n - l + 1;
        
        // Target values for these positions
        int val_l = l;
        int val_r = r;

        // Keep trying until BOTH ends of the mirror pair are correct
        while (p[l] != val_l || p[r] != val_r) {
            
            // Find where the target values currently are
            int idx_l = -1;
            int idx_r = -1;
            
            for (int i = 1; i <= n; ++i) {
                if (p[i] == val_l) idx_l = i;
                if (p[i] == val_r) idx_r = i;
            }

            int x, y; // The indices we will query

            // Priority 1: If the values are cross-swapped at the boundaries.
            // Using ? L R is deterministic (mirror of L,R is R,L).
            if (idx_l == r) {
                x = l; 
                y = r;
            } 
            else if (idx_r == l) {
                x = l; 
                y = r;
            }
            // Priority 2: Try to fix the Left side if it's wrong.
            // If the coin flips wrong, we might mess up R, but we will fix it later.
            else if (idx_l != l) {
                x = l;
                y = idx_l;
            }
            // Priority 3: Left is correct, but Right is wrong.
            // We try to fix Right. If coin flips wrong, we mess up Left, 
            // and will catch it in Priority 2 next iteration.
            else {
                x = idx_r;
                y = r;
            }

            // Perform Query
            cout << "? " << x << " " << y << endl;
            
            int u, v;
            cin >> u >> v;
            
            if (u == -1) exit(0); // Standard interactive problem exit condition
            
            swap(p[u], p[v]);
        }
    }

    cout << "!" << endl;
}

int main() {
    // Optimization for faster I/O not strictly necessary due to interaction, 
    // but good practice.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}