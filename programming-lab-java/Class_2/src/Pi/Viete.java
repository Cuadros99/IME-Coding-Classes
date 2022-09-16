package Pi;

import java.lang.Math;


public class Viete {
    public double getPi(int n_elem) {
        double aux = 1, num = 0;

        for(int i=0 ; i < n_elem; i++) {
            num += 2;
            num = Math.sqrt(num);
            aux *= num/2;
        }
        return 2/aux;
    }
}
