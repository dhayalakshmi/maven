package com.example;

public class ReverseString {

    public static String reverse(String s) {
        if (s == null) {
            return null;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = s.length() - 1; i >= 0; i--) {
            sb.append(s.charAt(i));
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        String text = "hello";
        System.out.println("Reverse of \"" + text + "\" is \"" + reverse(text) + "\"");
    }
}