package Principal;

public class GenericExample {
    public <T> void printExample(T vector[]) {
        T total;
        for(T e: vector)
            System.out.println(e);
    }

    public static void main(String[] args) {
        Integer vectorInt[] = {1,2,3,4};
        Double[] vectorFloatPoint = {1.0,2.0,3.0,4.0};
        Character vectorChar[] = {'a', 'b', 'c', 'd'};

        GenericExample example = new GenericExample();
        example.printExample(vectorInt);
        example.printExample(vectorFloatPoint);
        example.printExample(vectorChar);
    }
}
