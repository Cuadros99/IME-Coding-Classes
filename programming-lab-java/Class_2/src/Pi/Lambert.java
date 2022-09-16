package Pi;

public class Lambert {

    private double recursiveDenominator(int i, int maxMembers) {
        if(i == maxMembers) {
            return 1;
        }
        else {
            double aux = 2*i-1 + Math.pow(i,2)/recursiveDenominator(++i,maxMembers);
            return aux;
        }
    }
    public double getPi(int maxMembers) {
        return 4/(1 + 1/ recursiveDenominator(2, maxMembers));
    }

}
