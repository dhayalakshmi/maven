package com.lab;

public class Largest {
    public int findLargest(int a, int b, int c) {
        if (a >= b && a >= c) return a;
        if (b >= a && b >= c) return b;
        return c;
    }

    public static void main(String[] args) {
        Largest l = new Largest();
        System.out.println("Largest = " + l.findLargest(12, 45, 30));
    }
}