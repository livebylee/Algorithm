#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, P;
    if (!(cin >> N >> P)) return 0;
    vector<int> visited_order(P, 0); 
    
    long long current = (long long)N * N;
    current %= P;
    
    int step = 1;


    while (true) {
        int next_val = (int)current; // 현재 값 (0 ~ P-1)

        if (visited_order[next_val] != 0) {
            // 사이클이 시작된 순서 (예: 25가 1번째에 등장)
            int start_step = visited_order[next_val];
            
            // 현재 순서 - 사이클 시작 순서 = 사이클의 길이
            // 예: 4번째에 25가 다시 등장 (step=4), 1번째에 처음 등장 (start_step=1) -> 길이 4-1 = 3
            int cycle_length = step - start_step; 
            
            cout << cycle_length << "\n";
            return 0;
        }

        // 2. 현재 값을 방문 처리하고 순서 기록
        visited_order[next_val] = step;

        // 3. 다음 항을 계산하여 current 업데이트
        // Xk+1 = (Xk * N) % P
        current *= N;
        current %= P;
        
        // 4. 순서 증가
        step++;
    }

    return 0;
}