package com.lab;

public class Factorial {
    public long factorial(int n) {
        if (n < 0) throw new IllegalArgumentException("Negative number not allowed");
        long result = 1;
        for (int i = 2; i <= n; i++) {
            result *= i;
        }
        return result;
    }

    public static void main(String[] args) {
        Factorial f = new Factorial();
        System.out.println("5! = " + f.factorial(5));
    }
}