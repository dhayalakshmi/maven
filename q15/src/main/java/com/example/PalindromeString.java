package com.example;

public class PalindromeString {

    public static boolean isPalindrome(String s) {
        if (s == null) {
            return false;
        }
        String cleaned = s.toLowerCase().replaceAll("[^a-z0-9]", "");
        int left = 0;
        int right = cleaned.length() - 1;
        while (left < right) {
            if (cleaned.charAt(left) != cleaned.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    public static void main(String[] args) {
        String text = "madam";
        System.out.println("\"" + text + "\"" + (isPalindrome(text) ? " is a palindrome" : " is not a palindrome"));
    }
}