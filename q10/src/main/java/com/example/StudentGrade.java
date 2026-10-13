package com.example;

public class StudentGrade {

    public static String getGrade(int marks) {
        if (marks < 0 || marks > 100) {
            return "Invalid";
        } else if (marks >= 90) {
            return "A";
        } else if (marks >= 80) {
            return "B";
        } else if (marks >= 70) {
            return "C";
        } else if (marks >= 60) {
            return "D";
        } else if (marks >= 50) {
            return "E";
        } else {
            return "F";
        }
    }

    public static void main(String[] args) {
        int marks = 85;
        System.out.println("Marks: " + marks + " Grade: " + getGrade(marks));
    }
}