package com.lab;

public class PrimeChecker {
    public boolean isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        PrimeChecker p = new PrimeChecker();
        int n = 17;
        System.out.println(n + (p.isPrime(n) ? " is Prime" : " is not Prime"));
    }
}