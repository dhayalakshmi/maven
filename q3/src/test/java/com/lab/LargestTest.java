package com.lab;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class LargestTest {
    Largest l = new Largest();

    @Test
    void testFirstLargest() {
        assertEquals(50, l.findLargest(50, 20, 10));
    }

    @Test
    void testSecondLargest() {
        assertEquals(45, l.findLargest(12, 45, 30));
    }

    @Test
    void testThirdLargest() {
        assertEquals(99, l.findLargest(1, 2, 99));
    }
}