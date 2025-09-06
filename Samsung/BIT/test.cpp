#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);

        int max = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            max = std::max(max, a[i]);
        }

        std::vector<int> counting(max + 1, 0);
        for (int i = 0; i < n; ++i) {
            ++counting[a[i]];
        }

        for (int i = 0; i <= max; ++i) {
            if (counting[i]) {
                for (int j = 1; j <= counting[i]; ++j) std::cout << i << " ";
            }
        }
        std::cout << "\n";
    }
}