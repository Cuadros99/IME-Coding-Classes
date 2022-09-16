package Stacks;

public class Principal {
    public static void main(String[] args) {
        IntStack iStack =  new IntStack(10);
        iStack.push(5);
        iStack.push(2);
        iStack.push(4);
        iStack.push(3);
        iStack.pop();
    }
}
