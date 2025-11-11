#include <iostream>
#include <vector>
#include <algorithm> 
#include <cfloat>    

using namespace std;

int n;
int h[50];
int ans[50]; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }

    int max_visible_count = 0; 
    for(int b = 0; b < n; b++){
        int current_count = 0;
        
        double max_slope = -DBL_MAX; 
        for(int i = b + 1; i < n; i++){
            double g = (double)(h[i] - h[b]) / (i - b);
            if(g > max_slope) { 
                current_count++;  
                max_slope = g;    
            }
        }

        double min_slope = DBL_MAX; 
        for(int i = b - 1; i >= 0; i--){
            double g = (double)(h[i] - h[b]) / (i - b);
            if(g < min_slope) { 
                current_count++; 
                min_slope = g;    
            }
        }
        ans[b] = current_count;
        max_visible_count = max(max_visible_count, ans[b]);
    }

    cout << max_visible_count << '\n';
    
    return 0; 
}