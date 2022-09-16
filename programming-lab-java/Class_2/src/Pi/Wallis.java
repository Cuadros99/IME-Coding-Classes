package Pi;

public class Wallis {
    public static double getPi(double accuracy) {
        double aux = 1;
        int i = 1;

        while(Math.abs((2*aux)-Math.PI) > accuracy) {
            aux *= (4*Math.pow(i,2))/(4*Math.pow(i,2)-1);
            i++;
        }

        return 2*aux;
    }
}