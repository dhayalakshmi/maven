package com.example;

public class PalindromeNumber {

    public static boolean isPalindrome(int n) {
        if (n < 0) {
            return false;
        }
        int original = n;
        int rev = 0;
        while (n > 0) {
            rev = rev * 10 + n % 10;
            n /= 10;
        }
        return original == rev;
    }

    public static void main(String[] args) {
        int num = 121;
        System.out.println(num + (isPalindrome(num) ? " is a palindrome" : " is not a palindrome"));
    }
}