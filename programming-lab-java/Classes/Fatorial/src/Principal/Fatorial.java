package Principal;

public class Fatorial {
    private int num;

    public Fatorial(int num) {
        this.num = num;
    }

    public int getResult() {
        return num;
    }

    public void setResult(int num) {
        this.num = num;
    }

    private int internCompute(int number) {
        if(number == 1)
            return 1;
        return number*internCompute(number-1);
    }

    public int fatorialCompute() {
        return internCompute(num);
    }
}
