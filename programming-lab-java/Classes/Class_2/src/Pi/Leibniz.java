package Pi;

public class Leibniz {
    public static double getPi(double accuracy) {
        double exp = 1;
        int i = 1;

        while(Math.abs(4*exp - Math.PI) > accuracy) {
            if(i%2 != 0)
                exp -= 1.0/(2*i+1);
            else
                exp += 1.0/(2*i+1);
            i++;
        }

        return 4*exp;
    }
}
