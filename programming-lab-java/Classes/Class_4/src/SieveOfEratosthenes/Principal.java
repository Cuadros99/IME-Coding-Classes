package SieveOfEratosthenes;

import java.sql.SQLIntegrityConstraintViolationException;

public class Principal {
    public static void main(String[] args) {
        SieveAlgorithm Sieve1 = new SieveAlgorithm(100);
        Sieve1.showPrimes();
    }
}
