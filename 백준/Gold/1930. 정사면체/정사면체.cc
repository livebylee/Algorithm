#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;
using int64 = long long;

void Init(int a, int b, int c, int d, vector<pair<int, vector<int>>>& pv){
    // 1. A를 밑면으로 할 때: A, {B, C, D}
    vector<int> v1;
    v1.push_back(b);
    v1.push_back(c);
    v1.push_back(d);

    // 2. B를 밑면으로 할 때: B, {A, D, C} 
    // (A, C, D가 서로 붙어있는 면이므로, B가 밑면일 때 옆면이 시계방향으로 A, D, C 순서가 되도록 설정)
    vector<int> v2;
    v2.push_back(a);
    v2.push_back(d);
    v2.push_back(c);

    // 3. C를 밑면으로 할 때: C, {D, A, B} 
    vector<int> v3;
    v3.push_back(d);
    v3.push_back(a);
    v3.push_back(b);

    // 4. D를 밑면으로 할 때: D, {C, B, A} 
    vector<int> v4;
    v4.push_back(c);
    v4.push_back(b);
    v4.push_back(a);

    pv.push_back(make_pair(a, v1));
    pv.push_back(make_pair(b, v2));
    pv.push_back(make_pair(c, v3));
    pv.push_back(make_pair(d, v4));
}


bool CompareSame(vector<int>& v, vector<int>& comp){
    bool ret = false;
    // comp의 3가지 회전 상태를 v와 비교
    for (int i = 0; i < comp.size(); i++)
    {
        bool tmp = true;
        int addIdx = i; // comp를 i번 회전
        for (int j = 0; j < v.size(); j++)
        {
            // v[j]와 comp의 (j + addIdx)번째 요소를 비교
            if (v[j] != comp[(j + addIdx) % comp.size()]) tmp = false;
        }
        ret |= tmp;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;
    cin >> k;
    while (k--)
    {
        int a, b, c, d;
        // pv: (밑면 색깔, {옆면1, 옆면2, 옆면3}) 쌍을 저장하는 벡터
        vector<pair<int, vector<int>>> pv; 
        
        // 첫 번째 정사면체 입력
        cin >> a >> b >> c >> d; 
        Init(a, b, c, d, pv); // 첫 번째 정사면체의 4가지 '밑면' 배치를 모두 생성

        int ans = 0;

        // 두 번째 정사면체 입력
        cin >> a >> b >> c >> d; 
        
        // 두 번째 정사면체의 초기 상태: {a, b, c, d} -> 밑면 a, 옆면 {b, c, d}
        vector<int> comp{ b,c,d }; 
        
        // 첫 번째 정사면체의 모든 4가지 밑면 배치(pv)와 비교
        for (auto am : pv)
        {
            // 밑면 색깔이 같아야 회전을 통해 일치할 가능성이 있음
            if (am.first != a) continue; 
            
            // 밑면이 같은 경우, 옆면의 회전 일치 여부 확인
            vector<int>& v = am.second;
            bool res = CompareSame(v, comp);
            
            if (res) ans = 1; // 일치하는 경우가 발견되면 결과 1로 설정
        }
        cout << ans << "\n";
    }
}