class Solution {
    public double champagneTower(int poured, int query_row, int query_glass) {
        if(poured == 0) return 0;

        double[] m = new double[101];
        m[0] = poured;

        for(int i =0; i< query_row; i++){
            for(int j = i; j >= 0; j--){
                if(m[j] > 1){
                    double q = (m[j] - 1)/ 2;
                    m[j +1] += q;
                    m[j] = q;
                }else m[j] = 0;
            }
        }
        return Math.min(1, m[query_glass]);
    }
}