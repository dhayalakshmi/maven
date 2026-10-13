package com.example;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class ReverseStringTest {

    @Test
    void testNormalString() {
        assertEquals("olleh", ReverseString.reverse("hello"));
    }

    @Test
    void testEmptyString() {
        assertEquals("", ReverseString.reverse(""));
    }

    @Test
    void testSingleCharacter() {
        assertEquals("a", ReverseString.reverse("a"));
    }

    @Test
    void testWithSpaces() {
        assertEquals("dlrow olleh", ReverseString.reverse("hello world"));
    }

    @Test
    void testNullString() {
        assertNull(ReverseString.reverse(null));
    }
}