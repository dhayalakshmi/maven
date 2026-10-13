package com.lab;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class FactorialTest {
    Factorial f = new Factorial();

    @Test
    void testZero() {
        assertEquals(1, f.factorial(0));
    }

    @Test
    void testFive() {
        assertEquals(120, f.factorial(5));
    }

    @Test
    void testNegative() {
        assertThrows(IllegalArgumentException.class, () -> f.factorial(-1));
    }
}