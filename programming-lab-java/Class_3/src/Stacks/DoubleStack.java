package Stacks;

public class DoubleStack {
    double vector[];
    int size,top;

    public DoubleStack(int size) {
        this.size = size;
        this.vector = new double[size];
        top = -1;
    }

    public void push(double item) {
        if(top < size) {
            top++;
            vector[top] = item;
            return;
        }
        System.out.println("Stack is full");
    }

    public void pop() {
        if(top == -1) {
            System.out.println("Stack is empty");
            return;
        }
        top--;
    }
}
