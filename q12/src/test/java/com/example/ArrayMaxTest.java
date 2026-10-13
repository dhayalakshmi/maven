package com.example;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class ArrayMaxTest {

    @Test
    void testNormalArray() {
        assertEquals(89, ArrayMax.max(new int[]{12, 45, 7, 89, 23}));
    }

    @Test
    void testAllNegative() {
        assertEquals(-1, ArrayMax.max(new int[]{-5, -1, -9}));
    }

    @Test
    void testSingleElement() {
        assertEquals(42, ArrayMax.max(new int[]{42}));
    }

    @Test
    void testEmptyArrayThrows() {
        assertThrows(IllegalArgumentException.class, () -> ArrayMax.max(new int[]{}));
    }
}