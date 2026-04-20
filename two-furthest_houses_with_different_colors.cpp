class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int maxm = INT_MIN;
        int dist;
        for(int i = 0; i < colors.size(); i++){
            for(int j = 0; j < colors.size(); j++){
                if(colors[i] > colors[j]) dist = abs(i-j);

                maxm = max(maxm,dist);
            }
        }
        return maxm;
    }
};