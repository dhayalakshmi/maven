package com.example;

public class SimpleInterest {

    public static double calculate(double principal, double rate, double time) {
        return (principal * rate * time) / 100;
    }

    public static void main(String[] args) {
        double si = calculate(1000, 5, 2);
        System.out.println("Simple Interest = " + si);
    }
}