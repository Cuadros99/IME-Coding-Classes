package SieveOfEratosthenes;

public class SieveAlgorithm {
    int size;
    boolean[] numbersList;

    public SieveAlgorithm(int size) {
        this.size = size;
        numbersList = new boolean[size+1];
    }

    private void findPrimes() {
        for(int i=2; i < Math.sqrt(size); i++) {
            if(!numbersList[i]) {
                for(int j=2*i ; j < size; j+=i) {
                    numbersList[j] = true;
                }
            }
        }
    }
    public void showPrimes() {
        findPrimes();
        for(int k=2 ; k < size ; k++ ) {
            if(!numbersList[k])
                System.out.printf("%d ", k);
        }
    }
}
