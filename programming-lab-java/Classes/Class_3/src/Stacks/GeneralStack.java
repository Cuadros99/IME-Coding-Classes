package Stacks;

public class GeneralStack {
    int vector[],size,top;

    public GeneralStack(int size) {
        this.size = size;
        this.vector = new int[size];
        top = -1;
    }

    public void push(int item) {
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
