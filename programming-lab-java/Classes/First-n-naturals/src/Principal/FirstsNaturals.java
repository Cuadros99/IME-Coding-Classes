package Principal;

public class FirstsNaturals {
    private int max;

    public FirstsNaturals(int max) {
        this.max = max;
    }

    public int getMax() {
        return max;
    }

    public void setMax(int max) {
        this.max = max;
    }

    public void getNFirstNaturals() {
        int i=1;
        while(i<=max) {
            System.out.printf("%d ",i);
            i++;
        }
    }
}
