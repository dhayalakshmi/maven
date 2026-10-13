package com.example;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class PalindromeNumberTest {

    @Test
    void testPalindrome() {
        assertTrue(PalindromeNumber.isPalindrome(121));
        assertTrue(PalindromeNumber.isPalindrome(12321));
    }

    @Test
    void testNotPalindrome() {
        assertFalse(PalindromeNumber.isPalindrome(123));
    }

    @Test
    void testSingleDigit() {
        assertTrue(PalindromeNumber.isPalindrome(7));
    }

    @Test
    void testNegative() {
        assertFalse(PalindromeNumber.isPalindrome(-121));
    }
}