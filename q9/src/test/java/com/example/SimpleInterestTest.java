package com.example;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class SimpleInterestTest {

    @Test
    void testNormalCase() {
        assertEquals(100.0, SimpleInterest.calculate(1000, 5, 2), 0.001);
    }

    @Test
    void testZeroPrincipal() {
        assertEquals(0.0, SimpleInterest.calculate(0, 5, 2), 0.001);
    }

    @Test
    void testDecimalRate() {
        assertEquals(75.0, SimpleInterest.calculate(1000, 2.5, 3), 0.001);
    }
}