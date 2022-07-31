class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1, 0);
        long long nCr = 1, dm = 1, nm = rowIndex;
        result[0] = result[rowIndex] = 1;
        for(int i = 1; i < rowIndex; i++) {
            nCr =  nCr * nm/dm;
            nm--;
            dm++;
            result[i] = nCr;
        }
        return result;
    }
};