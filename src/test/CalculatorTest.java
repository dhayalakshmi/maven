package com.lab;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class CalculatorTest {
    Calculator c = new Calculator();

    @Test
    void testAddPositive() {
        assertEquals(30, c.add(10, 20));
    }

    @Test
    void testAddNegative() {
        assertEquals(-5, c.add(-10, 5));
    }
}