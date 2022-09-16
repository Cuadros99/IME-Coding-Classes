package Euler;

public class aEuler {

    private double recursiveDenominator(int i, int maxMembers) {
        if(i == maxMembers)
            return 1;
        else
            return  2*i + 1/(1 + 1/(1 + 1/recursiveDenominator(++i, maxMembers)));
    }

    public double getEuler(int maxMembers) {
        double res = 2 + 1/(1 + 1/recursiveDenominator(1, maxMembers));
        return res;
    }
}
