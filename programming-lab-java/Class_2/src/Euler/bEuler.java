package Euler;

public class bEuler {
    private double recursiveDominator(int i, int maxMembers) {
        if(i >= maxMembers)
            return 1;
        else
            return (i + 1/(recursiveDominator(i+4, maxMembers)));
    }
    public double getEuler(int maxMembers) {
        double res = 1 + 2/(1 + 1/recursiveDominator(6, maxMembers));
        return res;
    }
}
