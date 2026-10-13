package com.lab;

public class ReverseNumber {

    public static int reverse(int n) {
        boolean negative = n < 0;
        n = Math.abs(n);
        int rev = 0;
        while (n > 0) {
            rev = rev * 10 + n % 10;
            n /= 10;
        }
        return negative ? -rev : rev;
    }

    public static void main(String[] args) {
        System.out.println("Reverse of 12345 is " + reverse(12345));
    }
}