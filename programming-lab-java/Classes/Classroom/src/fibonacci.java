public class fibonacci {
    public static void main(String[] args) {
        int n = 10;
        long ans = 0;
        long n1 = 0;
        long n2 = 1;
        for(n--; n > 0; n--){
            ans = n1 + n2;
            n1 = n2;
            n2 = ans;
        }
        System.out.println(ans);
    }
}
