package Principal;

public class PrintingIntegers {
    public void printInts(int vector[]) {
        int total;
        for(int e: vector)
            System.out.println(e);
    }

    public static void main(String[] args) {
        int vectorInt[] = {1,2,3,4};

        PrintingIntegers example = new PrintingIntegers();
        example.printInts(vectorInt);
    }
}
