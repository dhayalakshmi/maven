package com.example;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class PalindromeStringTest {

    @Test
    void testPalindrome() {
        assertTrue(PalindromeString.isPalindrome("madam"));
    }

    @Test
    void testNotPalindrome() {
        assertFalse(PalindromeString.isPalindrome("hello"));
    }

    @Test
    void testIgnoreCaseAndSpaces() {
        assertTrue(PalindromeString.isPalindrome("Race Car"));
    }

    @Test
    void testSentence() {
        assertTrue(PalindromeString.isPalindrome("A man, a plan, a canal: Panama"));
    }

    @Test
    void testEmptyString() {
        assertTrue(PalindromeString.isPalindrome(""));
    }

    @Test
    void testNullString() {
        assertFalse(PalindromeString.isPalindrome(null));
    }
}