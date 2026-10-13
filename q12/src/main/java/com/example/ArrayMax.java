package com.example;

public class ArrayMax {

    public static int max(int[] arr) {
        if (arr == null || arr.length == 0) {
            throw new IllegalArgumentException("Array must not be empty");
        }
        int max = arr[0];
        for (int x : arr) {
            if (x > max) {
                max = x;
            }
        }
        return max;
    }

    public static void main(String[] args) {
        int[] arr = {12, 45, 7, 89, 23};
        System.out.println("Maximum = " + max(arr));
    }
}