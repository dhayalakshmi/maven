package com.lab;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class PrimeCheckerTest {
    PrimeChecker p = new PrimeChecker();

    @Test
    void testPrime() {
        assertTrue(p.isPrime(2));
        assertTrue(p.isPrime(17));
    }

    @Test
    void testNotPrime() {
        assertFalse(p.isPrime(1));
        assertFalse(p.isPrime(0));
        assertFalse(p.isPrime(20));
    }
}