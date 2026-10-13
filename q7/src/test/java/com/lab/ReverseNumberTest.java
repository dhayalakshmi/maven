package com.lab;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class ReverseNumberTest {

    @Test
    void testPositive() {
        assertEquals(54321, ReverseNumber.reverse(12345));
    }

    @Test
    void testNegative() {
        assertEquals(-321, ReverseNumber.reverse(-123));
    }

    @Test
    void testZero() {
        assertEquals(0, ReverseNumber.reverse(0));
    }

    @Test
    void testTrailingZeros() {
        assertEquals(1, ReverseNumber.reverse(100));
    }
}