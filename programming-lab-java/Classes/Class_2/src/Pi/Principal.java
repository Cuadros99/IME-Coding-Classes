package Pi;

public class Principal {
    public static void main(String[] args) {
        System.out.printf("Viete: %f\n", new Viete().getPi(10));
        System.out.printf("Wallis: %f\n",Wallis.getPi(0.00001));
        System.out.printf("Leibniz: %f\n",Leibniz.getPi(0.000001));
        System.out.printf("Lambert: %f\n",new Lambert().getPi(10));
    }
}