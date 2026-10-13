package com.lab;

public class EvenOdd {
    public boolean isEven(int n) {
        return n % 2 == 0;
    }

    public static void main(String[] args) {
        EvenOdd e = new EvenOdd();
        int n = 6;
        System.out.println(n + (e.isEven(n) ? " is Even" : " is Odd"));
    }
}