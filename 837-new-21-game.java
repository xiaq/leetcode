class Solution {
    public double new21Game(int N, int K, int W) {
        if (K == 0) {
            return 1;
        }
        double[] p = new double[K+W];
        for (int i = K; i <= N && i < p.length; i++) {
            p[i] = 1;
        }
        if (N-K+1 >= W) {
            p[K-1] = 1;
        } else {
            p[K-1] = (double)(N-K+1) / W;
        }
        for (int i = K-2; i >= 0; i--) {
            p[i] = p[i+1] + (p[i+1] - p[i+W+1]) / W;
        }
        return p[0];
    }    
}
