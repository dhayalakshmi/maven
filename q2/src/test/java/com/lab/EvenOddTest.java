package com.lab;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class EvenOddTest {
    EvenOdd e = new EvenOdd();

    @Test
    void testEven() {
        assertTrue(e.isEven(10));
        assertTrue(e.isEven(0));
    }

    @Test
    void testOdd() {
        assertFalse(e.isEven(7));
        assertFalse(e.isEven(-3));
    }
}

